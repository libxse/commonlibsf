#pragma once

#include "RE/B/BSInputEventSingleUser.h"
#include "RE/B/BSKeyboardDevice.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class BSInputDeviceManager :
		public BSTSingletonSDM<BSInputDeviceManager>,  // 00
		public BSInputEventSingleUser                  // 10
	{
	public:
		SF_RTTI_VTABLE(BSInputDeviceManager);

		~BSInputDeviceManager() override = default;

		[[nodiscard]] static BSInputDeviceManager* GetSingleton();

		[[nodiscard]] BSKeyboardDevice* GetKeyboard() const
		{
			return static_cast<BSKeyboardDevice*>(devices[0]);
		}

		// members
		std::uint64_t  unk60;        // 60
		BSInputDevice* devices[5];   // 68
		std::uint8_t   unk90[0x48];  // 90
	};
	static_assert(offsetof(BSInputDeviceManager, devices) == 0x68);
	static_assert(sizeof(BSInputDeviceManager) == 0xD8);
}
