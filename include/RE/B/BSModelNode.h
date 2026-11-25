#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"

namespace RE
{
	class NiNode;
	class NiTransform;
	class NiUpdateData;

	class BSModelNode :
		public BSIntrusiveRefCounted  // 08
	{
	public:
		SF_RTTI_VTABLE(BSModelNode);

		virtual ~BSModelNode();  // 00

		// add
		virtual void* Refresh(NiNode* a_rootNode, NiUpdateData* a_updateData);                     // 01
		virtual bool  Update(void* a_data, NiUpdateData* a_updateData, NiTransform* a_transform);  // 02
	};
	static_assert(sizeof(BSModelNode) == 0x10);
}
