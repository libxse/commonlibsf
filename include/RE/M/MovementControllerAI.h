#pragma once

namespace RE
{
	class MovementControllerAI
	{
	public:
		SF_RTTI_VTABLE(MovementControllerAI);

		virtual ~MovementControllerAI();  // 00

		// members
		std::byte    unk08[0x68];   // 08
		std::uint8_t movementMode;  // 70 - 1 = animation-driven, 2 = motion-driven
		std::byte    unk71[0x07];   // 71
	};
	static_assert(offsetof(MovementControllerAI, movementMode) == 0x70);
	static_assert(sizeof(MovementControllerAI) == 0x78);
}
