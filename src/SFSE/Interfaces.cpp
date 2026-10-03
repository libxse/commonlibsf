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

	void SerializationInterface::SetUniqueID(const std::uint32_t a_uid) const
	{
		GetProxy().SetUniqueID(GetPluginHandle(), a_uid);
	}

	void SerializationInterface::SetRevertCallback(const EventCallback a_callback) const
	{
		GetProxy().SetRevertCallback(GetPluginHandle(), std::bit_cast<void*>(a_callback));
	}

	void SerializationInterface::SetSaveCallback(const EventCallback a_callback) const
	{
		GetProxy().SetSaveCallback(GetPluginHandle(), std::bit_cast<void*>(a_callback));
	}

	void SerializationInterface::SetLoadCallback(const EventCallback a_callback) const
	{
		GetProxy().SetLoadCallback(GetPluginHandle(), std::bit_cast<void*>(a_callback));
	}

	void SerializationInterface::SetFormDeleteCallback(const FormDeleteCallback a_callback) const
	{
		GetProxy().SetFormDeleteCallback(GetPluginHandle(), std::bit_cast<void*>(a_callback));
	}

	bool SerializationInterface::WriteRecord(const std::uint32_t a_type, const std::uint32_t a_version, const void* a_buf, const std::uint32_t a_length) const
	{
		return GetProxy().WriteRecord(a_type, a_version, a_buf, a_length);
	}

	bool SerializationInterface::OpenRecord(const std::uint32_t a_type, const std::uint32_t a_version) const
	{
		return GetProxy().OpenRecord(a_type, a_version);
	}

	bool SerializationInterface::WriteRecordData(const void* a_buf, const std::uint32_t a_length) const
	{
		return GetProxy().WriteRecordData(a_buf, a_length);
	}

	bool SerializationInterface::GetNextRecordInfo(std::uint32_t& a_type, std::uint32_t& a_version, std::uint32_t& a_length) const
	{
		return GetProxy().GetNextRecordInfo(std::addressof(a_type), std::addressof(a_version), std::addressof(a_length));
	}

	std::uint32_t SerializationInterface::ReadRecordData(void* a_buf, const std::uint32_t a_length) const
	{
		return GetProxy().ReadRecordData(a_buf, a_length);
	}

	const PluginVersionData* PluginVersionData::GetSingleton() noexcept
	{
		return reinterpret_cast<const PluginVersionData*>(REX::W32::GetProcAddress(REX::W32::GetCurrentModule(), "SFSEPlugin_Version"));
	}
}
