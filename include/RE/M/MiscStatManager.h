#pragma once

namespace RE
{
	class MiscStatManager
	{
	public:
		static constexpr std::size_t kEntryStride = 0x20;
		static constexpr std::size_t kEntryNameOffset = 0x00;
		static constexpr std::size_t kEntryValueOffset = 0x10;

		struct Entry
		{
			std::uintptr_t name;        // 00
			std::byte      pad08[0x8];  // 08
			std::int32_t   value;       // 10
			std::byte      pad14[0xC];  // 14
		};
		static_assert(offsetof(Entry, name) == kEntryNameOffset);
		static_assert(offsetof(Entry, value) == kEntryValueOffset);
		static_assert(sizeof(Entry) == kEntryStride);
	};
}
