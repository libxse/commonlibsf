#pragma once

namespace RE
{
	class TESObjectREFR;

	class ScannableComponent
	{
	public:
		// members
		std::byte     pad00[0x24];         // 00
		std::uint32_t canonicalSpeciesId;  // 24
		std::uint8_t  scanned;             // 28
		std::uint8_t  pad29[0x03];         // 29

		[[nodiscard]] static char GetOutlineState(TESObjectREFR* a_ref)
		{
			using func_t = char (*)(TESObjectREFR*);
			static REL::Relocation<func_t> func{ ID::ScannableComponent::GetOutlineState };
			return func(a_ref);
		}

		static void SetScanned(TESObjectREFR* a_ref, bool a_scanned, std::uint8_t a_category, std::uint8_t a_pad = 0)
		{
			using func_t = void (*)(TESObjectREFR*, std::uint8_t, std::uint8_t, std::uint8_t);
			static REL::Relocation<func_t> func{ ID::ScannableComponent::SetScanned };
			func(a_ref, a_scanned ? 1 : 0, a_category, a_pad);
		}

		[[nodiscard]] static std::uint32_t GetCanonicalId(TESObjectREFR* a_ref)
		{
			using func_t = std::uint32_t (*)(TESObjectREFR*);
			static REL::Relocation<func_t> func{ ID::ScannableComponent::GetCanonicalId };
			return func(a_ref);
		}

		[[nodiscard]] static std::uintptr_t ResolveCanonicalForm(void* a_form)
		{
			using func_t = std::uintptr_t (*)(void*);
			static REL::Relocation<func_t> func{ ID::ScannableComponent::ResolveCanonicalForm };
			return func(a_form);
		}
	};
	static_assert(offsetof(ScannableComponent, canonicalSpeciesId) == 0x24);
	static_assert(offsetof(ScannableComponent, scanned) == 0x28);
}
