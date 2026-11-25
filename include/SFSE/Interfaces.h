#pragma once

namespace RE
{
	class IMenu;
}

namespace SFSE
{
	using PluginHandle = std::uint32_t;

	struct PluginInfo
	{
		enum Version : std::uint32_t
		{
			kVersion = 1
		};

		std::uint32_t infoVersion;
		const char*   name;
		std::uint32_t version;
	};

	namespace Impl
	{
		struct SFSEInterface
		{
			std::uint32_t sfseVersion;
			std::uint32_t runtimeVersion;
			std::uint32_t interfaceVersion;
			void* (*QueryInterface)(std::uint32_t);
			PluginHandle (*GetPluginHandle)();
			const void* (*GetPluginInfo)(const char*);
		};

		struct SFSEMessagingInterface
		{
			std::uint32_t interfaceVersion;
			bool (*RegisterListener)(PluginHandle, const char*, void*);
			bool (*Dispatch)(PluginHandle, std::uint32_t, void*, std::uint32_t, const char*);
		};

		struct SFSETrampolineInterface
		{
			std::uint32_t interfaceVersion;
			void* (*AllocateFromBranchPool)(PluginHandle, std::size_t);
			void* (*AllocateFromLocalPool)(PluginHandle, std::size_t);
		};

		struct SFSEMenuInterface
		{
			std::uint32_t interfaceVersion;
			void (*Register)(void*);
		};

		struct SFSETaskInterface
		{
			std::uint32_t interfaceVersion;
			void (*AddTask)(void*);
			void (*AddPermanentTask)(void*);
		};
	}

	class QueryInterface
	{
	protected:
		[[nodiscard]] decltype(auto) GetProxy() const noexcept
		{
			return reinterpret_cast<const Impl::SFSEInterface&>(*this);
		}

	private:
		[[nodiscard]] constexpr static REL::Version MakeVersion(std::uint32_t a_version) noexcept
		{
			return {
				static_cast<std::uint16_t>((a_version >> 8 * 3) & 0x0FF),
				static_cast<std::uint16_t>((a_version >> 8 * 2) & 0x0FF),
				static_cast<std::uint16_t>((a_version >> 8 / 2) & 0xFFF),
				static_cast<std::uint16_t>((a_version >> 8 * 0) & 0x00F)
			};
		}

	public:
		[[nodiscard]] std::uint32_t SFSEVersion() const noexcept { return GetProxy().sfseVersion; }
		[[nodiscard]] PluginHandle  GetPluginHandle() const { return GetProxy().GetPluginHandle(); }
		const PluginInfo*           GetPluginInfo(const char* a_name) const { return static_cast<const PluginInfo*>(GetProxy().GetPluginInfo(a_name)); }
		[[nodiscard]] REL::Version  RuntimeVersion() const noexcept { return MakeVersion(GetProxy().runtimeVersion); }
	};

	class PreLoadInterface :
		public QueryInterface
	{
	public:
		enum InterfaceType : std::uint32_t
		{
			kInvalid = 0,
			kTrampoline = 2
		};

		[[nodiscard]] void* QueryInterface(std::uint32_t a_id) const { return GetProxy().QueryInterface(a_id); }

		template <class T>
		T* QueryInterface(std::uint32_t a_id) const noexcept
		{
			auto result = static_cast<T*>(QueryInterface(a_id));
			if (result && result->Version() > T::kVersion)
				REX::ERROR("interface definition is out of date");

			return result;
		}
	};

	class LoadInterface :
		public QueryInterface
	{
	public:
		enum InterfaceType : std::uint32_t
		{
			kInvalid = 0,
			kMessaging,
			kTrampoline,
			kMenu,
			kTask,

			kTotal
		};

		[[nodiscard]] void* QueryInterface(std::uint32_t a_id) const { return GetProxy().QueryInterface(a_id); }

		template <class T>
		T* QueryInterface(std::uint32_t a_id) const noexcept
		{
			auto result = static_cast<T*>(QueryInterface(a_id));
			if (result && result->Version() > T::kVersion)
				REX::ERROR("interface definition is out of date");

			return result;
		}
	};

	class MessagingInterface
	{
	private:
		[[nodiscard]] decltype(auto) GetProxy() const noexcept
		{
			return reinterpret_cast<const Impl::SFSEMessagingInterface&>(*this);
		}

