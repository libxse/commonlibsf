#pragma once

#include "RE/B/BSContainer.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BaseFormComponent.h"
#include "RE/I/IKeywordFormBase.h"

namespace RE
{
	class BGSFormFolderKeywordList;

	class BGSKeywordForm :
		public BaseFormComponent,  // 00
		public IKeywordFormBase    // 08
	{
	public:
		SF_RTTI_VTABLE(BGSKeywordForm);

		~BGSKeywordForm() override;  // 00

		// override (BaseFormComponent)
		const BSFixedString& GetFormComponentType() const override;  // 01 - { return "BGSKeywordForm_Component"; }
		void                 InitializeDataComponent() override;     // 02 - { return; }

		// add
		virtual BGSKeyword*         GetDefaultKeyword() const;  // 0B
		bool                        AddKeyword(BGSKeyword* keyword);
		[[nodiscard]] bool          ContainsKeywordString(std::string_view a_editorID);
		void                        ForEachKeyword(std::function<BSContainer::ForEachResult(BGSKeyword*)> a_callback);
		[[nodiscard]] std::uint32_t GetNumKeywords() const;
		[[nodiscard]] bool          HasKeyword(BGSKeyword* keyword) const;
		[[nodiscard]] bool          HasKeywordString(std::string_view a_editorID);
		bool                        RemoveKeyword(BGSKeyword* keyword);

		// members
		BSTArray<BGSFormFolderKeywordList*> formFolderKeywordLists;  // 10
		BSTArray<BGSKeyword*>               keywords;                // 20
	};
	static_assert(sizeof(BGSKeywordForm) == 0x30);
}
