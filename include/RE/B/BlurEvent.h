#pragma once

#include "RE/B/BSTEvent.h"

namespace RE
{
	struct BlurEvent
	{
	public:
		enum class Type : std::uint32_t
		{
			kIncrement = 0,
			kDecrement = 1
		};

		[[nodiscard]] static BSTEventSource<BlurEvent>* GetEventSource()
		{
			static REL::Relocation<BSTEventSource<BlurEvent>*> source{ ID::BlurEvent::GetEventSource };
			return source.get();
		}

		Type type;  // 00
	};
	static_assert(sizeof(BlurEvent) == 0x4);
}