	public:
		enum Version : std::uint32_t
		{
			kVersion = 1
		};

		enum MessageType : std::uint32_t
		{
			kPostLoad,
			kPostPostLoad,
			kPostDataLoad,
			kPostPostDataLoad,
		};

		struct Message
		{
			const char*   sender;
			std::uint32_t type;
			std::uint32_t dataLen;
			void*         data;
		};

		using EventCallback = std::add_pointer_t<void(Message* a_msg)>;

		[[nodiscard]] std::uint32_t Version() const noexcept { return GetProxy().interfaceVersion; }
		bool                        Dispatch(std::uint32_t a_messageType, void* a_data, std::uint32_t a_dataLen, const char* a_receiver) const;
		bool                        RegisterListener(EventCallback a_callback) const { return RegisterListener("SFSE", a_callback); }
		bool                        RegisterListener(const char* a_sender, EventCallback a_callback) const;
	};

	class TrampolineInterface
	{
	private:
		[[nodiscard]] decltype(auto) GetProxy() const noexcept
		{
			return reinterpret_cast<const Impl::SFSETrampolineInterface&>(*this);
		}

	public:
		enum Version : std::uint32_t
		{
			kVersion = 1
		};

		[[nodiscard]] std::uint32_t Version() const noexcept { return GetProxy().interfaceVersion; }
		[[nodiscard]] void*         AllocateFromBranchPool(std::size_t a_size) const;
		[[nodiscard]] void*         AllocateFromLocalPool(std::size_t a_size) const;
	};

	class MenuInterface
	{
	private:
		[[nodiscard]] decltype(auto) GetProxy() const noexcept
		{
			return reinterpret_cast<const Impl::SFSEMenuInterface&>(*this);
		}

	public:
		enum Version : std::uint32_t
		{
			kVersion = 2
		};

		using RegCallback = void(RE::IMenu* a_menu);

		[[nodiscard]] std::uint32_t Version() const noexcept { return GetProxy().interfaceVersion; }
		void                        Register(RegCallback* a_callback) const;
	};

	class ITaskDelegate
	{
	public:
		virtual void Run() = 0;
		virtual void Destroy() = 0;
	};

	class TaskInterface
	{
	private:
		[[nodiscard]] decltype(auto) GetProxy() const noexcept
		{
			return reinterpret_cast<const Impl::SFSETaskInterface&>(*this);
		}

	public:
		enum Version : std::uint32_t
		{
			kVersion = 1
		};

		[[nodiscard]] std::uint32_t Version() const noexcept { return GetProxy().interfaceVersion; }

		void AddTask(ITaskDelegate* a_task) const { GetProxy().AddTask(a_task); }
		void AddTask(std::function<void()> a_task) const { GetProxy().AddTask(new Task(std::move(a_task))); }
		void AddPermanentTask(ITaskDelegate* a_task) const { GetProxy().AddPermanentTask(a_task); }
		void AddPermanentTask(std::function<void()> a_task) const { GetProxy().AddPermanentTask(new Task(std::move(a_task))); }

	private:
		class Task :
			public ITaskDelegate
		{
		public:
			explicit Task(std::function<void()>&& a_task) noexcept :
				_impl(std::move(a_task))
			{}

			void Run() override { _impl(); }
			void Destroy() override { delete this; }

		private:
			std::function<void()> _impl;
		};
	};

	struct PluginVersionData
	{
	public:
		enum Version : std::uint32_t
		{
			kVersion = 1
		};

		enum
		{
			kAddressIndependence_Signatures = 1 << 0,
			kAddressIndependence_AddressLibrary = 1 << 1,
			kAddressIndependence_AddressLibraryV2 = 1 << 2,
		};

		enum
		{
			kStructureIndependence_NoStructs = 1 << 0,
			kStructureIndependence_InitialLayout = 1 << 1,
			kStructureIndependence_1_8_86_Layout = 1 << 2,
			kStructureIndependence_1_14_70_Layout = 1 << 3,
		};

		constexpr void PluginVersion(const REL::Version a_version) noexcept { pluginVersion = a_version.pack(); }

		[[nodiscard]] constexpr REL::Version GetPluginVersion() const noexcept { return REL::Version::unpack(pluginVersion); }

