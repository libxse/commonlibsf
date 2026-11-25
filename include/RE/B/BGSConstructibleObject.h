#pragma once

#include "RE/B/BGSCraftableForm.h"
#include "RE/B/BGSCraftingUseSound.h"
#include "RE/B/BGSPickupPutdownSounds.h"
#include "RE/B/BGSTypedKeywordValueArray.h"
#include "RE/B/BSTList.h"
#include "RE/T/TESValueForm.h"

namespace RE
{
	class TESBoundObject;
	class TESGlobal;

	class BGSConstructibleObject :
		public BGSCraftableForm,        // 000
		public BGSPickupPutdownSounds,  // 0A0
		public TESValueForm,            // 108
		public BGSCraftingUseSound      // 118
	{
	public:
		SF_RTTI_VTABLE(BGSConstructibleObject);
		SF_FORMTYPE(COBJ);

		enum class LEARN_METHOD
		{
			kPickupOrScript,
			kScrapping,
			kIngestion,
			kDefaultOrConditionsMet,
			kPlan
		};

		~BGSConstructibleObject() override;  // 00

		// members
		BGSTypedKeywordValueArray<KeywordType::kRecipeFilter>                           recipeFilters;          // 150 - CK RecipeFilters (prev. "category")
		TESBoundObject*                                                                 learnedFrom;            // 168 - CK LearnedFrom (any TESBoundObject)
		BGSCurveForm*                                                                   baseReturnScaleTable;   // 170 - CK BaseReturnScaleTable
		TESGlobal*                                                                      maxBuildCount;          // 178 - CK MaxBuildCount
		BSTArray<BSTTuple3<TESForm*, BGSCurveForm*, BGSTypedFormValuePair::SharedVal>>* workbenchRepairRecipe;  // 180 - CK WorkbenchRepairRecipe
		REX::TEnum<LEARN_METHOD, std::uint8_t>                                          learnMethod;            // 188 - CK LearnMethod enum
		TESGlobal*                                                                      unk190;                 // 190 - TESGlobal???
		BGSKeyword*                                                                     unk198;                 // 198 - BGSKeyword???
		std::uint32_t                                                                   flags;                  // 1A0 - CK flag bitfield incl. ExcludeFromWorkshopLOD (bit layout TBD) (???)
	};
	static_assert(sizeof(BGSConstructibleObject) == 0x1A8);
	static_assert(offsetof(BGSConstructibleObject, pickupSound) == 0xA8);        // BGSPickupPutdownSounds base @ +0x0A0
	static_assert(offsetof(BGSConstructibleObject, value) == 0x110);             // TESValueForm base @ +0x108
	static_assert(offsetof(BGSConstructibleObject, craftingUseSound) == 0x120);  // BGSCraftingUseSound base @ +0x118
	static_assert(offsetof(BGSConstructibleObject, recipeFilters) == 0x150);     // first derived member
}
