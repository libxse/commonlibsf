#include "RE/M/MenuControls.h"

namespace RE
{
	MenuControls* MenuControls::GetSingleton()
	{
		static REL::Relocation<MenuControls**> singleton{ ID::MenuControls::Singleton };
		return *singleton;
	}

	void MenuControls::PerformInputProcessing(const InputEvent* a_queueHead)
	{
		using func_t = void (*)(MenuControls*, const InputEvent*);
		static REL::Relocation<func_t> func{ ID::MenuControls::PerformInputProcessing };
		func(this, a_queueHead);
	}

	bool MenuControls::RegisterHandler(BSInputEventUser* a_handler)
	{
		if (!a_handler || handlers.size > handlers.capacity || (handlers.capacity && !handlers.data)) {
			return false;
		}
		for (auto* handler : GetHandlers()) {
			if (handler == a_handler) {
				return true;
			}
		}

		struct Allocator
		{
			std::uintptr_t  vtable;
			HandlerStorage* array;
		};
		static_assert(sizeof(Allocator) == 0x10);
		static_assert(offsetof(Allocator, array) == 0x08);
		using func_t = std::uint32_t (*)(HandlerStorage*, Allocator*, std::uint32_t, std::uint32_t);
		static REL::Relocation<func_t> append{ ID::BSTArray::AppendIndex };
		Allocator                      allocator{ ID::BSTArray::HeapAllocatorFunctorVtable.address(), &handlers };
		a_handler->inputEventHandlingEnabled = true;
		const auto index = append(&handlers, &allocator, handlers.capacity, sizeof(BSInputEventUser*));
		if (index == 0xFFFFFFFFu) {
			return false;
		}
		handlers.data[index] = a_handler;
		return true;
	}

	void MenuControls::UnregisterHandler(BSInputEventUser* a_handler)
	{
		if (!a_handler) {
			return;
		}
		using func_t = void (*)(MenuControls*, BSInputEventUser*);
		static REL::Relocation<func_t> remove{ ID::MenuControls::UnregisterHandler };
		remove(this, a_handler);
	}
}
