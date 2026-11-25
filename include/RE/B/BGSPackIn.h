#pragma once

#include "RE/B/BGSForcedLocRefType.h"
#include "RE/B/BGSKeywordForm.h"
#include "RE/B/BGSNativeTerminalForm.h"
#include "RE/B/BGSPreviewTransform.h"
#include "RE/B/BGSPropertySheet.h"
#include "RE/B/BSStringT.h"
#include "RE/T/TESBoundObject.h"

namespace RE
{
	class BGSLayeredMaterialSwap;
	class TESObjectCELL;

	class BGSPackIn :
		public TESBoundObject,        // 000
		public BGSKeywordForm,        // 0E8
		public BGSPropertySheet,      // 118
		public BGSPreviewTransform,   // 128
		public BGSForcedLocRefType,   // 170
		public BGSNativeTerminalForm  // 188
	{
	public:
		SF_RTTI_VTABLE(BGSPackIn);
		SF_FORMTYPE(PKIN);

		~BGSPackIn() override;  // 00

		// members
		TESObjectCELL*                    cell;           // 198
		std::uint32_t                     flags;          // 1A0
		BSString                          filter;         // 1A4
		BSTArray<BGSLayeredMaterialSwap*> materialSwaps;  // 1B8
		std::uint32_t                     unk1C0;         // 1C8
	};
	static_assert(offsetof(BGSPackIn, filter) == 0x1A4);
	static_assert(sizeof(BGSPackIn) == 0x1D0);
}
