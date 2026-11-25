#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	class BSScaleformManager :
		public BSTSingletonSDM<BSScaleformManager>  // 00
	{
	public:
		SF_RTTI_VTABLE(BSScaleformManager);

		[[nodiscard]] static BSScaleformManager* GetSingleton()
		{
			static REL::Relocation<BSScaleformManager**> singleton{ ID::BSScaleformManager::Singleton };
			return *singleton;
		}

		BSFixedStringW* Translate(BSFixedStringW* a_result, const wchar_t* a_key)
		{
			using func_t = BSFixedStringW* (*)(BSScaleformManager*, BSFixedStringW*, const wchar_t*);
			static REL::Relocation<func_t> func{ ID::BSScaleformManager::Translate };
			return func(this, a_result, a_key);
		}

		[[nodiscard]] BSFixedStringW Translate(const wchar_t* a_key)
		{
			BSFixedStringW result;
			Translate(std::addressof(result), a_key);
			return result;
		}
	};
}
