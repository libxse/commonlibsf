#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	struct IMovementDirectControl :
		public IMovementInterface  // 00
	{
	public:
		SF_RTTI(IMovementDirectControl);
	};
	static_assert(sizeof(IMovementDirectControl) == 0x8);
}
