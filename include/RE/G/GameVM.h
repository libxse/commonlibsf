#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTFreeList.h"
#include "RE/B/BSTSingleton.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/C/CompiledScriptLoader.h"
#include "RE/H/HandlePolicy.h"
#include "RE/I/IClientVM.h"
#include "RE/I/IStackCallbackSaveInterface.h"
#include "RE/I/IVirtualMachine.h"
#include "RE/L/Logger.h"
#include "RE/O/ObjectBindPolicy.h"
#include "RE/P/Profiler.h"
#include "RE/R/RemoteDebugger.h"
#include "RE/S/SavePatcher.h"
#include "RE/S/SimpleAllocMemoryPagePolicy.h"

namespace RE
{
	struct InputEnableLayerDestroyedEvent;
	struct PositionPlayerEvent;
	struct TESFormDeleteEvent;
	struct TESFormIDRemapEvent;
	struct TESInitScriptEvent;
	struct TESResolveNPCTemplatesEvent;
	struct TESUniqueIDChangeEvent;

	namespace ModelReferenceEffectEvents
	{
		struct ReferenceEffectFinished;
	}

	namespace BSScript
	{
		struct StatsEvent;
		class IVMSaveLoadInterface;
		class IVMDebugInterface;
	}

	namespace GameScript
	{
		struct StatsEvent;
		struct UserLogEvent;

		class __declspec(novtable) DelayFunctor :
			public BSIntrusiveRefCounted  // 08
		{
		public:
			static constexpr auto RTTI{ RTTI::GameScript__DelayFunctor };
			static constexpr auto VTABLE{ VTABLE::GameScript__DelayFunctor };

			enum class FunctorType
			{
				kMoveTo = 0,
				kMoveToOwnEditorLoc = 1,
				kDamageObject = 2,
				kEnable = 3,
				kDisable = 4,
				kDelete = 5,
				kSetPosition = 6,
				kSetAngle = 7,
				kSetMotionType = 8,
				kNonLatentDelete = 9,
				kMoveToPackLoc = 10,
				kSetScale = 11,
				kDropObject = 12,
				kAttachAshPile = 13,
				kForceAddRemoveRagdoll = 15,
				kApplyHavokImpulse = 16,
				kReset = 17,
				kSendPlayerToJail = 18,
				kAddItem = 19,
				kResurrect = 20,
				kCast = 21,
				kScrollCast = 22,
				kRemoveItem = 23,
				kWaitFor3D = 24,
				kPlayBink = 25,
				kMoveToNearestNavmeshLoc = 26,
				kClearDestruction = 27,
				//kWaitForResourceRecalc -- appears to have been removed
				kRemoveComponent = 29,
				kDropRef = 30,
				kPopPlayerTo = 31,
			};

			virtual ~DelayFunctor();  // 00

			// add
			[[nodiscard]] virtual BSScript::Variable operator()() = 0;                                                                                // 01
			[[nodiscard]] virtual bool               IsLatent() const = 0;                                                                            // 02
			[[nodiscard]] virtual bool               WantsRequeue() const { return false; }                                                           // 03
			[[nodiscard]] virtual FunctorType        GetType() const = 0;                                                                             // 04
			virtual bool                             SaveImpl(BSStorage& a_storage) const = 0;                                                        // 05
			virtual bool                             LoadImpl(const BSStorage& a_storage, std::uint32_t a_scriptSaveVersion, bool& a_dataValid) = 0;  // 06

			SF_HEAP_REDEFINE_NEW(DelayFunctor);

			// members
			std::uint32_t stackID;  // 0C
		};
		static_assert(sizeof(DelayFunctor) == 0x10);
	}

