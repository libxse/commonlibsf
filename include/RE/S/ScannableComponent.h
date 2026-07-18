#pragma once

namespace RE
{
	class TESObjectREFR;

	// Runtime per-ref scannable component (hand scanner outline / scanned state).
	// Distinct from authored BGSScannableFormComponent on forms.
	//
	// Important: the scanned byte is TRANSIENT (empty save serializer; reset on materialize).
	// Callers must guard with GetOutlineState(ref) != 0 before SetScanned (null component faults).
	// Verified Starfield 1.16.236–1.16.244.
	namespace ScannableComponent
	{
		// Outline / presence: 0 = none/missing, 1 = unscanned (blue), 2 = scanned (green for most types).
		[[nodiscard]] inline char GetOutlineState(TESObjectREFR* a_ref)
		{
			using func_t = char (*)(TESObjectREFR*);
			static REL::Relocation<func_t> func{ ID::ScannableComponent::GetOutlineState };
			return func(a_ref);
		}

		// Writes the transient scanned state. a_category is the scanner category byte (engine path).
		inline void SetScanned(TESObjectREFR* a_ref, bool a_scanned, std::uint8_t a_category, std::uint8_t a_pad = 0)
		{
			using func_t = void (*)(TESObjectREFR*, std::uint8_t, std::uint8_t, std::uint8_t);
			static REL::Relocation<func_t> func{ ID::ScannableComponent::SetScanned };
			func(a_ref, a_scanned ? 1 : 0, a_category, a_pad);
		}

		// Canonical species id stamped into the component (+0x24), used by outline keying.
		[[nodiscard]] inline std::uint32_t GetCanonicalId(TESObjectREFR* a_ref)
		{
			using func_t = std::uint32_t (*)(TESObjectREFR*);
			static REL::Relocation<func_t> func{ ID::ScannableComponent::GetCanonicalId };
			return func(a_ref);
		}

		// Layout (runtime instance; partial — do not sizeof the whole component):
		inline constexpr std::size_t kCanonicalSpeciesIdOff = 0x24;
		inline constexpr std::size_t kScannedByteOff = 0x28;
	}
}
