#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSInputEventUser.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTSingleton.h"
#include "RE/U/UserEvents.h"

#include <array>
#include <span>
#include <string>
#include <string_view>

namespace RE
{
	class ControlMap :
		public BSTSingletonSDM<ControlMap>  // 000
	{
	public:
		SF_RTTI_VTABLE(ControlMap);

		using InputContextID = UserEvents::INPUT_CONTEXT_ID;

		enum class BindingSlot : std::uint8_t
		{
			kMain = 0,
			kAlternate = 1,
			kUnbound = 2
		};

		struct UserEventMapping
		{
			BSFixedString eventID;            // 00
			std::uint32_t keyCode;            // 08
			std::uint32_t modifierKeyCode;    // 0C
			BindingSlot   bindingSlot;        // 10
			std::uint8_t  unk11;              // 11
			std::uint16_t unk12;              // 12
			std::uint8_t  sortIndex;          // 14
			std::byte     pad15[3];           // 15
			std::uint32_t contextMask;        // 18
			std::uint8_t  metadata;           // 1C
			bool          visibleInControls;  // 1D
			bool          usesLinkedBinding;  // 1E
			std::uint8_t  unk1F;              // 1F
			bool          required;           // 20
			std::byte     pad21[7];           // 21
		};
		static_assert(offsetof(UserEventMapping, keyCode) == 0x08);
		static_assert(offsetof(UserEventMapping, bindingSlot) == 0x10);
		static_assert(offsetof(UserEventMapping, sortIndex) == 0x14);
		static_assert(offsetof(UserEventMapping, contextMask) == 0x18);
		static_assert(offsetof(UserEventMapping, visibleInControls) == 0x1D);
		static_assert(offsetof(UserEventMapping, required) == 0x20);
		static_assert(sizeof(UserEventMapping) == 0x28);

		// Partial layout.
		struct InputContext
		{
			std::array<BSTArray<UserEventMapping>, 3> deviceMappings;  // 00
		};
		static_assert(sizeof(InputContext) == 0x30);

		struct ActiveInputContext
		{
			InputContextID inputContextID;  // 00
			std::byte      pad01[0x0F];     // 01
		};
		static_assert(sizeof(ActiveInputContext) == 0x10);

		static constexpr std::size_t MAPPABLE_INPUT_CONTEXT_COUNT = 0x4E;
		static constexpr std::size_t INPUT_CONTEXT_NAME_COUNT = 0x51;

		// Formats a defaults row; keyboard codes are virtual-key codes.
		[[nodiscard]] static std::string FormatMappingRow(
			const char* a_event, const char* a_keyboard, const char* a_mouse, const char* a_gamepad,
			bool a_keyboardVisible, bool a_mouseVisible, bool a_gamepadVisible,
			std::uint32_t a_controlMask, std::uint32_t a_groupMask, bool a_required);

		[[nodiscard]] static std::string FormatMappingRow(
			const char* a_event, std::uint32_t a_keyboard, std::uint32_t a_mouse, std::uint32_t a_gamepad,
			bool a_keyboardVisible, bool a_mouseVisible, bool a_gamepadVisible,
			std::uint32_t a_controlMask, std::uint32_t a_groupMask, bool a_required);

		// Loading or parsing replaces mappings and invalidates borrowed views.
		void LoadMappings();

		// Parses complete defaults; saved overrides and link resolution are separate.
		void ParseMappings(const char* a_text);

		void ResolveLinkedMappings();

		[[nodiscard]] static ControlMap* GetSingleton()
		{
			static REL::Relocation<ControlMap**> singleton{ ID::ControlMap::Singleton };
			return *singleton;
		}

		[[nodiscard]] InputContext* GetInputContext(InputContextID a_id) noexcept
		{
			const auto index = static_cast<std::size_t>(a_id);
			return index < inputContexts.size() ? inputContexts[index] : nullptr;
		}

		[[nodiscard]] const InputContext* GetInputContext(InputContextID a_id) const noexcept
		{
			const auto index = static_cast<std::size_t>(a_id);
			return index < inputContexts.size() ? inputContexts[index] : nullptr;
		}

		// Borrowed on the game thread; invalidated by remapping.
		[[nodiscard]] std::span<const UserEventMapping> GetMappings(
			InputContextID a_id, InputEvent::DeviceType a_device) const noexcept
		{
			const auto  device = static_cast<std::size_t>(a_device);
			const auto* inputContext = GetInputContext(a_id);
			if (!inputContext || device >= inputContext->deviceMappings.size()) {
				return {};
			}

			const auto& mappings = inputContext->deviceMappings[device];
			return { mappings.data(), mappings.size() };
		}

		// Invalidated by context-stack changes.
		[[nodiscard]] std::span<const ActiveInputContext> GetActiveInputContexts() const noexcept
		{
			return { activeInputContexts.data(), activeInputContexts.size() };
		}

		[[nodiscard]] static std::string_view GetInputContextName(InputContextID a_id) noexcept
		{
			const auto index = static_cast<std::size_t>(a_id);
			if (index >= INPUT_CONTEXT_NAME_COUNT) {
				return {};
			}

			static REL::Relocation<const char* const*> names{ ID::ControlMap::InputContextNameTable };
			const auto*                                name = names.get()[index];
			return name ? std::string_view{ name } : std::string_view{};
		}

		// members
		std::array<InputContext*, MAPPABLE_INPUT_CONTEXT_COUNT> inputContexts;        // 010
		std::byte                                               pad280[0x28];         // 280
		BSTArray<ActiveInputContext>                            activeInputContexts;  // 2A8
		std::byte                                               pad2B8[0xE8];         // 2B8
	};
	static_assert(offsetof(ControlMap, inputContexts) == 0x10);
	static_assert(offsetof(ControlMap, activeInputContexts) == 0x2A8);
	static_assert(sizeof(ControlMap) == 0x3A0);
}
