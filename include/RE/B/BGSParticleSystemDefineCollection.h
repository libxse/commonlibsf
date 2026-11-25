#pragma once

#include "RE/B/BGSReflectedForm.h"
#include "RE/B/BSBlendable.h"
#include "RE/B/BSTArray.h"
#include "RE/W/WwiseSoundHook.h"

namespace RE
{
	class ParticleSystemDefine;

	class BGSParticleSystemDefineCollection : public BGSReflectedForm
	{
	public:
		SF_RTTI_VTABLE(BGSParticleSystemDefineCollection);
		SF_FORMTYPE(PSDC);

		~BGSParticleSystemDefineCollection() override;  // 00

		// members
		std::byte defines[0x18];  // 30 - std::vector<ParticleSystemDefine*>
	};
	static_assert(sizeof(BGSParticleSystemDefineCollection) == 0x50);
}
