#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	struct IMovementPlannerDirectControl :
		public IMovementInterface  // 00
	{
	public:
		SF_RTTI(IMovementPlannerDirectControl);
	};
	static_assert(sizeof(IMovementPlannerDirectControl) == 0x8);
}
