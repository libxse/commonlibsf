#pragma once

#include "RE/B/BSExtraData.h"
#include "RE/B/BSIntrusiveRefCounted.h"
#include "RE/B/BSLock.h"
#include "RE/E/ExtraDataTypes.h"

namespace RE
{
	class BaseExtraList
	{
	public:
		void AddExtra(BSExtraData* a_extra)
		{
			using func_t = decltype(&BaseExtraList::AddExtra);
			static REL::Relocation<func_t> func{ ID::BaseExtraList::AddExtra };
			return func(this, a_extra);
		}

		[[nodiscard]] BSExtraData* GetByType(ExtraDataType a_type) const noexcept
		{
			if (!HasType(a_type))
				return nullptr;

			for (auto iter = m_head; iter; iter = iter->next)
				if (iter->type == a_type)
					return iter;

			return nullptr;
		}

		bool HasType(ExtraDataType a_type) const noexcept
		{
			const auto    type = std::to_underlying(a_type);
			std::uint32_t index = type >> 3;
			std::uint8_t  bit = 1 << (type & 7);

			return m_flags && (m_flags[index] & bit);
		}

	private:
		// members
		BSExtraData*  m_head{};                          // 00
		BSExtraData** m_tail{ std::addressof(m_head) };  // 08
		std::uint8_t* m_flags{};                         // 10
	};
	static_assert(sizeof(BaseExtraList) == 0x18);

	namespace detail
	{
		template <class T>
		concept ExtraDataListConstraint =
			std::derived_from<T, BSExtraData> &&
			!std::is_pointer_v<T> &&
			!std::is_reference_v<T>;
	}

	class ExtraDataList :
		public BSIntrusiveRefCounted  // 00
	{
	public:
		void AddExtra(BSExtraData* a_extra)
		{
			const BSAutoWriteLock l{ m_extraRWLock };
			m_extraData.AddExtra(a_extra);
		}

		[[nodiscard]] BSExtraData* GetByType(ExtraDataType a_type) const noexcept
		{
			const BSAutoReadLock l{ m_extraRWLock };
			return m_extraData.GetByType(a_type);
		}

		template <detail::ExtraDataListConstraint T>
		[[nodiscard]] T* GetByType() const noexcept
		{
			return static_cast<T*>(GetByType(T::EXTRADATATYPE));
		}

		[[nodiscard]] bool HasQuestObjectAlias() const
		{
			using func_t = decltype(&ExtraDataList::HasQuestObjectAlias);
			static REL::Relocation<func_t> func{ ID::ExtraDataList::HasQuestObjectAlias };
			return func(this);
		}

		[[nodiscard]] bool HasType(ExtraDataType a_type) const noexcept
		{
			BSAutoReadLock l{ m_extraRWLock };
			return m_extraData.HasType(a_type);
		}

		template <detail::ExtraDataListConstraint T>
		[[nodiscard]] bool HasType() const noexcept
		{
			return HasType(T::EXTRADATATYPE);
		}

	private:
		// members
		BaseExtraList           m_extraData;    // 08
		mutable BSReadWriteLock m_extraRWLock;  // 20
	};
	static_assert(sizeof(ExtraDataList) == 0x28);
}
