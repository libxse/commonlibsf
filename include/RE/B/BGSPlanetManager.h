#pragma once

namespace RE
{
	class TESObjectREFR;

	namespace BGSPlanet
	{
		// Runtime planet manager (stamps the active planet FormID for scan/render domains).
		// Verified Starfield 1.16.236–1.16.244. Layout is partial; only +0x80 is asserted.
		class Manager
		{
		public:
			SF_RTTI_VTABLE(BGSPlanet__Manager);

			[[nodiscard]] static Manager* GetSingleton()
			{
				static REL::Relocation<Manager**> singleton{ ID::BGSPlanet::Manager::Singleton };
				return *singleton;
			}

			// Writes the current planet FormID at +0x80 (engine: MOV [RCX+0x80], EDX).
			void SetCurrentPlanet(std::uint32_t a_planetFormId)
			{
				using func_t = decltype(&Manager::SetCurrentPlanet);
				static REL::Relocation<func_t> func{ ID::BGSPlanet::Manager::SetCurrentPlanet };
				return func(this, a_planetFormId);
			}

			// members (partial)
			std::byte     unk00[0x80];          // 00
			std::uint32_t currentPlanetFormId;  // 80
		};
		static_assert(offsetof(Manager, currentPlanetFormId) == 0x80);

		// Resolves the planet domain id used by monocle/survey readers from a reference.
		// Engine writes into out params. Prefer over raw form+0x54 when matching scanner UI keys.
		inline std::uint64_t ResolvePlanetFromRef(
			TESObjectREFR* a_ref,
			std::int32_t*  a_outPlanet,
			std::int32_t*  a_outSecondary = nullptr)
		{
			using func_t = std::uint64_t (*)(TESObjectREFR*, std::int32_t*, std::int32_t*);
			static REL::Relocation<func_t> func{ ID::BGSPlanet::Manager::ResolvePlanetFromRef };
			std::int32_t                  secondary = 0;
			return func(a_ref, a_outPlanet, a_outSecondary ? a_outSecondary : &secondary);
		}
	}
}
