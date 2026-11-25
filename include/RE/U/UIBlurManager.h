#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	struct BlurEvent;

	class TESImageSpaceModifier;
	class UIBlurManager;

	struct DefaultObjectsReadyEvent
	{
	public:
		struct Event
		{
		public:
		};
	};

	class UIBlurManager :
		public BSTSingletonSDM<UIBlurManager>,                 // 00
		public BSTEventSink<DefaultObjectsReadyEvent::Event>,  // 10
		public BSTEventSink<BlurEvent>                         // 18
	{
	public:
		SF_RTTI_VTABLE(UIBlurManager);

		~UIBlurManager() override;  // 00

		[[nodiscard]] static UIBlurManager* GetSingleton()
		{
			static REL::Relocation<UIBlurManager*> singleton{ ID::UIBlurManager::Singleton };
			return singleton.get();
		}

		void DecrementBlurCount();
		void IncrementBlurCount();

		BSEventNotifyControl ProcessEvent(
			const DefaultObjectsReadyEvent::Event&           a_event,
			BSTEventSource<DefaultObjectsReadyEvent::Event>* a_source) override;

		BSEventNotifyControl ProcessEvent(
			const BlurEvent&           a_event,
			BSTEventSource<BlurEvent>* a_source) override;

		// members
		TESImageSpaceModifier* blurEffect;  // 020
		std::uint32_t          blurCount;   // 028
		std::uint32_t          pad02C;      // 02C
	};
	static_assert(offsetof(UIBlurManager, blurEffect) == 0x20);
	static_assert(offsetof(UIBlurManager, blurCount) == 0x28);
	static_assert(sizeof(UIBlurManager) == 0x30);
}
