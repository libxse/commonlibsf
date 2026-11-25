#pragma once

#include "REL/Trampoline.h"

namespace SFSE
{
	using Trampoline [[deprecated("Use REL::Trampoline instead")]] = REL::Trampoline;

	// DEPRECATED
	[[nodiscard, deprecated("Use REL::GetTrampoline instead")]] inline REL::Trampoline& GetTrampoline() noexcept
	{
		return REL::GetTrampoline();
	}
}
