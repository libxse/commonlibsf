#include "SFSE/API.h"

#include "SFSE/Interfaces.h"
#include "SFSE/Logger.h"

#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/msvc_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/spdlog.h>

namespace SFSE
{
	namespace Impl
	{
		class API :
			public REX::TSingleton<API>
		{
		public:
			void Init(InitInfo, const SFSE::QueryInterface* a_intfc);
			void InitLog();
			void InitTrampoline();
			void InitHook(REL::EHookStep a_step);

			InitInfo info;

			std::string_view pluginName{};
			std::string_view pluginAuthor{};
			REL::Version     pluginVersion{};

			std::uint32_t                           sfseVersion{};
			PluginHandle                            pluginHandle{ static_cast<PluginHandle>(-1) };
			std::function<const void*(const char*)> pluginInfoAccessor;

			TrampolineInterface* trampolineInterface{ nullptr };
			MessagingInterface*  messagingInterface{ nullptr };
			MenuInterface*       menuInterface{ nullptr };
			TaskInterface*       taskInterface{ nullptr };

			std::mutex                         apiLock;
			std::vector<std::function<void()>> apiInitRegs;
			bool                               apiInit{};
		};

		void API::Init(InitInfo a_info, const SFSE::QueryInterface* a_intfc)
		{
			info = a_info;

			static std::once_flag once;
			std::call_once(once, [&]() {
				if (const auto data = PluginVersionData::GetSingleton()) {
					pluginName = data->GetPluginName();
					pluginAuthor = data->GetAuthorName();
					pluginVersion = data->GetPluginVersion();
				} else {
					std::vector<char> buf(REX::W32::MAX_PATH, '\0');
					const auto        size = REX::W32::GetModuleFileNameA(REX::W32::GetCurrentModule(), buf.data(), REX::W32::MAX_PATH);
					if (size) {
						std::filesystem::path p(buf.begin(), buf.begin() + size);
						pluginName = p.stem().string();
					}
				}

				sfseVersion = a_intfc->SFSEVersion();
				pluginHandle = a_intfc->GetPluginHandle();
				pluginInfoAccessor = reinterpret_cast<const Impl::SFSEInterface*>(a_intfc)->GetPluginInfo;
			});
		}

		void API::InitLog()
		{
			if (info.log) {
				static std::once_flag once;
				std::call_once(once, [&]() {
					auto path = log::log_directory();
					if (!path)
						return;

					*path /= std::format("{}.log", info.logName ? info.logName : SFSE::GetPluginName());

					std::vector<spdlog::sink_ptr> sinks{
						std::make_shared<spdlog::sinks::msvc_sink_mt>()
					};

					if (info.logRotate > 0) {
						constexpr auto maxSize = std::numeric_limits<std::size_t>::max();
						sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(path->string(), maxSize, info.logRotate, true));
					} else {
						sinks.push_back(std::make_shared<spdlog::sinks::basic_file_sink_mt>(path->string(), true));
					}

					auto logger = std::make_shared<spdlog::logger>("global", sinks.begin(), sinks.end());
					logger->set_level(static_cast<spdlog::level::level_enum>(info.logLevel));
					logger->flush_on(static_cast<spdlog::level::level_enum>(info.logLevel));

					spdlog::set_default_logger(std::move(logger));
					spdlog::set_pattern(info.logPattern ? info.logPattern : "[%T.%e] [%=5t] [%L] %v");

					REX::INFO("{} v{}", GetPluginName(), GetPluginVersion());
				});
			}
		}

		void API::InitTrampoline()
		{
			if (info.trampoline) {
				static std::once_flag once;
				std::call_once(once, [&]() {
					if (!info.trampolineSize) {
						const auto hookStore = REL::FHookStore::GetSingleton();
						info.trampolineSize += hookStore->GetSizeTrampoline();
					}

					auto& trampoline = REL::GetTrampoline();
					if (const auto intfc = GetTrampolineInterface()) {
						if (const auto mem = intfc->AllocateFromBranchPool(info.trampolineSize))
							trampoline.set_trampoline(mem, info.trampolineSize);
						else
							trampoline.create(info.trampolineSize);
					}
				});
			}
		}

