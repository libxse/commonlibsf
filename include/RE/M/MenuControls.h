#pragma once

#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSInputEventUser.h"
#include "RE/B/BSTSingleton.h"

#include <cstddef>
#include <span>

namespace RE
{
	class MenuControls :
		public BSInputEventReceiver,          // 00
		public BSTSingletonSDM<MenuControls>  // 10
	{
	public:
		SF_RTTI_VTABLE(MenuControls);

		// Engine-owned; mutate through RegisterHandler/UnregisterHandler.
		struct HandlerStorage
		{
			std::uint32_t      size{};      // 00
			std::uint32_t      capacity{};  // 04
			BSInputEventUser** data{};      // 08
		};
		static_assert(sizeof(HandlerStorage) == 0x10);
		static_assert(offsetof(HandlerStorage, data) == 0x08);

		// override (BSInputEventReceiver)
		virtual void PerformInputProcessing(const InputEvent* a_queueHead) override;  // 01

		[[nodiscard]] static MenuControls* GetSingleton();

		// Borrowed handlers must outlive registration. Do not mutate during dispatch.
		[[nodiscard]] bool RegisterHandler(BSInputEventUser* a_handler);
		void               UnregisterHandler(BSInputEventUser* a_handler);

		[[nodiscard]] std::uint32_t GetHandlerCount() const noexcept { return handlers.size; }

		// Invalidated by registration, removal or teardown.
		[[nodiscard]] std::span<BSInputEventUser* const> GetHandlers() const noexcept
		{
			return { handlers.data, handlers.size };
		}

		// members
		HandlerStorage    handlers;                // 20
		BSInputEventUser* disconnectHandler{};     // 30
		BSInputEventUser* deviceChangeHandler{};   // 38
		BSInputEventUser* quickSaveLoadHandler{};  // 40
		BSInputEventUser* menuOpenHandler{};       // 48
		BSInputEventUser* unk50{};                 // 50
		BSInputEventUser* gpuCaptureHandler{};     // 58
		BSInputEventUser* cpuCaptureHandler{};     // 60
		BSInputEventUser* cameraZoomHandler{};     // 68
		std::byte         unk70[0x08]{};           // 70

	protected:
		MenuControls() = default;
		virtual ~MenuControls() = default;  // 00
	};
	static_assert(offsetof(MenuControls, handlers) == 0x20);
	static_assert(offsetof(MenuControls, disconnectHandler) == 0x30);
	static_assert(offsetof(MenuControls, cameraZoomHandler) == 0x68);
	static_assert(sizeof(MenuControls) == 0x78);
}
