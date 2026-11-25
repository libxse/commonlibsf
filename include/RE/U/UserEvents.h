#pragma once

namespace RE
{
	namespace UserEvents
	{
		enum class INPUT_CONTEXT_ID : std::uint8_t
		{
			kMainGameplay = 0x00,
			kConsoleOpening = 0x01,
			kBasicMenuNav = 0x02,
			kVirtualController = 0x03,
			kMenu3DModelRotation = 0x04,
			kMenu3DModelZoom = 0x05,
			kQuickContainer = 0x06,
			kMultiActivate_A = 0x07,
			kMultiActivate_X = 0x08,
			kMultiActivate_Y = 0x09,
			kMultiActivate_B = 0x0A,
			kLeftThumbstick = 0x0B,
			kRightThumbstick = 0x0C,
			kCursor = 0x0D,
			kCursor_LeftStick = 0x0E,
			kBook = 0x0F,
			kDataSlateButtons = 0x10,
			kConsole = 0x11,
			kDebugOverlay = 0x12,
			kTFC = 0x13,
			kDebug = 0x14,
			kDebugCamera = 0x15,
			kWorkshop = 0x16,
			kWorkshop_QuickMenu = 0x17,
			kTerminal = 0x18,
			kPhotoMode = 0x19,
			kSecurity = 0x1A,
			kScope = 0x1B,
			kSitWait = 0x1C,
			kDataMenu = 0x1D,
			kDataMenu_Shortcuts = 0x1E,
			kShieldFocus = 0x1F,
			kZeroG = 0x20,
			kShipHUD = 0x21,
			kShipHUD_Cancel = 0x22,
			kShip_QuickContainer = 0x23,
			kShipHUD_Targeting = 0x24,
			kShipHUD_Alt = 0x25,
			kSpaceship_Interaction = 0x26,
			kShipFlightCam_FreeRot = 0x27,
			kStarMap = 0x28,
			kStarMap_JumpWindow = 0x29,
			kStarMap_SystemInspect = 0x2A,
			kSurfaceMap = 0x2B,
			kSpaceshipEditor = 0x2C,
			kShipBuilder_Empty = 0x2D,
			kShipBuilder_Add = 0x2E,
			kShipBuilder_Edit = 0x2F,
			kShipBuilder_Color = 0x30,
			kShipBuilder_FlightCheck = 0x31,
			kShipBuilder_ExitConfirm = 0x32,
			kShipBuilder_Selection = 0x33,
			kShipBuilder_Upgrade = 0x34,
			kShipInfo = 0x35,
			kShipInfo_BuySell = 0x36,
			kShipInfo_Modify = 0x37,
			kMonocle = 0x38,
			kMonocleKBMZoom = 0x39,
			kLevelUp = 0x3A,
			kNewMission = 0x3B,
			kMovementOverride = 0x3C,
			kTextInput = 0x3D,
			kMissionFromStarMap = 0x3E,
			kSpaceshipEditorSimplified = 0x3F,
			kShipBuilder_Add_Simple = 0x40,
			kShipBuilder_Empty_Simple = 0x41,
			kShipBuilder_Edit_Simple = 0x42,
			kShipBuilder_Selection_Simple = 0x43,
			kShipHUD_Monocle = 0x44,
			kBasicMenuNav_JustCancel = 0x45,
			kStarMap_QuickSelect = 0x46,
			kCreations = 0x47,
			kLogin = 0x48,
			kVehicle = 0x49,
			kVehicle_Hangar = 0x4A,
			kAlmanac = 0x4B,
			kOpenAlmanac = 0x4C,
			kShipHUD_CruiseMode = 0x4D,
			kStopContextProcessing = 0x4E,
			kCount = 0x4F,
			kNone = 0x50
		};
	}

	enum class USER_EVENT_SENDER_ID : std::uint32_t
	{
		None = 0,
		Gameplay = 1,
		Menu = 2,
		Script = 3
	};

	enum class USER_EVENT_FLAG : std::uint32_t
	{
		Walking = (1 << 0),
		Looking = (1 << 1),
		Activation = (1 << 2),    //Unconfirmed
		TabMenuMaybe = (1 << 3),  //Unconfirmed
		Console = (1 << 4),       //Unconfirmed
		POVSwitch = (1 << 5),     //Unconfirmed
		Fighting = (1 << 6),
		Sneaking = (1 << 7),
		Menu = (1 << 8),
		WheelZoom = (1 << 9),  //Unconfirmed
		Jumping = (1 << 10),
		Movement = Walking | Jumping,
	};
	REX_DEFINE_ENUM_CLASS_FLAGS(USER_EVENT_FLAG);

	enum class OTHER_EVENT_FLAG : std::uint32_t
	{
		Journal = (1 << 0),
		Activate = (1 << 1),
		FastTravel = (1 << 2),
		CamSwitch = (1 << 3),
		VATS = (1 << 4),
		Favorites = (1 << 5),
		PipboyLight = (1 << 6),  //Unconfirmed
		ZKey = (1 << 7),
		Running = (1 << 8),
		Unk = (1 << 9),  //??
		Sprinting = (1 << 10),
		HandScanner = (1 << 11),
		Takeoff = (1 << 12),
		Inventory = (1 << 13),
		GravJump = (1 << 14),
		FarTravel = (1 << 15),
		LocationDiscovery = (1 << 16),
		Others = HandScanner | Takeoff | Inventory | GravJump | FarTravel,
	};
	REX_DEFINE_ENUM_CLASS_FLAGS(OTHER_EVENT_FLAG);
}
