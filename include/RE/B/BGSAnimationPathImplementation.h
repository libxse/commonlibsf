#pragma once

namespace RE
{
	class TESObjectREFR;

	class AnimationPathInterface
	{
	public:
		SF_RTTI(AnimationPathInterface);

		virtual ~AnimationPathInterface();  // 00
	};
	static_assert(sizeof(AnimationPathInterface) == 0x8);

	class BGSAnimationPathImplementation :
		public AnimationPathInterface  // 00
	{
	public:
		SF_RTTI_VTABLE(BGSAnimationPathImplementation);

		// members
		TESObjectREFR* reference;  // 08
	};
	static_assert(offsetof(BGSAnimationPathImplementation, reference) == 0x08);
}
