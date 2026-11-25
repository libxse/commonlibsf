#pragma once

#include "RE/M/MemoryManager.h"

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstring>

namespace RE
{
	// View + owner of Starfield engine members commented as
	// `std::vector<T, BSTHeapSTLAllocator<T, N>>`. Layout is three pointers
	// (begin / end / capacity-end), so sizeof == 0x18 on x64.
	//
	// Why not use `std::vector<T>` directly? MSVC's debug build
	// (`_ITERATOR_DEBUG_LEVEL=2`) inflates `sizeof(std::vector<void*>)` beyond 0x18
	// because of checked-iterator bookkeeping. This wrapper is build-mode-stable.
	//
	// Mutation uses the engine's MemoryManager (RE::malloc / RE::free), which is the
	// same global heap Bethesda's BSTHeapSTLAllocator ultimately delegates to. Buffers
	// allocated by the game can be freed by us and vice-versa without cross-heap
	// corruption. The raw BSTHeapSTLAllocatorBase REL::IDs (34039/34440) are NOT
	// plain allocators - calling 34039 with (bytes, align) returns an image-space
	// pointer, not a heap buffer. Probably just wrong offset ids and needs to be further RE'd
	//
	// Threading: no internal locking. Callers must ensure no other thread is
	// iterating or mutating the same vector. Safe during OnDataLoaded / main-thread
	// script ticks; not safe from background threads.
	template <class T>
	class BSTHeapSTLVector
	{
	public:
		using value_type = T;
		using pointer = T*;
		using const_pointer = const T*;
		using reference = T&;
		using const_reference = const T&;
		using iterator = T*;
		using const_iterator = const T*;
		using size_type = std::size_t;
		using difference_type = std::ptrdiff_t;

		[[nodiscard]] constexpr iterator       begin() noexcept { return _begin; }
		[[nodiscard]] constexpr const_iterator begin() const noexcept { return _begin; }
		[[nodiscard]] constexpr const_iterator cbegin() const noexcept { return _begin; }

		[[nodiscard]] constexpr iterator       end() noexcept { return _end; }
		[[nodiscard]] constexpr const_iterator end() const noexcept { return _end; }
		[[nodiscard]] constexpr const_iterator cend() const noexcept { return _end; }

		[[nodiscard]] constexpr pointer       data() noexcept { return _begin; }
		[[nodiscard]] constexpr const_pointer data() const noexcept { return _begin; }

		[[nodiscard]] constexpr size_type size() const noexcept
		{
			return static_cast<size_type>(_end - _begin);
		}

		[[nodiscard]] constexpr size_type capacity() const noexcept
		{
			return static_cast<size_type>(_capacityEnd - _begin);
		}

		[[nodiscard]] constexpr bool empty() const noexcept { return _begin == _end; }

		[[nodiscard]] constexpr reference       operator[](size_type a_index) noexcept { return _begin[a_index]; }
		[[nodiscard]] constexpr const_reference operator[](size_type a_index) const noexcept { return _begin[a_index]; }

		[[nodiscard]] constexpr reference       front() noexcept { return *_begin; }
		[[nodiscard]] constexpr const_reference front() const noexcept { return *_begin; }
		[[nodiscard]] constexpr reference       back() noexcept { return _end[-1]; }
		[[nodiscard]] constexpr const_reference back() const noexcept { return _end[-1]; }

		// Mutation -----------------------------------------------------------------

		// Appends a copy of a_value. Grows the buffer via the same automatic
		// reserve policy used by BSTArray when capacity is exhausted.
		void push_back(T a_value)
		{
			if (_end == _capacityEnd) {
				reserve_auto(size() + 1);
			}
			*_end = a_value;
			++_end;
		}

		// Removes the element at index a_index (0-based). Shifts subsequent
		// elements down and decrements end. Does nothing if a_index >= size().
		void erase(size_type a_index)
		{
			if (a_index >= size()) {
				return;
			}
			for (auto p = _begin + a_index; p + 1 != _end; ++p) {
				p[0] = p[1];
			}
			--_end;
			*_end = value_type{};
		}

		// Removes the first element equal to a_value and returns whether any slot
		// was removed. Does not touch the backing buffer's capacity.
		[[nodiscard]] bool erase_value(const T& a_value)
		{
			for (size_type i = 0; i < size(); ++i) {
				if (_begin[i] == a_value) {
					erase(i);
					return true;
				}
			}
			return false;
		}

		// Empties the vector without freeing the buffer (capacity unchanged).
		void clear() noexcept { _end = _begin; }

		// Pre-grows capacity to at least a_min. No-op if capacity already suffices.
		void reserve(size_type a_min)
		{
			if (a_min > capacity()) {
				reserve_exact(a_min);
			}
		}

		void shrink_to_fit() { reserve_exact(size()); }

		void pop_back()
		{
			if (!empty()) {
				--_end;
			}
		}

		// Frees the backing buffer via the game's allocator and zeroes all three
		// pointers. Use this (not `std::free`) when discarding a vector we built.
		void release_buffer()
		{
			if (_begin) {
				RE::free(_begin, alignof(T) > alignof(std::max_align_t));
			}
			_begin = nullptr;
			_end = nullptr;
			_capacityEnd = nullptr;
		}

	protected:
		void reserve_exact(size_type a_capacity)
		{
			assert(a_capacity >= size());
			if (a_capacity == capacity()) {
				return;
			}
			if (a_capacity == 0) {
				release_buffer();
				return;
			}

			const auto oldSize = size();
			const auto bytes = a_capacity * sizeof(T);
			const auto alignRequired = alignof(T) > alignof(std::max_align_t);
			auto*      newBuffer = static_cast<T*>(RE::malloc(bytes, alignRequired ? alignof(T) : 0));
			if (!newBuffer) {
				REX::FAIL("out of memory");
			}
			std::memset(newBuffer, 0, bytes);
			if (oldSize > 0) {
				std::memcpy(newBuffer, _begin, oldSize * sizeof(T));
			}
			if (_begin) {
				RE::free(_begin, alignRequired);
			}
			_begin = newBuffer;
			_end = newBuffer + oldSize;
			_capacityEnd = newBuffer + a_capacity;
		}

	private:
		void reserve_auto(size_type a_capacity)
		{
			if (a_capacity > capacity()) {
				const auto grow = std::max(a_capacity, capacity() * 2);
				reserve_exact(grow);
			}
		}

		// members
		T* _begin{ nullptr };        // 00
		T* _end{ nullptr };          // 08
		T* _capacityEnd{ nullptr };  // 10
	};
	static_assert(sizeof(BSTHeapSTLVector<void*>) == 0x18);
}
