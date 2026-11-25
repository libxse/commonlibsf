#pragma once

#include "RE/B/BSFixedString.h"

namespace RE::BSScript
{
	class __declspec(novtable) IVMRemoteDebuggerInterface
	{
	public:
		SF_RTTI(BSScript__IVMRemoteDebuggerInterface);  // VTABLE seems to have been removed in 1.15.216

		~IVMRemoteDebuggerInterface() = delete;

		virtual bool IsCompletelyFrozen() = 0;  // 00 -- just calls IsCompletelyFrozen on the VM
		virtual void Unk01() = 0;               // 01
		virtual void Unk02() = 0;               // 02
	};
	static_assert(sizeof(IVMRemoteDebuggerInterface) == 0x8);
}
