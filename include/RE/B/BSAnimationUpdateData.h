#pragma once

#include "RE/N/NiPoint.h"

namespace RE
{
	class BGSModelNode;
	class IPostAnimationChannelUpdateFunctor;

	class BSAnimationUpdateData
	{
	public:
		// members
		NiPoint3A                           location;           // 00
		NiPoint3A                           rotation;           // 10
		NiPoint3A                           unk20;              // 20
		NiPoint3A                           unk30;              // 30
		float                               unk40;              // 40
		float                               unk44;              // 44
		IPostAnimationChannelUpdateFunctor* postUpdateFunctor;  // 48
		BGSModelNode*                       modelNode;          // 50
		float                               unk58;              // 58
		float                               unk5C;              // 5C
		float                               timeDelta;          // 60
		std::uint16_t                       unk64;              // 64
		std::uint16_t                       unk66;              // 66
		std::uint16_t                       unk68;              // 68
		bool                                forceUpdate;        // 6A
		bool                                modelCulled;        // 6B
		bool                                unk6C;              // 6C
		bool                                unk6D;              // 6D
		bool                                unk6E;              // 6E
		bool                                unk6F;              // 6F
		float                               unk70;              // 70
	};
	static_assert(offsetof(BSAnimationUpdateData, modelNode) == 0x50);
	static_assert(offsetof(BSAnimationUpdateData, timeDelta) == 0x60);
	static_assert(offsetof(BSAnimationUpdateData, modelCulled) == 0x6B);
	static_assert(sizeof(BSAnimationUpdateData) == 0x80);
}
