#include "RE/M/Misc.h"

#include "RE/B/BSStringT.h"

namespace RE
{
	class IMessageBoxCallback;
	class MessageMenuManager;

	namespace
	{
		struct MessageBoxParams
		{
			MessageBoxParams() = default;
			MessageBoxParams(const MessageBoxParams&) = delete;
			MessageBoxParams& operator=(const MessageBoxParams&) = delete;

			IMessageBoxCallback* callback{};           // 00
			BSString             header;               // 08
			BSString             body;                 // 18
			BSString             unk28;                // 28
			std::uint32_t        warningContext{ 5 };  // 38: script
		};
		static_assert(sizeof(MessageBoxParams) == 0x40);
		static_assert(offsetof(MessageBoxParams, callback) == 0x00);
		static_assert(offsetof(MessageBoxParams, header) == 0x08);
		static_assert(offsetof(MessageBoxParams, body) == 0x18);
		static_assert(offsetof(MessageBoxParams, unk28) == 0x28);
		static_assert(offsetof(MessageBoxParams, warningContext) == 0x38);
	}

	void DebugMessageBox(const char* a_message, const char* a_header)
	{
		static REL::Relocation<MessageMenuManager**> singleton{ ID::MessageMenuManager::Singleton };
		auto                                         manager = *singleton;
		if (!manager) {
			return;
		}

		MessageBoxParams params;
		params.header.Assign(a_header ? a_header : "DEBUG");
		params.body.Assign(a_message);

		// This overload supplies the localized OK button and moves the owned
		// strings into its request. BSString cleans up any buffers not moved out;
		// this helper never supplies a callback.
		using create_t = void (*)(MessageMenuManager*, MessageBoxParams*, bool);
		static REL::Relocation<create_t> create{ ID::MessageMenuManager::CreateMessageBox };
		create(manager, &params, false);
	}
}
