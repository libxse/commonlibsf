#pragma once

#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/I/IMovementAnimationDrivenFeedback.h"
#include "RE/I/IMovementDirectControl.h"
#include "RE/I/IMovementPlannerDirectControl.h"
#include "RE/I/IMovementProcessMessageInterface.h"
#include "RE/I/IMovementQueryAnimDeltas.h"
#include "RE/I/IMovementSelectIdle.h"
#include "RE/M/MovementControllerAI.h"

namespace RE
{
	class MovementControllerNPC :
		public MovementControllerAI,              // 00
		public IMovementProcessMessageInterface,  // 78
		public IMovementSelectIdle,               // 80
		public IMovementDirectControl,            // 88
		public IMovementPlannerDirectControl,     // 90
		public IMovementQueryAnimDeltas,          // 98
		public IMovementAnimationDrivenFeedback,  // A0
		public BSIntrusiveRefCounted              // A8
	{
	public:
		SF_RTTI_VTABLE(MovementControllerNPC);

		void SetAnimationDriven()
		{
			using func_t = decltype(&MovementControllerNPC::SetAnimationDriven);
			static REL::Relocation<func_t> func{ ID::MovementControllerNPC::SetAnimationDriven };
			return func(this);
		}

		void SetMotionDriven()
		{
			using func_t = decltype(&MovementControllerNPC::SetMotionDriven);
			static REL::Relocation<func_t> func{ ID::MovementControllerNPC::SetMotionDriven };
			return func(this);
		}
	};
}
