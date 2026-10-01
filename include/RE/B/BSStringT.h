#pragma once

#include "RE/M/MemoryManager.h"

namespace RE
{
	template <class CharT, std::uint16_t>
	class DynamicMemoryManagementPol
	{
	public:
		using value_type = CharT;
		using size_type = std::uint16_t;
		using propagate_on_container_move_assignment = std::true_type;

		[[nodiscard]] value_type* allocate(size_type a_count) { return calloc<value_type>(a_count); }

		void deallocate(value_type* a_ptr, size_type) { free(a_ptr); }
	};

	template <
		class CharT,
		std::uint16_t N = static_cast<std::uint16_t>(-1),
		template <class, std::uint16_t> class Allocator = DynamicMemoryManagementPol>
	class BSStringT :
		public Allocator<CharT, N>  // 00
	{
	public:
		using value_type = CharT;
		using pointer = value_type*;
		using const_pointer = const value_type*;
		using reference = value_type&;
		using const_reference = const value_type&;
		using size_type = std::uint16_t;
		using allocator_type = Allocator<value_type, N>;
		using traits_type = std::char_traits<value_type>;

		constexpr BSStringT() noexcept = default;
		BSStringT(const_pointer a_string) { Assign(a_string); }
		BSStringT(const BSStringT& a_rhs) { Assign(a_rhs.c_str()); }
		BSStringT(BSStringT&& a_rhs) noexcept { move_from(std::move(a_rhs)); }
		~BSStringT() { release(); }

		BSStringT& operator=(const BSStringT& a_rhs)
		{
			if (this != std::addressof(a_rhs)) {
				Assign(a_rhs.c_str());
			}
			return *this;
		}

		BSStringT& operator=(BSStringT&& a_rhs) noexcept
		{
			if (this != std::addressof(a_rhs)) {
				release();
				move_from(std::move(a_rhs));
			}
			return *this;
		}

		BSStringT& operator=(const_pointer a_string)
		{
			Assign(a_string);
			return *this;
		}

		bool Assign(const_pointer a_string, std::size_t a_reserveLength = 0)
		{
			using func_t = bool (*)(BSStringT*, const_pointer, std::size_t);
			static REL::Relocation<func_t> func{ ID::BSStringT::Assign };
			return func(this, a_string, a_reserveLength);
		}

		[[nodiscard]] const_pointer data() const noexcept
		{
			if (_capacity <= kInlineCapacity) {
				return _storage;
			}
			pointer result;
			std::memcpy(&result, _storage, sizeof(result));
			return result;
		}

		[[nodiscard]] pointer       data() noexcept { return const_cast<pointer>(std::as_const(*this).data()); }
		[[nodiscard]] const_pointer c_str() const noexcept { return data(); }
		[[nodiscard]] operator std::basic_string_view<value_type, traits_type>() const noexcept { return { data(), size() }; }
		[[nodiscard]] bool      empty() const noexcept { return size() == 0; }
		[[nodiscard]] size_type size() const noexcept { return length(); }
		[[nodiscard]] size_type length() const noexcept { return _size == std::numeric_limits<size_type>::max() ? static_cast<size_type>(traits_type::length(c_str())) : _size; }
		[[nodiscard]] size_type capacity() const noexcept { return _capacity; }

	private:
		static constexpr size_type kInlineCapacity = 0xC;

		void release()
		{
			if (_capacity > kInlineCapacity) {
				allocator_type::deallocate(data(), _capacity);
			}
		}

		void move_from(BSStringT&& a_rhs) noexcept
		{
			std::memcpy(_storage, a_rhs._storage, sizeof(_storage));
			_size = a_rhs._size;
			_capacity = a_rhs._capacity;
			a_rhs._storage[0] = '\0';
			a_rhs._size = 0;
			a_rhs._capacity = 1;
		}

		value_type _storage[kInlineCapacity]{};  // 00
		size_type  _capacity{ 1 };               // 0C (includes the terminator)
		size_type  _size{};                      // 0E
	};

	using BSString = BSStringT<char>;
	static_assert(sizeof(BSString) == 0x10);
	static_assert(alignof(BSString) == 0x2);
}
