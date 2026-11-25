#pragma once

#include "RE/B/BGSMod.h"
#include "RE/B/BSTArray.h"
#include "RE/B/BaseFormComponent.h"

namespace RE
{
	enum class QualityUpgradeKind
	{
		kEmpty,
		kEncodedFormID,
		kResolvedMod,
	};

	// AUQ1 stores 32-bit OMOD form IDs. Each 8-byte slot is one of:
	// - 0
	// - an encoded FormID: (formID << 1) | 1
	// - or, after validation/resolution, a BGSMod::Attachment::Mod*
	// I believe somehow part of BSComponentDB2, but the component's not stored inline on the form, so it's not a simple array of these on the form.
	class QualityUpgradeDetail
	{
	public:
		using value_type = std::uint64_t;

		[[nodiscard]] static constexpr value_type EncodeFormID(std::uint32_t a_formID) noexcept
		{
			return (static_cast<value_type>(a_formID) << 1) | 1;
		}

		[[nodiscard]] QualityUpgradeKind GetKind() const noexcept
		{
			if (raw == 0) {
				return QualityUpgradeKind::kEmpty;
			}
			return (raw & 1) != 0 ? QualityUpgradeKind::kEncodedFormID : QualityUpgradeKind::kResolvedMod;
		}

		[[nodiscard]] bool IsEmpty() const noexcept { return GetKind() == QualityUpgradeKind::kEmpty; }
		[[nodiscard]] bool IsEncoded() const noexcept { return GetKind() == QualityUpgradeKind::kEncodedFormID; }
		[[nodiscard]] bool IsResolved() const noexcept { return GetKind() == QualityUpgradeKind::kResolvedMod; }

		[[nodiscard]] std::uint32_t AsFormID() const noexcept
		{
			return IsEncoded() ? static_cast<std::uint32_t>(raw >> 1) : 0;
		}

		[[nodiscard]] BGSMod::Attachment::Mod* AsMod() const noexcept
		{
			return IsResolved() ? reinterpret_cast<BGSMod::Attachment::Mod*>(raw) : nullptr;
		}

		value_type raw{ 0 };  // 00
	};
	static_assert(sizeof(QualityUpgradeDetail) == 0x8);

	class BGSQualityUpgradeFormComponent : public BaseFormComponent
	{
	public:
		using BGSQualityUpgrade_Type = QualityUpgradeDetail::value_type;
		SF_RTTI_VTABLE(BGSQualityUpgradeFormComponent);

		[[nodiscard]] QualityUpgradeDetail GetEntry(std::size_t a_index) const noexcept
		{
			using size_type = BSTArray<BGSQualityUpgrade_Type>::size_type;
			return a_index < qualityUpgrades.size() ?
			           QualityUpgradeDetail{ qualityUpgrades[static_cast<size_type>(a_index)] } :
			           QualityUpgradeDetail{};
		}

		[[nodiscard]] BGSMod::Attachment::Mod* GetQualityUpgrade(std::size_t a_index) const noexcept
		{
			return GetEntry(a_index).AsMod();
		}

		// The engine-owned BSFixedString key used by the component registry.
		// Backed by BGSQualityUpgradeFormComponent_GetFormComponentType at RVA
		[[nodiscard]] static const BSFixedString& GetComponentTypeName()
		{
			using func_t = const BSFixedString& (*)();
			static REL::Relocation<func_t> func{ RE::ID::BGSQualityUpgradeFormComponent::GetComponentTypeName };
			return func();
		}

		// The component is not stored inline on the form — it lives in BSComponentDB2.
		// The game helper returns a {component, dbRecord} pair via a hidden out-pointer.
		// Returns nullptr if the form has no quality-upgrade component.
		[[nodiscard]] static BGSQualityUpgradeFormComponent* LookupFor(const TESForm* a_form)
		{
			if (!a_form) {
				return nullptr;
			}
			using func_t = void (*)(const TESForm*, void**, std::uint32_t, const BSFixedString*);
			static REL::Relocation<func_t> func{ RE::ID::FormComponentLookup::GetForForm };
			void*                          out[2]{};
			func(a_form, out, 6, &GetComponentTypeName());
			return static_cast<BGSQualityUpgradeFormComponent*>(out[0]);
		}

		// members
		BSTArray<BGSQualityUpgrade_Type> qualityUpgrades;  // 08
	};
	static_assert(sizeof(BGSQualityUpgradeFormComponent::BGSQualityUpgrade_Type) == 0x8);
	static_assert(sizeof(BSTArray<BGSQualityUpgradeFormComponent::BGSQualityUpgrade_Type>) == 0x10);
	static_assert(offsetof(BGSQualityUpgradeFormComponent, qualityUpgrades) == 0x08);
	static_assert(offsetof(BGSQualityUpgradeFormComponent, qualityUpgrades) == sizeof(BaseFormComponent));
	static_assert(sizeof(BGSQualityUpgradeFormComponent) == 0x18);
}
