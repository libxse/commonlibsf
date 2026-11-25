#include "RE/B/BSInputEventSingleUser.h"

namespace RE
{
	void BSInputEventSingleUser::PerformInputProcessing(const InputEvent* a_queueHead)
	{
		using func_t = decltype(&BSInputEventSingleUser::PerformInputProcessing);
		static REL::Relocation<func_t> func{ ID::BSInputEventSingleUser::PerformInputProcessing };
		func(this, a_queueHead);
	}
}
