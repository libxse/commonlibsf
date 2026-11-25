#pragma once

#include "RE/B/BGSKeyword.h"
#include "RE/B/BSTHeapSTLVector.h"

namespace RE
{
	enum class KeywordType
	{
		kNone,
		kComponentTechLevel,
		kAttachPoint,
		kComponentProperty,
		kInstantiationFilter,
		kModAssociation,
		kSound,
		kAnimArchetype,
		kFunctionCall,
		kRecipeFilter,
		kAttractionType,
		kDialogueSubtype,
		kQuestTarget,
		kAnimFlavor,
		kAnimGender,
		kAnimFaceArchetype,
		kQuestGroup,
		kAnimInjured,
		kDispelEffect,

		kTotal
	};

	template <KeywordType TYPE>
	class BGSTypedKeywordValue
	{
	public:
		std::uint16_t keywordIndex;  // 0
		std::uint16_t pad02;         // 2
		std::uint32_t pad04;         // 4
	};
	static_assert(sizeof(BGSTypedKeywordValue<KeywordType::kNone>) == 0x8);

	// By the time plugins touch these at runtime (post-data-loaded ARMO and WEAP
	// attachParents, form keyword lists, etc.) the backing storage is a contiguous
	// BGSKeyword* buffer managed by the game's BSTHeapSTLAllocator — the same
	// begin / end / capacityEnd triplet modeled by BSTHeapSTLVector. During
	// preload/finalize of some keyword types (notably kAttachPoint) the field may
	// briefly hold BSComponentDB2 index records instead of BGSKeyword pointers;
	// do not mutate through this view during that window.
	template <KeywordType TYPE>
	class BGSTypedKeywordValueArray : public BSTHeapSTLVector<BGSKeyword*>
	{
	public:
		// Membership test uses formID equality (not pointer equality) so that
		// callers holding a BGSKeyword* from any lookup path — including forms
		// rebuilt across load cycles — see the same answer as AddKeyword and
		// RemoveKeyword, which also compare by formID.
		[[nodiscard]] bool HasKeyword(BGSKeyword* a_keyword)
		{
			if (!a_keyword) {
				return false;
			}
			for (auto* kw : *this) {
				if (kw && kw->formID == a_keyword->formID) {
					return true;
				}
			}
			return false;
		}

		// Typed-keyword arrays appear to keep capacity tightly matched to live
		// size after engine-driven adds. Reserve exactly size() + 1 here before
		// appending so the generic vector stays vector-like, while this wrapper preserves the
		// tighter capacityEnd post-condition that callers may observe on these fields.
		[[nodiscard]] bool AddKeyword(BGSKeyword* a_keyword)
		{
			if (!a_keyword) {
				return false;
			}
			for (auto* kw : *this) {
				if (kw && kw->formID == a_keyword->formID) {
					return false;
				}
			}
			this->reserve_exact(this->size() + 1);
			this->push_back(a_keyword);
			return true;
		}

		[[nodiscard]] bool RemoveKeyword(BGSKeyword* a_keyword)
		{
			if (!a_keyword) {
				return false;
			}
			for (size_type i = 0; i < size(); ++i) {
				auto* kw = (*this)[i];
				if (kw && kw->formID == a_keyword->formID) {
					erase(i);
					return true;
				}
			}
			return false;
		}
	};
	static_assert(sizeof(BGSTypedKeywordValueArray<KeywordType::kNone>) == 0x18);
}
