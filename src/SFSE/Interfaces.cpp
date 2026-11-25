#include "SFSE/Interfaces.h"

#include "SFSE/API.h"
#include "SFSE/Logger.h"

namespace SFSE
{
	bool MessagingInterface::Dispatch(const std::uint32_t a_messageType, void* a_data, const std::uint32_t a_dataLen, const char* a_receiver) const
	{
		const auto result = GetProxy().Dispatch(GetPluginHandle(), a_messageType, a_data, a_dataLen, a_receiver);
		if (!result) {
			REX::ERROR("Failed to dispatch message to {}", (a_receiver ? a_receiver : "all listeners"));
		}

		return result;
	}

	bool MessagingInterface::RegisterListener(const char* a_sender, const EventCallback a_callback) const
	{
		const auto result = GetProxy().RegisterListener(GetPluginHandle(), a_sender, std::bit_cast<void*>(a_callback));
		if (!result) {
			REX::ERROR("Failed to register messaging listener for {}", a_sender);
		}
		return result;
	}

	void* TrampolineInterface::AllocateFromBranchPool(const std::size_t a_size) const
	{
		return GetProxy().AllocateFromBranchPool(GetPluginHandle(), a_size);
	}

	void* TrampolineInterface::AllocateFromLocalPool(const std::size_t a_size) const
	{
		return GetProxy().AllocateFromLocalPool(GetPluginHandle(), a_size);
	}

	void MenuInterface::Register(RegCallback* a_callback) const
	{
		return GetProxy().Register(reinterpret_cast<void*>(a_callback));
	}

	const PluginVersionData* PluginVersionData::GetSingleton() noexcept
	{
		return reinterpret_cast<const PluginVersionData*>(REX::W32::GetProcAddress(REX::W32::GetCurrentModule(), "SFSEPlugin_Version"));
	}
}
