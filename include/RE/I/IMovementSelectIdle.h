#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	struct IMovementSelectIdle :
		public IMovementInterface  // 00
	{
	public:
		SF_RTTI(IMovementSelectIdle);
	};
	static_assert(sizeof(IMovementSelectIdle) == 0x8);
}
