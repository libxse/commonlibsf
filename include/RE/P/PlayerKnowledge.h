#pragma once

namespace RE
{
	namespace BSGalaxy
	{
		[[nodiscard]] inline std::uintptr_t GetKnowledgeManager()
		{
			using func_t = std::uintptr_t (*)();
			static REL::Relocation<func_t> func{ ID::BSGalaxy::GetKnowledgeManager };
			return func();
		}

		inline constexpr std::size_t kKnowledgeDbOffset = 0x8B0;

		[[nodiscard]] inline std::uintptr_t GetKnowledgeDB()
		{
			const auto manager = GetKnowledgeManager();
			if (!manager) {
				return 0;
			}
			return *reinterpret_cast<std::uintptr_t*>(manager + kKnowledgeDbOffset);
		}

		class PlayerKnowledge
		{
		public:
			static constexpr std::size_t    kPlanetFormKnowledgeIdOffset = 0x54;
			static constexpr std::size_t    kMapOffset = 0x268;
			static constexpr std::size_t    kPlanetOverlayMapOffset = 0x300;
			static constexpr std::uintptr_t kLookupNotFound = 0xfe0;
			static constexpr std::size_t    kEntrySubobjOffset = 0x20;
			static constexpr std::size_t    kBucketOffsetTable = 0x12;
			static constexpr std::size_t    kSpeciesHashmapOff = 0x18;
			static constexpr std::size_t    kSpeciesSlotsPtrOff = 0x40;
			static constexpr std::size_t    kSpeciesHashEndOff = 0x48;
			static constexpr std::size_t    kSpeciesSlotStride = 0x30;
			static constexpr std::uint32_t  kAttributeKnownBitsMask = 0x7u;

			struct SpeciesSlot
			{
				std::byte      pad00[0x08];  // 00
				std::uint32_t* arrBegin;     // 08
				std::uint32_t* arrEnd;       // 10
				std::uint32_t* arrCap;       // 18
				std::uint8_t   percent;      // 20
				std::uint8_t   scanFlag;     // 21
				std::uint8_t   pad22[0x0E];  // 22
			};
			static_assert(offsetof(SpeciesSlot, arrBegin) == 0x08);
			static_assert(offsetof(SpeciesSlot, percent) == 0x20);
			static_assert(offsetof(SpeciesSlot, scanFlag) == 0x21);
			static_assert(sizeof(SpeciesSlot) == 0x30);

			[[nodiscard]] static std::uint64_t MakeKey(std::uint16_t a_disc, std::uint32_t a_planetKnowledgeId) noexcept
			{
				return (static_cast<std::uint64_t>(a_disc) << 48) |
				       (static_cast<std::uint64_t>(a_planetKnowledgeId) << 16);
			}

			[[nodiscard]] static std::uint16_t GetDiscriminator()
			{
				static REL::Relocation<std::uint16_t*> disc{ ID::BSGalaxy::PlayerKnowledge::DiscriminatorId };
				return disc.get() ? *disc : 0;
			}

			static void SetScanFlag(void* a_subobj, std::uint32_t a_speciesId, std::uint8_t a_delta, std::uint64_t a_zero = 0)
			{
				using func_t = void (*)(void*, std::uint32_t, std::uint8_t, std::uint64_t);
				static REL::Relocation<func_t> func{ ID::BSGalaxy::PlayerKnowledge::SetScanFlag };
				func(a_subobj, a_speciesId, a_delta, a_zero);
			}

			static void SetScanPercent(void* a_subobj, std::uint32_t a_speciesId, std::uint8_t a_percent, std::uint64_t a_zero = 0)
			{
				using func_t = void (*)(void*, std::uint32_t, std::uint8_t, std::uint64_t);
				static REL::Relocation<func_t> func{ ID::BSGalaxy::PlayerKnowledge::SetScanPercent };
				func(a_subobj, a_speciesId, a_percent, a_zero);
			}

			[[nodiscard]] static std::uint64_t HashSpeciesSlot(std::uintptr_t a_hashmap, const void* a_key4)
			{
				using func_t = std::uint64_t (*)(std::uintptr_t, const void*);
				static REL::Relocation<func_t> func{ ID::BSGalaxy::PlayerKnowledge::HashSpeciesSlot };
				return func(a_hashmap, a_key4);
			}

			static void MarkTraitKnown(std::uint32_t a_planetId, std::uintptr_t a_keyword, bool a_known = true)
			{
				using func_t = void (*)(std::uint32_t, std::uintptr_t, bool);
				static REL::Relocation<func_t> func{ ID::BSGalaxy::PlayerKnowledge::MarkTraitKnown };
				func(a_planetId, a_keyword, a_known);
			}
		};
	}
}
