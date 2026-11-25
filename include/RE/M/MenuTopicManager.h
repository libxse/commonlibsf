#pragma once

#include "RE/B/BSTEvent.h"
#include "RE/B/BSTSingleton.h"

namespace RE
{
	struct MenuOpenCloseEvent;
	struct PositionPlayerEvent;

	class MenuTopicManager :
		public BSTSingletonSDM<MenuTopicManager>,  // 00
		public BSTEventSink<MenuOpenCloseEvent>,   // 10
		public BSTEventSink<PositionPlayerEvent>   // 18
	{
	public:
		[[nodiscard]] static MenuTopicManager* GetSingleton()
		{
			static REL::Relocation<MenuTopicManager**> singleton{ ID::MenuTopicManager::Singleton };
			return *singleton;
		}

		// members
		BSPointerHandle<TESObjectREFR> speaker;  // 20
	};
}
