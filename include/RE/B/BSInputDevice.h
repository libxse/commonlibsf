#pragma once

#include "RE/B/BSFixedString.h"

namespace RE
{
	class BSInputDevice
	{
	public:
		SF_RTTI_VTABLE(BSInputDevice);

		virtual ~BSInputDevice();  // 00

		// add
		virtual void          Initialize() = 0;                                                                 // 01
		virtual void          Poll(float a_pollDelta) = 0;                                                      // 02
		virtual void          Shutdown() = 0;                                                                   // 03
		virtual bool          GetKeyNameFromCode(std::uint32_t a_keyCode, BSFixedStringCS& a_name) const;       // 04
		virtual std::uint32_t GetKeyCodeFromName(const char* a_name) const;                                     // 05
		virtual bool          GetMappedKeyCode(std::uint32_t a_keyCode, std::uint32_t& a_mappedKeyCode) const;  // 06
		virtual bool          IsEnabled() const { return true; }                                                // 07
		virtual void          ClearInputState() = 0;                                                            // 08

		// members
		std::uint8_t unk08[0x78];  // 08
	};
	static_assert(sizeof(BSInputDevice) == 0x80);
}
