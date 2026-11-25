#pragma once

#include "RE/B/BSCoreTypes.h"
#include "RE/B/BSFixedString.h"
#include "RE/B/BSPointerHandle.h"
#include "RE/B/BSTEvent.h"
#include "RE/N/NiSmartPointer.h"

namespace RE
{
	class Actor;
	class BGSAttackData;
	class BGSLocation;
	class bhkNPCollisionObject;
	class HUDModeType;
	class SpellItem;
	class TESBoundObject;
	class TESObjectBOOK;
	class TESObjectCELL;
	class TESObjectMISC;
	class TESObjectREFR;

	enum class ACTOR_COMBAT_STATE : std::int32_t;

	struct Activation
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<Activation::Event>* GetEventSource()
			{
				using func_t = decltype(&Activation::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Activation::Event::GetEventSource };
				return func();
			}

			// members
			NiPointer<Actor>         source;  // 00
			NiPointer<TESObjectREFR> target;  // 08
		};
		static_assert(sizeof(Activation::Event) == 0x10);
	};

	struct ActivityEvents
	{
		struct ActivityCompletedEvent
		{
			[[nodiscard]] static BSTEventSource<ActivityEvents::ActivityCompletedEvent>* GetEventSource()
			{
				using func_t = decltype(&ActivityEvents::ActivityCompletedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::ActivityEvents::ActivityCompletedEvent::GetEventSource };
				return func();
			}
		};
	};

	struct ActorCellChangeEvent
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<ActorCellChangeEvent::Event>* GetEventSource()
			{
				using func_t = decltype(&ActorCellChangeEvent::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::ActorCellChangeEvent::Event::GetEventSource };
				return func();
			}

			// members
			NiPointer<Actor> actor;  // 00
			TESObjectCELL*   cellA;  // 08
			TESObjectCELL*   cellB;  // 10
		};
		static_assert(sizeof(ActorCellChangeEvent::Event) == 0x18);
	};

	struct ActorItemEquipped
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<ActorItemEquipped::Event>* GetEventSource()
			{
				using func_t = decltype(&ActorItemEquipped::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::ActorItemEquipped::Event::GetEventSource };
				return func();
			}

			// members
			TESBoundObject*  item;   // 00
			NiPointer<Actor> actor;  // 08
		};
		static_assert(sizeof(ActorItemEquipped::Event) == 0x10);
	};

	struct AttachReference
	{
		struct Event
		{
			[[nodiscard]] static auto GetEventSource()
			{
				static REL::Relocation<BSTEventSource<AttachReference::Event>*> ptr{ ID::AttachReference::Event::GetEventSource };
				return ptr.get();
			}

			// members
			NiPointer<TESObjectREFR> ref;  // 00
		};
	};

	struct AutoLoadDoorRolloverEvent
	{
		[[nodiscard]] static BSTEventSource<AutoLoadDoorRolloverEvent>* GetEventSource()
		{
			using func_t = decltype(&AutoLoadDoorRolloverEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::AutoLoadDoorRolloverEvent::GetEventSource };
			return func();
		}
	};

	struct BarterMenu_BuyItem
	{
		[[nodiscard]] static BSTEventSource<BarterMenu_BuyItem>* GetEventSource()
		{
			using func_t = decltype(&BarterMenu_BuyItem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::BarterMenu_BuyItem::GetEventSource };
			return func();
		}
	};

	struct BarterMenu_CloseMenu
	{
		[[nodiscard]] static BSTEventSource<BarterMenu_CloseMenu>* GetEventSource()
		{
			using func_t = decltype(&BarterMenu_CloseMenu::GetEventSource);
			static REL::Relocation<func_t> func{ ID::BarterMenu_CloseMenu::GetEventSource };
			return func();
		}
	};

	struct BarterMenu_HideModel
	{
		[[nodiscard]] static BSTEventSource<BarterMenu_HideModel>* GetEventSource()
		{
			using func_t = decltype(&BarterMenu_HideModel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::BarterMenu_HideModel::GetEventSource };
			return func();
		}
	};

	struct BarterMenu_LoadModel
	{
		[[nodiscard]] static BSTEventSource<BarterMenu_LoadModel>* GetEventSource()
		{
			using func_t = decltype(&BarterMenu_LoadModel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::BarterMenu_LoadModel::GetEventSource };
			return func();
		}
	};

	struct BarterMenu_SellItem
	{
		[[nodiscard]] static BSTEventSource<BarterMenu_SellItem>* GetEventSource()
		{
			using func_t = decltype(&BarterMenu_SellItem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::BarterMenu_SellItem::GetEventSource };
			return func();
		}
	};

	struct BarterMenu_SetMouseOverModel
	{
		[[nodiscard]] static BSTEventSource<BarterMenu_SetMouseOverModel>* GetEventSource()
		{
			using func_t = decltype(&BarterMenu_SetMouseOverModel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::BarterMenu_SetMouseOverModel::GetEventSource };
			return func();
		}
	};

	struct BarterMenu_ViewedItem
	{
		[[nodiscard]] static BSTEventSource<BarterMenu_ViewedItem>* GetEventSource()
		{
			using func_t = decltype(&BarterMenu_ViewedItem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::BarterMenu_ViewedItem::GetEventSource };
			return func();
		}
	};

	struct BGSAcousticSpaceListener
	{
		struct StackChangedEvent
		{
			[[nodiscard]] static BSTEventSource<BGSAcousticSpaceListener::StackChangedEvent>* GetEventSource()
			{
				using func_t = decltype(&BGSAcousticSpaceListener::StackChangedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::BGSAcousticSpaceListener::StackChangedEvent::GetEventSource };
				return func();
			}
		};
	};

	struct BGSActorEvent
	{
		// members
		BSPointerHandle<Actor> actor;  // 00
	};
	static_assert(sizeof(BGSActorEvent) == 0x4);

	struct BGSActorCellEvent :
		public BGSActorEvent
	{
		enum class Type : std::uint32_t
		{
			kEnter = 0,
			kLeave = 1
		};

		[[nodiscard]] auto GetCell() const { return TESForm::LookupByID<TESObjectCELL>(formID); }

		[[nodiscard]] constexpr bool IsEnter() const noexcept { return type == Type::kEnter; }
		[[nodiscard]] constexpr bool IsLeave() const noexcept { return type == Type::kLeave; }

		// members
		TESFormID formID;
		Type      type;
	};

	struct BGSAffinityEventEvent
	{
		[[nodiscard]] static BSTEventSource<BGSAffinityEventEvent>* GetEventSource()
		{
			using func_t = decltype(&BGSAffinityEventEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::BGSAffinityEventEvent::GetEventSource };
			return func();
		}
	};

	struct BGSAppPausedEvent
	{
		[[nodiscard]] static BSTEventSource<BGSAppPausedEvent>* GetEventSource()
		{
			using func_t = decltype(&BGSAppPausedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::BGSAppPausedEvent::GetEventSource };
			return func();
		}

		// members
		bool paused;  // 00
	};
	static_assert(sizeof(BGSAppPausedEvent) == 0x1);

	struct BGSCellGridLoadEvent
	{
		[[nodiscard]] static BSTEventSource<BGSCellGridLoadEvent>* GetEventSource()
		{
			using func_t = decltype(&BGSCellGridLoadEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::BGSCellGridLoadEvent::GetEventSource };
			return func();
		}
	};

	namespace BGSPlanet
	{
		struct PlayerKnowledgeFlagSetEvent
		{
			[[nodiscard]] static BSTEventSource<BGSPlanet::PlayerKnowledgeFlagSetEvent>* GetEventSource()
			{
				using func_t = decltype(&BGSPlanet::PlayerKnowledgeFlagSetEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::BGSPlanet::PlayerKnowledgeFlagSetEvent::GetEventSource };
				return func();
			}
		};
	};

	struct BGSRadiationDamageEvent
	{
		[[nodiscard]] static BSTEventSource<BGSRadiationDamageEvent>* GetEventSource()
		{
			using func_t = decltype(&BGSRadiationDamageEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::BGSRadiationDamageEvent::GetEventSource };
			return func();
		}
	};

	struct BGSScannerGuideEffectStatusUpdateEvent
	{
		[[nodiscard]] static BSTEventSource<BGSScannerGuideEffectStatusUpdateEvent>* GetEventSource()
		{
			using func_t = decltype(&BGSScannerGuideEffectStatusUpdateEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::BGSScannerGuideEffectStatusUpdateEvent::GetEventSource };
			return func();
		}
	};

	struct BGSSceneActionPlayerDialogue
	{
		struct ActionEndEvent
		{
			[[nodiscard]] static BSTEventSource<BGSSceneActionPlayerDialogue::ActionEndEvent>* GetEventSource()
			{
				using func_t = decltype(&BGSSceneActionPlayerDialogue::ActionEndEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::BGSSceneActionPlayerDialogue::ActionEndEvent::GetEventSource };
				return func();
			}
		};
	};

	struct BinkMovieStoppedPlayingEvent
	{
		[[nodiscard]] static BSTEventSource<BinkMovieStoppedPlayingEvent>* GetEventSource()
		{
			using func_t = decltype(&BinkMovieStoppedPlayingEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::BinkMovieStoppedPlayingEvent::GetEventSource };
			return func();
		}
	};

	struct BooksRead
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<BooksRead::Event>* GetEventSource()
			{
				using func_t = decltype(&BooksRead::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::BooksRead::Event::GetEventSource };
				return func();
			}

			// members
			TESObjectBOOK* book;     // 00
			bool           hasAV;    // 08
			bool           hasPerk;  // 09
		};
		static_assert(sizeof(BooksRead::Event) == 0x10);
	};

	struct Bounty
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<Bounty::Event>* GetEventSource()
			{
				using func_t = decltype(&Bounty::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Bounty::Event::GetEventSource };
				return func();
			}

			// members
			TESFaction*  faction;    // 00
			std::int32_t bounty;     // 08
			std::int32_t oldBounty;  // 0C
		};
		static_assert(sizeof(Bounty::Event) == 0x10);
	};

	struct BSChargenAPI
	{
		struct BIDataUtils
		{
			struct PresetNPCChangedEvent
			{
				[[nodiscard]] static BSTEventSource<BSChargenAPI::BIDataUtils::PresetNPCChangedEvent>* GetEventSource()
				{
					using func_t = decltype(&BSChargenAPI::BIDataUtils::PresetNPCChangedEvent::GetEventSource);
					static REL::Relocation<func_t> func{ ID::BSChargenAPI::BIDataUtils::PresetNPCChangedEvent::GetEventSource };
					return func();
				}
			};
		};
	};

	struct CellAttachDetachEvent
	{
		enum class Type : std::int32_t
		{
			kPreAttach,
			kPostAttach,
			kPreDetach,
			kPostDetach
		};

		[[nodiscard]] static BSTEventSource<CellAttachDetachEvent>* GetEventSource()
		{
			using func_t = decltype(&CellAttachDetachEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CellAttachDetachEvent::GetEventSource };
			return func();
		}

		// members
		TESObjectCELL* cell;  // 00
		Type           type;  // 08
	};
	static_assert(sizeof(CellAttachDetachEvent) == 0x10);

	struct ChallengeCompletedEvent
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<ChallengeCompletedEvent::Event>* GetEventSource()
			{
				using func_t = decltype(&ChallengeCompletedEvent::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::ChallengeCompletedEvent::Event::GetEventSource };
				return func();
			}
		};
	};

	struct CharGen_BrowChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_BrowChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_BrowChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_BrowChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_BrowColorChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_BrowColorChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_BrowColorChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_BrowColorChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_CancelTextEntry
	{
		[[nodiscard]] static BSTEventSource<CharGen_CancelTextEntry>* GetEventSource()
		{
			using func_t = decltype(&CharGen_CancelTextEntry::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_CancelTextEntry::GetEventSource };
			return func();
		}
	};

	struct CharGen_CloseMenu
	{
		[[nodiscard]] static BSTEventSource<CharGen_CloseMenu>* GetEventSource()
		{
			using func_t = decltype(&CharGen_CloseMenu::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_CloseMenu::GetEventSource };
			return func();
		}
	};

	struct CharGen_CyclePronoun
	{
		[[nodiscard]] static BSTEventSource<CharGen_CyclePronoun>* GetEventSource()
		{
			using func_t = decltype(&CharGen_CyclePronoun::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_CyclePronoun::GetEventSource };
			return func();
		}
	};

	struct CharGen_DirtScarsEtcChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_DirtScarsEtcChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_DirtScarsEtcChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_DirtScarsEtcChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_EndBodyChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_EndBodyChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_EndBodyChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_EndBodyChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_EndTextEntry
	{
		[[nodiscard]] static BSTEventSource<CharGen_EndTextEntry>* GetEventSource()
		{
			using func_t = decltype(&CharGen_EndTextEntry::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_EndTextEntry::GetEventSource };
			return func();
		}
	};

	struct CharGen_EyeColorChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_EyeColorChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_EyeColorChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_EyeColorChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_FacialHairChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_FacialHairChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_FacialHairChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_FacialHairChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_FacialHairColorChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_FacialHairColorChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_FacialHairColorChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_FacialHairColorChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_HairChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_HairChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_HairChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_HairChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_HairColorChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_HairColorChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_HairColorChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_HairColorChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_HeadpartPlusSelectorChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_HeadpartPlusSelectorChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_HeadpartPlusSelectorChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_HeadpartPlusSelectorChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_HeadpartPresetChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_HeadpartPresetChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_HeadpartPresetChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_HeadpartPresetChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_JewelryChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_JewelryChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_JewelryChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_JewelryChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_JewelryColorChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_JewelryColorChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_JewelryColorChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_JewelryColorChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_MakeupChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_MakeupChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_MakeupChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_MakeupChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_MarkingsChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_MarkingsChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_MarkingsChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_MarkingsChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_PostBlendColorOptionChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_PostBlendColorOptionChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_PostBlendColorOptionChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_PostBlendColorOptionChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_PostBlendFaceChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_PostBlendFaceChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_PostBlendFaceChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_PostBlendFaceChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_PostBlendIntensityChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_PostBlendIntensityChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_PostBlendIntensityChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_PostBlendIntensityChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_PresetChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_PresetChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_PresetChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_PresetChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_RollOffLocomotion
	{
		[[nodiscard]] static BSTEventSource<CharGen_RollOffLocomotion>* GetEventSource()
		{
			using func_t = decltype(&CharGen_RollOffLocomotion::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_RollOffLocomotion::GetEventSource };
			return func();
		}
	};

	struct CharGen_RollOnLocomotion
	{
		[[nodiscard]] static BSTEventSource<CharGen_RollOnLocomotion>* GetEventSource()
		{
			using func_t = decltype(&CharGen_RollOnLocomotion::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_RollOnLocomotion::GetEventSource };
			return func();
		}
	};

	struct CharGen_RotatePaperdoll
	{
		[[nodiscard]] static BSTEventSource<CharGen_RotatePaperdoll>* GetEventSource()
		{
			using func_t = decltype(&CharGen_RotatePaperdoll::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_RotatePaperdoll::GetEventSource };
			return func();
		}
	};

	struct CharGen_SetAdditionalSlider
	{
		[[nodiscard]] static BSTEventSource<CharGen_SetAdditionalSlider>* GetEventSource()
		{
			using func_t = decltype(&CharGen_SetAdditionalSlider::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_SetAdditionalSlider::GetEventSource };
			return func();
		}
	};

	struct CharGen_SetBackground
	{
		[[nodiscard]] static BSTEventSource<CharGen_SetBackground>* GetEventSource()
		{
			using func_t = decltype(&CharGen_SetBackground::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_SetBackground::GetEventSource };
			return func();
		}
	};

	struct CharGen_SetBlockInputUnderPopup
	{
		[[nodiscard]] static BSTEventSource<CharGen_SetBlockInputUnderPopup>* GetEventSource()
		{
			using func_t = decltype(&CharGen_SetBlockInputUnderPopup::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_SetBlockInputUnderPopup::GetEventSource };
			return func();
		}
	};

	struct CharGen_SetBodyValues
	{
		[[nodiscard]] static BSTEventSource<CharGen_SetBodyValues>* GetEventSource()
		{
			using func_t = decltype(&CharGen_SetBodyValues::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_SetBodyValues::GetEventSource };
			return func();
		}
	};

	struct CharGen_SetCameraPosition
	{
		[[nodiscard]] static BSTEventSource<CharGen_SetCameraPosition>* GetEventSource()
		{
			using func_t = decltype(&CharGen_SetCameraPosition::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_SetCameraPosition::GetEventSource };
			return func();
		}
	};

	struct CharGen_SetPronoun
	{
		[[nodiscard]] static BSTEventSource<CharGen_SetPronoun>* GetEventSource()
		{
			using func_t = decltype(&CharGen_SetPronoun::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_SetPronoun::GetEventSource };
			return func();
		}
	};

	struct CharGen_SetSex
	{
		[[nodiscard]] static BSTEventSource<CharGen_SetSex>* GetEventSource()
		{
			using func_t = decltype(&CharGen_SetSex::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_SetSex::GetEventSource };
			return func();
		}
	};

	struct CharGen_SetSlider
	{
		[[nodiscard]] static BSTEventSource<CharGen_SetSlider>* GetEventSource()
		{
			using func_t = decltype(&CharGen_SetSlider::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_SetSlider::GetEventSource };
			return func();
		}
	};

	struct CharGen_SetTrait
	{
		[[nodiscard]] static BSTEventSource<CharGen_SetTrait>* GetEventSource()
		{
			using func_t = decltype(&CharGen_SetTrait::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_SetTrait::GetEventSource };
			return func();
		}
	};

	struct CharGen_ShowChooseBackgroundMessage
	{
		[[nodiscard]] static BSTEventSource<CharGen_ShowChooseBackgroundMessage>* GetEventSource()
		{
			using func_t = decltype(&CharGen_ShowChooseBackgroundMessage::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_ShowChooseBackgroundMessage::GetEventSource };
			return func();
		}
	};

	struct CharGen_ShowPlayerRenameMessage
	{
		[[nodiscard]] static BSTEventSource<CharGen_ShowPlayerRenameMessage>* GetEventSource()
		{
			using func_t = decltype(&CharGen_ShowPlayerRenameMessage::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_ShowPlayerRenameMessage::GetEventSource };
			return func();
		}
	};

	struct CharGen_SkintoneChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_SkintoneChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_SkintoneChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_SkintoneChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_StartBodyChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_StartBodyChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_StartBodyChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_StartBodyChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_StartTextEntry
	{
		[[nodiscard]] static BSTEventSource<CharGen_StartTextEntry>* GetEventSource()
		{
			using func_t = decltype(&CharGen_StartTextEntry::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_StartTextEntry::GetEventSource };
			return func();
		}
	};

	struct CharGen_SwitchBodyType
	{
		[[nodiscard]] static BSTEventSource<CharGen_SwitchBodyType>* GetEventSource()
		{
			using func_t = decltype(&CharGen_SwitchBodyType::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_SwitchBodyType::GetEventSource };
			return func();
		}
	};

	struct CharGen_SwitchLocomotion
	{
		[[nodiscard]] static BSTEventSource<CharGen_SwitchLocomotion>* GetEventSource()
		{
			using func_t = decltype(&CharGen_SwitchLocomotion::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_SwitchLocomotion::GetEventSource };
			return func();
		}
	};

	struct CharGen_TeethChange
	{
		[[nodiscard]] static BSTEventSource<CharGen_TeethChange>* GetEventSource()
		{
			using func_t = decltype(&CharGen_TeethChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_TeethChange::GetEventSource };
			return func();
		}
	};

	struct CharGen_TeethRollOff
	{
		[[nodiscard]] static BSTEventSource<CharGen_TeethRollOff>* GetEventSource()
		{
			using func_t = decltype(&CharGen_TeethRollOff::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_TeethRollOff::GetEventSource };
			return func();
		}
	};

	struct CharGen_TeethRollOn
	{
		[[nodiscard]] static BSTEventSource<CharGen_TeethRollOn>* GetEventSource()
		{
			using func_t = decltype(&CharGen_TeethRollOn::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_TeethRollOn::GetEventSource };
			return func();
		}
	};

	struct CharGen_ToggleMarking
	{
		[[nodiscard]] static BSTEventSource<CharGen_ToggleMarking>* GetEventSource()
		{
			using func_t = decltype(&CharGen_ToggleMarking::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_ToggleMarking::GetEventSource };
			return func();
		}
	};

	struct CharGen_TogglePreviewHabSuit
	{
		[[nodiscard]] static BSTEventSource<CharGen_TogglePreviewHabSuit>* GetEventSource()
		{
			using func_t = decltype(&CharGen_TogglePreviewHabSuit::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CharGen_TogglePreviewHabSuit::GetEventSource };
			return func();
		}
	};

	struct ClearHUDMessagesEvent
	{
		[[nodiscard]] static BSTEventSource<ClearHUDMessagesEvent>* GetEventSource()
		{
			using func_t = decltype(&ClearHUDMessagesEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ClearHUDMessagesEvent::GetEventSource };
			return func();
		}
	};

	struct ClearQuickContainerEvent
	{
		[[nodiscard]] static BSTEventSource<ClearQuickContainerEvent>* GetEventSource()
		{
			using func_t = decltype(&ClearQuickContainerEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ClearQuickContainerEvent::GetEventSource };
			return func();
		}
	};

	struct ClearShipHudTarget
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<ClearShipHudTarget::Event>* GetEventSource()
			{
				using func_t = decltype(&ClearShipHudTarget::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::ClearShipHudTarget::Event::GetEventSource };
				return func();
			}
		};
	};

	struct ContainerMenu_HideModel
	{
		[[nodiscard]] static BSTEventSource<ContainerMenu_HideModel>* GetEventSource()
		{
			using func_t = decltype(&ContainerMenu_HideModel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ContainerMenu_HideModel::GetEventSource };
			return func();
		}
	};

	struct ContainerMenu_Jettison
	{
		[[nodiscard]] static BSTEventSource<ContainerMenu_Jettison>* GetEventSource()
		{
			using func_t = decltype(&ContainerMenu_Jettison::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ContainerMenu_Jettison::GetEventSource };
			return func();
		}
	};

	struct ContainerMenu_LoadModel
	{
		[[nodiscard]] static BSTEventSource<ContainerMenu_LoadModel>* GetEventSource()
		{
			using func_t = decltype(&ContainerMenu_LoadModel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ContainerMenu_LoadModel::GetEventSource };
			return func();
		}
	};

	struct ContainerMenu_OpenRefuelMenu
	{
		[[nodiscard]] static BSTEventSource<ContainerMenu_OpenRefuelMenu>* GetEventSource()
		{
			using func_t = decltype(&ContainerMenu_OpenRefuelMenu::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ContainerMenu_OpenRefuelMenu::GetEventSource };
			return func();
		}
	};

	struct ContainerMenu_SetMouseOverModel
	{
		[[nodiscard]] static BSTEventSource<ContainerMenu_SetMouseOverModel>* GetEventSource()
		{
			using func_t = decltype(&ContainerMenu_SetMouseOverModel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ContainerMenu_SetMouseOverModel::GetEventSource };
			return func();
		}
	};

	struct ContainerMenu_TakeAll
	{
		[[nodiscard]] static BSTEventSource<ContainerMenu_TakeAll>* GetEventSource()
		{
			using func_t = decltype(&ContainerMenu_TakeAll::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ContainerMenu_TakeAll::GetEventSource };
			return func();
		}
	};

	struct ContainerMenu_ToggleEquip
	{
		[[nodiscard]] static BSTEventSource<ContainerMenu_ToggleEquip>* GetEventSource()
		{
			using func_t = decltype(&ContainerMenu_ToggleEquip::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ContainerMenu_ToggleEquip::GetEventSource };
			return func();
		}
	};

	struct ContainerMenu_TransferItem
	{
		[[nodiscard]] static BSTEventSource<ContainerMenu_TransferItem>* GetEventSource()
		{
			using func_t = decltype(&ContainerMenu_TransferItem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ContainerMenu_TransferItem::GetEventSource };
			return func();
		}
	};

	struct ContainerMenuClosed
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<ContainerMenuClosed::Event>* GetEventSource()
			{
				using func_t = decltype(&ContainerMenuClosed::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::ContainerMenuClosed::Event::GetEventSource };
				return func();
			}
		};
	};

	struct ControlsRemappedEvent
	{
		[[nodiscard]] static BSTEventSource<ControlsRemappedEvent>* GetEventSource()
		{
			using func_t = decltype(&ControlsRemappedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ControlsRemappedEvent::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_CloseMenu
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_CloseMenu>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_CloseMenu::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_CloseMenu::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_CraftItem
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_CraftItem>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_CraftItem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_CraftItem::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_ExitBench
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_ExitBench>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_ExitBench::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_ExitBench::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_Highlight3D
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_Highlight3D>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_Highlight3D::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_Highlight3D::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_InstallMod
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_InstallMod>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_InstallMod::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_InstallMod::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_RenameItem
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_RenameItem>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_RenameItem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_RenameItem::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_RevertedModdedItem
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_RevertedModdedItem>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_RevertedModdedItem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_RevertedModdedItem::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_RevertHighlight
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_RevertHighlight>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_RevertHighlight::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_RevertHighlight::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_SelectedMod
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_SelectedMod>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_SelectedMod::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_SelectedMod::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_SelectedModSlot
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_SelectedModSlot>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_SelectedModSlot::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_SelectedModSlot::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_SelectedModdableItem
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_SelectedModdableItem>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_SelectedModdableItem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_SelectedModdableItem::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_SelectedRecipe
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_SelectedRecipe>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_SelectedRecipe::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_SelectedRecipe::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_ToggleTracking
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_ToggleTracking>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_ToggleTracking::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_ToggleTracking::GetEventSource };
			return func();
		}
	};

	struct CraftingMenu_ViewingModdableItem
	{
		[[nodiscard]] static BSTEventSource<CraftingMenu_ViewingModdableItem>* GetEventSource()
		{
			using func_t = decltype(&CraftingMenu_ViewingModdableItem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::CraftingMenu_ViewingModdableItem::GetEventSource };
			return func();
		}
	};

	struct CriticalHitEvent
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<CriticalHitEvent::Event>* GetEventSource()
			{
				using func_t = decltype(&CriticalHitEvent::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::CriticalHitEvent::Event::GetEventSource };
				return func();
			}

			// members
			const NiPointer<Actor> attacker;       // 00
			const TESObjectWEAP*   weapon;         // 08
			bool                   isSneakAttack;  // 10
		};
		static_assert(sizeof(CriticalHitEvent::Event) == 0x18);
	};

	struct CustomMarkerUpdate
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<CustomMarkerUpdate::Event>* GetEventSource()
			{
				using func_t = decltype(&CustomMarkerUpdate::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::CustomMarkerUpdate::Event::GetEventSource };
				return func();
			}
		};
	};

	struct DataMenu_Missions
	{
		[[nodiscard]] static BSTEventSource<DataMenu_Missions>* GetEventSource()
		{
			using func_t = decltype(&DataMenu_Missions::GetEventSource);
			static REL::Relocation<func_t> func{ ID::DataMenu_Missions::GetEventSource };
			return func();
		}
	};

	struct DataMenu_PlotToLocation
	{
		[[nodiscard]] static BSTEventSource<DataMenu_PlotToLocation>* GetEventSource()
		{
			using func_t = decltype(&DataMenu_PlotToLocation::GetEventSource);
			static REL::Relocation<func_t> func{ ID::DataMenu_PlotToLocation::GetEventSource };
			return func();
		}
	};

	struct DataMenu_Reopened
	{
		[[nodiscard]] static BSTEventSource<DataMenu_Reopened>* GetEventSource()
		{
			using func_t = decltype(&DataMenu_Reopened::GetEventSource);
			static REL::Relocation<func_t> func{ ID::DataMenu_Reopened::GetEventSource };
			return func();
		}
	};

	struct DataMenu_SetPaperDollActive
	{
		[[nodiscard]] static BSTEventSource<DataMenu_SetPaperDollActive>* GetEventSource()
		{
			using func_t = decltype(&DataMenu_SetPaperDollActive::GetEventSource);
			static REL::Relocation<func_t> func{ ID::DataMenu_SetPaperDollActive::GetEventSource };
			return func();
		}
	};

	struct DataSlateMenu_playSFX
	{
		[[nodiscard]] static BSTEventSource<DataSlateMenu_playSFX>* GetEventSource()
		{
			using func_t = decltype(&DataSlateMenu_playSFX::GetEventSource);
			static REL::Relocation<func_t> func{ ID::DataSlateMenu_playSFX::GetEventSource };
			return func();
		}
	};

	struct DataSlateMenu_toggleAudio
	{
		[[nodiscard]] static BSTEventSource<DataSlateMenu_toggleAudio>* GetEventSource()
		{
			using func_t = decltype(&DataSlateMenu_toggleAudio::GetEventSource);
			static REL::Relocation<func_t> func{ ID::DataSlateMenu_toggleAudio::GetEventSource };
			return func();
		}
	};

	struct DaysPassed
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<DaysPassed::Event>* GetEventSource()
			{
				using func_t = decltype(&DaysPassed::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::DaysPassed::Event::GetEventSource };
				return func();
			}

			// members
			std::int32_t days;  // 00
		};
		static_assert(sizeof(DaysPassed::Event) == 0x4);
	};

	struct DialogueMenu_OnDialogueSelect
	{
		[[nodiscard]] static BSTEventSource<DialogueMenu_OnDialogueSelect>* GetEventSource()
		{
			using func_t = decltype(&DialogueMenu_OnDialogueSelect::GetEventSource);
			static REL::Relocation<func_t> func{ ID::DialogueMenu_OnDialogueSelect::GetEventSource };
			return func();
		}
	};

	struct DialogueMenu_OnListVisibilityChange
	{
		[[nodiscard]] static BSTEventSource<DialogueMenu_OnListVisibilityChange>* GetEventSource()
		{
			using func_t = decltype(&DialogueMenu_OnListVisibilityChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::DialogueMenu_OnListVisibilityChange::GetEventSource };
			return func();
		}
	};

	struct DialogueMenu_OnPersuasionAutoWin
	{
		[[nodiscard]] static BSTEventSource<DialogueMenu_OnPersuasionAutoWin>* GetEventSource()
		{
			using func_t = decltype(&DialogueMenu_OnPersuasionAutoWin::GetEventSource);
			static REL::Relocation<func_t> func{ ID::DialogueMenu_OnPersuasionAutoWin::GetEventSource };
			return func();
		}
	};

	struct DialogueMenu_RequestExit
	{
		[[nodiscard]] static BSTEventSource<DialogueMenu_RequestExit>* GetEventSource()
		{
			using func_t = decltype(&DialogueMenu_RequestExit::GetEventSource);
			static REL::Relocation<func_t> func{ ID::DialogueMenu_RequestExit::GetEventSource };
			return func();
		}
	};

	struct DialogueMenu_RequestSkipDialogue
	{
		[[nodiscard]] static BSTEventSource<DialogueMenu_RequestSkipDialogue>* GetEventSource()
		{
			using func_t = decltype(&DialogueMenu_RequestSkipDialogue::GetEventSource);
			static REL::Relocation<func_t> func{ ID::DialogueMenu_RequestSkipDialogue::GetEventSource };
			return func();
		}
	};

	struct EnteredUnity
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<EnteredUnity::Event>* GetEventSource()
			{
				using func_t = decltype(&EnteredUnity::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::EnteredUnity::Event::GetEventSource };
				return func();
			}
		};
	};

	struct ExperienceMeterDisplayData
	{
		[[nodiscard]] static BSTEventSource<ExperienceMeterDisplayData>* GetEventSource()
		{
			using func_t = decltype(&ExperienceMeterDisplayData::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ExperienceMeterDisplayData::GetEventSource };
			return func();
		}
	};

	struct FavoritesMenu_AssignQuickkey
	{
		[[nodiscard]] static BSTEventSource<FavoritesMenu_AssignQuickkey>* GetEventSource()
		{
			using func_t = decltype(&FavoritesMenu_AssignQuickkey::GetEventSource);
			static REL::Relocation<func_t> func{ ID::FavoritesMenu_AssignQuickkey::GetEventSource };
			return func();
		}
	};

	struct FavoritesMenu_UseQuickkey
	{
		[[nodiscard]] static BSTEventSource<FavoritesMenu_UseQuickkey>* GetEventSource()
		{
			using func_t = decltype(&FavoritesMenu_UseQuickkey::GetEventSource);
			static REL::Relocation<func_t> func{ ID::FavoritesMenu_UseQuickkey::GetEventSource };
			return func();
		}
	};

	struct FirstThirdPersonSwitch
	{
		struct Event
		{
			enum class Type : std::int32_t
			{
				kFirst,
				kThird,
			};

			[[nodiscard]] static BSTEventSource<FirstThirdPersonSwitch::Event>* GetEventSource()
			{
				using func_t = decltype(&FirstThirdPersonSwitch::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::FirstThirdPersonSwitch::Event::GetEventSource };
				return func();
			}

			[[nodiscard]] constexpr bool IsFirst() const noexcept { return type == Type::kFirst; }
			[[nodiscard]] constexpr bool IsThird() const noexcept { return type == Type::kThird; }

			// members
			Type oldType;  // 00
			Type type;     // 04
		};
		static_assert(sizeof(FirstThirdPersonSwitch::Event) == 0x8);
	};

	struct HideSubtitleEvent
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<HideSubtitleEvent::Event>* GetEventSource()
			{
				using func_t = decltype(&HideSubtitleEvent::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::HideSubtitleEvent::Event::GetEventSource };
				return func();
			}
		};
	};

	struct HourPassed
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<HourPassed::Event>* GetEventSource()
			{
				using func_t = decltype(&HourPassed::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::HourPassed::Event::GetEventSource };
				return func();
			}
		};
	};

	struct HoursPassed
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<HoursPassed::Event>* GetEventSource()
			{
				using func_t = decltype(&HoursPassed::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::HoursPassed::Event::GetEventSource };
				return func();
			}
		};
	};

	struct HUDModeEvent
	{
		[[nodiscard]] static BSTEventSource<HUDModeEvent>* GetEventSource()
		{
			using func_t = decltype(&HUDModeEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::HUDModeEvent::GetEventSource };
			return func();
		}

		// members
		const BSTArray<HUDModeType>* modes;
	};
	static_assert(sizeof(HUDModeEvent) == 0x8);

	struct HUDNotification_MissionActiveWidgetUpdate
	{
		[[nodiscard]] static BSTEventSource<HUDNotification_MissionActiveWidgetUpdate>* GetEventSource()
		{
			using func_t = decltype(&HUDNotification_MissionActiveWidgetUpdate::GetEventSource);
			static REL::Relocation<func_t> func{ ID::HUDNotification_MissionActiveWidgetUpdate::GetEventSource };
			return func();
		}
	};

	struct HUDNotification_SetMissionActive
	{
		[[nodiscard]] static BSTEventSource<HUDNotification_SetMissionActive>* GetEventSource()
		{
			using func_t = decltype(&HUDNotification_SetMissionActive::GetEventSource);
			static REL::Relocation<func_t> func{ ID::HUDNotification_SetMissionActive::GetEventSource };
			return func();
		}
	};

	struct HUDNotificationEvent
	{
		[[nodiscard]] static BSTEventSource<HUDNotificationEvent>* GetEventSource()
		{
			using func_t = decltype(&HUDNotificationEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::HUDNotificationEvent::GetEventSource };
			return func();
		}
	};

	struct HUDRolloverActivationButtonEvent
	{
		[[nodiscard]] static BSTEventSource<HUDRolloverActivationButtonEvent>* GetEventSource()
		{
			using func_t = decltype(&HUDRolloverActivationButtonEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::HUDRolloverActivationButtonEvent::GetEventSource };
			return func();
		}
	};

	struct InstantReferenceInteractionEvent
	{
		[[nodiscard]] static BSTEventSource<InstantReferenceInteractionEvent>* GetEventSource()
		{
			using func_t = decltype(&InstantReferenceInteractionEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::InstantReferenceInteractionEvent::GetEventSource };
			return func();
		}
	};

	struct InventoryItemEvent
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<InventoryItemEvent::Event>* GetEventSource()
			{
				using func_t = decltype(&InventoryItemEvent::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::InventoryItemEvent::Event::GetEventSource };
				return func();
			}
		};
	};

	struct InventoryMenu_Change3DView
	{
		[[nodiscard]] static BSTEventSource<InventoryMenu_Change3DView>* GetEventSource()
		{
			using func_t = decltype(&InventoryMenu_Change3DView::GetEventSource);
			static REL::Relocation<func_t> func{ ID::InventoryMenu_Change3DView::GetEventSource };
			return func();
		}
	};

	struct InventoryMenu_HideModel
	{
		[[nodiscard]] static BSTEventSource<InventoryMenu_HideModel>* GetEventSource()
		{
			using func_t = decltype(&InventoryMenu_HideModel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::InventoryMenu_HideModel::GetEventSource };
			return func();
		}
	};

	struct InventoryMenu_LoadModel
	{
		[[nodiscard]] static BSTEventSource<InventoryMenu_LoadModel>* GetEventSource()
		{
			using func_t = decltype(&InventoryMenu_LoadModel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::InventoryMenu_LoadModel::GetEventSource };
			return func();
		}
	};

	struct InventoryMenu_OnEnterCategory
	{
		[[nodiscard]] static BSTEventSource<InventoryMenu_OnEnterCategory>* GetEventSource()
		{
			using func_t = decltype(&InventoryMenu_OnEnterCategory::GetEventSource);
			static REL::Relocation<func_t> func{ ID::InventoryMenu_OnEnterCategory::GetEventSource };
			return func();
		}
	};

	struct InventoryMenu_OpenCargoHold
	{
		[[nodiscard]] static BSTEventSource<InventoryMenu_OpenCargoHold>* GetEventSource()
		{
			using func_t = decltype(&InventoryMenu_OpenCargoHold::GetEventSource);
			static REL::Relocation<func_t> func{ ID::InventoryMenu_OpenCargoHold::GetEventSource };
			return func();
		}
	};

	struct InventoryMenu_PaperDollTryOn
	{
		[[nodiscard]] static BSTEventSource<InventoryMenu_PaperDollTryOn>* GetEventSource()
		{
			using func_t = decltype(&InventoryMenu_PaperDollTryOn::GetEventSource);
			static REL::Relocation<func_t> func{ ID::InventoryMenu_PaperDollTryOn::GetEventSource };
			return func();
		}
	};

	struct InventoryMenu_ResetPaperDollInv
	{
		[[nodiscard]] static BSTEventSource<InventoryMenu_ResetPaperDollInv>* GetEventSource()
		{
			using func_t = decltype(&InventoryMenu_ResetPaperDollInv::GetEventSource);
			static REL::Relocation<func_t> func{ ID::InventoryMenu_ResetPaperDollInv::GetEventSource };
			return func();
		}
	};

	struct InventoryMenu_SelectItem
	{
		[[nodiscard]] static BSTEventSource<InventoryMenu_SelectItem>* GetEventSource()
		{
			using func_t = decltype(&InventoryMenu_SelectItem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::InventoryMenu_SelectItem::GetEventSource };
			return func();
		}
	};

	struct InventoryMenu_SetMouseOverModel
	{
		[[nodiscard]] static BSTEventSource<InventoryMenu_SetMouseOverModel>* GetEventSource()
		{
			using func_t = decltype(&InventoryMenu_SetMouseOverModel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::InventoryMenu_SetMouseOverModel::GetEventSource };
			return func();
		}
	};

	struct InventoryMenu_ToggleFavorite
	{
		[[nodiscard]] static BSTEventSource<InventoryMenu_ToggleFavorite>* GetEventSource()
		{
			using func_t = decltype(&InventoryMenu_ToggleFavorite::GetEventSource);
			static REL::Relocation<func_t> func{ ID::InventoryMenu_ToggleFavorite::GetEventSource };
			return func();
		}
	};

	struct InventoryMenu_ToggleHelmet
	{
		[[nodiscard]] static BSTEventSource<InventoryMenu_ToggleHelmet>* GetEventSource()
		{
			using func_t = decltype(&InventoryMenu_ToggleHelmet::GetEventSource);
			static REL::Relocation<func_t> func{ ID::InventoryMenu_ToggleHelmet::GetEventSource };
			return func();
		}
	};

	struct InventoryMenu_ToggleSuit
	{
		[[nodiscard]] static BSTEventSource<InventoryMenu_ToggleSuit>* GetEventSource()
		{
			using func_t = decltype(&InventoryMenu_ToggleSuit::GetEventSource);
			static REL::Relocation<func_t> func{ ID::InventoryMenu_ToggleSuit::GetEventSource };
			return func();
		}
	};

	struct ItemSteal
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<ItemSteal::Event>* GetEventSource()
			{
				using func_t = decltype(&ItemSteal::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::ItemSteal::Event::GetEventSource };
				return func();
			}

			// members
			std::uint32_t  count;  // 00
			TESObjectMISC* item;   // 04
		};
		static_assert(sizeof(ItemSteal::Event) == 0x10);
	};

	struct LevelIncrease
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<LevelIncrease::Event>* GetEventSource()
			{
				using func_t = decltype(&LevelIncrease::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::LevelIncrease::Event::GetEventSource };
				return func();
			}

			// members
			std::uint32_t level;
		};
		static_assert(sizeof(LevelIncrease::Event) == 0x4);
	};

	struct LevelUp_AnimFinished
	{
		[[nodiscard]] static BSTEventSource<LevelUp_AnimFinished>* GetEventSource()
		{
			using func_t = decltype(&LevelUp_AnimFinished::GetEventSource);
			static REL::Relocation<func_t> func{ ID::LevelUp_AnimFinished::GetEventSource };
			return func();
		}
	};

	struct LevelUp_OnWidgetShown
	{
		[[nodiscard]] static BSTEventSource<LevelUp_OnWidgetShown>* GetEventSource()
		{
			using func_t = decltype(&LevelUp_OnWidgetShown::GetEventSource);
			static REL::Relocation<func_t> func{ ID::LevelUp_OnWidgetShown::GetEventSource };
			return func();
		}
	};

	struct LocationLinked
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<LocationLinked::Event>* GetEventSource()
			{
				using func_t = decltype(&LocationLinked::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::LocationLinked::Event::GetEventSource };
				return func();
			}
		};
	};

	struct LocationTextEvent
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<LocationTextEvent::Event>* GetEventSource()
			{
				using func_t = decltype(&LocationTextEvent::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::LocationTextEvent::Event::GetEventSource };
				return func();
			}
		};
	};

	struct LocationTextWidget_FinishedQueue
	{
		[[nodiscard]] static BSTEventSource<LocationTextWidget_FinishedQueue>* GetEventSource()
		{
			using func_t = decltype(&LocationTextWidget_FinishedQueue::GetEventSource);
			static REL::Relocation<func_t> func{ ID::LocationTextWidget_FinishedQueue::GetEventSource };
			return func();
		}
	};

	struct MenuOpenCloseEvent
	{
		// members
		BSFixedString menuName;  // 00
		bool          opening;   // 08
	};
	static_assert(sizeof(MenuOpenCloseEvent) == 0x10);

	struct MessageBoxMenu_OnBackOut
	{
		[[nodiscard]] static BSTEventSource<MessageBoxMenu_OnBackOut>* GetEventSource()
		{
			using func_t = decltype(&MessageBoxMenu_OnBackOut::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MessageBoxMenu_OnBackOut::GetEventSource };
			return func();
		}
	};

	struct MessageBoxMenu_OnButtonPress
	{
		[[nodiscard]] static BSTEventSource<MessageBoxMenu_OnButtonPress>* GetEventSource()
		{
			using func_t = decltype(&MessageBoxMenu_OnButtonPress::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MessageBoxMenu_OnButtonPress::GetEventSource };
			return func();
		}
	};

	struct MessageBoxMenu_OnScriptedButtonPress
	{
		[[nodiscard]] static BSTEventSource<MessageBoxMenu_OnScriptedButtonPress>* GetEventSource()
		{
			using func_t = decltype(&MessageBoxMenu_OnScriptedButtonPress::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MessageBoxMenu_OnScriptedButtonPress::GetEventSource };
			return func();
		}
	};

	struct MissionBoard_MissionEntryChanged
	{
		[[nodiscard]] static BSTEventSource<MissionBoard_MissionEntryChanged>* GetEventSource()
		{
			using func_t = decltype(&MissionBoard_MissionEntryChanged::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MissionBoard_MissionEntryChanged::GetEventSource };
			return func();
		}
	};

	struct MissionBoard_MissionEntryPressed
	{
		[[nodiscard]] static BSTEventSource<MissionBoard_MissionEntryPressed>* GetEventSource()
		{
			using func_t = decltype(&MissionBoard_MissionEntryPressed::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MissionBoard_MissionEntryPressed::GetEventSource };
			return func();
		}
	};

	struct MissionMenu_ClearState
	{
		[[nodiscard]] static BSTEventSource<MissionMenu_ClearState>* GetEventSource()
		{
			using func_t = decltype(&MissionMenu_ClearState::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MissionMenu_ClearState::GetEventSource };
			return func();
		}
	};

	struct MissionMenu_PlotToLocation
	{
		[[nodiscard]] static BSTEventSource<MissionMenu_PlotToLocation>* GetEventSource()
		{
			using func_t = decltype(&MissionMenu_PlotToLocation::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MissionMenu_PlotToLocation::GetEventSource };
			return func();
		}
	};

	struct MissionMenu_RejectQuest
	{
		[[nodiscard]] static BSTEventSource<MissionMenu_RejectQuest>* GetEventSource()
		{
			using func_t = decltype(&MissionMenu_RejectQuest::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MissionMenu_RejectQuest::GetEventSource };
			return func();
		}
	};

	struct MissionMenu_ShowItemLocation
	{
		[[nodiscard]] static BSTEventSource<MissionMenu_ShowItemLocation>* GetEventSource()
		{
			using func_t = decltype(&MissionMenu_ShowItemLocation::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MissionMenu_ShowItemLocation::GetEventSource };
			return func();
		}
	};

	struct MissionMenu_ToggleTrackingQuest
	{
		[[nodiscard]] static BSTEventSource<MissionMenu_ToggleTrackingQuest>* GetEventSource()
		{
			using func_t = decltype(&MissionMenu_ToggleTrackingQuest::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MissionMenu_ToggleTrackingQuest::GetEventSource };
			return func();
		}
	};

	namespace ModelReferenceEffectEvents
	{
		struct ReferenceEffectFinished
		{
			[[nodiscard]] static BSTEventSource<ModelReferenceEffectEvents::ReferenceEffectFinished>* GetEventSource()
			{
				using func_t = decltype(&ModelReferenceEffectEvents::ReferenceEffectFinished::GetEventSource);
				static REL::Relocation<func_t> func{ ID::ModelReferenceEffectEvents::ReferenceEffectFinished::GetEventSource };
				return func();
			}
		};
	};

	struct MonocleMenu_Bioscan
	{
		[[nodiscard]] static BSTEventSource<MonocleMenu_Bioscan>* GetEventSource()
		{
			using func_t = decltype(&MonocleMenu_Bioscan::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MonocleMenu_Bioscan::GetEventSource };
			return func();
		}
	};

	struct MonocleMenu_FastTravel
	{
		[[nodiscard]] static BSTEventSource<MonocleMenu_FastTravel>* GetEventSource()
		{
			using func_t = decltype(&MonocleMenu_FastTravel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MonocleMenu_FastTravel::GetEventSource };
			return func();
		}
	};

	struct MonocleMenu_Harvest
	{
		[[nodiscard]] static BSTEventSource<MonocleMenu_Harvest>* GetEventSource()
		{
			using func_t = decltype(&MonocleMenu_Harvest::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MonocleMenu_Harvest::GetEventSource };
			return func();
		}
	};

	struct MonocleMenu_Initialize
	{
		[[nodiscard]] static BSTEventSource<MonocleMenu_Initialize>* GetEventSource()
		{
			using func_t = decltype(&MonocleMenu_Initialize::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MonocleMenu_Initialize::GetEventSource };
			return func();
		}
	};

	struct MonocleMenu_Outpost
	{
		[[nodiscard]] static BSTEventSource<MonocleMenu_Outpost>* GetEventSource()
		{
			using func_t = decltype(&MonocleMenu_Outpost::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MonocleMenu_Outpost::GetEventSource };
			return func();
		}
	};

	struct MonocleMenu_PhotoMode
	{
		[[nodiscard]] static BSTEventSource<MonocleMenu_PhotoMode>* GetEventSource()
		{
			using func_t = decltype(&MonocleMenu_PhotoMode::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MonocleMenu_PhotoMode::GetEventSource };
			return func();
		}
	};

	struct MonocleMenu_SocialSpell
	{
		[[nodiscard]] static BSTEventSource<MonocleMenu_SocialSpell>* GetEventSource()
		{
			using func_t = decltype(&MonocleMenu_SocialSpell::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MonocleMenu_SocialSpell::GetEventSource };
			return func();
		}
	};

	struct MonocleMenu_SurfaceMap
	{
		[[nodiscard]] static BSTEventSource<MonocleMenu_SurfaceMap>* GetEventSource()
		{
			using func_t = decltype(&MonocleMenu_SurfaceMap::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MonocleMenu_SurfaceMap::GetEventSource };
			return func();
		}
	};

	struct MonocleMenu_ZoomIn
	{
		[[nodiscard]] static BSTEventSource<MonocleMenu_ZoomIn>* GetEventSource()
		{
			using func_t = decltype(&MonocleMenu_ZoomIn::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MonocleMenu_ZoomIn::GetEventSource };
			return func();
		}
	};

	struct MonocleMenu_ZoomOut
	{
		[[nodiscard]] static BSTEventSource<MonocleMenu_ZoomOut>* GetEventSource()
		{
			using func_t = decltype(&MonocleMenu_ZoomOut::GetEventSource);
			static REL::Relocation<func_t> func{ ID::MonocleMenu_ZoomOut::GetEventSource };
			return func();
		}
	};

	struct PauseMenu_ActionCanceled
	{
		[[nodiscard]] static BSTEventSource<PauseMenu_ActionCanceled>* GetEventSource()
		{
			using func_t = decltype(&PauseMenu_ActionCanceled::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PauseMenu_ActionCanceled::GetEventSource };
			return func();
		}
	};

	struct PauseMenu_ConfirmAction
	{
		[[nodiscard]] static BSTEventSource<PauseMenu_ConfirmAction>* GetEventSource()
		{
			using func_t = decltype(&PauseMenu_ConfirmAction::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PauseMenu_ConfirmAction::GetEventSource };
			return func();
		}
	};

	struct PauseMenu_ConfirmLoad
	{
		[[nodiscard]] static BSTEventSource<PauseMenu_ConfirmLoad>* GetEventSource()
		{
			using func_t = decltype(&PauseMenu_ConfirmLoad::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PauseMenu_ConfirmLoad::GetEventSource };
			return func();
		}
	};

	struct PauseMenu_ConfirmSave
	{
		[[nodiscard]] static BSTEventSource<PauseMenu_ConfirmSave>* GetEventSource()
		{
			using func_t = decltype(&PauseMenu_ConfirmSave::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PauseMenu_ConfirmSave::GetEventSource };
			return func();
		}
	};

	struct PauseMenu_DeleteSave
	{
		[[nodiscard]] static BSTEventSource<PauseMenu_DeleteSave>* GetEventSource()
		{
			using func_t = decltype(&PauseMenu_DeleteSave::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PauseMenu_DeleteSave::GetEventSource };
			return func();
		}
	};

	struct PauseMenu_QuitToDesktop
	{
		[[nodiscard]] static BSTEventSource<PauseMenu_QuitToDesktop>* GetEventSource()
		{
			using func_t = decltype(&PauseMenu_QuitToDesktop::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PauseMenu_QuitToDesktop::GetEventSource };
			return func();
		}
	};

	struct PauseMenu_SetCharacter
	{
		[[nodiscard]] static BSTEventSource<PauseMenu_SetCharacter>* GetEventSource()
		{
			using func_t = decltype(&PauseMenu_SetCharacter::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PauseMenu_SetCharacter::GetEventSource };
			return func();
		}
	};

	struct PauseMenu_StartAction
	{
		[[nodiscard]] static BSTEventSource<PauseMenu_StartAction>* GetEventSource()
		{
			using func_t = decltype(&PauseMenu_StartAction::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PauseMenu_StartAction::GetEventSource };
			return func();
		}

		[[nodiscard]] std::uint32_t GetActionType() const
		{
			std::uint32_t result{};
			using func_t = std::uint32_t* (*)(std::uint32_t*, const PauseMenu_StartAction*);
			static REL::Relocation<func_t> func{ ID::PauseMenu_StartAction::ExtractActionType };
			func(std::addressof(result), this);
			return result;
		}
	};

	struct PauseMenu_StartLoad
	{
		[[nodiscard]] static BSTEventSource<PauseMenu_StartLoad>* GetEventSource()
		{
			using func_t = decltype(&PauseMenu_StartLoad::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PauseMenu_StartLoad::GetEventSource };
			return func();
		}
	};

	struct PerkChanged
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<PerkChanged::Event>* GetEventSource()
			{
				using func_t = decltype(&PerkChanged::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::PerkChanged::Event::GetEventSource };
				return func();
			}
		};
	};

	struct PhotoGallery_DeletePhoto
	{
		[[nodiscard]] static BSTEventSource<PhotoGallery_DeletePhoto>* GetEventSource()
		{
			using func_t = decltype(&PhotoGallery_DeletePhoto::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PhotoGallery_DeletePhoto::GetEventSource };
			return func();
		}
	};

	struct PhotoMode_InitializeCategory
	{
		[[nodiscard]] static BSTEventSource<PhotoMode_InitializeCategory>* GetEventSource()
		{
			using func_t = decltype(&PhotoMode_InitializeCategory::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PhotoMode_InitializeCategory::GetEventSource };
			return func();
		}
	};

	struct PhotoMode_RefineSetting
	{
		[[nodiscard]] static BSTEventSource<PhotoMode_RefineSetting>* GetEventSource()
		{
			using func_t = decltype(&PhotoMode_RefineSetting::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PhotoMode_RefineSetting::GetEventSource };
			return func();
		}
	};

	struct PhotoMode_ResetToDefaults
	{
		[[nodiscard]] static BSTEventSource<PhotoMode_ResetToDefaults>* GetEventSource()
		{
			using func_t = decltype(&PhotoMode_ResetToDefaults::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PhotoMode_ResetToDefaults::GetEventSource };
			return func();
		}
	};

	struct PhotoMode_SliderChanged
	{
		[[nodiscard]] static BSTEventSource<PhotoMode_SliderChanged>* GetEventSource()
		{
			using func_t = decltype(&PhotoMode_SliderChanged::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PhotoMode_SliderChanged::GetEventSource };
			return func();
		}
	};

	struct PhotoMode_StepperChanged
	{
		[[nodiscard]] static BSTEventSource<PhotoMode_StepperChanged>* GetEventSource()
		{
			using func_t = decltype(&PhotoMode_StepperChanged::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PhotoMode_StepperChanged::GetEventSource };
			return func();
		}
	};

	struct PhotoMode_TakeSnapshot
	{
		[[nodiscard]] static BSTEventSource<PhotoMode_TakeSnapshot>* GetEventSource()
		{
			using func_t = decltype(&PhotoMode_TakeSnapshot::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PhotoMode_TakeSnapshot::GetEventSource };
			return func();
		}
	};

	struct PhotoMode_ToggleHelmet
	{
		[[nodiscard]] static BSTEventSource<PhotoMode_ToggleHelmet>* GetEventSource()
		{
			using func_t = decltype(&PhotoMode_ToggleHelmet::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PhotoMode_ToggleHelmet::GetEventSource };
			return func();
		}
	};

	struct PhotoMode_ToggleUI
	{
		[[nodiscard]] static BSTEventSource<PhotoMode_ToggleUI>* GetEventSource()
		{
			using func_t = decltype(&PhotoMode_ToggleUI::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PhotoMode_ToggleUI::GetEventSource };
			return func();
		}
	};

	struct PickpocketMenu_OnItemSelect
	{
		[[nodiscard]] static BSTEventSource<PickpocketMenu_OnItemSelect>* GetEventSource()
		{
			using func_t = decltype(&PickpocketMenu_OnItemSelect::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PickpocketMenu_OnItemSelect::GetEventSource };
			return func();
		}
	};

	struct PickRefStateChangedEvent
	{
		[[nodiscard]] static BSTEventSource<PickRefStateChangedEvent>* GetEventSource()
		{
			using func_t = decltype(&PickRefStateChangedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PickRefStateChangedEvent::GetEventSource };
			return func();
		}
	};

	struct PickRefUpdateEvent
	{
		[[nodiscard]] static BSTEventSource<PickRefUpdateEvent>* GetEventSource()
		{
			using func_t = decltype(&PickRefUpdateEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PickRefUpdateEvent::GetEventSource };
			return func();
		}
	};

	struct PlayBink_CloseMenu
	{
		[[nodiscard]] static BSTEventSource<PlayBink_CloseMenu>* GetEventSource()
		{
			using func_t = decltype(&PlayBink_CloseMenu::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PlayBink_CloseMenu::GetEventSource };
			return func();
		}
	};

	struct PlayerAmmoChanged
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<PlayerAmmoChanged::Event>* GetEventSource()
			{
				using func_t = decltype(&PlayerAmmoChanged::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::PlayerAmmoChanged::Event::GetEventSource };
				return func();
			}

			// members
			std::uint32_t clipCount;
			std::uint32_t reserveCount;
		};
		static_assert(sizeof(PlayerAmmoChanged::Event) == 0x8);
	};

	struct PlayerAssaultActorEvent
	{
		[[nodiscard]] static BSTEventSource<PlayerAssaultActorEvent>* GetEventSource()
		{
			using func_t = decltype(&PlayerAssaultActorEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PlayerAssaultActorEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<Actor> actor;     // 00
		BGSLocation*     location;  // 08 - nullptr if no location
		bool             isCrime;   // 10
	};
	static_assert(sizeof(PlayerAssaultActorEvent) == 0x18);

	struct PlayerControls
	{
		struct PlayerIronSightsEndEvent
		{
			[[nodiscard]] static BSTEventSource<PlayerControls::PlayerIronSightsEndEvent>* GetEventSource()
			{
				using func_t = decltype(&PlayerControls::PlayerIronSightsEndEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::PlayerControls::PlayerIronSightsEndEvent::GetEventSource };
				return func();
			}
		};

		struct PlayerIronSightsStartEvent
		{
			[[nodiscard]] static BSTEventSource<PlayerControls::PlayerIronSightsStartEvent>* GetEventSource()
			{
				using func_t = decltype(&PlayerControls::PlayerIronSightsStartEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::PlayerControls::PlayerIronSightsStartEvent::GetEventSource };
				return func();
			}
		};

		struct PlayerJumpPressEvent
		{
			[[nodiscard]] static BSTEventSource<PlayerControls::PlayerJumpPressEvent>* GetEventSource()
			{
				using func_t = decltype(&PlayerControls::PlayerJumpPressEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::PlayerControls::PlayerJumpPressEvent::GetEventSource };
				return func();
			}
		};

		struct PlayerJumpReleaseEvent
		{
			[[nodiscard]] static BSTEventSource<PlayerControls::PlayerJumpReleaseEvent>* GetEventSource()
			{
				using func_t = decltype(&PlayerControls::PlayerJumpReleaseEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::PlayerControls::PlayerJumpReleaseEvent::GetEventSource };
				return func();
			}
		};

		struct PlayerZeroGSprintJustPressedEvent
		{
			[[nodiscard]] static BSTEventSource<PlayerControls::PlayerZeroGSprintJustPressedEvent>* GetEventSource()
			{
				using func_t = decltype(&PlayerControls::PlayerZeroGSprintJustPressedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::PlayerControls::PlayerZeroGSprintJustPressedEvent::GetEventSource };
				return func();
			}
		};

		struct PlayerZeroGSprintReleasedEvent
		{
			[[nodiscard]] static BSTEventSource<PlayerControls::PlayerZeroGSprintReleasedEvent>* GetEventSource()
			{
				using func_t = decltype(&PlayerControls::PlayerZeroGSprintReleasedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::PlayerControls::PlayerZeroGSprintReleasedEvent::GetEventSource };
				return func();
			}
		};
	};

	struct PlayerCrimeGoldEvent
	{
		enum class Type : std::uint32_t
		{
			kNone = static_cast<std::underlying_type_t<Type>>(-1),

			kSteal = 0,
			kPickpocket,
			kTrespass,
			kAttack,
			kMurder,
			kEscape,
			kUnused,
		};

		[[nodiscard]] static BSTEventSource<PlayerCrimeGoldEvent>* GetEventSource()
		{
			using func_t = decltype(&PlayerCrimeGoldEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PlayerCrimeGoldEvent::GetEventSource };
			return func();
		}

		[[nodiscard]] constexpr bool IsSteal() const noexcept { return type == Type::kSteal; }
		[[nodiscard]] constexpr bool IsPickpocket() const noexcept { return type == Type::kPickpocket; }
		[[nodiscard]] constexpr bool IsTrespass() const noexcept { return type == Type::kTrespass; }
		[[nodiscard]] constexpr bool IsAttack() const noexcept { return type == Type::kAttack; }
		[[nodiscard]] constexpr bool IsMurder() const noexcept { return type == Type::kMurder; }
		[[nodiscard]] constexpr bool IsEscape() const noexcept { return type == Type::kEscape; }

		// members
		std::uint64_t unk00;    // 00
		TESFaction*   faction;  // 08
		std::uint32_t value;    // 10
		Type          type;     // 18
	};
	static_assert(sizeof(PlayerCrimeGoldEvent) == 0x18);

	struct PlayerCrosshairModeEvent
	{
		[[nodiscard]] static BSTEventSource<PlayerCrosshairModeEvent>* GetEventSource()
		{
			using func_t = decltype(&PlayerCrosshairModeEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PlayerCrosshairModeEvent::GetEventSource };
			return func();
		}
	};

	struct PlayerDetectionLevelChangeEvent
	{
		[[nodiscard]] static BSTEventSource<PlayerDetectionLevelChangeEvent>* GetEventSource()
		{
			using func_t = decltype(&PlayerDetectionLevelChangeEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PlayerDetectionLevelChangeEvent::GetEventSource };
			return func();
		}
	};

	struct PlayerDifficultySettingChanged
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<PlayerDifficultySettingChanged::Event>* GetEventSource()
			{
				using func_t = decltype(&PlayerDifficultySettingChanged::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::PlayerDifficultySettingChanged::Event::GetEventSource };
				return func();
			}

			// members
			std::uint32_t oldDifficulty;  // 00
			std::uint32_t newDifficulty;  // 04
		};
		static_assert(sizeof(PlayerDifficultySettingChanged::Event) == 0x8);
	};

	struct PlayerFastTravel
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<PlayerFastTravel::Event>* GetEventSource()
			{
				using func_t = decltype(&PlayerFastTravel::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::PlayerFastTravel::Event::GetEventSource };
				return func();
			}
		};
	};

	struct PlayerJailEvent
	{
		[[nodiscard]] static BSTEventSource<PlayerJailEvent>* GetEventSource()
		{
			using func_t = decltype(&PlayerJailEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PlayerJailEvent::GetEventSource };
			return func();
		}

		// members
		std::uint64_t unk00;     // 00 - Guard ActorHandle?
		TESFaction*   faction;   // 08
		BGSLocation*  location;  // 10 - nullptr if no location
		std::uint32_t value;     // 18
	};
	static_assert(sizeof(PlayerJailEvent) == 0x20);

	struct PlayerMurderActorEvent
	{
		[[nodiscard]] static BSTEventSource<PlayerMurderActorEvent>* GetEventSource()
		{
			using func_t = decltype(&PlayerMurderActorEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PlayerMurderActorEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<Actor> actor;     // 00
		BGSLocation*     location;  // 08 - nullptr if no location
		bool             isCrime;   // 10
	};
	static_assert(sizeof(PlayerMurderActorEvent) == 0x18);

	struct PlayerPayFineEvent
	{
		[[nodiscard]] static BSTEventSource<PlayerPayFineEvent>* GetEventSource()
		{
			using func_t = decltype(&PlayerPayFineEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PlayerPayFineEvent::GetEventSource };
			return func();
		}

		// members
		std::uint64_t unk00;    // 00
		TESFaction*   faction;  // 08
		std::uint32_t value;    // 10
	};
	static_assert(sizeof(PlayerPayFineEvent) == 0x18);

	struct PlayerSetWeaponStateEvent
	{
		[[nodiscard]] static BSTEventSource<PlayerSetWeaponStateEvent>* GetEventSource()
		{
			using func_t = decltype(&PlayerSetWeaponStateEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PlayerSetWeaponStateEvent::GetEventSource };
			return func();
		}
	};

	struct PlayerSneakingChangeEvent
	{
		[[nodiscard]] static BSTEventSource<PlayerSneakingChangeEvent>* GetEventSource()
		{
			using func_t = decltype(&PlayerSneakingChangeEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PlayerSneakingChangeEvent::GetEventSource };
			return func();
		}

		// members
		bool isSneaking;  // 00
	};
	static_assert(sizeof(PlayerSneakingChangeEvent) == 0x1);

	struct PlayerTrespassEvent
	{
		[[nodiscard]] static BSTEventSource<PlayerTrespassEvent>* GetEventSource()
		{
			using func_t = decltype(&PlayerTrespassEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PlayerTrespassEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<Actor> actor;     // 00
		BGSLocation*     location;  // 08 - nullptr if no location
		bool             isCrime;   // 10
	};
	static_assert(sizeof(PlayerTrespassEvent) == 0x18);

	struct PlayerUpdateEvent
	{
		[[nodiscard]] static BSTEventSource<PlayerUpdateEvent>* GetEventSource()
		{
			using func_t = decltype(&PlayerUpdateEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PlayerUpdateEvent::GetEventSource };
			return func();
		}
	};

	struct PowersMenu_ActivateEssence
	{
		[[nodiscard]] static BSTEventSource<PowersMenu_ActivateEssence>* GetEventSource()
		{
			using func_t = decltype(&PowersMenu_ActivateEssence::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PowersMenu_ActivateEssence::GetEventSource };
			return func();
		}
	};

	struct PowersMenu_EquipPower
	{
		[[nodiscard]] static BSTEventSource<PowersMenu_EquipPower>* GetEventSource()
		{
			using func_t = decltype(&PowersMenu_EquipPower::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PowersMenu_EquipPower::GetEventSource };
			return func();
		}
	};

	struct PowersMenu_FavoritePower
	{
		[[nodiscard]] static BSTEventSource<PowersMenu_FavoritePower>* GetEventSource()
		{
			using func_t = decltype(&PowersMenu_FavoritePower::GetEventSource);
			static REL::Relocation<func_t> func{ ID::PowersMenu_FavoritePower::GetEventSource };
			return func();
		}
	};

	struct Refuel_Accept
	{
		[[nodiscard]] static BSTEventSource<Refuel_Accept>* GetEventSource()
		{
			using func_t = decltype(&Refuel_Accept::GetEventSource);
			static REL::Relocation<func_t> func{ ID::Refuel_Accept::GetEventSource };
			return func();
		}
	};

	struct Refuel_Cancel
	{
		[[nodiscard]] static BSTEventSource<Refuel_Cancel>* GetEventSource()
		{
			using func_t = decltype(&Refuel_Cancel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::Refuel_Cancel::GetEventSource };
			return func();
		}
	};

	struct ReloadWeaponEvent
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<ReloadWeaponEvent::Event>* GetEventSource()
			{
				using func_t = decltype(&ReloadWeaponEvent::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::ReloadWeaponEvent::Event::GetEventSource };
				return func();
			}

			NiPointer<Actor> actor;  // 00
		};
	};

	struct Research
	{
		struct ResearchProgressEvent
		{
			[[nodiscard]] static BSTEventSource<Research::ResearchProgressEvent>* GetEventSource()
			{
				using func_t = decltype(&Research::ResearchProgressEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Research::ResearchProgressEvent::GetEventSource };
				return func();
			}
		};
	};

	struct ResearchMenu_AddMaterial
	{
		[[nodiscard]] static BSTEventSource<ResearchMenu_AddMaterial>* GetEventSource()
		{
			using func_t = decltype(&ResearchMenu_AddMaterial::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ResearchMenu_AddMaterial::GetEventSource };
			return func();
		}
	};

	struct ResearchMenu_CategorySelected
	{
		[[nodiscard]] static BSTEventSource<ResearchMenu_CategorySelected>* GetEventSource()
		{
			using func_t = decltype(&ResearchMenu_CategorySelected::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ResearchMenu_CategorySelected::GetEventSource };
			return func();
		}
	};

	struct ResearchMenu_HideModel
	{
		[[nodiscard]] static BSTEventSource<ResearchMenu_HideModel>* GetEventSource()
		{
			using func_t = decltype(&ResearchMenu_HideModel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ResearchMenu_HideModel::GetEventSource };
			return func();
		}
	};

	struct ResearchMenu_PreviewProject
	{
		[[nodiscard]] static BSTEventSource<ResearchMenu_PreviewProject>* GetEventSource()
		{
			using func_t = decltype(&ResearchMenu_PreviewProject::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ResearchMenu_PreviewProject::GetEventSource };
			return func();
		}
	};

	struct ResearchMenu_ProjectViewed
	{
		[[nodiscard]] static BSTEventSource<ResearchMenu_ProjectViewed>* GetEventSource()
		{
			using func_t = decltype(&ResearchMenu_ProjectViewed::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ResearchMenu_ProjectViewed::GetEventSource };
			return func();
		}
	};

	struct ResearchMenu_ToggleTrackingProject
	{
		[[nodiscard]] static BSTEventSource<ResearchMenu_ToggleTrackingProject>* GetEventSource()
		{
			using func_t = decltype(&ResearchMenu_ToggleTrackingProject::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ResearchMenu_ToggleTrackingProject::GetEventSource };
			return func();
		}
	};

	struct Reticle_OnLongAnimFinished
	{
		[[nodiscard]] static BSTEventSource<Reticle_OnLongAnimFinished>* GetEventSource()
		{
			using func_t = decltype(&Reticle_OnLongAnimFinished::GetEventSource);
			static REL::Relocation<func_t> func{ ID::Reticle_OnLongAnimFinished::GetEventSource };
			return func();
		}
	};

	struct RuntimeComponentDBFactory
	{
		struct ReferenceDetach
		{
			[[nodiscard]] static BSTEventSource<RuntimeComponentDBFactory::ReferenceDetach>* GetEventSource()
			{
				using func_t = decltype(&RuntimeComponentDBFactory::ReferenceDetach::GetEventSource);
				static REL::Relocation<func_t> func{ ID::RuntimeComponentDBFactory::ReferenceDetach::GetEventSource };
				return func();
			}

			// members
			NiPointer<TESObjectREFR> ref;
		};
		static_assert(sizeof(RuntimeComponentDBFactory::ReferenceDetach) == 0x8);

		struct ReferenceSet3d
		{
			[[nodiscard]] static BSTEventSource<RuntimeComponentDBFactory::ReferenceSet3d>* GetEventSource()
			{
				using func_t = decltype(&RuntimeComponentDBFactory::ReferenceSet3d::GetEventSource);
				static REL::Relocation<func_t> func{ ID::RuntimeComponentDBFactory::ReferenceSet3d::GetEventSource };
				return func();
			}

			// members
			NiPointer<TESObjectREFR> ref;
		};
		static_assert(sizeof(RuntimeComponentDBFactory::ReferenceSet3d) == 0x8);
	};

	struct SaveLoadEvent
	{
		enum class OpType : std::uint8_t
		{
			kAutosave = 1,
			kLoadMostRecent = 2,
			kQuicksave = 3,
			kQuickload = 4,
			kManualSave = 5,
			kLoad = 6,
			kExitSaveToMainMenu = 7,
			kExitSaveToDesktop = 8,
			kLoadNamedFile = 0xB,
		};

		enum class Status : std::uint8_t
		{
			kBegin = 0,
			kLoadSucceeded = 1,
			kFailed = 3,
			kSaveCompleted = 4,
			kLoadDispatchRefused = 5,
		};

		[[nodiscard]] static BSTEventSource<SaveLoadEvent>* GetEventSource()
		{
			using func_t = decltype(&SaveLoadEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::SaveLoadEvent::GetEventSource };
			return func();
		}

		// members
		std::uint32_t elapsedMs;      // 00
		std::uint32_t fileSizeBytes;  // 04
		std::uint32_t unk08;          // 08
		OpType        opType;         // 0C
		Status        status;         // 0D
	};
	static_assert(sizeof(SaveLoadEvent) == 0x10);

	struct SecurityMenu_BackOutKey
	{
		[[nodiscard]] static BSTEventSource<SecurityMenu_BackOutKey>* GetEventSource()
		{
			using func_t = decltype(&SecurityMenu_BackOutKey::GetEventSource);
			static REL::Relocation<func_t> func{ ID::SecurityMenu_BackOutKey::GetEventSource };
			return func();
		}
	};

	struct SecurityMenu_ConfirmExit
	{
		[[nodiscard]] static BSTEventSource<SecurityMenu_ConfirmExit>* GetEventSource()
		{
			using func_t = decltype(&SecurityMenu_ConfirmExit::GetEventSource);
			static REL::Relocation<func_t> func{ ID::SecurityMenu_ConfirmExit::GetEventSource };
			return func();
		}
	};

	struct SecurityMenu_EliminateUnusedKeys
	{
		[[nodiscard]] static BSTEventSource<SecurityMenu_EliminateUnusedKeys>* GetEventSource()
		{
			using func_t = decltype(&SecurityMenu_EliminateUnusedKeys::GetEventSource);
			static REL::Relocation<func_t> func{ ID::SecurityMenu_EliminateUnusedKeys::GetEventSource };
			return func();
		}
	};

	struct SecurityMenu_GetRingHint
	{
		[[nodiscard]] static BSTEventSource<SecurityMenu_GetRingHint>* GetEventSource()
		{
			using func_t = decltype(&SecurityMenu_GetRingHint::GetEventSource);
			static REL::Relocation<func_t> func{ ID::SecurityMenu_GetRingHint::GetEventSource };
			return func();
		}
	};

	struct SecurityMenu_SelectNewKey
	{
		[[nodiscard]] static BSTEventSource<SecurityMenu_SelectNewKey>* GetEventSource()
		{
			using func_t = decltype(&SecurityMenu_SelectNewKey::GetEventSource);
			static REL::Relocation<func_t> func{ ID::SecurityMenu_SelectNewKey::GetEventSource };
			return func();
		}
	};

	struct SecurityMenu_TryUseKey
	{
		[[nodiscard]] static BSTEventSource<SecurityMenu_TryUseKey>* GetEventSource()
		{
			using func_t = decltype(&SecurityMenu_TryUseKey::GetEventSource);
			static REL::Relocation<func_t> func{ ID::SecurityMenu_TryUseKey::GetEventSource };
			return func();
		}
	};

	struct ShipCameraStateToggled
	{
		[[nodiscard]] static BSTEventSource<ShipCameraStateToggled>* GetEventSource()
		{
			using func_t = decltype(&ShipCameraStateToggled::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipCameraStateToggled::GetEventSource };
			return func();
		}
	};

	struct ShipEditor_SystemSelected
	{
		[[nodiscard]] static BSTEventSource<ShipEditor_SystemSelected>* GetEventSource()
		{
			using func_t = decltype(&ShipEditor_SystemSelected::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipEditor_SystemSelected::GetEventSource };
			return func();
		}
	};

	struct ShipHud_AbortJump
	{
		[[nodiscard]] static BSTEventSource<ShipHud_AbortJump>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_AbortJump::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_AbortJump::GetEventSource };
			return func();
		}
	};

	struct ShipHud_Activate
	{
		[[nodiscard]] static BSTEventSource<ShipHud_Activate>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_Activate::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_Activate::GetEventSource };
			return func();
		}
	};

	struct ShipHud_BodyViewMarkerDimensions
	{
		[[nodiscard]] static BSTEventSource<ShipHud_BodyViewMarkerDimensions>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_BodyViewMarkerDimensions::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_BodyViewMarkerDimensions::GetEventSource };
			return func();
		}
	};

	struct ShipHud_ChangeComponentSelection
	{
		[[nodiscard]] static BSTEventSource<ShipHud_ChangeComponentSelection>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_ChangeComponentSelection::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_ChangeComponentSelection::GetEventSource };
			return func();
		}
	};

	struct ShipHud_Deselect
	{
		[[nodiscard]] static BSTEventSource<ShipHud_Deselect>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_Deselect::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_Deselect::GetEventSource };
			return func();
		}
	};

	struct ShipHud_DockRequested
	{
		[[nodiscard]] static BSTEventSource<ShipHud_DockRequested>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_DockRequested::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_DockRequested::GetEventSource };
			return func();
		}
	};

	struct ShipHud_FarTravel
	{
		[[nodiscard]] static BSTEventSource<ShipHud_FarTravel>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_FarTravel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_FarTravel::GetEventSource };
			return func();
		}
	};

	struct ShipHud_HailAccepted
	{
		[[nodiscard]] static BSTEventSource<ShipHud_HailAccepted>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_HailAccepted::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_HailAccepted::GetEventSource };
			return func();
		}
	};

	struct ShipHud_HailCancelled
	{
		[[nodiscard]] static BSTEventSource<ShipHud_HailCancelled>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_HailCancelled::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_HailCancelled::GetEventSource };
			return func();
		}
	};

	struct ShipHud_HailShip
	{
		[[nodiscard]] static BSTEventSource<ShipHud_HailShip>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_HailShip::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_HailShip::GetEventSource };
			return func();
		}
	};

	struct ShipHud_JumpToQuestMarker
	{
		[[nodiscard]] static BSTEventSource<ShipHud_JumpToQuestMarker>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_JumpToQuestMarker::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_JumpToQuestMarker::GetEventSource };
			return func();
		}
	};

	struct ShipHud_Land
	{
		[[nodiscard]] static BSTEventSource<ShipHud_Land>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_Land::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_Land::GetEventSource };
			return func();
		}
	};

	struct ShipHud_LandingMarkerMap
	{
		[[nodiscard]] static BSTEventSource<ShipHud_LandingMarkerMap>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_LandingMarkerMap::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_LandingMarkerMap::GetEventSource };
			return func();
		}
	};

	struct ShipHud_Map
	{
		[[nodiscard]] static BSTEventSource<ShipHud_Map>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_Map::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_Map::GetEventSource };
			return func();
		}
	};

	struct ShipHud_OpenPhotoMode
	{
		[[nodiscard]] static BSTEventSource<ShipHud_OpenPhotoMode>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_OpenPhotoMode::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_OpenPhotoMode::GetEventSource };
			return func();
		}
	};

	struct ShipHud_Repair
	{
		[[nodiscard]] static BSTEventSource<ShipHud_Repair>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_Repair::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_Repair::GetEventSource };
			return func();
		}
	};

	struct ShipHud_SetTargetMode
	{
		[[nodiscard]] static BSTEventSource<ShipHud_SetTargetMode>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_SetTargetMode::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_SetTargetMode::GetEventSource };
			return func();
		}
	};

	struct ShipHud_Target
	{
		[[nodiscard]] static BSTEventSource<ShipHud_Target>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_Target::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_Target::GetEventSource };
			return func();
		}
	};

	struct ShipHud_TargetShipSystem
	{
		[[nodiscard]] static BSTEventSource<ShipHud_TargetShipSystem>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_TargetShipSystem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_TargetShipSystem::GetEventSource };
			return func();
		}
	};

	struct ShipHud_UntargetShipSystem
	{
		[[nodiscard]] static BSTEventSource<ShipHud_UntargetShipSystem>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_UntargetShipSystem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_UntargetShipSystem::GetEventSource };
			return func();
		}
	};

	struct ShipHud_UpdateComponentPower
	{
		[[nodiscard]] static BSTEventSource<ShipHud_UpdateComponentPower>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_UpdateComponentPower::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_UpdateComponentPower::GetEventSource };
			return func();
		}
	};

	struct ShipHud_UpdateTargetPanelRect
	{
		[[nodiscard]] static BSTEventSource<ShipHud_UpdateTargetPanelRect>* GetEventSource()
		{
			using func_t = decltype(&ShipHud_UpdateTargetPanelRect::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHud_UpdateTargetPanelRect::GetEventSource };
			return func();
		}
	};

	struct ShipHudQuickContainer_TransferItem
	{
		[[nodiscard]] static BSTEventSource<ShipHudQuickContainer_TransferItem>* GetEventSource()
		{
			using func_t = decltype(&ShipHudQuickContainer_TransferItem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHudQuickContainer_TransferItem::GetEventSource };
			return func();
		}
	};

	struct ShipHudQuickContainer_TransferMenu
	{
		[[nodiscard]] static BSTEventSource<ShipHudQuickContainer_TransferMenu>* GetEventSource()
		{
			using func_t = decltype(&ShipHudQuickContainer_TransferMenu::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShipHudQuickContainer_TransferMenu::GetEventSource };
			return func();
		}
	};

	struct ShowHUDMessageEvent
	{
		[[nodiscard]] static BSTEventSource<ShowHUDMessageEvent>* GetEventSource()
		{
			using func_t = decltype(&ShowHUDMessageEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShowHUDMessageEvent::GetEventSource };
			return func();
		}

		// members
		BSFixedString text;         // 00
		BSFixedString sound;        // 08
		bool          canThrottle;  // 10
		bool          isWarning;    // 11
	};
	static_assert(sizeof(ShowHUDMessageEvent) == 0x18);

	struct ShowingQuestMarketTextEvent
	{
		[[nodiscard]] static BSTEventSource<ShowingQuestMarketTextEvent>* GetEventSource()
		{
			using func_t = decltype(&ShowingQuestMarketTextEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShowingQuestMarketTextEvent::GetEventSource };
			return func();
		}
	};

	struct ShowLongShipBootup
	{
		[[nodiscard]] static BSTEventSource<ShowLongShipBootup>* GetEventSource()
		{
			using func_t = decltype(&ShowLongShipBootup::GetEventSource);
			static REL::Relocation<func_t> func{ ID::ShowLongShipBootup::GetEventSource };
			return func();
		}

		// members
		bool unk00;  // 00
	};
	static_assert(sizeof(ShowLongShipBootup) == 0x1);

	struct ShowSubtitleEvent
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<ShowSubtitleEvent::Event>* GetEventSource()
			{
				using func_t = decltype(&ShowSubtitleEvent::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::ShowSubtitleEvent::Event::GetEventSource };
				return func();
			}

			const char* subtitleText{ nullptr };  // 00
			const char* speakerName{ nullptr };   // 08
			bool        isPlayer{ false };        // 10
		};
		static_assert(sizeof(Event) == 0x18);
	};

	struct SkillsMenu_Accept
	{
		[[nodiscard]] static BSTEventSource<SkillsMenu_Accept>* GetEventSource()
		{
			using func_t = decltype(&SkillsMenu_Accept::GetEventSource);
			static REL::Relocation<func_t> func{ ID::SkillsMenu_Accept::GetEventSource };
			return func();
		}
	};

	struct SleepWaitMenu_InterruptRest
	{
		[[nodiscard]] static BSTEventSource<SleepWaitMenu_InterruptRest>* GetEventSource()
		{
			using func_t = decltype(&SleepWaitMenu_InterruptRest::GetEventSource);
			static REL::Relocation<func_t> func{ ID::SleepWaitMenu_InterruptRest::GetEventSource };
			return func();
		}
	};

	struct SleepWaitMenu_StartRest
	{
		[[nodiscard]] static BSTEventSource<SleepWaitMenu_StartRest>* GetEventSource()
		{
			using func_t = decltype(&SleepWaitMenu_StartRest::GetEventSource);
			static REL::Relocation<func_t> func{ ID::SleepWaitMenu_StartRest::GetEventSource };
			return func();
		}
	};

	namespace Spaceship
	{
		struct TakeOffEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::TakeOffEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::TakeOffEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::TakeOffEvent::GetEventSource };
				return func();
			}

			NiPointer<TESObjectREFR> ship;
			std::uint32_t            state;
		};

		struct GravJumpEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::GravJumpEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::GravJumpEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::GravJumpEvent::GetEventSource };
				return func();
			}

			NiPointer<TESObjectREFR> ship;
			std::uint32_t            state;
			NiPointer<BGSLocation>   destination;
		};

		struct LandedSetEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::LandedSetEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::LandedSetEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::LandedSetEvent::GetEventSource };
				return func();
			}
		};

		struct BoughtEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::BoughtEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::BoughtEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::BoughtEvent::GetEventSource };
				return func();
			}
		};

		struct ContrabandScanWarningEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::ContrabandScanWarningEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::ContrabandScanWarningEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::ContrabandScanWarningEvent::GetEventSource };
				return func();
			}
		};

		struct DockEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::DockEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::DockEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::DockEvent::GetEventSource };
				return func();
			}
		};

		struct DynamicNavmeshCompleted
		{
			[[nodiscard]] static BSTEventSource<Spaceship::DynamicNavmeshCompleted>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::DynamicNavmeshCompleted::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::DynamicNavmeshCompleted::GetEventSource };
				return func();
			}
		};

		struct FarTravelEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::FarTravelEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::FarTravelEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::FarTravelEvent::GetEventSource };
				return func();
			}
		};

		struct LandingEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::LandingEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::LandingEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::LandingEvent::GetEventSource };
				return func();
			}
		};

		struct PlanetScanEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::PlanetScanEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::PlanetScanEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::PlanetScanEvent::GetEventSource };
				return func();
			}
		};

		struct RampDownEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::RampDownEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::RampDownEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::RampDownEvent::GetEventSource };
				return func();
			}
		};

		struct RefueledEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::RefueledEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::RefueledEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::RefueledEvent::GetEventSource };
				return func();
			}
		};

		struct RegisteredEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::RegisteredEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::RegisteredEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::RegisteredEvent::GetEventSource };
				return func();
			}
		};

		struct ShieldEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::ShieldEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::ShieldEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::ShieldEvent::GetEventSource };
				return func();
			}
		};

		struct ShipAddedEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::ShipAddedEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::ShipAddedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::ShipAddedEvent::GetEventSource };
				return func();
			}
		};

		struct ShipCollisionEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::ShipCollisionEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::ShipCollisionEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::ShipCollisionEvent::GetEventSource };
				return func();
			}
		};

		struct ShipCustomizedEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::ShipCustomizedEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::ShipCustomizedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::ShipCustomizedEvent::GetEventSource };
				return func();
			}
		};

		struct SoldEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::SoldEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::SoldEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::SoldEvent::GetEventSource };
				return func();
			}
		};

		struct SystemDamagedEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::SystemDamagedEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::SystemDamagedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::SystemDamagedEvent::GetEventSource };
				return func();
			}
		};

		struct SystemPowerAllocationEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::SystemPowerAllocationEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::SystemPowerAllocationEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::SystemPowerAllocationEvent::GetEventSource };
				return func();
			}
		};

		struct SystemPowerChangeEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::SystemPowerChangeEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::SystemPowerChangeEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::SystemPowerChangeEvent::GetEventSource };
				return func();
			}
		};

		struct SystemRepairedBIEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::SystemRepairedBIEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::SystemRepairedBIEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::SystemRepairedBIEvent::GetEventSource };
				return func();
			}
		};

		struct SystemRepairedEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::SystemRepairedEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::SystemRepairedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::SystemRepairedEvent::GetEventSource };
				return func();
			}
		};

		struct TakeDamagEvent
		{
			[[nodiscard]] static BSTEventSource<Spaceship::TakeDamagEvent>* GetEventSource()
			{
				using func_t = decltype(&Spaceship::TakeDamagEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Spaceship::TakeDamagEvent::GetEventSource };
				return func();
			}
		};
	};

	struct SpaceshipBIEvents
	{
		struct ShipPowerAllocationBIEventSent
		{
			[[nodiscard]] static BSTEventSource<SpaceshipBIEvents::ShipPowerAllocationBIEventSent>* GetEventSource()
			{
				using func_t = decltype(&SpaceshipBIEvents::ShipPowerAllocationBIEventSent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::SpaceshipBIEvents::ShipPowerAllocationBIEventSent::GetEventSource };
				return func();
			}
		};
	};

	struct SpaceshipWeaponBinding
	{
		struct SpaceshipWeaponBindingChangedEvent
		{
			[[nodiscard]] static BSTEventSource<SpaceshipWeaponBinding::SpaceshipWeaponBindingChangedEvent>* GetEventSource()
			{
				using func_t = decltype(&SpaceshipWeaponBinding::SpaceshipWeaponBindingChangedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::SpaceshipWeaponBinding::SpaceshipWeaponBindingChangedEvent::GetEventSource };
				return func();
			}
		};
	};

	struct SpellsLearned
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<SpellsLearned::Event>* GetEventSource()
			{
				using func_t = decltype(&SpellsLearned::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::SpellsLearned::Event::GetEventSource };
				return func();
			}

			// members
			SpellItem* spell;  // 00
		};
		static_assert(sizeof(SpellsLearned::Event) == 0x8);
	};

	struct StarMap
	{
		struct PlanetTraitKnownEvent
		{
			[[nodiscard]] static BSTEventSource<StarMap::PlanetTraitKnownEvent>* GetEventSource()
			{
				using func_t = decltype(&StarMap::PlanetTraitKnownEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::StarMap::PlanetTraitKnownEvent::GetEventSource };
				return func();
			}
		};
	};

	struct StarMapMenu_LandingInputInProgress
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_LandingInputInProgress>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_LandingInputInProgress::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_LandingInputInProgress::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_MarkerGroupContainerVisibilityChanged
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_MarkerGroupContainerVisibilityChanged>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_MarkerGroupContainerVisibilityChanged::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_MarkerGroupContainerVisibilityChanged::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_MarkerGroupEntryClicked
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_MarkerGroupEntryClicked>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_MarkerGroupEntryClicked::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_MarkerGroupEntryClicked::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_MarkerGroupEntryHoverChanged
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_MarkerGroupEntryHoverChanged>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_MarkerGroupEntryHoverChanged::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_MarkerGroupEntryHoverChanged::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_ScanPlanet
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_ScanPlanet>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_ScanPlanet::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_ScanPlanet::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_SelectedLandingSite
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_SelectedLandingSite>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_SelectedLandingSite::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_SelectedLandingSite::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_SelectedLandingSiteFailed
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_SelectedLandingSiteFailed>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_SelectedLandingSiteFailed::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_SelectedLandingSiteFailed::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_ShowRealCursor
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_ShowRealCursor>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_ShowRealCursor::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_ShowRealCursor::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_QuickSelectChange
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_QuickSelectChange>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_QuickSelectChange::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_QuickSelectChange::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_Galaxy_FocusSystem
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_Galaxy_FocusSystem>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_Galaxy_FocusSystem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_Galaxy_FocusSystem::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_OnGalaxyViewInitialized
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_OnGalaxyViewInitialized>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_OnGalaxyViewInitialized::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_OnGalaxyViewInitialized::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_ExecuteRoute
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_ExecuteRoute>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_ExecuteRoute::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_ExecuteRoute::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_OnCancel
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_OnCancel>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_OnCancel::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_OnCancel::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_OnClearRoute
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_OnClearRoute>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_OnClearRoute::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_OnClearRoute::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_OnExitStarMap
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_OnExitStarMap>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_OnExitStarMap::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_OnExitStarMap::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_OnHintButtonClicked
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_OnHintButtonClicked>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_OnHintButtonClicked::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_OnHintButtonClicked::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_OnOutpostEntrySelected
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_OnOutpostEntrySelected>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_OnOutpostEntrySelected::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_OnOutpostEntrySelected::GetEventSource };
			return func();
		}
	};

	struct StarMapMenu_ReadyToClose
	{
		[[nodiscard]] static BSTEventSource<StarMapMenu_ReadyToClose>* GetEventSource()
		{
			using func_t = decltype(&StarMapMenu_ReadyToClose::GetEventSource);
			static REL::Relocation<func_t> func{ ID::StarMapMenu_ReadyToClose::GetEventSource };
			return func();
		}
	};

	struct SurfaceMapMenu_MarkerClicked
	{
		[[nodiscard]] static BSTEventSource<SurfaceMapMenu_MarkerClicked>* GetEventSource()
		{
			using func_t = decltype(&SurfaceMapMenu_MarkerClicked::GetEventSource);
			static REL::Relocation<func_t> func{ ID::SurfaceMapMenu_MarkerClicked::GetEventSource };
			return func();
		}
	};

	struct SurfaceMapMenu_TryPlaceCustomMarker
	{
		[[nodiscard]] static BSTEventSource<SurfaceMapMenu_TryPlaceCustomMarker>* GetEventSource()
		{
			using func_t = decltype(&SurfaceMapMenu_TryPlaceCustomMarker::GetEventSource);
			static REL::Relocation<func_t> func{ ID::SurfaceMapMenu_TryPlaceCustomMarker::GetEventSource };
			return func();
		}
	};

	struct TakeoffMenu_ExitShip
	{
		[[nodiscard]] static BSTEventSource<TakeoffMenu_ExitShip>* GetEventSource()
		{
			using func_t = decltype(&TakeoffMenu_ExitShip::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TakeoffMenu_ExitShip::GetEventSource };
			return func();
		}
	};

	struct TakeoffMenu_Launch
	{
		[[nodiscard]] static BSTEventSource<TakeoffMenu_Launch>* GetEventSource()
		{
			using func_t = decltype(&TakeoffMenu_Launch::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TakeoffMenu_Launch::GetEventSource };
			return func();
		}
	};

	struct TargetHitEvent
	{
		[[nodiscard]] static BSTEventSource<TargetHitEvent>* GetEventSource()
		{
			using func_t = decltype(&TargetHitEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TargetHitEvent::GetEventSource };
			return func();
		}
	};

	struct Terminal_CloseAllViews
	{
		[[nodiscard]] static BSTEventSource<Terminal_CloseAllViews>* GetEventSource()
		{
			using func_t = decltype(&Terminal_CloseAllViews::GetEventSource);
			static REL::Relocation<func_t> func{ ID::Terminal_CloseAllViews::GetEventSource };
			return func();
		}
	};

	struct Terminal_CloseTopView
	{
		[[nodiscard]] static BSTEventSource<Terminal_CloseTopView>* GetEventSource()
		{
			using func_t = decltype(&Terminal_CloseTopView::GetEventSource);
			static REL::Relocation<func_t> func{ ID::Terminal_CloseTopView::GetEventSource };
			return func();
		}
	};

	struct Terminal_CloseView
	{
		[[nodiscard]] static BSTEventSource<Terminal_CloseView>* GetEventSource()
		{
			using func_t = decltype(&Terminal_CloseView::GetEventSource);
			static REL::Relocation<func_t> func{ ID::Terminal_CloseView::GetEventSource };
			return func();
		}
	};

	struct TerminalHacked
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<TerminalHacked::Event>* GetEventSource()
			{
				using func_t = decltype(&TerminalHacked::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::TerminalHacked::Event::GetEventSource };
				return func();
			}
		};
	};

	struct TerminalMenu_CancelEvent
	{
		[[nodiscard]] static BSTEventSource<TerminalMenu_CancelEvent>* GetEventSource()
		{
			using func_t = decltype(&TerminalMenu_CancelEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TerminalMenu_CancelEvent::GetEventSource };
			return func();
		}
	};

	struct TESActivateEvent
	{
		[[nodiscard]] static BSTEventSource<TESActivateEvent>* GetEventSource()
		{
			using func_t = decltype(&TESActivateEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESActivateEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> target;  // 00
		NiPointer<TESObjectREFR> source;  // 08
	};
	static_assert(sizeof(TESActivateEvent) == 0x10);

	struct TESActorActivatedRefEvent
	{
		[[nodiscard]] static BSTEventSource<TESActorActivatedRefEvent>* GetEventSource()
		{
			using func_t = decltype(&TESActorActivatedRefEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESActorActivatedRefEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<Actor>         actor;   // 00
		NiPointer<TESObjectREFR> target;  // 08
	};
	static_assert(sizeof(TESActorActivatedRefEvent) == 0x10);

	struct TESActorLocationChangeEvent
	{
		[[nodiscard]] static BSTEventSource<TESActorLocationChangeEvent>* GetEventSource()
		{
			using func_t = decltype(&TESActorLocationChangeEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESActorLocationChangeEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<Actor> actor;        // 00
		BGSLocation*     oldLocation;  // 08
		BGSLocation*     newLocation;  // 10
	};
	static_assert(sizeof(TESActorLocationChangeEvent) == 0x18);

	struct TESBookReadEvent
	{
		[[nodiscard]] static BSTEventSource<TESBookReadEvent>* GetEventSource()
		{
			using func_t = decltype(&TESBookReadEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESBookReadEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> ref;  // 00
	};
	static_assert(sizeof(TESBookReadEvent) == 0x8);

	struct TESCellFullyLoadedEvent
	{
		[[nodiscard]] static BSTEventSource<TESCellFullyLoadedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESCellFullyLoadedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESCellFullyLoadedEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<TESObjectCELL> cell;  // 00
	};
	static_assert(sizeof(TESCellFullyLoadedEvent) == 0x8);

	struct TESCellNavmeshGeneratedEvent
	{
		[[nodiscard]] static BSTEventSource<TESCellNavmeshGeneratedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESCellNavmeshGeneratedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESCellNavmeshGeneratedEvent::GetEventSource };
			return func();
		}
	};

	struct TESCombatEvent
	{
		[[nodiscard]] static BSTEventSource<TESCombatEvent>* GetEventSource()
		{
			using func_t = decltype(&TESCombatEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESCombatEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<Actor>   source;  // 00
		NiPointer<Actor>   target;  // 08 - nullptr when combat state is none
		ACTOR_COMBAT_STATE state;   // 10
	};
	static_assert(sizeof(TESCombatEvent) == 0x18);

	struct TESContainerChangedEvent
	{
		[[nodiscard]] static BSTEventSource<TESContainerChangedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESContainerChangedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESContainerChangedEvent::GetEventSource };
			return func();
		}

		// members
		TESFormID     source;      // 00
		TESFormID     target;      // 04
		TESFormID     baseObject;  // 08
		std::uint32_t itemCount;   // 0C
		TESFormID     itemRef;     // 10
		std::uint16_t uniqueID;    // 14
		std::uint64_t unk18;       // 18
		std::uint32_t unk20;       // 20
	};
	static_assert(sizeof(TESContainerChangedEvent) == 0x28);

	struct TESDeathEvent
	{
		[[nodiscard]] static BSTEventSource<TESDeathEvent>* GetEventSource()
		{
			using func_t = decltype(&TESDeathEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESDeathEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<Actor> actorDying;   // 00
		NiPointer<Actor> actorKiller;  // 08
		bool             dead;         // 10
	};
	static_assert(sizeof(TESDeathEvent) == 0x18);

	struct TESEquipEvent
	{
		[[nodiscard]] static BSTEventSource<TESEquipEvent>* GetEventSource()
		{
			using func_t = decltype(&TESEquipEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESEquipEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<Actor> actor;       // 00
		TESFormID        baseObject;  // 08
		TESFormID        origRef;     // 0C
		std::uint16_t    uniqueID;    // 10
		bool             equipped;    // 12
	};
	static_assert(sizeof(TESEquipEvent) == 0x18);

	struct TESFormDeleteEvent
	{
		[[nodiscard]] static BSTEventSource<TESFormDeleteEvent>* GetEventSource()
		{
			using func_t = decltype(&TESFormDeleteEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESFormDeleteEvent::GetEventSource };
			return func();
		}

		// members
		TESFormID formID;  // 00
	};
	static_assert(sizeof(TESFormDeleteEvent) == 0x4);

	struct TESFormIDRemapEvent
	{
		[[nodiscard]] static BSTEventSource<TESFormIDRemapEvent>* GetEventSource()
		{
			using func_t = decltype(&TESFormIDRemapEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESFormIDRemapEvent::GetEventSource };
			return func();
		}

		// members
		TESFormID oldFormID;  // 00
		TESFormID newFormID;  // 04
	};
	static_assert(sizeof(TESFormIDRemapEvent) == 0x8);

	struct TESFurnitureEvent
	{
		enum class Type : std::int32_t
		{
			kEnter,
			kExit
		};

		[[nodiscard]] static BSTEventSource<TESFurnitureEvent>* GetEventSource()
		{
			using func_t = decltype(&TESFurnitureEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESFurnitureEvent::GetEventSource };
			return func();
		}

		[[nodiscard]] constexpr bool IsEnter() const noexcept { return type == Type::kEnter; }
		[[nodiscard]] constexpr bool IsExit() const noexcept { return type == Type::kExit; }

		// members
		std::byte                pad00[0x8];  // 00 - wtf is this now? it used to be an NiPointer<Actor> in previous games
		NiPointer<TESObjectREFR> furniture;   // 08
		Type                     type;        // 10
	};
	static_assert(sizeof(TESFurnitureEvent) == 0x18);

	struct TESGrabReleaseEvent
	{
		[[nodiscard]] static BSTEventSource<TESGrabReleaseEvent>* GetEventSource()
		{
			using func_t = decltype(&TESGrabReleaseEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESGrabReleaseEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> target;   // 00
		bool                     grabbed;  // 08
	};
	static_assert(sizeof(TESGrabReleaseEvent) == 0x10);

	struct TESHarvestEvent
	{
		struct ItemHarvested
		{
			[[nodiscard]] static BSTEventSource<TESHarvestEvent::ItemHarvested>* GetEventSource()
			{
				using func_t = decltype(&TESHarvestEvent::ItemHarvested::GetEventSource);
				static REL::Relocation<func_t> func{ ID::TESHarvestEvent::ItemHarvested::GetEventSource };
				return func();
			}

			// members
			TESBoundObject*          item;     // 00
			NiPointer<TESObjectREFR> itemRef;  // 08
			NiPointer<Actor>         actor;    // 10
		};
		static_assert(sizeof(TESHarvestEvent::ItemHarvested) == 0x18);
	};

	struct DamageImpactData
	{
		// members
		NiPoint3A                       location;  // 00
		NiPoint3A                       normal;    // 10
		NiPoint3A                       velocity;  // 20
		NiPointer<bhkNPCollisionObject> colObj;    // 30
	};
	static_assert(sizeof(DamageImpactData) == 0x40);

	class HitData
	{
	public:
		// members
		DamageImpactData                       impactData;      // 00
		BSPointerHandle<Actor>                 aggressor;       // 40
		BSPointerHandle<Actor>                 target;          // 44
		BSPointerHandle<TESObjectREFR>         sourceRef;       // 48
		std::uint64_t                          attackData;      // 50 - NiPointer<BGSAttackData>
		BGSObjectInstanceT<TESObjectWEAP>      weapon;          // 58
		SpellItem*                             criticalEffect;  // 68
		SpellItem*                             hitEffect;       // 70
		std::uint64_t                          unk78;           // 78
		const TESAmmo*                         ammo;            // 80
		std::byte                              pad88[0x5C];     // 88
		REX::TEnum<BGSBodyPartDefs::LIMB_ENUM> damageLimb;      // E4
		std::byte                              padE8[0x8];      // E8
	};
	static_assert(sizeof(HitData) == 0xF0);

	struct TESHitEvent
	{
		[[nodiscard]] static BSTEventSource<TESHitEvent>* GetEventSource()
		{
			using func_t = decltype(&TESHitEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESHitEvent::GetEventSource };
			return func();
		}

		// members
		HitData                  hitData;           // 000
		NiPointer<TESObjectREFR> target;            // 0F0
		NiPointer<TESObjectREFR> cause;             // 0F8
		BSFixedString            material;          // 100
		TESFormID                sourceFormID;      // 108
		TESFormID                projectileFormID;  // 10C
		bool                     usesHitData;       // 110
	};
	static_assert(sizeof(TESHitEvent) == 0x120);

	struct TESLoadGameEvent
	{
		[[nodiscard]] static BSTEventSource<TESLoadGameEvent>* GetEventSource()
		{
			using func_t = decltype(&TESLoadGameEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESLoadGameEvent::GetEventSource };
			return func();
		}
	};

	struct TESLockChangedEvent
	{
		[[nodiscard]] static BSTEventSource<TESLockChangedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESLockChangedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESLockChangedEvent::GetEventSource };
			return func();
		}

		// members
		const NiPointer<TESObjectREFR> ref;
	};
	static_assert(sizeof(TESLockChangedEvent) == 0x8);

	struct TESMissionAcceptedEvent
	{
		[[nodiscard]] static BSTEventSource<TESMissionAcceptedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESMissionAcceptedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESMissionAcceptedEvent::GetEventSource };
			return func();
		}
	};

	struct TESObjectLoadedEvent
	{
		[[nodiscard]] static BSTEventSource<TESObjectLoadedEvent>* GetEventSource()
		{
			using func_t = decltype(&TESObjectLoadedEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESObjectLoadedEvent::GetEventSource };
			return func();
		}

		// members
		TESFormID     formID;  // 00
		bool          loaded;  // 04
		std::uint8_t  pad05;   // 05
		std::uint16_t pad06;   // 06
	};
	static_assert(sizeof(TESObjectLoadedEvent) == 0x8);

	struct TESPickNewIdleEvent
	{
		[[nodiscard]] static BSTEventSource<TESPickNewIdleEvent>* GetEventSource()
		{
			using func_t = decltype(&TESPickNewIdleEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESPickNewIdleEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<Actor> actor;  // 00
	};
	static_assert(sizeof(TESPickNewIdleEvent) == 0x8);

	struct TESPlayerFollowerWarpEvent
	{
		[[nodiscard]] static BSTEventSource<TESPlayerFollowerWarpEvent>* GetEventSource()
		{
			using func_t = decltype(&TESPlayerFollowerWarpEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESPlayerFollowerWarpEvent::GetEventSource };
			return func();
		}
	};

	struct TESQuestRewardEvent
	{
		[[nodiscard]] static BSTEventSource<TESQuestRewardEvent>* GetEventSource()
		{
			using func_t = decltype(&TESQuestRewardEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESQuestRewardEvent::GetEventSource };
			return func();
		}
	};

	struct TESResetEvent
	{
		[[nodiscard]] static BSTEventSource<TESResetEvent>* GetEventSource()
		{
			using func_t = decltype(&TESResetEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESResetEvent::GetEventSource };
			return func();
		}

		// members
		NiPointer<TESObjectREFR> ref;  // 00
	};
	static_assert(sizeof(TESResetEvent) == 0x8);

	struct TESResolveNPCTemplatesEvent
	{
		[[nodiscard]] static BSTEventSource<TESResolveNPCTemplatesEvent>* GetEventSource()
		{
			using func_t = decltype(&TESResolveNPCTemplatesEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESResolveNPCTemplatesEvent::GetEventSource };
			return func();
		}

		// members
		TESFormID formID;  // 00
	};
	static_assert(sizeof(TESResolveNPCTemplatesEvent) == 0x4);

	struct TESSleepStartEvent
	{
		[[nodiscard]] static BSTEventSource<TESSleepStartEvent>* GetEventSource()
		{
			using func_t = decltype(&TESSleepStartEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESSleepStartEvent::GetEventSource };
			return func();
		}

		// members
		float                    timeStart;  // 00
		float                    timeEnd;    // 04
		NiPointer<TESObjectREFR> bed;        // 08
	};
	static_assert(sizeof(TESSleepStartEvent) == 0x10);

	struct TESSleepStopEvent
	{
		[[nodiscard]] static BSTEventSource<TESSleepStopEvent>* GetEventSource()
		{
			using func_t = decltype(&TESSleepStopEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::TESSleepStopEvent::GetEventSource };
			return func();
		}

		// members
		bool                     interrupted;  // 00
		NiPointer<TESObjectREFR> bed;          // 01
	};
	static_assert(sizeof(TESSleepStopEvent) == 0x10);

	struct TraitDiscoveryTextEvent
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<TraitDiscoveryTextEvent::Event>* GetEventSource()
			{
				using func_t = decltype(&TraitDiscoveryTextEvent::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::TraitDiscoveryTextEvent::Event::GetEventSource };
				return func();
			}
		};
	};

	struct TryUpdateShipHudTarget
	{
		struct Event
		{
			[[nodiscard]] static BSTEventSource<TryUpdateShipHudTarget::Event>* GetEventSource()
			{
				using func_t = decltype(&TryUpdateShipHudTarget::Event::GetEventSource);
				static REL::Relocation<func_t> func{ ID::TryUpdateShipHudTarget::Event::GetEventSource };
				return func();
			}
		};
	};

	struct UIMenuChargenMenuDisablePaperdoll
	{
		[[nodiscard]] static BSTEventSource<UIMenuChargenMenuDisablePaperdoll>* GetEventSource()
		{
			using func_t = decltype(&UIMenuChargenMenuDisablePaperdoll::GetEventSource);
			static REL::Relocation<func_t> func{ ID::UIMenuChargenMenuDisablePaperdoll::GetEventSource };
			return func();
		}
	};

	struct UnlockedTerminalElementEvent
	{
		[[nodiscard]] static BSTEventSource<UnlockedTerminalElementEvent>* GetEventSource()
		{
			using func_t = decltype(&UnlockedTerminalElementEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::UnlockedTerminalElementEvent::GetEventSource };
			return func();
		}
	};

	struct UpdateActivateListenerEvent
	{
		[[nodiscard]] static BSTEventSource<UpdateActivateListenerEvent>* GetEventSource()
		{
			using func_t = decltype(&UpdateActivateListenerEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::UpdateActivateListenerEvent::GetEventSource };
			return func();
		}
	};

	struct UpdateSceneRectEvent
	{
		[[nodiscard]] static BSTEventSource<UpdateSceneRectEvent>* GetEventSource()
		{
			using func_t = decltype(&UpdateSceneRectEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::UpdateSceneRectEvent::GetEventSource };
			return func();
		}
	};

	struct WeaponFiredEvent
	{
		[[nodiscard]] static auto GetEventSource()
		{
			static REL::Relocation<BSTEventSource<WeaponFiredEvent>*> ptr{ ID::WeaponFiredEvent::GetEventSource };
			return ptr.get();
		}

		// members
		void*            unk00;  // 00
		void*            unk08;  // 08
		NiPointer<Actor> actor;  // 10
	};

	struct Workshop
	{
		struct CargoLinkAddedEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::CargoLinkAddedEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::CargoLinkAddedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::CargoLinkAddedEvent::GetEventSource };
				return func();
			}
		};

		struct CargoLinkTargetChangedEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::CargoLinkTargetChangedEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::CargoLinkTargetChangedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::CargoLinkTargetChangedEvent::GetEventSource };
				return func();
			}
		};

		struct EnterOutpostBeaconModeEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::EnterOutpostBeaconModeEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::EnterOutpostBeaconModeEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::EnterOutpostBeaconModeEvent::GetEventSource };
				return func();
			}
		};

		struct ItemGrabbedEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::ItemGrabbedEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::ItemGrabbedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::ItemGrabbedEvent::GetEventSource };
				return func();
			}
		};

		struct ItemMovedEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::ItemMovedEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::ItemMovedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::ItemMovedEvent::GetEventSource };
				return func();
			}

			// members
			NiPointer<TESObjectREFR> workshop;  // 00
			NiPointer<TESObjectREFR> item;      // 08
			NiPointer<TESObjectREFR> source;    // 10 - game always passes PlayerCharacter?
		};
		static_assert(sizeof(ItemMovedEvent) == 0x18);

		struct ItemPlacedEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::ItemPlacedEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::ItemPlacedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::ItemPlacedEvent::GetEventSource };
				return func();
			}

			// members
			bool                     unk00;     // 00
			NiPointer<TESObjectREFR> workshop;  // 08
			NiPointer<TESObjectREFR> item;      // 10
			NiPointer<TESObjectREFR> source;    // 18 - game always passes PlayerCharacter?
		};
		static_assert(sizeof(ItemPlacedEvent) == 0x20);

		struct ItemProducedEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::ItemProducedEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::ItemProducedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::ItemProducedEvent::GetEventSource };
				return func();
			}
		};

		struct ItemRemovedEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::ItemRemovedEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::ItemRemovedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::ItemRemovedEvent::GetEventSource };
				return func();
			}

			// members
			NiPointer<TESObjectREFR> workshop;  // 00
			NiPointer<TESObjectREFR> item;      // 08
			NiPointer<TESObjectREFR> source;    // 10 - game always passes PlayerCharacter?
		};
		static_assert(sizeof(ItemRemovedEvent) == 0x18);

		struct ItemRepairedEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::ItemRepairedEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::ItemRepairedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::ItemRepairedEvent::GetEventSource };
				return func();
			}
		};

		struct ItemScrappedEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::ItemScrappedEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::ItemScrappedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::ItemScrappedEvent::GetEventSource };
				return func();
			}
		};

		struct OutpostNameChangedEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::OutpostNameChangedEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::OutpostNameChangedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::OutpostNameChangedEvent::GetEventSource };
				return func();
			}
		};

		struct OutpostPlacedEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::OutpostPlacedEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::OutpostPlacedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::OutpostPlacedEvent::GetEventSource };
				return func();
			}
		};

		struct PlacementStatusEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::PlacementStatusEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::PlacementStatusEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::PlacementStatusEvent::GetEventSource };
				return func();
			}
		};

		struct PowerOffEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::PowerOffEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::PowerOffEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::PowerOffEvent::GetEventSource };
				return func();
			}
		};

		struct PowerOnEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::PowerOnEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::PowerOnEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::PowerOnEvent::GetEventSource };
				return func();
			}
		};

		struct SnapBehaviorCycledEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::SnapBehaviorCycledEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::SnapBehaviorCycledEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::SnapBehaviorCycledEvent::GetEventSource };
				return func();
			}
		};

		struct WorkshopFlyCameraEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::WorkshopFlyCameraEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::WorkshopFlyCameraEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::WorkshopFlyCameraEvent::GetEventSource };
				return func();
			}
		};

		struct WorkshopItemPlacedEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::WorkshopItemPlacedEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::WorkshopItemPlacedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::WorkshopItemPlacedEvent::GetEventSource };
				return func();
			}

			// members
			NiPointer<TESObjectREFR> workshop;  // 00
		};

		struct WorkshopModeEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::WorkshopModeEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::WorkshopModeEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::WorkshopModeEvent::GetEventSource };
				return func();
			}

			// members
			NiPointer<TESObjectREFR> workshop;  // 00
			NiPointer<TESObjectREFR> source;    // 08 - game always passes PlayerCharacter?
		};

		struct WorkshopOutputLinkEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::WorkshopOutputLinkEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::WorkshopOutputLinkEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::WorkshopOutputLinkEvent::GetEventSource };
				return func();
			}
		};

		struct WorkshopStatsChangedEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::WorkshopStatsChangedEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::WorkshopStatsChangedEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::WorkshopStatsChangedEvent::GetEventSource };
				return func();
			}
		};

		struct WorkshopUpdateStatsEvent
		{
			[[nodiscard]] static BSTEventSource<Workshop::WorkshopUpdateStatsEvent>* GetEventSource()
			{
				using func_t = decltype(&Workshop::WorkshopUpdateStatsEvent::GetEventSource);
				static REL::Relocation<func_t> func{ ID::Workshop::WorkshopUpdateStatsEvent::GetEventSource };
				return func();
			}
		};
	};

	struct WorkshopBuilderMenu_ChangeBuildItem
	{
		[[nodiscard]] static BSTEventSource<WorkshopBuilderMenu_ChangeBuildItem>* GetEventSource()
		{
			using func_t = decltype(&WorkshopBuilderMenu_ChangeBuildItem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::WorkshopBuilderMenu_ChangeBuildItem::GetEventSource };
			return func();
		}
	};

	struct WorkshopBuilderMenu_SelectedItem
	{
		[[nodiscard]] static BSTEventSource<WorkshopBuilderMenu_SelectedItem>* GetEventSource()
		{
			using func_t = decltype(&WorkshopBuilderMenu_SelectedItem::GetEventSource);
			static REL::Relocation<func_t> func{ ID::WorkshopBuilderMenu_SelectedItem::GetEventSource };
			return func();
		}
	};

	struct WorkshopBuilderMenu_ToggleTracking
	{
		[[nodiscard]] static BSTEventSource<WorkshopBuilderMenu_ToggleTracking>* GetEventSource()
		{
			using func_t = decltype(&WorkshopBuilderMenu_ToggleTracking::GetEventSource);
			static REL::Relocation<func_t> func{ ID::WorkshopBuilderMenu_ToggleTracking::GetEventSource };
			return func();
		}
	};

	struct WorkshopMenu_AttemptBuild
	{
		[[nodiscard]] static BSTEventSource<WorkshopMenu_AttemptBuild>* GetEventSource()
		{
			using func_t = decltype(&WorkshopMenu_AttemptBuild::GetEventSource);
			static REL::Relocation<func_t> func{ ID::WorkshopMenu_AttemptBuild::GetEventSource };
			return func();
		}
	};

	struct WorkshopMenu_ChangeVariant
	{
		[[nodiscard]] static BSTEventSource<WorkshopMenu_ChangeVariant>* GetEventSource()
		{
			using func_t = decltype(&WorkshopMenu_ChangeVariant::GetEventSource);
			static REL::Relocation<func_t> func{ ID::WorkshopMenu_ChangeVariant::GetEventSource };
			return func();
		}
	};

	struct WorkshopMenu_ConnectionEvent
	{
		[[nodiscard]] static BSTEventSource<WorkshopMenu_ConnectionEvent>* GetEventSource()
		{
			using func_t = decltype(&WorkshopMenu_ConnectionEvent::GetEventSource);
			static REL::Relocation<func_t> func{ ID::WorkshopMenu_ConnectionEvent::GetEventSource };
			return func();
		}
	};

	struct WorkshopMenu_SelectedCategory
	{
		[[nodiscard]] static BSTEventSource<WorkshopMenu_SelectedCategory>* GetEventSource()
		{
			using func_t = decltype(&WorkshopMenu_SelectedCategory::GetEventSource);
			static REL::Relocation<func_t> func{ ID::WorkshopMenu_SelectedCategory::GetEventSource };
			return func();
		}
	};

	struct WorkshopMenu_SelectedGridObject
	{
		[[nodiscard]] static BSTEventSource<WorkshopMenu_SelectedGridObject>* GetEventSource()
		{
			using func_t = decltype(&WorkshopMenu_SelectedGridObject::GetEventSource);
			static REL::Relocation<func_t> func{ ID::WorkshopMenu_SelectedGridObject::GetEventSource };
			return func();
		}
	};

	struct WorkshopMenu_ShowExtras
	{
		[[nodiscard]] static BSTEventSource<WorkshopMenu_ShowExtras>* GetEventSource()
		{
			using func_t = decltype(&WorkshopMenu_ShowExtras::GetEventSource);
			static REL::Relocation<func_t> func{ ID::WorkshopMenu_ShowExtras::GetEventSource };
			return func();
		}
	};

	struct WorkshopMenu_SwitchMode
	{
		[[nodiscard]] static BSTEventSource<WorkshopMenu_SwitchMode>* GetEventSource()
		{
			using func_t = decltype(&WorkshopMenu_SwitchMode::GetEventSource);
			static REL::Relocation<func_t> func{ ID::WorkshopMenu_SwitchMode::GetEventSource };
			return func();
		}
	};

	struct WorkshopMenu_ToggleDistance
	{
		[[nodiscard]] static BSTEventSource<WorkshopMenu_ToggleDistance>* GetEventSource()
		{
			using func_t = decltype(&WorkshopMenu_ToggleDistance::GetEventSource);
			static REL::Relocation<func_t> func{ ID::WorkshopMenu_ToggleDistance::GetEventSource };
			return func();
		}
	};

	struct WorkshopMenu_ToggleTracking
	{
		[[nodiscard]] static BSTEventSource<WorkshopMenu_ToggleTracking>* GetEventSource()
		{
			using func_t = decltype(&WorkshopMenu_ToggleTracking::GetEventSource);
			static REL::Relocation<func_t> func{ ID::WorkshopMenu_ToggleTracking::GetEventSource };
			return func();
		}
	};

	struct WorkshopMenu_ToggleView
	{
		[[nodiscard]] static BSTEventSource<WorkshopMenu_ToggleView>* GetEventSource()
		{
			using func_t = decltype(&WorkshopMenu_ToggleView::GetEventSource);
			static REL::Relocation<func_t> func{ ID::WorkshopMenu_ToggleView::GetEventSource };
			return func();
		}
	};
}
