#pragma once

#include "RE/B/BGSTypedFormValuePair.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTTuple3.h"
#include "RE/T/TESCondition.h"
#include "RE/T/TESDescription.h"
#include "RE/T/TESForm.h"
#include "RE/T/TESFullName.h"

namespace RE
{
	class BGSCurveForm;
	class BGSKeyword;

	class BGSCraftableForm :
		public TESForm,         // 00
		public TESDescription,  // 38
		public TESFullName      // 50
	{
	public:
		SF_RTTI_VTABLE(BGSCraftableForm);

		~BGSCraftableForm() override;  // 00

		// add
		virtual void Unk_62();  // 62

		// members
		BGSKeyword*                                                                     benchKeyword;   // 60 - CK WorkbenchKeyword
		TESCondition                                                                    conditions;     // 68
		BSTArray<BSTTuple3<TESForm*, BGSCurveForm*, BGSTypedFormValuePair::SharedVal>>* components;     // 78 - CK RequiredItemList
		BSTArray<BSTTuple3<TESForm*, BGSCurveForm*, BGSTypedFormValuePair::SharedVal>>* requiredPerks;  // 80
		TESForm*                                                                        createdObject;  // 88 - CK CreatedObject (arbitrary TESForm, not just TESBoundObject)
		std::uint8_t                                                                    unk90;          // 90 - heatmap: 2911/3091 populated, values ~1 (CreatedObjectCount candidate)
		float                                                                           menuSortOrder;  // 94 - CK MenuPriorityOrder
		std::uint8_t                                                                    unk98;          // 98 - heatmap: 12/3091 populated (rare flag byte)
	};
	static_assert(sizeof(BGSCraftableForm) == 0xA0);
	static_assert(offsetof(BGSCraftableForm, unk18) == 0x18);         // TESForm base @ +0x00
	static_assert(offsetof(BGSCraftableForm, fileOffset) == 0x40);    // TESDescription base @ +0x38
	static_assert(offsetof(BGSCraftableForm, fullName) == 0x58);      // TESFullName base @ +0x50
	static_assert(offsetof(BGSCraftableForm, benchKeyword) == 0x60);  // first derived member
}
