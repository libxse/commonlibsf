#pragma once

#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSInputEventUser.h"

namespace RE
{
	class BSInputEventSingleUser :
		public BSInputEventReceiver,  // 00
		public BSInputEventUser       // 10
	{
	public:
		SF_RTTI_VTABLE(BSInputEventSingleUser);

		virtual ~BSInputEventSingleUser() = default;  // 00

		// override (BSInputEventReceiver)
		virtual void PerformInputProcessing(const InputEvent* a_queueHead) override;  // 01
	};
	static_assert(sizeof(BSInputEventSingleUser) == 0x50);
}
