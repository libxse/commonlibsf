#pragma once

#include "REX/W32/D3D12.h"
#include "REX/W32/DXGI.h"
#include "REX/W32/DXGI_2.h"

namespace RE::CreationRendererPrivate
{
	struct DeviceProperties;

	namespace detail
	{
		struct QueueOwnerA;
		struct QueueOwnerB;
	}

	// No RTTI - names from engine assert strings, not RTTI. accessor over g_RendererRoot;
	class Renderer
	{
	public:
		[[nodiscard]] static Renderer* GetSingleton()
		{
			static REL::Relocation<Renderer**> singleton{ ID::CreationRendererPrivate::Renderer::Singleton };
			return *singleton;
		}

		[[nodiscard]] REX::W32::ID3D12Device* GetDevice() const;

		[[nodiscard]] REX::W32::ID3D12CommandQueue* GetGraphicsQueue() const;

		[[nodiscard]] REX::W32::IDXGIFactory2* GetDXGIFactory() const;
		[[nodiscard]] REX::W32::IDXGIAdapter*  GetAdapter() const;

		// members
		std::byte            pad00[0x28];       // 00
		detail::QueueOwnerA* queueOwnerA;       // 28
		DeviceProperties*    deviceProperties;  // 30 (arDeviceProperties)
	};
	static_assert(offsetof(Renderer, queueOwnerA) == 0x28);
	static_assert(offsetof(Renderer, deviceProperties) == 0x30);

	struct DeviceProperties
	{
		std::byte                pad000[0x408];  // 000
		REX::W32::IDXGIFactory2* dxgiFactory;    // 408 (pDXGIFactory)
		REX::W32::IDXGIAdapter*  dxActiveGPU;    // 410 (pDxActiveGPU)
		REX::W32::ID3D12Device*  dxDevice;       // 418 (pDxDevice)
	};
	static_assert(offsetof(DeviceProperties, dxgiFactory) == 0x408);
	static_assert(offsetof(DeviceProperties, dxActiveGPU) == 0x410);
	static_assert(offsetof(DeviceProperties, dxDevice) == 0x418);

	namespace detail
	{
		struct QueueOwnerA
		{
			std::byte    pad00[0x08];  // 00
			QueueOwnerB* inner;        // 08
		};
		static_assert(offsetof(QueueOwnerA, inner) == 0x08);

		struct QueueOwnerB
		{
			std::byte                     pad00[0x60];    // 00
			REX::W32::ID3D12CommandQueue* graphicsQueue;  // 60 (pgraphicsQueue)
		};
		static_assert(offsetof(QueueOwnerB, graphicsQueue) == 0x60);
	}

	inline REX::W32::ID3D12Device* Renderer::GetDevice() const
	{
		return deviceProperties ? deviceProperties->dxDevice : nullptr;
	}

	inline REX::W32::ID3D12CommandQueue* Renderer::GetGraphicsQueue() const
	{
		if (!queueOwnerA || !queueOwnerA->inner) {
			return nullptr;
		}
		return queueOwnerA->inner->graphicsQueue;
	}

	inline REX::W32::IDXGIFactory2* Renderer::GetDXGIFactory() const
	{
		return deviceProperties ? deviceProperties->dxgiFactory : nullptr;
	}

	inline REX::W32::IDXGIAdapter* Renderer::GetAdapter() const
	{
		return deviceProperties ? deviceProperties->dxActiveGPU : nullptr;
	}
}
