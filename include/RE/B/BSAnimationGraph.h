#pragma once

#include "RE/B/BGSAnimationPathImplementation.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSLock.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSmartPointer.h"

namespace RE
{
	class BSAnimationGraphEvent;
	class BSFadeNode;
	struct BSMovementDataChangedEvent;
	struct BSSubGraphActivationUpdate;
	class BSTransformDeltaEvent;
	class BSAnimationUpdateData;
	class IPostAnimationChannelUpdateFunctor;
	class NiTransform;

	class BSAnimationGraph :
		public BSTEventSource<BSAnimationGraphEvent>,       // 00
		public BSTEventSource<BSMovementDataChangedEvent>,  // 28
		public BSTEventSource<BSSubGraphActivationUpdate>,  // 50
		public BSTEventSource<BSTransformDeltaEvent>,       // 78
		public BSIntrusiveRefCounted                        // A0
	{
	public:
		virtual ~BSAnimationGraph();

		virtual void Unk_01();                                                                       // 01
		virtual void Unk_02();                                                                       // 02
		virtual void Unk_03();                                                                       // 03
		virtual void Update(BSAnimationUpdateData& a_updateData);                                    // 04
		virtual void Unk_05();                                                                       // 05
		virtual void Unk_06();                                                                       // 06
		virtual void GenerateOutputPose(BSAnimationUpdateData& a_updateData, void* a_eventListOut);  // 07
		virtual void Unk_08();                                                                       // 08
		virtual void Unk_09();                                                                       // 09
		virtual void Unk_0A();                                                                       // 0A
		virtual void Unk_0B();                                                                       // 0B
		virtual void Unk_0C();                                                                       // 0C
		virtual void Unk_0D();                                                                       // 0D
		virtual void Unk_0E();                                                                       // 0E
		virtual void Unk_0F();                                                                       // 0F
		virtual void Unk_10();                                                                       // 10
		virtual void Unk_11();                                                                       // 11
		virtual void Unk_12();                                                                       // 12
		virtual void Unk_13();                                                                       // 13
		virtual void Unk_14();                                                                       // 14
		virtual void Unk_15();                                                                       // 15
		virtual void Unk_16();                                                                       // 16
		virtual void Unk_17();                                                                       // 17
		virtual void Unk_18();                                                                       // 18
		virtual void Unk_19();                                                                       // 19
		virtual void Unk_1A();                                                                       // 1A
		virtual void Unk_1B();                                                                       // 1B
		virtual void Unk_1C();                                                                       // 1C
		virtual void Unk_1D();                                                                       // 1D
		virtual void Unk_1E();                                                                       // 1E
		virtual void Unk_1F();                                                                       // 1F
		virtual void Unk_20();                                                                       // 20
		virtual void Unk_21();                                                                       // 21
		virtual void Unk_22();                                                                       // 22
		virtual void Unk_23();                                                                       // 23
		virtual void Unk_24();                                                                       // 24
		virtual void Unk_25();                                                                       // 25
		virtual void Unk_26();                                                                       // 26
		virtual void Unk_27();                                                                       // 27
		virtual void Unk_28();                                                                       // 28
		virtual void Unk_29();                                                                       // 29
		virtual void Unk_2A();                                                                       // 2A
		virtual void Unk_2B();                                                                       // 2B
		virtual void Unk_2C();                                                                       // 2C
	};

	static_assert(sizeof(BSAnimationGraph) == 0xA8);

	class AnimationManager : public BSAnimationGraph
	{
	public:
		virtual ~AnimationManager();

		[[nodiscard]] TESObjectREFR* GetTargetReference() const
		{
			return animationPath ? animationPath->reference : nullptr;
		}

		// members
		std::byte                           unkA8[0x218];       // A8
		BGSAnimationPathImplementation*     animationPath;      // 2C0
		std::uint64_t                       unk2C8;             // 2C8
		IPostAnimationChannelUpdateFunctor* postUpdateFunctor;  // 2D0
		float                               sampleQuantum;      // 2D8
		std::uint32_t                       unk2DC;             // 2DC
		std::uint32_t                       unk2E0;             // 2E0
		std::uint32_t                       unk2E4;             // 2E4
		std::uint32_t                       prevPoseCount;      // 2E8
		std::uint32_t                       unk2EC;             // 2EC
		NiTransform*                        prevPoseSnapshot;   // 2F0
		std::uint32_t                       currPoseCount;      // 2F8
		std::uint32_t                       unk2FC;             // 2FC
		NiTransform*                        currPoseSnapshot;   // 300
		std::byte                           unk308[0x28];       // 308
		BSFadeNode*                         rootNode;           // 330
		std::byte                           unk338[0x4C];       // 338
		float                               lastUpdateDelta;    // 384
		std::uint32_t                       unk388;             // 388
		std::uint32_t                       updateCount;        // 38C
		std::byte                           unk390[0x30];       // 390
	};
	static_assert(offsetof(AnimationManager, animationPath) == 0x2C0);
	static_assert(offsetof(AnimationManager, rootNode) == 0x330);
	static_assert(sizeof(AnimationManager) == 0x3C0);

	class BSAnimationGraphManager :
		public BSTEventSink<BSAnimationGraphEvent>,
		public BSIntrusiveRefCounted
	{
	public:
		// TODO: Properly implement BSTSmallArray
		template <typename T, std::uint32_t N>
		class SmallArray
		{
		public:
			inline std::uint32_t size() { return _size; }
			inline void*         data() { return _local ? _stack : _heap; }

			inline T& operator[](std::uint32_t a_idx)
			{
				return static_cast<T*>(data())[a_idx];
			}

			std::uint32_t _size;
			std::uint32_t _unk;
			std::uint32_t _capacity: 31;
			std::uint32_t _local: 1;
			union
			{
				void*     _heap;
				std::byte _stack[sizeof(T) * N];
			};
		};

		virtual ~BSAnimationGraphManager();

		std::uint32_t                                    unk0C;                 // 0C
		std::uint32_t                                    unk10;                 // 10
		std::uint32_t                                    unk14;                 // 14
		std::uint32_t                                    unk18;                 // 18
		std::uint32_t                                    unk1C;                 // 1C
		std::uint32_t                                    unk20;                 // 20
		std::uint32_t                                    unk24;                 // 24
		std::uint32_t                                    unk28;                 // 28
		std::uint32_t                                    unk2C;                 // 2C
		SmallArray<BSTSmartPointer<BSAnimationGraph>, 1> graphs;                // 30
		std::uint32_t                                    unk50[0x8];            // 50
		BSSpinLock                                       updateLock;            // 68
		BSSpinLock                                       dependentManagerLock;  // 70
		std::uint32_t                                    activeGraph;           // 78
		std::uint32_t                                    generateDepth;         // 7C
	};
	static_assert(sizeof(BSAnimationGraphManager) == 0x80);
}
