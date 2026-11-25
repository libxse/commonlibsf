#pragma once

#include "RE/B/BSTSingleton.h"
#include "RE/T/TESImageSpace.h"

namespace RE
{
	class ILightEmittanceManager
	{
	public:
		SF_RTTI(ILightEmittanceManager);

		virtual ~ILightEmittanceManager() = default;  // 00
	};

	class IExternalEmittanceManager :
		public ILightEmittanceManager
	{
	public:
		SF_RTTI(IExternalEmittanceManager);
	};

	class __declspec(novtable) Sky :
		public BSTSingletonSDM<Sky>,      // 00
		public IExternalEmittanceManager  // 10
	{
	public:
		SF_RTTI_VTABLE(Sky);

		virtual ~Sky();  // 00

		// members
		std::byte                         pad1B[253];           // 1B
		BGSWeatherSettingsForm*           currentWeather;       // 118
		BGSWeatherSettingsForm*           lastWeather;          // 120
		std::byte                         pad128[32];           // 128
		void*                             unk148;               // 148
		std::byte                         pad150[304];          // 150
		TESImageSpace::ImageSpaceSettings imageSpaceSettings1;  // 280
		std::byte                         pad648[2172];         // 648
		float                             windSpeed;            // EC4
		std::byte                         padEC8[88];           // EC8
		uint32_t                          mode;                 // F20
		std::byte                         padF24[316];          // F24
		NiCamera*                         unk1060;              // 1060
		std::byte                         pad1068[32];          // 1068
		TESImageSpace::ImageSpaceSettings imageSpaceSettings2;  // 1088
	};
	static_assert(offsetof(Sky, windSpeed) == 0xEC4);
}
