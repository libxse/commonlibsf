#pragma once

#include "RE/B/BSStringT.h"

namespace RE
{
	class TESFile
	{
	public:
		SF_RTTI_VTABLE(TESFile);

		enum class Flags
		{
			kNone = 0,
			kMaster = 1 << 0,
			kEnabled = 1 << 2,
			kLocalized = 1 << 7,
			kSmall = 1 << 8,
			kUpdate = 1 << 9,
			kMedium = 1 << 10,
			kBlueprint = 1 << 11
		};

		struct TypedIndex
		{
			std::uint8_t  fullIndex;    // 00
			std::uint8_t  mediumIndex;  // 01
			std::uint16_t smallIndex;   // 02
		};
		static_assert(sizeof(TypedIndex) == 0x4);

		std::uint8_t                        pad0[0x38];       // 000
		char                                fileName[260];    // 038
		std::uint8_t                        pad13C[0x7B];     // 13C
		std::uint8_t                        compileIndex;     // 1B7
		REX::TEnumSet<Flags, std::uint32_t> fileFlags;        // 1B8
		std::uint8_t                        pad1BC[0x4];      // 1BC
		std::uint8_t                        pad1C0[0x58];     // 1C0
		TypedIndex                          fileIndex;        // 218
		BSString                            fileAuthor;       // 21C
		BSString                            fileDescription;  // 22C
	};
	static_assert(offsetof(TESFile, fileFlags) == 0x1B8);
	static_assert(offsetof(TESFile, fileIndex) == 0x218);
	static_assert(offsetof(TESFile, fileAuthor) == 0x21C);
	static_assert(offsetof(TESFile, fileDescription) == 0x22C);
}