	class GameVM :
		public BSTSingletonSDM<GameVM>,                                           // 0000
		public BSScript::IClientVM,                                               // 0010
		public BSScript::IStackCallbackSaveInterface,                             // 0018
		public BSTEventSink<BSScript::StatsEvent>,                                // 0020
		public BSTEventSink<InputEnableLayerDestroyedEvent>,                      // 0028
		public BSTEventSink<PositionPlayerEvent>,                                 // 0030
		public BSTEventSink<TESFormDeleteEvent>,                                  // 0038
		public BSTEventSink<TESFormIDRemapEvent>,                                 // 0040
		public BSTEventSink<TESInitScriptEvent>,                                  // 0048
		public BSTEventSink<TESResolveNPCTemplatesEvent>,                         // 0050
		public BSTEventSink<TESUniqueIDChangeEvent>,                              // 0058
		public BSTEventSource<GameScript::StatsEvent>,                            // 0060
		public BSTEventSource<GameScript::UserLogEvent>,                          // 0088
		public BSTEventSink<ModelReferenceEffectEvents::ReferenceEffectFinished>  // 00B0
	{
	public:
		SF_RTTI_VTABLE(GameVM);

		~GameVM() override;  // 00

		// override (BSScript::IClientVM)
		bool IsVMFrozen() const override;    // 01
		void PreSave() override;             // 02
		void Unk_03() override { return; };  // 03

		// override (BSScript::IStackCallbackSaveInterface)
		bool SaveStackCallback(BSStorage& a_buffer, const BSTSmartPointer<BSScript::IStackCallbackFunctor>& a_callback) const override;                // 01
		bool LoadStackCallback(const BSStorage& a_buffer, bool& a_arg2, BSTSmartPointer<BSScript::IStackCallbackFunctor>& a_callback) const override;  // 02

		// override (BSTEventSink<BSScript::StatsEvent>)
		BSEventNotifyControl ProcessEvent(const BSScript::StatsEvent& a_event, BSTEventSource<BSScript::StatsEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<InputEnableLayerDestroyedEvent>)
		BSEventNotifyControl ProcessEvent(const InputEnableLayerDestroyedEvent& a_event, BSTEventSource<InputEnableLayerDestroyedEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<PositionPlayerEvent>)
		BSEventNotifyControl ProcessEvent(const PositionPlayerEvent& a_event, BSTEventSource<PositionPlayerEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<TESFormDeleteEvent>)
		BSEventNotifyControl ProcessEvent(const TESFormDeleteEvent& a_event, BSTEventSource<TESFormDeleteEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<TESFormIDRemapEvent>)
		BSEventNotifyControl ProcessEvent(const TESFormIDRemapEvent& a_event, BSTEventSource<TESFormIDRemapEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<TESInitScriptEvent>)
		BSEventNotifyControl ProcessEvent(const TESInitScriptEvent& a_event, BSTEventSource<TESInitScriptEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<TESResolveNPCTemplatesEvent>)
		BSEventNotifyControl ProcessEvent(const TESResolveNPCTemplatesEvent& a_event, BSTEventSource<TESResolveNPCTemplatesEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<TESUniqueIDChangeEvent>)
		BSEventNotifyControl ProcessEvent(const TESUniqueIDChangeEvent& a_event, BSTEventSource<TESUniqueIDChangeEvent>* a_dispatcher) override;  // 01

		// override (BSTEventSink<ModelReferenceEffectEvents::ReferenceEffectFinished>)
		BSEventNotifyControl ProcessEvent(const ModelReferenceEffectEvents::ReferenceEffectFinished& a_event, BSTEventSource<ModelReferenceEffectEvents::ReferenceEffectFinished>* a_dispatcher) override;  // 01

		[[nodiscard]] static GameVM* GetSingleton()
		{
			static REL::Relocation<GameVM**> singleton{ ID::GameVM::Singleton };
			return *singleton;
		}

		inline BSScript::IVirtualMachine* GetVM() const
		{
			return impl.get();
		}

		static void BindEverythingToScript(BSScript::IVirtualMachine** a_vm)
		{
			using func_t = decltype(&BindEverythingToScript);
			static REL::Relocation<func_t> func{ ID::GameVM::BindEverythingToScript };
			return func(a_vm);
		}

		// members
		std::uint64_t                                                                    unkB8;                          // 00B8
		std::uint64_t                                                                    unkC0;                          // 00C0
		std::uint64_t                                                                    unkC8;                          // 00C8
		std::uint64_t                                                                    unkD0;                          // 00D0
		std::uint64_t                                                                    unkD8;                          // 00D8
		BSTSmartPointer<BSScript::IVirtualMachine>                                       impl;                           // 00E0
		BSScript::IVMSaveLoadInterface*                                                  saveLoadInterface;              // 00E8
		BSScript::IVMDebugInterface*                                                     debugInterface;                 // 00F0
		BSScript::SimpleAllocMemoryPagePolicy                                            memoryPagePolicy;               // 0128
		BSScript::CompiledScriptLoader                                                   scriptLoader;                   // 0160
		GameScript::Logger                                                               logger;                         // 01E8
		GameScript::HandlePolicy                                                         handlePolicy;                   // 02A8
		GameScript::ObjectBindPolicy                                                     objectBindPolicy;               // 03A8
		BSTSmartPointer<BSScript::IStore>                                                scriptStore;                    // 03B0
		/*GameScript::FragmentSystem*/ std::byte                                         fragmentSystem[0x200];          // 05B0
		GameScript::Profiler                                                             profiler;                       // 06E0
		GameScript::RemoteDebugger                                                       remoteDebugger;                 // 07B8
		GameScript::SavePatcher                                                          savePatcher;                    // 07C0
		BSSpinLock                                                                       freezeLock;                     // 07C8
		bool                                                                             frozen;                         // 07CC
		BSSpinLock                                                                       vmTimeLock;                     // 07D4
		std::uint32_t                                                                    currentTime;                    // 07D8
		std::uint32_t                                                                    currentMenuModeTime;            // 07DC
		std::uint32_t                                                                    currentGameTime;                // 07E0
		bool                                                                             updateHasBeenRun;               // 07E1
		bool                                                                             saveLoad;                       // 07E8
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>                renderSafeFunctorPool1;         // 2800
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>*/ std::byte renderSafeFunctorQueue1[0x28];  // 2828
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>                renderSafeFunctorPool2;         // 4840
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>*/ std::byte renderSafeFunctorQueue2[0x28];  // 4868
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>                postRenderFunctorPool1;         // 6880
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>*/ std::byte postRenderFunctorQueue1[0x28];  // 68A8
		BSTStaticFreeList<BSTSmartPointer<GameScript::DelayFunctor>, 512>                postRenderFunctorPool2;         // 88C0
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>*/ std::byte postRenderFunctorQueue2[0x28];  // 88E8
		BSSpinLock                                                                       renderSafeQueueLock;            // 88F0
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* */ void*   renderSafeQueueToReadFrom;      // 88F8
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* */ void*   renderSafeQueueToWriteTo;       // 8900
		BSSpinLock                                                                       postRenderQueueLock;            // 8908
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* */ void*   postRenderQueueToReadFrom;      // 8910
		/*BSTCommonLLMessageQueue<BSTSmartPointer<GameScript::DelayFunctor>>* */ void*   postRenderQueueToWriteTo;       // 8918
		BSSpinLock                                                                       userLogLock;                    // 8920
		/*BSTHashMap<BSFixedString, BSScript::ErrorLogger*>*/ std::byte                  userLogs[0x38];                 // 8958
		BSSpinLock                                                                       statsWarningLock;               // 8960
		std::uint32_t                                                                    initialSuspendOverageTime;      // 8964
		std::uint32_t                                                                    initialRunningOverageTime;      // 8968
		std::uint32_t                                                                    initialStackMemoryOverageTime;  // 896C
		std::uint32_t                                                                    lastWarningTime;                // 8970
		std::uint32_t                                                                    overflowFlags;                  // 8978
	};
	static_assert(sizeof(GameVM) == 0x8978);
}
