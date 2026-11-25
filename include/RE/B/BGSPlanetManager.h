#pragma once

#include "RE/B/BSTSingleton.h"

namespace RE
{
	class TESObjectREFR;

	namespace BGSPlanet
	{
		inline constexpr std::size_t kSurveyNotifyReasonOffset = 0x08;

		enum class SurveyChangeReason : std::uint8_t
		{
			kScanLevelChanged = 0x0C,
		};

		class Manager :
			public BSTSingletonSDM<Manager>  // 00
		{
		public:
			SF_RTTI_VTABLE(BGSPlanet__Manager);

			[[nodiscard]] static Manager* GetSingleton()
			{
				static REL::Relocation<Manager**> singleton{ ID::BGSPlanet::Manager::Singleton };
				return *singleton;
			}

			void SetCurrentPlanet(std::uint32_t a_planetFormId)
			{
				using func_t = decltype(&Manager::SetCurrentPlanet);
				static REL::Relocation<func_t> func{ ID::BGSPlanet::Manager::SetCurrentPlanet };
				return func(this, a_planetFormId);
			}

			// members
			std::byte     pad10[0x70];          // 10
			std::uint32_t currentPlanetFormId;  // 80
		};
		static_assert(offsetof(Manager, currentPlanetFormId) == 0x80);

		inline std::uint64_t ResolvePlanetFromRef(
			TESObjectREFR* a_ref,
			std::int32_t*  a_outPlanet,
			std::int32_t*  a_outSecondary = nullptr)
		{
			using func_t = std::uint64_t (*)(TESObjectREFR*, std::int32_t*, std::int32_t*);
			static REL::Relocation<func_t> func{ ID::BGSPlanet::ResolvePlanetFromRef };
			std::int32_t                   secondary = 0;
			return func(a_ref, a_outPlanet, a_outSecondary ? a_outSecondary : &secondary);
		}
	}
}
