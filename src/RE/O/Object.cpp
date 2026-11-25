#include "RE/O/Object.h"

namespace RE::BSScript
{
	void Object::dtor()
	{
		using func_t = decltype(&Object::dtor);
		using func2_t = ObjectTypeInfo* (*)(ObjectTypeInfo*, std::uint32_t);
		static REL::Relocation<func_t>  UnkObjectDtorSubroutine{ ID::BSScript::Object::dtorUnkSub };
		static REL::Relocation<func2_t> ObjectTypeInfoDealloc{ ID::BSScript::ObjectTypeInfo::dtor };

		this->lockStructure =
			reinterpret_cast<void*>(reinterpret_cast<volatile std::uint64_t>(this->lockStructure) & 0xfffffffffffffffe);

		if (this->lockStructure != 0) {
			_InterlockedExchangeAdd(reinterpret_cast<volatile long*>(this->lockStructure), -1);
		}

		ObjectTypeInfo* pType = this->type.get();

		//BSTSmartPointer will decrement type's refcount automatically at end of scope
		if (pType->QRefCount() == 1) {
			//This stops the smart pointer from dereferencing a dangling ObjectTypeInfo pointer after
			//ObjectTypeInfoDealloc frees Object::type (and also does unknown global/TLS variable plumbing)
			this->type->IncRef();
			this->type.reset();
			ObjectTypeInfoDealloc(pType, 1);
		}

		UnkObjectDtorSubroutine(this);
	}

	[[nodiscard]] std::uint32_t Object::DecRef()
	{
		std::int32_t  iVar1;
		std::uint32_t uVar2;
		bool          bVar3;

		uVar2 = 0;
		do {
			while (true) {
				while (iVar1 = this->refCountAndHandleLock, iVar1 < 0) {
					if (uVar2 == 0) {
						_mm_pause();
						uVar2 = 1;
					} else {
						bVar3 = 9999 < uVar2;
						if (!bVar3) {
							uVar2 = uVar2 + 1;
						}
						REX::W32::Sleep(static_cast<unsigned int>(bVar3));
					}
				}

				if (iVar1 != 2)
					break;

				bVar3 = _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&(this->refCountAndHandleLock)),
							-0x7ffffffe, 2) == 2;
				if (bVar3) {
					_mm_mfence();
					this->handlePolicy->ReleaseHandle(this->handle);
					_mm_mfence();
					this->refCountAndHandleLock = 1;
					return 1;
				}
			}
			bVar3 = _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&(this->refCountAndHandleLock)),
						iVar1 - 1, iVar1) == iVar1;

		} while (!bVar3);
		return iVar1 - 1;
	}

	[[nodiscard]] std::size_t Object::GetHandle()
	{
		std::uint32_t uVar1;
		std::uint32_t uVar2;
		bool          bVar3;
		//The hexadecimal numbers next to the member functions in
		// IObjectHandlePolicy are vtable indices, NOT byte offsets
		this->handlePolicy->EmptyHandle();
		uVar2 = 0;
		do {
			while (uVar1 = this->refCountAndHandleLock, (int)uVar1 < 0) {
				if (uVar2 == 0) {
					_mm_pause();
					uVar2 = 1;
				} else {
					bVar3 = 9999 < uVar2;
					if (!bVar3) {
						uVar2 = uVar2 + 1;
					}
					REX::W32::Sleep(static_cast<std::uint32_t>(bVar3));
				}
			}

			bVar3 = _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&(this->refCountAndHandleLock)),
						uVar1 | 0x80000000, uVar1) == (long)uVar1;

		} while (!bVar3);
		_mm_mfence();
		this->refCountAndHandleLock = uVar1;
		_mm_mfence();
		return this->handle;
	}

	void Object::IncRef()
	{
		std::uint32_t uVar1 = 0;
		std::uint32_t uVar2;
		//std::uint64_t uVar3;
		std::uint32_t uVar4 = 0;
		bool          bVar5;

		do {
			while (true) {
				_mm_mfence();
				while (uVar2 = this->refCountAndHandleLock, (int)uVar2 < 0) {
					if (uVar4 == 0) {
						_mm_pause();
						uVar4 = 1;
					} else {
						bVar5 = 9999 < uVar4;
						if (!bVar5) {
							uVar4 = uVar4 + 1;
						}
						REX::W32::Sleep(static_cast<std::uint32_t>(bVar5));
					}
				}
				if (uVar2 != 1)
					break;

				bVar5 = _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&(this->refCountAndHandleLock)),
							-0x7fffffff, 1) == 1;
				if (bVar5) {
					_mm_mfence();
					this->handlePolicy->PersistHandle(this->handle);
					_mm_mfence();
					this->refCountAndHandleLock = 2;
					return;
				}
			}

			bVar5 = _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&(this->refCountAndHandleLock)),
						uVar2 + 1, uVar2) == (long)uVar2;
			if (bVar5) {
				uVar1 = uVar2;
				return;
			}

		} while (!bVar5);

		this->refCountAndHandleLock = uVar1;
		return;
	}
}
