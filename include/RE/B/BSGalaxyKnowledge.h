#pragma once

#include "RE/B/BSTArray.h"

namespace RE
{
	// Galaxy knowledge DB accessors + PlayerKnowledge survey slot layout (1.16.236–1.16.244).
	// Durable per-planet scan/trait state lives in BSGalaxy::PlayerKnowledge components.
	namespace BSGalaxy
	{
		namespace KnowledgeManager
		{
			// Returns the knowledge-manager singleton. Knowledge DB pointer is at manager+0x8B0.
			[[nodiscard]] inline std::uintptr_t GetSingleton()
			{
				using func_t = std::uintptr_t (*)();
				static REL::Relocation<func_t> func{ ID::BSGalaxy::KnowledgeManager::GetSingleton };
				return func();
			}

			inline constexpr std::size_t kKnowledgeDbOffset = 0x8B0;

			[[nodiscard]] inline std::uintptr_t GetKnowledgeDB()
			{
				const auto manager = GetSingleton();
				if (!manager) {
					return 0;
				}
				return *reinterpret_cast<std::uintptr_t*>(manager + kKnowledgeDbOffset);
			}
		}

		namespace PlayerKnowledge
		{
			// BSTHashMap of knowledge entries starts at this offset within the knowledge DB object.
			inline constexpr std::size_t kMapOffset = 0x268;
			// Secondary planet-overlay map (documented for callers; not all paths use it).
			inline constexpr std::size_t kPlanetOverlayMapOffset = 0x300;

			// Lookup miss sentinel: out[3] == kLookupNotFound && out[2] == 0.
			inline constexpr std::uintptr_t kLookupNotFound = 0xfe0;

			// Key: (disc << 48) | (planetFormId << 16). disc is *DiscriminatorId.
			[[nodiscard]] inline std::uint64_t MakeKey(std::uint16_t a_disc, std::uint32_t a_planetFormId) noexcept
			{
				return (static_cast<std::uint64_t>(a_disc) << 48) |
				       (static_cast<std::uint64_t>(a_planetFormId) << 16);
			}

			[[nodiscard]] inline std::uint16_t GetDiscriminator()
			{
				static REL::Relocation<std::uint16_t*> disc{ ID::BSGalaxy::PlayerKnowledge::DiscriminatorId };
				return disc.get() ? *disc : 0;
			}

			// Knowledge DB hashmap lookup (ID_126806). out layout on success: out[2]=entry base, out[3]=index.
			inline void* Lookup(std::uintptr_t a_container, std::uintptr_t a_out[4], const std::uint64_t* a_key)
			{
				using func_t = void* (*)(std::uintptr_t*, std::uintptr_t[4], const std::uint64_t*);
				static REL::Relocation<func_t> func{ ID::BSComponentDB2::Lookup };
				return func(reinterpret_cast<std::uintptr_t*>(a_container), a_out, a_key);
			}

			// Species-slot writers (operate on the per-planet survey subobject).
			inline void SetScanFlag(void* a_subobj, std::uint32_t a_speciesId, std::uint8_t a_delta, std::uint64_t a_zero = 0)
			{
				using func_t = void (*)(void*, std::uint32_t, std::uint8_t, std::uint64_t);
				static REL::Relocation<func_t> func{ ID::BSGalaxy::PlayerKnowledge::SetScanFlag };
				func(a_subobj, a_speciesId, a_delta, a_zero);
			}

			inline void SetScanPercent(void* a_subobj, std::uint32_t a_speciesId, std::uint8_t a_percent, std::uint64_t a_zero = 0)
			{
				using func_t = void (*)(void*, std::uint32_t, std::uint8_t, std::uint64_t);
				static REL::Relocation<func_t> func{ ID::BSGalaxy::PlayerKnowledge::SetScanPercent };
				func(a_subobj, a_speciesId, a_percent, a_zero);
			}

			[[nodiscard]] inline std::uint64_t HashSpeciesSlot(std::uintptr_t a_hashmap, const void* a_key4)
			{
				using func_t = std::uint64_t (*)(std::uintptr_t, const void*);
				static REL::Relocation<func_t> func{ ID::BSGalaxy::PlayerKnowledge::HashSpeciesSlot };
				return func(a_hashmap, a_key4);
			}

			inline void MarkTraitKnown(std::uint32_t a_planetId, std::uintptr_t a_keyword, bool a_known = true)
			{
				using func_t = void (*)(std::uint32_t, std::uintptr_t, bool);
				static REL::Relocation<func_t> func{ ID::BSGalaxy::PlayerKnowledge::MarkTraitKnown };
				func(a_planetId, a_keyword, a_known);
			}

			// Layout: entry + 0x20 = survey subobject base.
			inline constexpr std::size_t kEntrySubobjOffset = 0x20;
			inline constexpr std::size_t kBucketOffsetTable = 0x12;  // u16[] within bucket base

			// Subobj offsets (species key hashmap / slots). Attribute bitmask is u32 at subobj+0x00.
			inline constexpr std::size_t kSpeciesHashmapOff = 0x18;
			inline constexpr std::size_t kSpeciesSlotsPtrOff = 0x40;
			inline constexpr std::size_t kSpeciesHashEndOff = 0x48;
			inline constexpr std::size_t kSpeciesSlotStride = 0x30;
			inline constexpr std::uint32_t kAttributeKnownBitsMask = 0x7u;  // bits 0..2

			// Per-species slot (stride 0x30). Marker FormIDs live in BSTArray-like begin/end/cap at +0x08.
			struct SpeciesScanSlot
			{
				std::byte      pad00[0x08];  // 00
				std::uint32_t* arrBegin;     // 08
				std::uint32_t* arrEnd;       // 10
				std::uint32_t* arrCap;       // 18
				std::uint8_t   percent;      // 20 — UI/secondary categories
				std::uint8_t   scanFlag;     // 21 — GetSurveyPercent counts this
				std::uint8_t   pad22[0x0E];  // 22
			};
			static_assert(offsetof(SpeciesScanSlot, arrBegin) == 0x08);
			static_assert(offsetof(SpeciesScanSlot, percent) == 0x20);
			static_assert(offsetof(SpeciesScanSlot, scanFlag) == 0x21);
			static_assert(sizeof(SpeciesScanSlot) == 0x30);
		}
	}
}
