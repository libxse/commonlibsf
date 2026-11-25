#pragma once

#include "RE/B/BSLock.h"
#include "RE/U/UserEvents.h"

namespace RE
{
	class BSInputEnableLayer;

	class BSInputEnableManager
	{
	public:
		struct IDebugNameFunctor
		{
			virtual ~IDebugNameFunctor() = default;

			virtual void operator()(BSFixedString& a_name) = 0;
		};

		template <class T>
		struct DebugNameFunctor : IDebugNameFunctor
		{
			DebugNameFunctor(const T a_functor) :
				m_functor(a_functor)
			{}

			virtual void operator()(BSFixedString& a_name) override
			{
				m_functor(a_name);
			}

		private:
			const T m_functor;
		};

		virtual ~BSInputEnableManager() = 0;

		static BSInputEnableManager* GetSingleton()
		{
			static REL::Relocation<BSInputEnableManager**> singleton{ ID::BSInputEnableManager::Singleton };
			return *singleton;
		}

		inline bool AllocateNewLayerImpl(BSInputEnableLayer** a_layer, IDebugNameFunctor* a_debugName)
		{
			using func_t = decltype(&BSInputEnableManager::AllocateNewLayerImpl);
			static REL::Relocation<func_t> func{ ID::BSInputEnableManager::AllocateNewLayerImpl };
			return func(this, a_layer, a_debugName);
		}

		inline bool AllocateNewLayer(BSInputEnableLayer** a_layer, const char* a_debugName)
		{
			DebugNameFunctor functor([a_debugName](BSFixedString& a_name) {
				BSFixedString name{ a_debugName };
				a_name = name;
			});

			return AllocateNewLayerImpl(a_layer, &functor);
		}

		inline static void EnableUserEvent(std::uint32_t* a_layer, USER_EVENT_FLAG a_flags, bool a_enable, USER_EVENT_SENDER_ID a_sender = USER_EVENT_SENDER_ID::None)
		{
			using func_t = decltype(&BSInputEnableManager::EnableUserEvent);
			static REL::Relocation<func_t> func{ ID::BSInputEnableManager::EnableUserEvent };
			func(a_layer, a_flags, a_enable, a_sender);
		}

		inline static void EnableOtherEvent(std::uint32_t* a_layer, OTHER_EVENT_FLAG a_flags, bool a_enable, USER_EVENT_SENDER_ID a_sender = USER_EVENT_SENDER_ID::None)
		{
			using func_t = decltype(&BSInputEnableManager::EnableOtherEvent);
			static REL::Relocation<func_t> func{ ID::BSInputEnableManager::EnableOtherEvent };
			func(a_layer, a_flags, a_enable, a_sender);
		}

		inline void ForceUserEventEnabled(USER_EVENT_FLAG a_flags, bool a_enabled)
		{
			BSAutoLock _(m_cacheLock);
			if (a_enabled)
				m_forcedUserEventFlags |= a_flags;
			else
				m_forcedUserEventFlags &= ~a_flags;
		}

		inline void ForceOtherEventEnabled(OTHER_EVENT_FLAG a_flags, bool a_enabled)
		{
			BSAutoLock _(m_cacheLock);
			if (a_enabled)
				m_forcedOtherEventFlags |= a_flags;
			else
				m_forcedOtherEventFlags &= ~a_flags;
		}

		// members
		std::byte        m_pad008[0x080];          // 0x008
		BSSpinLock       m_cacheLock;              // 0x088
		USER_EVENT_FLAG  m_cachedUserEventFlags;   // 0x090
		OTHER_EVENT_FLAG m_cachedOtherEventFlags;  // 0x094
		USER_EVENT_FLAG  m_forcedUserEventFlags;   // 0x098
		OTHER_EVENT_FLAG m_forcedOtherEventFlags;  // 0x09C
		BSSpinLock       m_layerLock;              // 0x0A0
												   // TODO: more members
	};
	static_assert(offsetof(BSInputEnableManager, m_cacheLock) == 0x088);
}