		constexpr void PluginName(const std::string_view a_plugin) noexcept { SetCharBuffer(a_plugin, std::span{ pluginName }); }

		[[nodiscard]] constexpr std::string_view GetPluginName() const noexcept { return std::string_view{ pluginName }; }

		constexpr void AuthorName(const std::string_view a_name) noexcept { SetCharBuffer(a_name, std::span{ author }); }

		[[nodiscard]] constexpr std::string_view GetAuthorName() const noexcept { return std::string_view{ author }; }

		constexpr void UsesSigScanning(const bool a_value) noexcept { SetOrClearBit(addressIndependence, kAddressIndependence_Signatures, a_value); }

		constexpr void UsesAddressLibrary(const bool a_value) noexcept { SetOrClearBit(addressIndependence, kAddressIndependence_AddressLibraryV2, a_value); }

		constexpr void HasNoStructUse(const bool a_value) noexcept { SetOrClearBit(structureCompatibility, kStructureIndependence_NoStructs, a_value); }

		constexpr void IsLayoutDependent(const bool a_value) noexcept { SetOrClearBit(structureCompatibility, kStructureIndependence_1_14_70_Layout, a_value); }

		constexpr void CompatibleVersions(std::initializer_list<REL::Version> a_versions) noexcept
		{
			// must be zero-terminated
			assert(a_versions.size() < std::size(compatibleVersions) - 1);
			std::ranges::transform(a_versions, std::begin(compatibleVersions), [](const REL::Version& a_version) noexcept {
				return a_version.pack();
			});
		}

		constexpr void MinimumRequiredXSEVersion(const REL::Version a_version) noexcept { xseMinimum = a_version.pack(); }

		[[nodiscard]] static const PluginVersionData* GetSingleton() noexcept;

		const std::uint32_t dataVersion{ kVersion };
		std::uint32_t       pluginVersion = 0;
		char                pluginName[256] = {};
		char                author[256] = {};
		std::uint32_t       addressIndependence;
		std::uint32_t       structureCompatibility;
		std::uint32_t       compatibleVersions[16] = {};
		std::uint32_t       xseMinimum = 0;
		const std::uint32_t reservedNonBreaking = 0;
		const std::uint32_t reservedBreaking = 0;

	private:
		static constexpr void SetCharBuffer(std::string_view a_src, std::span<char> a_dst) noexcept
		{
			assert(a_src.size() < a_dst.size());
			std::ranges::fill(a_dst, '\0');
			std::ranges::copy(a_src, a_dst.begin());
		}

		static constexpr void SetOrClearBit(std::uint32_t& a_data, const std::uint32_t a_bit, const bool a_set) noexcept
		{
			if (a_set)
				a_data |= a_bit;
			else
				a_data &= ~a_bit;
		}
	};

	static_assert(offsetof(PluginVersionData, dataVersion) == 0x000);
	static_assert(offsetof(PluginVersionData, pluginVersion) == 0x004);
	static_assert(offsetof(PluginVersionData, pluginName) == 0x008);
	static_assert(offsetof(PluginVersionData, author) == 0x108);
	static_assert(offsetof(PluginVersionData, addressIndependence) == 0x208);
	static_assert(offsetof(PluginVersionData, structureCompatibility) == 0x20C);
	static_assert(offsetof(PluginVersionData, compatibleVersions) == 0x210);
	static_assert(offsetof(PluginVersionData, xseMinimum) == 0x250);
	static_assert(offsetof(PluginVersionData, reservedNonBreaking) == 0x254);
	static_assert(offsetof(PluginVersionData, reservedBreaking) == 0x258);
	static_assert(sizeof(PluginVersionData) == 0x25C);
}

#define SFSE_EXPORT extern "C" [[maybe_unused]] __declspec(dllexport)
#define SFSE_PLUGIN_PRELOAD(...) SFSE_EXPORT bool SFSEPlugin_Preload(__VA_ARGS__)
#define SFSE_PLUGIN_LOAD(...) SFSE_EXPORT bool SFSEPlugin_Load(__VA_ARGS__)
#define SFSE_PLUGIN_VERSION SFSE_EXPORT constinit SFSE::PluginVersionData SFSEPlugin_Version