		void API::InitHook(REL::EHookStep a_step)
		{
			if (info.hook) {
				const auto hookStore = REL::FHookStore::GetSingleton();
				hookStore->Init();
				hookStore->Enable(a_step);
			}
		}
	}

	void Init(const PreLoadInterface* a_intfc, InitInfo a_info) noexcept
	{
		static std::once_flag once;
		std::call_once(once, [&]() {
			auto api = Impl::API::GetSingleton();
			api->Init(a_info, a_intfc);
			api->InitLog();

			api->trampolineInterface = a_intfc->QueryInterface<TrampolineInterface>(PreLoadInterface::kTrampoline);

			api->InitTrampoline();
			api->InitHook(REL::EHookStep::PreLoad);
		});
	}

	void Init(const LoadInterface* a_intfc, InitInfo a_info) noexcept
	{
		static std::once_flag once;
		std::call_once(once, [&]() {
			auto api = Impl::API::GetSingleton();
			api->Init(a_info, a_intfc);
			api->InitLog();

			api->messagingInterface = a_intfc->QueryInterface<MessagingInterface>(LoadInterface::kMessaging);
			api->trampolineInterface = a_intfc->QueryInterface<TrampolineInterface>(LoadInterface::kTrampoline);
			api->menuInterface = a_intfc->QueryInterface<MenuInterface>(LoadInterface::kMenu);
			api->taskInterface = a_intfc->QueryInterface<TaskInterface>(LoadInterface::kTask);

			const std::scoped_lock lock{ api->apiLock };
			if (!api->apiInit) {
				api->apiInit = true;
				auto& regs = api->apiInitRegs;
				for (const auto& reg : regs) {
					reg();
				}
				regs.clear();
				regs.shrink_to_fit();
			}

			api->InitTrampoline();
			api->InitHook(REL::EHookStep::Load);
		});
	}

	void RegisterForAPIInitEvent(const std::function<void()>& a_fn)
	{
		auto                   api = Impl::API::GetSingleton();
		const std::scoped_lock lock{ api->apiLock };
		if (!api->apiInit) {
			api->apiInitRegs.push_back(a_fn);
			return;
		}

		a_fn();
	}

	std::uint32_t GetSFSEVersion() noexcept
	{
		return Impl::API::GetSingleton()->sfseVersion;
	}

	std::string_view GetPluginName() noexcept
	{
		return Impl::API::GetSingleton()->pluginName;
	}

	std::string_view GetPluginAuthor() noexcept
	{
		return Impl::API::GetSingleton()->pluginAuthor;
	}

	REL::Version GetPluginVersion() noexcept
	{
		return Impl::API::GetSingleton()->pluginVersion;
	}

	PluginHandle GetPluginHandle() noexcept
	{
		return Impl::API::GetSingleton()->pluginHandle;
	}

	const PluginInfo* GetPluginInfo(std::string_view a_plugin) noexcept
	{
		if (const auto& accessor = Impl::API::GetSingleton()->pluginInfoAccessor) {
			if (const auto result = accessor(a_plugin.data())) {
				return static_cast<const PluginInfo*>(result);
			}
		}

		REX::ERROR("failed to get plugin info for {}", a_plugin);
		return nullptr;
	}

	const TrampolineInterface* GetTrampolineInterface() noexcept
	{
		return Impl::API::GetSingleton()->trampolineInterface;
	}

	const MessagingInterface* GetMessagingInterface() noexcept
	{
		return Impl::API::GetSingleton()->messagingInterface;
	}

	const MenuInterface* GetMenuInterface() noexcept
	{
		return Impl::API::GetSingleton()->menuInterface;
	}

	const TaskInterface* GetTaskInterface() noexcept
	{
		return Impl::API::GetSingleton()->taskInterface;
	}
}

namespace SFSE
{
	void Init(const LoadInterface* a_intfc, const bool a_log) noexcept
	{
		Init(a_intfc, { .log = a_log });
	}

	void AllocTrampoline(std::size_t a_size, bool) noexcept
	{
		auto api = Impl::API::GetSingleton();
		api->info.trampoline = true;
		api->info.trampolineSize = a_size;
		api->InitTrampoline();
	}
}
