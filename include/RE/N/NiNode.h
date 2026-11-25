#pragma once

#include "RE/B/BSTArray.h"
#include "RE/N/NiAVObject.h"
#include "RE/N/NiTransform.h"

namespace RE
{
	class __declspec(novtable) NiNode :
		public NiAVObject
	{
	public:
		SF_RTTI(NiNode);

		//add
		virtual ~NiNode() = default;
		virtual NiNode*      GetAsNiNode();
		virtual void*        AddChild(NiAVObject* child);
		virtual bool*        RemoveChild(NiAVObject* child);
		virtual NiAVObject*  GetObjectByName(const BSFixedString& name);
		virtual NiAVObject*  FindObjectRecursive(const BSFixedString& name);
		virtual NiTransform* GetLocalTransform();
		virtual void*        SetLocalTransform(const NiTransform& transform);

		// members
		BSTArray<NiPointer<NiAVObject>> children;
		void*                           extraData;
		std::uint32_t                   childCount;
		std::uint32_t                   flags;
		std::uint64_t                   pad148;
	};
	//static_assert(sizeof(NiNode) == 0x150);
}
