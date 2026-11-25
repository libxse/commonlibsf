#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/I/IObjectHandlePolicy.h"
#include "RE/M/MemoryManager.h"
#include "RE/O/ObjectTypeInfo.h"

namespace RE::BSScript
{
	class ObjectTypeInfo;
	class Variable;

	class Object
	{
	public:
		void dtor();

		~Object()
		{
			dtor();
		}

		Object* ctor(const BSTSmartPointer<ObjectTypeInfo>& a_type, const IObjectHandlePolicy& a_handlePolicy, std::uint32_t a_numProperties)
		{
			using func_t = decltype(&Object::ctor);
			static REL::Relocation<func_t> func{ ID::BSScript::Object::ctor };
			return func(this, a_type, a_handlePolicy, a_numProperties);
		}

		Object(const BSTSmartPointer<ObjectTypeInfo>& a_type, const IObjectHandlePolicy& a_handlePolicy, std::uint32_t a_numProperties)
		{
			ctor(a_type, a_handlePolicy, a_numProperties);
		}

		Object() = delete;

		[[nodiscard]] constexpr bool IsConstructed() const noexcept { return static_cast<bool>(constructed); }
		[[nodiscard]] constexpr bool IsInitialized() const noexcept { return static_cast<bool>(initialized); }
		[[nodiscard]] constexpr bool IsValid() const noexcept { return static_cast<bool>(valid); }

		[[nodiscard]] std::uint32_t DecRef();
		[[nodiscard]] std::size_t   GetHandle();
		void                        IncRef();

		SF_HEAP_REDEFINE_NEW();

		// members
		std::uint16_t                   unk00;                     // 00
		std::uint16_t                   unk02;                     // 02
		std::uint32_t                   unk04;                     // 04
		std::uint64_t                   unk08;                     // 08
		std::uint32_t                   constructed: 1;            // 10:00
		std::uint32_t                   initialized: 1;            // 10:01
		std::uint32_t                   valid: 1;                  // 10:02
		std::uint32_t                   remainingPropsToInit: 29;  // 10:03
		std::uint32_t                   unk14;                     // 14
		std::uint32_t                   unk18;                     // 18
		std::uint32_t                   unk1C;                     // 1C
		BSTSmartPointer<ObjectTypeInfo> type;                      // 20
		BSFixedString                   currentState;              // 28
		volatile void*                  lockStructure;             // 30
		IObjectHandlePolicy*            handlePolicy;              // 38
		std::size_t                     handle;                    // 40
		volatile std::uint32_t          refCountAndHandleLock;     // 48
	};
	static_assert(sizeof(Object) == 0x50);
}
