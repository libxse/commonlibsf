#pragma once

#include "RE/I/IMovementInterface.h"

namespace RE
{
	class IMovementProcessMessageInterface :
		public IMovementInterface  // 00
	{
	public:
		~IMovementProcessMessageInterface() override;

		// add
		virtual void Unk_01();  // 01
	};
	static_assert(sizeof(IMovementProcessMessageInterface) == 0x8);
}
