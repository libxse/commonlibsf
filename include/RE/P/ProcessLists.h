#pragma once

#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	struct PositionPlayerEvent;

	class __declspec(novtable) ProcessLists :
		public BSTEventSink<PositionPlayerEvent>,  // 000
		public BSTSingletonSDM<ProcessLists>       // 008
	{
	public:
		SF_RTTI_VTABLE(ProcessLists);

		virtual ~ProcessLists();  // 00

		// override
		virtual BSEventNotifyControl ProcessEvent(const PositionPlayerEvent&, BSTEventSource<PositionPlayerEvent>*) override;  // 01

		[[nodiscard]] static ProcessLists* GetSingleton()
		{
			static REL::Relocation<ProcessLists**> singleton{ ID::ProcessLists::Singleton };
			return *singleton;
		}

		[[nodiscard]] bool AreHostileActorsNear(BSScrapArray<BSPointerHandle<Actor>>* a_hostileActors = nullptr)
		{
			using func_t = decltype(&ProcessLists::AreHostileActorsNear);
			static REL::Relocation<func_t> func{ ID::ProcessLists::AreHostileActorsNear };
			return func(this, a_hostileActors);
		}

		void EnableAI(bool a_enable)
		{
			using func_t = decltype(&ProcessLists::EnableAI);
			static REL::Relocation<func_t> func{ ID::ProcessLists::ToggleAI };
			func(this, a_enable);
		}

		// members
		std::byte                        pad018[0x10];                  // 018
		std::int32_t                     numberHighActors;              // 028
		std::int32_t                     numberFullyEnabledHighActors;  // 02C
		std::byte                        pad030[0x1C];                  // 030
		bool                             runDetection;                  // 04C
		std::byte                        unk04D;                        // 04D
		bool                             processHigh;                   // 04E
		bool                             processLow;                    // 04F
		bool                             processMiddleHigh;             // 050
		bool                             processMiddleLow;              // 051
		bool                             processSchedules;              // 052
		bool                             showSubtitles;                 // 053
		std::byte                        pad054[0xC];                   // 054
		BSTArray<BSPointerHandle<Actor>> highActorHandles;              // 060
		BSTArray<BSPointerHandle<Actor>> lowActorHandles;               // 070
		BSTArray<BSPointerHandle<Actor>> middleHighActorHandles;        // 080
		BSTArray<BSPointerHandle<Actor>> middleLowActorHandles;         // 090
		std::byte                        pad0A0[0x154];                 // 0A0
		bool                             runSchedules;                  // 1F4
		bool                             runMovement;                   // 1F5
		bool                             runAnimations;                 // 1F6
	};
	static_assert(offsetof(ProcessLists, numberHighActors) == 0x28);
	static_assert(offsetof(ProcessLists, numberFullyEnabledHighActors) == 0x2C);
	static_assert(offsetof(ProcessLists, runDetection) == 0x4C);
	static_assert(offsetof(ProcessLists, showSubtitles) == 0x53);
	static_assert(offsetof(ProcessLists, highActorHandles) == 0x60);
	static_assert(offsetof(ProcessLists, lowActorHandles) == 0x70);
	static_assert(offsetof(ProcessLists, middleHighActorHandles) == 0x80);
	static_assert(offsetof(ProcessLists, middleLowActorHandles) == 0x90);
	static_assert(offsetof(ProcessLists, runSchedules) == 0x1F4);
}
