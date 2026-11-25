#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	struct IMovementQueryAnimDeltas :
		public IMovementInterface  // 00
	{
	public:
		SF_RTTI(IMovementQueryAnimDeltas);
	};
	static_assert(sizeof(IMovementQueryAnimDeltas) == 0x8);
}
