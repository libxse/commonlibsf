#pragma once

#include "RE/B/BGSModelNode.h"
#include "RE/N/NiNode.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class BSFadeNode :
		public NiNode  // 000
	{
	public:
		SF_RTTI_VTABLE(BSFadeNode);

		// members
		std::byte               unk160[0x20];  // 160
		NiPointer<BGSModelNode> bgsModelNode;  // 180
		std::byte               unk188[0x38];  // 188
	};
	static_assert(offsetof(BSFadeNode, bgsModelNode) == 0x180);
	static_assert(sizeof(BSFadeNode) == 0x1C0);
}
