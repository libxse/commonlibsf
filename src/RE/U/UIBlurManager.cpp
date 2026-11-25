#include "RE/U/UIBlurManager.h"
#include "RE/B/BlurEvent.h"

namespace RE
{
	namespace
	{
		using process_blur_event_t = BSEventNotifyControl (*)(
			BSTEventSink<BlurEvent>*,
			const BlurEvent&,
			BSTEventSource<BlurEvent>*);

		void SendBlurEvent(UIBlurManager* a_manager, const BlurEvent::Type a_type)
		{
			if (!a_manager) {
				return;
			}

			static REL::Relocation<process_blur_event_t> processEvent{ ID::UIBlurManager::ProcessBlurEvent };
			const BlurEvent                              event{ a_type };
			processEvent(static_cast<BSTEventSink<BlurEvent>*>(a_manager), event, BlurEvent::GetEventSource());
		}
	}

	void UIBlurManager::DecrementBlurCount()
	{
		SendBlurEvent(this, BlurEvent::Type::kDecrement);
	}

	void UIBlurManager::IncrementBlurCount()
	{
		SendBlurEvent(this, BlurEvent::Type::kIncrement);
	}
}
