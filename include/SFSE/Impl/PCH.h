#pragma once

#include "REL/REL.h"
#include "REX/REX.h"

namespace SFSE
{
	using namespace std::literals;
}

namespace RE
{
	using namespace std::literals;
}

#include "RE/IDs.h"
#include "RE/IDs_NiRTTI.h"
#include "RE/IDs_RTTI.h"
#include "RE/IDs_VTABLE.h"

#include "RE/M/msvc.h"

#undef cdecl  // Workaround for Clang.
