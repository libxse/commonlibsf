#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	struct IMovementAnimationDrivenFeedback :
		public IMovementInterface  // 00
	{
	public:
		SF_RTTI(IMovementAnimationDrivenFeedback);
	};
	static_assert(sizeof(IMovementAnimationDrivenFeedback) == 0x8);
}
