#pragma once

#include "RE/B/BSModelNode.h"
#include "RE/B/BSTArray.h"
#include "RE/N/NiTransform.h"

namespace RE
{
	class NiAVObject;

	class BGSModelNode :
		public BSModelNode  // 00
	{
	public:
		SF_RTTI_VTABLE(BGSModelNode);

		struct Rig
		{
			struct Buffer
			{
				// members
				void*        unk00;  // 00
				void*        unk08;  // 08
				NiTransform* data;   // 10 - one slot per rig bone
			};

			// members
			std::uint32_t  refCount;     // 00
			std::uint32_t  unk04;        // 04
			Buffer*        local;        // 08
			Buffer*        world;        // 10
			Buffer*        prevWorld;    // 18
			void*          unk20;        // 20
			std::uint16_t* parents;      // 28
			void*          unk30;        // 30
			std::uint16_t* order;        // 38
			std::byte      unk40[0x48];  // 40
			bool           rebuild;      // 88
		};
		static_assert(offsetof(Rig, rebuild) == 0x88);

		struct NodeEntry
		{
			// members
			std::uint16_t rigIndex;  // 00
			std::uint16_t unk02;     // 02
			std::uint16_t unk04;     // 04
			std::uint16_t unk06;     // 06
			NiAVObject*   node;      // 08
		};
		static_assert(sizeof(NodeEntry) == 0x10);

		~BGSModelNode() override;  // 00

		// members
		Rig*                rig;          // 10
		BSTArray<NodeEntry> nodes;        // 18
		std::byte           unk28[0x68];  // 28
	};
	static_assert(offsetof(BGSModelNode, nodes) == 0x18);
	static_assert(sizeof(BGSModelNode) == 0x90);
}
