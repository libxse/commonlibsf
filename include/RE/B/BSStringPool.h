#pragma once

namespace RE
{
	struct BSStringPool
	{
	public:
		class Entry
		{
		public:
			enum : std::uint8_t
			{
				kExternal = 1 << 1,
			};

			static void Release(Entry*& a_entry)
			{
				using func_t = decltype(&Entry::Release);
				static REL::Relocation<func_t> func{ ID::BSStringPool::Entry::Release };
				func(a_entry);
			}

			std::uint32_t Acquire()
			{
				REX::TAtomicRef refCount{ _refCount };
				return ++refCount;
			}

			template <class T>
			[[nodiscard]] const T* data() const noexcept
			{
				const auto entry = leaf();
				if (entry) {
					return reinterpret_cast<const T*>(entry + 1);
				} else {
					return nullptr;
				}
			}

			[[nodiscard]] const Entry* leaf() const noexcept
			{
				auto iter = this;
				while (iter && iter->external()) {
					iter = iter->_right;
				}
				return iter;
			}

			[[nodiscard]] std::uint32_t length() const noexcept
			{
				const auto entry = leaf();
				return entry ? entry->_length : 0;
			}

			[[nodiscard]] bool          external() const noexcept { return _flags & kExternal; }
			[[nodiscard]] std::uint32_t size() const noexcept { return length(); }

			// members
			Entry* _left;  // 00
			union
			{
				std::uint32_t _length;  // Number of bytes (even for wchar_t).
				Entry*        _right;
			};  // 08
			volatile std::uint32_t _refCount;  // 10
			std::uint8_t           _flags;     // 14
		};
		static_assert(sizeof(Entry) == 0x18);

		static void GetEntry(BSStringPool::Entry*& a_result, const char* a_string, bool a_caseSensitive)
		{
			using func_t = void (*)(BSStringPool::Entry*&, const char*, bool);
			static REL::Relocation<func_t> func{ ID::BSStringPool::GetEntry };
			func(a_result, a_string, a_caseSensitive);
		}

		static void GetEntry(BSStringPool::Entry*& a_result, const wchar_t* a_string, bool a_caseSensitive)
		{
			using func_t = void (*)(BSStringPool::Entry*&, const wchar_t*, bool);
			static REL::Relocation<func_t> func{ ID::BSStringPool::GetEntryW };
			func(a_result, a_string, a_caseSensitive);
		}
	};
	static_assert(std::is_empty_v<BSStringPool>);

	struct BucketTable
	{
	public:
		struct Lock
		{
		public:
			// members
			volatile std::uint32_t unk0;  // 00
			volatile std::uint32_t unk4;  // 04
			std::uint32_t          unk8;  // 08
		};
		static_assert(sizeof(Lock) == 0xC);

		static BucketTable& GetSingleton()
		{
			using func_t = decltype(&BucketTable::GetSingleton);
			static REL::Relocation<func_t> func{ ID::BSStringPool::BucketTable::GetSingleton };
			return func();
		}

		// members
		BSStringPool::Entry* buckets[0x40000];  // 000000
		Lock                 locks[0x100];      // 200000
		bool                 initialized;       // 200C00
	};
	static_assert(sizeof(BucketTable) == 0x200C08);
}
