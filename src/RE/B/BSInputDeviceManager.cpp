#include "RE/B/BSInputDeviceManager.h"

namespace RE
{
	BSInputDeviceManager* BSInputDeviceManager::GetSingleton()
	{
		static REL::Relocation<BSInputDeviceManager**> singleton{ ID::BSInputDeviceManager::Singleton };
		return *singleton;
	}
}
