#pragma once
#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTScatterTable.h"
#include "RE/I/IMenu.h"

namespace RE
{
	class IMenu;

	namespace Scaleform
	{
		template <class T>
		class Ptr;
	}

	struct BIUIMenuVisiblePausedBeginEvent;
	struct BIUIMenuVisiblePausedEndEvent;
	struct BSCursorRotationChange;
	struct BSCursorTypeChange;
	struct MenuModeChangeEvent;
	struct MenuOpenCloseEvent;
	struct MenuPauseChangeEvent;
	struct MenuPauseCounterChangeEvent;
	struct TutorialEvent;

	class UI :
		public BSTSingletonSDM<UI>,                              // 000
		public BSInputEventReceiver,                             // 010
		public BSTEventSource<MenuOpenCloseEvent>,               // 020
		public BSTEventSource<MenuModeChangeEvent>,              // 048
		public BSTEventSource<MenuPauseChangeEvent>,             // 070
		public BSTEventSource<MenuPauseCounterChangeEvent>,      // 098
		public BSTEventSource<TutorialEvent>,                    // 0C0
		public BSTEventSource<BSCursorTypeChange>,               // 0E8
		public BSTEventSource<BSCursorRotationChange>,           // 110
		public BSTEventSource<BIUIMenuVisiblePausedBeginEvent>,  // 138
		public BSTEventSource<BIUIMenuVisiblePausedEndEvent>     // 160
	{
	public:
		SF_RTTI_VTABLE(UI);

		struct UIMenuEntry
		{
			using Create_t = Scaleform::Ptr<IMenu>*(Scaleform::Ptr<IMenu>*);

			Scaleform::Ptr<IMenu> menu;             // 00
			Create_t*             initFunc;         // 08
			void*                 unk10 = nullptr;  // 10
			uint64_t              unk18 = 1;        // 18
			uint64_t              unk20 = 0;        // 20
		};
		static_assert(sizeof(UIMenuEntry) == 0x28);

		struct UIMenuNameHash
		{
			[[nodiscard]] std::uint32_t operator()(const BSFixedString& a_key) const noexcept
			{
				const auto chars = reinterpret_cast<std::uintptr_t>(a_key.c_str());
				return static_cast<std::uint32_t>(chars) ^ static_cast<std::uint32_t>(chars >> 32);
			}
		};

		using UIMenuMap = BSTHashMap<BSFixedString, UIMenuEntry, UIMenuNameHash>;
		static_assert(sizeof(UIMenuMap) == 0x38);

		template <class T>
		[[nodiscard]] auto GetEventSource()
		{
			return static_cast<BSTEventSource<T>*>(this);
		}

		inline static UI* GetSingleton()
		{
			static REL::Relocation<UI**> singleton{ ID::UI::Singleton };
			return *singleton;
		}

		[[nodiscard]] const UIMenuEntry* GetMenuEntry(const BSFixedString& a_menuName) const
		{
			const auto it = menuMap.find(a_menuName);
			return it != menuMap.end() ? std::addressof(it->value) : nullptr;
		}

		[[nodiscard]] Scaleform::Ptr<IMenu> GetMenu(const BSFixedString& a_menuName) const
		{
			const auto* entry = GetMenuEntry(a_menuName);
			return entry ? entry->menu : nullptr;
		}

		Scaleform::Ptr<Scaleform::GFx::Movie> GetMenuMovie(const BSFixedString& a_menuName) const
		{
			auto menu = GetMenu(a_menuName);
			return menu ? menu->uiMovie : nullptr;
		}

		bool IsMenuOpen(const BSFixedString& a_name) const
		{
			using func_t = decltype(&UI::IsMenuOpen);
			static REL::Relocation<func_t> func{ ID::UI::IsMenuOpen };
			return func(this, a_name);
		}

		[[nodiscard]] bool IsMenuRegistered(const BSFixedString& a_name) const
		{
			return menuMap.contains(a_name);
		}

		bool IsMenusVisible() const
		{
			return menusVisible;
		}

		void RegisterMenu(const char* a_name, UIMenuEntry::Create_t* a_create, bool a_flag = true)
		{
			using func_t = void (*)(UI*, const char*, bool, UIMenuEntry::Create_t*);
			static REL::Relocation<func_t> func{ ID::UI::RegisterMenu };
			func(this, a_name, a_flag, a_create);
		}

		template <class T>
		void RegisterSink(BSTEventSink<T>* a_sink)
		{
			GetEventSource<T>()->RegisterSink(a_sink);
		}

		template <class T>
		void UnregisterSink(BSTEventSink<T>* a_sink)
		{
			GetEventSource<T>()->UnregisterSink(a_sink);
		}

		std::uint8_t                    pad188[0x268];   // 188
		BSTArray<Scaleform::Ptr<IMenu>> menuStack;       // 3F0
		std::uint8_t                    pad400[0x18];    // 400
		uint64_t                        unk418;          // 418
		uint64_t                        unk420;          // 420
		uint64_t                        unk428;          // 428
		BSTArray<Scaleform::Ptr<IMenu>> menuArray;       // 430
		BSTArray<Scaleform::Ptr<IMenu>> menusToAdvance;  // 440
		std::uint64_t                   unk450[4];       // 450
		UIMenuMap                       menuMap;         // 470
		std::uint8_t                    pad4A8[0x38];    // 4A8
		std::uint64_t                   unk4E0;          // 4E0
		std::uint64_t                   unk4E8;          // 4E8
		float                           unk4F0;          // 4F0
		float                           advanceDelta;    // 4F4
		uint16_t                        unk4F8;          // 4F8
		bool                            menusVisible;    // 4FA
		std::uint8_t                    pad4FB[5];       // 4FB
		std::uint64_t                   unk500;          // 500
		std::uint64_t                   unk508;          // 508
		std::uint8_t                    pad510[0x28];    // 510
		std::uint8_t                    unk538;          // 538
		std::uint8_t                    pad539[7];       // 539
	};
	static_assert(offsetof(UI, menuStack) == 0x3F0);
	static_assert(offsetof(UI, menuArray) == 0x430);
	static_assert(offsetof(UI, menusToAdvance) == 0x440);
	static_assert(offsetof(UI, menuMap) == 0x470);
	static_assert(offsetof(UI, advanceDelta) == 0x4F4);
	static_assert(offsetof(UI, unk500) == 0x500);
	static_assert(offsetof(UI, unk538) == 0x538);
	static_assert(sizeof(BSTScatterTableEntry<BSFixedString, UI::UIMenuEntry>) == 0x38);
	static_assert(offsetof(UI, menusVisible) == 0x4FA);
	static_assert(sizeof(UI) == 0x540);
}
