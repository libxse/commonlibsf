#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSInputEventSingleUser.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"
#include "RE/I/IDataModel.h"
#include "RE/U/UserEvents.h"

#include <array>
#include <cstddef>
#include <span>

namespace RE
{
	class SettingsPanel_RemapMode;
	class SettingsPanel_SaveControls;
	class SettingsPanel_SaveSettings;
	class SettingsPanel_SliderChanged;
	class SettingsPanel_StepperChanged;
	class SettingsPanel_CheckBoxChanged;
	class SettingsPanel_ResetToDefaults;
	class SettingsPanel_OpenSettings;
	class SettingsPanel_OpenCategory;
	class SettingsPanel_ClearBinding;
	class SettingsPanel_RemapConfirmed;
	class SettingsPanel_ValidateControls;
	class SettingsPanel_LinkClicked;

	class SettingsDataModel :
		public IDataModel,                                    // 000
		public BSInputEventSingleUser,                        // 010
		public BSTSingletonExplicit<SettingsDataModel>,       // 0C8
		public BSTEventSink<SettingsPanel_RemapMode>,         // 060
		public BSTEventSink<SettingsPanel_SaveControls>,      // 068
		public BSTEventSink<SettingsPanel_SaveSettings>,      // 070
		public BSTEventSink<SettingsPanel_SliderChanged>,     // 078
		public BSTEventSink<SettingsPanel_StepperChanged>,    // 080
		public BSTEventSink<SettingsPanel_CheckBoxChanged>,   // 088
		public BSTEventSink<SettingsPanel_ResetToDefaults>,   // 090
		public BSTEventSink<SettingsPanel_OpenSettings>,      // 098
		public BSTEventSink<SettingsPanel_OpenCategory>,      // 0A0
		public BSTEventSink<SettingsPanel_ClearBinding>,      // 0A8
		public BSTEventSink<SettingsPanel_RemapConfirmed>,    // 0B0
		public BSTEventSink<SettingsPanel_ValidateControls>,  // 0B8
		public BSTEventSink<SettingsPanel_LinkClicked>        // 0C0
	{
	public:
		SF_RTTI_VTABLE(SettingsDataModel);

		using InputContextID = UserEvents::INPUT_CONTEXT_ID;

		struct BindingDefinition
		{
			InputContextID context;          // 00
			std::byte      pad01[3];         // 01
			std::uint32_t  contextOrder;     // 04
			std::uint32_t  sortIndex;        // 08
			bool           required;         // 0C
			std::byte      pad0D[3];         // 0D
			BSFixedString  event;            // 10
			std::uint32_t  variantCount;     // 18
			std::uint32_t  variantCapacity;  // 1C
			const void*    variants;         // 20
		};
		static_assert(offsetof(BindingDefinition, event) == 0x10);
		static_assert(offsetof(BindingDefinition, variants) == 0x20);
		static_assert(sizeof(BindingDefinition) == 0x28);

		virtual ~SettingsDataModel();  // 00

		// Borrowed on the settings/UI thread; invalidated when bindings are rebuilt.
		[[nodiscard]] static std::span<const BindingDefinition> GetBindingDefinitions()
		{
			static REL::Relocation<const BSTArray<BindingDefinition>*> definitions{ ID::SettingsDataModel::BindingDefinitions };
			return { definitions->data(), definitions->size() };
		}

		[[nodiscard]] static SettingsDataModel* GetSingleton()
		{
			static REL::Relocation<SettingsDataModel**> singleton{ ID::SettingsDataModel::Singleton };
			return *singleton;
		}

		static void CancelRemap()
		{
			using func_t = decltype(&SettingsDataModel::CancelRemap);
			static REL::Relocation<func_t> func{ ID::SettingsDataModel::CancelRemap };
			func();
		}

		[[nodiscard]] static constexpr std::uint32_t GetControlsMenuOrder(InputContextID a_id) noexcept
		{
			for (std::uint32_t i = 0; i < CONTROLS_MENU_INPUT_CONTEXT_ORDER.size(); ++i) {
				if (CONTROLS_MENU_INPUT_CONTEXT_ORDER[i] == a_id) {
					return i;
				}
			}

			return static_cast<std::uint32_t>(CONTROLS_MENU_INPUT_CONTEXT_ORDER.size()) +
			       static_cast<std::uint8_t>(a_id);
		}

		[[nodiscard]] static constexpr InputContextID GetControlsMenuCategory(InputContextID a_id) noexcept
		{
			const auto id = static_cast<std::uint8_t>(a_id);
			if (id >= 0x06 && id <= 0x0A) {
				return InputContextID::kQuickContainer;
			}
			if (id >= 0x02 && id <= 0x05) {
				return InputContextID::kBasicMenuNav;
			}
			if (a_id == InputContextID::kShipHUD || a_id == InputContextID::kShipHUD_Cancel) {
				return InputContextID::kShipHUD;
			}
			if (a_id == InputContextID::kSpaceship_Interaction || a_id == InputContextID::kShipFlightCam_FreeRot) {
				return InputContextID::kSpaceship_Interaction;
			}
			return a_id;
		}

		inline static constexpr std::array CONTROLS_MENU_INPUT_CONTEXT_ORDER{
			InputContextID::kMainGameplay,
			InputContextID::kShipHUD,
			InputContextID::kShipHUD_Cancel,
			InputContextID::kShip_QuickContainer,
			InputContextID::kShipHUD_Targeting,
			InputContextID::kShipHUD_Alt,
			InputContextID::kSpaceship_Interaction,
			InputContextID::kShipFlightCam_FreeRot,
			InputContextID::kShipHUD_CruiseMode,
			InputContextID::kBasicMenuNav,
			InputContextID::kVirtualController,
			InputContextID::kMenu3DModelRotation,
			InputContextID::kMenu3DModelZoom,
			InputContextID::kQuickContainer,
			InputContextID::kMultiActivate_A,
			InputContextID::kMultiActivate_X,
			InputContextID::kMultiActivate_Y,
			InputContextID::kMultiActivate_B,
			InputContextID::kLeftThumbstick,
			InputContextID::kRightThumbstick,
			InputContextID::kCursor,
			InputContextID::kCursor_LeftStick,
			InputContextID::kBook,
			InputContextID::kDataSlateButtons,
			InputContextID::kWorkshop,
			InputContextID::kWorkshop_QuickMenu,
			InputContextID::kTerminal,
			InputContextID::kPhotoMode,
			InputContextID::kSecurity,
			InputContextID::kScope,
			InputContextID::kSitWait,
			InputContextID::kDataMenu,
			InputContextID::kDataMenu_Shortcuts,
			InputContextID::kShieldFocus,
			InputContextID::kZeroG,
			InputContextID::kStarMap,
			InputContextID::kStarMap_JumpWindow,
			InputContextID::kStarMap_SystemInspect,
			InputContextID::kSurfaceMap,
			InputContextID::kSpaceshipEditor,
			InputContextID::kShipBuilder_Empty,
			InputContextID::kShipBuilder_Add,
			InputContextID::kShipBuilder_Edit,
			InputContextID::kShipBuilder_Color,
			InputContextID::kShipBuilder_FlightCheck,
			InputContextID::kShipBuilder_ExitConfirm,
			InputContextID::kShipBuilder_Selection,
			InputContextID::kShipBuilder_Upgrade,
			InputContextID::kSpaceshipEditorSimplified,
			InputContextID::kShipBuilder_Add_Simple,
			InputContextID::kShipBuilder_Empty_Simple,
			InputContextID::kShipBuilder_Edit_Simple,
			InputContextID::kShipBuilder_Selection_Simple,
			InputContextID::kShipInfo,
			InputContextID::kShipInfo_BuySell,
			InputContextID::kShipInfo_Modify,
			InputContextID::kMonocle,
			InputContextID::kVehicle
		};
		static_assert(CONTROLS_MENU_INPUT_CONTEXT_ORDER.size() == 58);

		// members
		std::byte unk0C8[0x878];  // 0C8
	};
	static_assert(offsetof(SettingsDataModel, unk08) == 0x8);
	static_assert(offsetof(SettingsDataModel, currInputTimeCount) == 0x18);
	static_assert(offsetof(SettingsDataModel, inputEventHandlingEnabled) == 0x58);
	static_assert(offsetof(SettingsDataModel, unk0C8) == 0xC8);
	static_assert(sizeof(SettingsDataModel) == 0x940);
}
