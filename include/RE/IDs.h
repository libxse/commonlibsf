#pragma once

namespace RE::ID
{
	namespace Activation::Event
	{
		inline constexpr REL::ID GetEventSource{ 63133 };  // 106834
	}

	namespace ActivityEvents::ActivityCompletedEvent
	{
		inline constexpr REL::ID GetEventSource{ 47920 };  // 86737
	}

	namespace Actor
	{
		inline constexpr REL::ID EvaluatePackage{ 0 };    // 150640
		inline constexpr REL::ID GetActorKnowledge{ 0 };  // 150669
		inline constexpr REL::ID IsHostileToActor{ 0 };   // 150777
		inline constexpr REL::ID IsJumping{ 0 };          // 150985
		inline constexpr REL::ID IsOverEncumbered{ 0 };   // 150999
		inline constexpr REL::ID IsSneaking{ 0 };         // 151014
		inline constexpr REL::ID SetSkinTone{ 97400 };
		inline constexpr REL::ID UpdateAppearance{ 101306 };
		inline constexpr REL::ID UpdateChargenAppearance{ 97399 };
	}

	namespace ActorUtils
	{
		inline constexpr REL::ID ChangeAnimArchetype{ 0 };  // 150497
	}

	namespace ActorValue
	{
		inline constexpr REL::ID GetSingleton{ 0 };  // 36266
	}

	namespace ActorEquipManager
	{
		inline constexpr REL::ID Singleton{ 0 };      // 879425
		inline constexpr REL::ID EquipObject{ 0 };    // 151991
		inline constexpr REL::ID UnequipObject{ 0 };  // 152007
	}

	namespace ActorCellChangeEvent::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107081
	}

	namespace ActorItemEquipped::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 151162
	}

	namespace AttachReference::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 778826
	}

	namespace AutoLoadDoorRolloverEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 103703
	}

	namespace BarterMenu_BuyItem
	{
		inline constexpr REL::ID GetEventSource{ 91373 };  // 138993
	}

	namespace BarterMenu_CloseMenu
	{
		inline constexpr REL::ID GetEventSource{ 91378 };  // 138994
	}

	namespace BarterMenu_HideModel
	{
		inline constexpr REL::ID GetEventSource{ 91376 };  // 138995
	}

	namespace BarterMenu_LoadModel
	{
		inline constexpr REL::ID GetEventSource{ 91377 };  // 138996
	}

	namespace BarterMenu_SellItem
	{
		inline constexpr REL::ID GetEventSource{ 91372 };  // 138997
	}

	namespace BarterMenu_SetMouseOverModel
	{
		inline constexpr REL::ID GetEventSource{ 91371 };  // 138998
	}

	namespace BarterMenu_ViewedItem
	{
		inline constexpr REL::ID GetEventSource{ 91374 };  // 139000
	}

	namespace BaseExtraList
	{
		inline constexpr REL::ID AddExtra{ 44736 };
	}

	namespace BGSAcousticSpaceListener::StackChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 145815
	}

	namespace BGSAffinityEventEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107086
	}

	namespace BGSAppPausedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 167011
	}

	namespace BGSCellGridLoadEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107087
	}

	namespace BGSDefaultObjectManager
	{
		inline constexpr REL::ID DefaultObjectData{ 0 };  // 761776
		inline constexpr REL::ID GetSingleton{ 0 };       // 82283
	}

	namespace BGSEditorID
	{
		inline constexpr REL::ID Register{ 0 };  // 86172
	}

	namespace BGSEntryPoint
	{
		inline constexpr REL::ID HandleEntryPoint{ 0 };  // 110912
	}

	namespace BGSInventoryInterface
	{
		inline constexpr REL::ID Singleton{ 0 };           // 825787
		inline constexpr REL::ID GetInventoryObject{ 0 };  // 87520
	}

	namespace BGSObjectInstance
	{
		inline constexpr REL::ID ctor{ 0 };  // 101725
	}

	namespace BGSPlanet::PlayerKnowledgeFlagSetEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 92501
	}

	namespace BGSRadiationDamageEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107106
	}

	namespace BGSSaveLoadFileEntry
	{
		inline constexpr REL::ID LoadData{ 0 };  // 147331
	}

	namespace BGSSaveLoadGame
	{
		inline constexpr REL::ID SaveGame{ 0 };  // 147515
		inline constexpr REL::ID LoadGame{ 0 };  // 147564
	}

	namespace BGSSaveLoadManager
	{
		inline constexpr REL::ID IsLoadingAllowed{ 98657 };
		inline constexpr REL::ID DeleteSaveFile{ 0 };          // 147844
		inline constexpr REL::ID QueueBuildSaveGameList{ 0 };  // 147900
		inline constexpr REL::ID QueueSaveLoadTask{ 0 };       // 1536882
		inline constexpr REL::ID Singleton{ 883588 };
	}

	namespace BGSScannerGuideEffectStatusUpdateEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 138080
	}

	namespace BGSSceneActionPlayerDialogue::ActionEndEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 100215
	}

	namespace BGSStoryTeller
	{
		inline constexpr REL::ID Singleton{ 0 };  // 878850
	}

	namespace BinkMovieStoppedPlayingEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 131237
	}

	namespace BooksRead::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 103540
	}

	namespace Bounty::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 153651
	}

	namespace BSChargenAPI::BIDataUtils::PresetNPCChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141184
	}

	namespace BSInputEnableLayer
	{
		inline constexpr REL::ID SetUserFlags{ 0 };   // 106486
		inline constexpr REL::ID SetOtherFlags{ 0 };  // 109447
	}

	namespace BSInputEnableManager
	{
		inline constexpr REL::ID CreateLayer{ 0 };  // 179101
		inline constexpr REL::ID Singleton{ 0 };    // 878792
	}

	namespace BSInputEventUser
	{
		inline constexpr REL::ID Unk09{ 0 };  // 178899
	}

	namespace BSLog
	{
		inline constexpr REL::ID ctor{ 0 };               // 184813
		inline constexpr REL::ID dtor{ 0 };               // 184816
		inline constexpr REL::ID CycleLog{ 0 };           // 184822
		inline constexpr REL::ID FlushBuffer{ 0 };        // 184823
		inline constexpr REL::ID FlushBufferToFile{ 0 };  // 184824
		inline constexpr REL::ID GenerateTimeStamp{ 0 };  // 184825
		inline constexpr REL::ID MakeLogFilename{ 0 };    // 184826
		inline constexpr REL::ID WriteData{ 0 };          // 184832
		inline constexpr REL::ID WriteEntry{ 0 };         // 184833
	}

	namespace BSNonReentrantSpinLock
	{
		inline constexpr REL::ID Lock{ 37396 };
		inline constexpr REL::ID TryLock{ 0 };  // 74235 - inlined?
		inline constexpr REL::ID Unlock{ 0 };   // 73895 - inlined?
	}

	namespace BSPointerHandleManagerInterface
	{
		inline constexpr REL::ID GetSmartPointer{ 0 };  // 72432
	}

	namespace BSReadWriteLock
	{
		inline constexpr REL::ID LockRead{ 123862 };
		inline constexpr REL::ID LockWrite{ 123863 };
		inline constexpr REL::ID UnlockRead{ 36021 };
		inline constexpr REL::ID UnlockWrite{ 35983 };
	}

	namespace BSScript
	{
		namespace Array
		{
			inline constexpr REL::ID ctor{ 0 };  // 196577
			inline constexpr REL::ID dtor{ 0 };  // 196579
		}

		namespace Object
		{
			inline constexpr REL::ID ctor{ 137778 };  // 196025
			inline constexpr REL::ID dtor{ 0 };       // 196032 - inlined
			inline constexpr REL::ID dtorUnkSub{ 137823 };
			inline constexpr REL::ID GetHandle{ 0 };  // 196069 - inlined
			inline constexpr REL::ID SetHandle{ 0 };  // 196079
			inline constexpr REL::ID IncRef{ 0 };     // 37879
			inline constexpr REL::ID DecRef{ 0 };     // 196057
		}

		namespace ObjectBindPolicy
		{
			inline constexpr REL::ID BindObject{ 0 };  // 195981
		}

		namespace ObjectTypeInfo
		{
			inline constexpr REL::ID ctor{ 138400 };           // 197047
			inline constexpr REL::ID dtor{ 137885 };           // 196202
			inline constexpr REL::ID Clear{ 0 };               // 196218
			inline constexpr REL::ID CopyFromLinkedData{ 0 };  // 196219
			inline constexpr REL::ID GetProperty{ 0 };         // 196241
		}

		namespace Stack
		{
			inline constexpr REL::ID ctor{ 0 };                   // 196325
			inline constexpr REL::ID dtor{ 0 };                   // 196333
			inline constexpr REL::ID GetStackFrameVariable{ 0 };  // 196367 - inlined
			inline constexpr REL::ID GetPageForFrame{ 138020 };   // 196366
		}

		namespace StackFrame
		{
			inline constexpr REL::ID GetVariable{ 84986 };
		}

		namespace Internal
		{
			namespace NF_util
			{
				namespace NativeFunctionBase
				{
					inline constexpr REL::ID Call{ 138074 };
					inline constexpr REL::ID GetParam{ 138061 };
					inline constexpr REL::ID GetSourceFilename{ 138065 };
					inline constexpr REL::ID GetParamInfo{ 138067 };
					inline constexpr REL::ID Unk_15{ 138068 };
				}
			}
		}
	}

	namespace BSSpinLock
	{
		inline constexpr REL::ID Lock{ 123819 };
		inline constexpr REL::ID TryLock{ 123818 };
		inline constexpr REL::ID Unlock{ 35630 };
	}

	namespace BSStringPool
	{
		namespace Entry
		{
			inline constexpr REL::ID Release{ 139340 };
		}

		namespace BucketTable
		{
			inline constexpr REL::ID GetSingleton{ 139337 };
		}

		inline constexpr REL::ID GetEntry{ 139352 };
		inline constexpr REL::ID GetEntryW{ 139354 };
	}

	namespace BSStorage
	{
		inline constexpr REL::ID FlushStreamBuffer{ 0 };    // 72433
		inline constexpr REL::ID PrepareStreamBuffer{ 0 };  // 72461
		inline constexpr REL::ID WriteString{ 0 };          // 87863
	}

	namespace BSSystemFile
	{
		inline constexpr REL::ID ctor{ 0 };            // 198445
		inline constexpr REL::ID dtor{ 0 };            // 198446
		inline constexpr REL::ID DoClose{ 0 };         // 198452
		inline constexpr REL::ID DeleteFileA{ 0 };     // 198451
		inline constexpr REL::ID DoOpen{ 0 };          // 198454
		inline constexpr REL::ID DoSeek{ 0 };          // 198456
		inline constexpr REL::ID DoSetEndOfFile{ 0 };  // 198457
		inline constexpr REL::ID Flush{ 0 };           // 78151
		inline constexpr REL::ID GetSize{ 0 };         // 85176
		inline constexpr REL::ID Read{ 0 };            // 75362
		inline constexpr REL::ID RenameFile{ 0 };      // 198459
		inline constexpr REL::ID Truncate{ 0 };        // 195959
		inline constexpr REL::ID Write{ 0 };           // 75363
		inline constexpr REL::ID operatorEqCopy{ 0 };  // 198448
	}

	namespace BSTEventSource
	{
		inline constexpr REL::ID Notify{ 123824 };
		inline constexpr REL::ID RegisterSink{ 123821 };
		inline constexpr REL::ID UnregisterSink{ 123822 };
	}

	namespace BSTHeapSTLAllocatorBase
	{
		inline constexpr REL::ID allocate{ 0 };    // 34039
		inline constexpr REL::ID deallocate{ 0 };  // 34440
	}

	namespace Calendar
	{
		inline constexpr REL::ID Singleton{ 0 };  // 878435
	}

	namespace CellAttachDetachEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 84784
	}

	namespace ChallengeCompletedEvent::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 86781
	}

	namespace CharGen_BrowChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141185
	}

	namespace CharGen_BrowColorChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141186
	}

	namespace CharGen_CancelTextEntry
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141187
	}

	namespace CharGen_CloseMenu
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141188
	}

	namespace CharGen_CyclePronoun
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141189
	}

	namespace CharGen_DirtScarsEtcChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141190
	}

	namespace CharGen_EndBodyChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141191
	}

	namespace CharGen_EndTextEntry
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141192
	}

	namespace CharGen_EyeColorChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141193
	}

	namespace CharGen_FacialHairChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141194
	}

	namespace CharGen_FacialHairColorChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141195
	}

	namespace CharGen_HairChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141196
	}

	namespace CharGen_HairColorChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141197
	}

	namespace CharGen_HeadpartPlusSelectorChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141198
	}

	namespace CharGen_HeadpartPresetChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141199
	}

	namespace CharGen_JewelryChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141200
	}

	namespace CharGen_JewelryColorChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141201
	}

	namespace CharGen_MakeupChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141202
	}

	namespace CharGen_MarkingsChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141203
	}

	namespace CharGen_PostBlendColorOptionChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141204
	}

	namespace CharGen_PostBlendFaceChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141205
	}

	namespace CharGen_PostBlendIntensityChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141206
	}

	namespace CharGen_PresetChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141207
	}

	namespace CharGen_RollOffLocomotion
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141208
	}

	namespace CharGen_RollOnLocomotion
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141209
	}

	namespace CharGen_RotatePaperdoll
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141210
	}

	namespace CharGen_SetAdditionalSlider
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141211
	}

	namespace CharGen_SetBackground
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141212
	}

	namespace CharGen_SetBlockInputUnderPopup
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141213
	}

	namespace CharGen_SetBodyValues
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141214
	}

	namespace CharGen_SetCameraPosition
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141215
	}

	namespace CharGen_SetPronoun
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141216
	}

	namespace CharGen_SetSex
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141217
	}

	namespace CharGen_SetSlider
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141218
	}

	namespace CharGen_SetTrait
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141219
	}

	namespace CharGen_ShowChooseBackgroundMessage
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141220
	}

	namespace CharGen_ShowPlayerRenameMessage
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141221
	}

	namespace CharGen_SkintoneChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141222
	}

	namespace CharGen_StartBodyChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141223
	}

	namespace CharGen_StartTextEntry
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141224
	}

	namespace CharGen_SwitchBodyType
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141225
	}

	namespace CharGen_SwitchLocomotion
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141226
	}

	namespace CharGen_TeethChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141227
	}

	namespace CharGen_TeethRollOff
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141228
	}

	namespace CharGen_TeethRollOn
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141229
	}

	namespace CharGen_ToggleMarking
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141230
	}

	namespace CharGen_TogglePreviewHabSuit
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141231
	}

	namespace ClearHUDMessagesEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 133511
	}

	namespace ClearQuickContainerEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 103704
	}

	namespace ClearShipHudTarget::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137011
	}

	namespace ConsoleLog
	{
		inline constexpr REL::ID Singleton{ 938104 };
		inline constexpr REL::ID AddString{ 113649 };
		inline constexpr REL::ID Print{ 113647 };
	}

	namespace ContainerMenu_HideModel
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166510
	}

	namespace ContainerMenu_Jettison
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166511
	}

	namespace ContainerMenu_LoadModel
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166512
	}

	namespace ContainerMenu_OpenRefuelMenu
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166513
	}

	namespace ContainerMenu_SetMouseOverModel
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166514
	}

	namespace ContainerMenu_TakeAll
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166515
	}

	namespace ContainerMenu_ToggleEquip
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166516
	}

	namespace ContainerMenu_TransferItem
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166518
	}

	namespace ContainerMenuClosed::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 131197
	}

	namespace ControlsRemappedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 136133
	}

	namespace CraftingMenu_CloseMenu
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132468
	}

	namespace CraftingMenu_CraftItem
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132096
	}

	namespace CraftingMenu_ExitBench
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132097
	}

	namespace CraftingMenu_Highlight3D
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144186
	}

	namespace CraftingMenu_InstallMod
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132098
	}

	namespace CraftingMenu_RenameItem
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132099
	}

	namespace CraftingMenu_RevertedModdedItem
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132100
	}

	namespace CraftingMenu_RevertHighlight
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144187
	}

	namespace CraftingMenu_SelectedMod
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132101
	}

	namespace CraftingMenu_SelectedModSlot
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132102
	}

	namespace CraftingMenu_SelectedModdableItem
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132103
	}

	namespace CraftingMenu_SelectedRecipe
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132104
	}

	namespace CraftingMenu_ToggleTracking
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132106
	}

	namespace CraftingMenu_ViewingModdableItem
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132107
	}

	namespace CriticalHitEvent::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 153653
	}

	namespace CustomMarkerUpdate::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 153654
	}

	namespace DataMenu_Missions
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141471
	}

	namespace DataMenu_PlotToLocation
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141473
	}

	namespace DataMenu_Reopened
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141474
	}

	namespace DataMenu_SetPaperDollActive
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141482
	}

	namespace DataSlateMenu_playSFX
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139188
	}

	namespace DataSlateMenu_toggleAudio
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139189
	}

	namespace DaysPassed::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 148411
	}

	namespace DialogueMenu_OnDialogueSelect
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166594
	}

	namespace DialogueMenu_OnListVisibilityChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166595
	}

	namespace DialogueMenu_OnPersuasionAutoWin
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166596
	}

	namespace DialogueMenu_RequestExit
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166598
	}

	namespace DialogueMenu_RequestSkipDialogue
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166599
	}

	namespace EnteredUnity::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 153656
	}

	namespace ExperienceMeterDisplayData
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 138446
	}

	namespace ExtraDataList
	{
		inline constexpr REL::ID HasQuestObjectAlias{ 0 };  // 83336
	}

	namespace FavoritesMenu_AssignQuickkey
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166789
	}

	namespace FavoritesMenu_UseQuickkey
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 166790
	}

	namespace FirstThirdPersonSwitch::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 34458
	}

	namespace FORM_ENUM_STRING
	{
		inline constexpr REL::ID FormEnumString{ 0 };  // 761416
	}

	namespace GameMenuBase
	{
		inline constexpr REL::ID ctor{ 0 };   // 130577
		inline constexpr REL::ID Unk10{ 0 };  // 141505
		inline constexpr REL::ID Unk11{ 0 };  // 141506
	}

	namespace GameScript
	{
		namespace RemoteDebugger
		{
			inline constexpr REL::ID HandleContinueRequest{ 0 };        // 167579
			inline constexpr REL::ID HandleDisconnectRequest{ 0 };      // 167580
			inline constexpr REL::ID HandlePauseRequest{ 0 };           // 167581
			inline constexpr REL::ID HandleSetBreakpointsRequest{ 0 };  // 167582
			inline constexpr REL::ID HandleStackTraceRequest{ 0 };      // 167583
			inline constexpr REL::ID HandleThreadsRequest{ 0 };         // 167584
			inline constexpr REL::ID HandleValueRequest{ 0 };           // 167585
			inline constexpr REL::ID HandleVariablesRequest{ 0 };       // 167586
			inline constexpr REL::ID HandleStepRequest{ 0 };            // 167587
		}
	}

	namespace GameSettingCollection
	{
		inline constexpr REL::ID Singleton{ 938225 };
		inline constexpr REL::ID GetSetting{ 49324 };
	}

	namespace GameVM
	{
		inline constexpr REL::ID Singleton{ 937585 };
		inline constexpr REL::ID BindEverythingToScript{ 117899 };
	}

	namespace HideSubtitleEvent::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 133630
	}

	namespace HourPassed::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 148412
	}

	namespace HoursPassed::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 167218
	}

	namespace HUDModeEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 133039
	}

	namespace HUDNotification_MissionActiveWidgetUpdate
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 138666
	}

	namespace HUDNotification_SetMissionActive
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 138669
	}

	namespace HUDNotificationEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 138665
	}

	namespace HUDRolloverActivationButtonEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 133042
	}

	namespace idLogging
	{
		inline constexpr REL::ID Singleton{ 0 };  // 895197
	}

	namespace idTCP
	{
		inline constexpr REL::ID Accept{ 0 };  // 211257
		inline constexpr REL::ID Close{ 0 };   // 211258
		inline constexpr REL::ID Listen{ 0 };  // 211259
		inline constexpr REL::ID Read{ 0 };    // 211264
		inline constexpr REL::ID Write{ 0 };   // 211266
	}

	namespace IMenu
	{
		inline constexpr REL::ID dtor{ 0 };               // 187216
		inline constexpr REL::ID ShouldHandleEvent{ 0 };  // 187262
		inline constexpr REL::ID OnThumbstickEvent{ 0 };  // 187235
		inline constexpr REL::ID OnButtonEvent{ 0 };      // 187234
		inline constexpr REL::ID LoadMovie{ 0 };          // 187240
		inline constexpr REL::ID ProcessMessage{ 0 };     // 187247
		inline constexpr REL::ID Unk09{ 0 };              // 80440
		inline constexpr REL::ID Unk0A{ 0 };              // 187238
		inline constexpr REL::ID Unk0E{ 0 };              // 187242
		inline constexpr REL::ID Unk10{ 0 };              // 187241
		inline constexpr REL::ID Unk11{ 0 };              // 187243
		inline constexpr REL::ID Unk12{ 0 };              // 80451
		inline constexpr REL::ID Unk13{ 0 };              // 76183
		inline constexpr REL::ID Unk15{ 0 };              // 187225
		inline constexpr REL::ID Unk18{ 0 };              // 1275268
		inline constexpr REL::ID Unk19{ 0 };              // 187245
		inline constexpr REL::ID Unk1A{ 0 };              // 187232
	}

	namespace INIPrefSettingCollection
	{
		inline constexpr REL::ID Singleton{ 944391 };
	}

	namespace INISettingCollection
	{
		inline constexpr REL::ID Singleton{ 944389 };
	}

	namespace InputEnableLayer
	{
		inline constexpr REL::ID Free{ 0 };  // 36626
	}

	namespace InstantReferenceInteractionEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107112
	}

	namespace InventoryItemEvent::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 87526
	}

	namespace InventoryMenu_Change3DView
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132470
	}

	namespace InventoryMenu_HideModel
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139340
	}

	namespace InventoryMenu_LoadModel
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139341
	}

	namespace InventoryMenu_OnEnterCategory
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139342
	}

	namespace InventoryMenu_OpenCargoHold
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139343
	}

	namespace InventoryMenu_PaperDollTryOn
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132471
	}

	namespace InventoryMenu_ResetPaperDollInv
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132472
	}

	namespace InventoryMenu_SelectItem
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139344
	}

	namespace InventoryMenu_SetMouseOverModel
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139345
	}

	namespace InventoryMenu_ToggleFavorite
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139347
	}

	namespace InventoryMenu_ToggleHelmet
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 134925
	}

	namespace InventoryMenu_ToggleSuit
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 134926
	}

	namespace ItemSteal::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 153659
	}

	namespace LevelIncrease::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 153662
	}

	namespace LevelUp_AnimFinished
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 138447
	}

	namespace LevelUp_OnWidgetShown
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 138448
	}

	namespace LocationLinked::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 104623
	}

	namespace LocationTextEvent::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 138717
	}

	namespace LocationTextWidget_FinishedQueue
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 138451
	}

	namespace LockPickedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107115
		inline constexpr REL::ID Notify{ 0 };          // 107339
	}

	namespace Main
	{
		inline constexpr REL::ID Singleton{ 883591 };
		inline constexpr REL::ID WorldRoot{ 0 };  // 887308
	}

	namespace msvc
	{
		namespace type_info
		{
			inline constexpr REL::ID name{ 0 };       // 248847
			inline constexpr REL::ID _RootNode{ 0 };  // 824582
			inline constexpr REL::ID compare{ 0 };    // 248848
		}
	}

	namespace MemoryManager
	{
		namespace AutoScrapBuffer
		{
			inline constexpr REL::ID ctor{ 0 };  // 178513
			inline constexpr REL::ID dtor{ 0 };  // 178516
		}

		inline constexpr REL::ID GetSingleton{ 35721 };
		inline constexpr REL::ID Allocate{ 123792 };
		inline constexpr REL::ID Free{ 123793 };
		inline constexpr REL::ID GetThreadScrapHeap{ 0 };  // 36848
	}

	namespace MenuTopicManager
	{
		inline constexpr REL::ID Singleton{ 0 };  // 879316
	}

	namespace MessageBoxMenu_OnBackOut
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 167116
	}

	namespace MessageBoxMenu_OnButtonPress
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 167117
	}

	namespace MessageBoxMenu_OnScriptedButtonPress
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 167118
	}

	namespace Misc
	{
		inline constexpr REL::ID DebugNotification{ 0 };        // 138728
		inline constexpr REL::ID LookupReferenceByHandle{ 0 };  // 72986
		inline constexpr REL::ID PlayMenuSound{ 0 };            // 167344
	}

	namespace MissionBoard_MissionEntryChanged
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139500
	}

	namespace MissionBoard_MissionEntryPressed
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139501
	}

	namespace MissionMenu_ClearState
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139095
	}

	namespace MissionMenu_PlotToLocation
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139096
	}

	namespace MissionMenu_RejectQuest
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139097
	}

	namespace MissionMenu_ShowItemLocation
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139100
	}

	namespace MissionMenu_ToggleTrackingQuest
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139102
	}

	namespace ModelReferenceEffectEvents::ReferenceEffectFinished
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 145389
	}

	namespace MonocleMenu_Bioscan
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139641
	}

	namespace MonocleMenu_FastTravel
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139642
	}

	namespace MonocleMenu_Harvest
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139643
	}

	namespace MonocleMenu_Initialize
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139644
	}

	namespace MonocleMenu_Outpost
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139645
	}

	namespace MonocleMenu_PhotoMode
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139646
	}

	namespace MonocleMenu_SocialSpell
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139648
	}

	namespace MonocleMenu_SurfaceMap
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139651
	}

	namespace MonocleMenu_ZoomIn
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139653
	}

	namespace MonocleMenu_ZoomOut
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139654
	}

	namespace NiCamera
	{
		inline constexpr REL::ID WorldToScreenInternal{ 0 };  // 210415
	}

	namespace NiMatrix3
	{
		inline constexpr REL::ID ToEulerAnglesXYZ{ 0 };  // 210095
	}

	namespace PauseMenu_ActionCanceled
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141614
	}

	namespace PauseMenu_ConfirmAction
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141615
	}

	namespace PauseMenu_ConfirmLoad
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141616
	}

	namespace PauseMenu_ConfirmSave
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141617
	}

	namespace PauseMenu_DeleteSave
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141618
	}

	namespace PauseMenu_QuitToDesktop
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141619
	}

	namespace PauseMenu_SetCharacter
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141620
	}

	namespace PauseMenu_StartAction
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141621
	}

	namespace PauseMenu_StartLoad
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141622
	}

	namespace PerkChanged::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 76533
	}

	namespace PhotoGallery_DeletePhoto
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 130819
	}

	namespace PhotoMode_InitializeCategory
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139736
	}

	namespace PhotoMode_RefineSetting
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 1536789
	}

	namespace PhotoMode_ResetToDefaults
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139737
	}

	namespace PhotoMode_SliderChanged
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139738
	}

	namespace PhotoMode_StepperChanged
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139739
	}

	namespace PhotoMode_TakeSnapshot
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139740
	}

	namespace PhotoMode_ToggleHelmet
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139741
	}

	namespace PhotoMode_ToggleUI
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139742
	}

	namespace PickpocketMenu_OnItemSelect
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 139918
	}

	namespace PickRefStateChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 86519
	}

	namespace PickRefUpdateEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119433
	}

	namespace PlayBink_CloseMenu
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141653
	}

	namespace PlayerAmmoChanged::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 153665
	}

	namespace PlayerAssaultActorEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107120
	}

	namespace PlayerCamera
	{
		inline constexpr REL::ID Singleton{ 937788 };
		inline constexpr REL::ID ForceFirstPerson{ 113397 };
		inline constexpr REL::ID ForceThirdPerson{ 113398 };
		inline constexpr REL::ID SetCameraState{ 0 };  // 166078
		inline constexpr REL::ID QCameraEquals{ 0 };   // 166081
	}

	namespace PlayerCharacter
	{
		inline constexpr REL::ID Singleton{ 922868 };
	}

	namespace PlayerControls::PlayerIronSightsEndEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 129341
	}

	namespace PlayerControls::PlayerIronSightsStartEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 129342
	}

	namespace PlayerControls::PlayerJumpPressEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 129146
	}

	namespace PlayerControls::PlayerJumpReleaseEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 129147
	}

	namespace PlayerControls::PlayerZeroGSprintJustPressedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 129188
	}

	namespace PlayerControls::PlayerZeroGSprintReleasedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 129189
	}

	namespace PlayerCrimeGoldEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107122
	}

	namespace PlayerCrosshairModeEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 133336
	}

	namespace PlayerDetectionLevelChangeEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 133601
	}

	namespace PlayerDifficultySettingChanged::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 153667
	}

	namespace PlayerFastTravel::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 153668
	}

	namespace PlayerJailEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107124
	}

	namespace PlayerMurderActorEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107126
	}

	namespace PlayerPayFineEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107127
	}

	namespace PlayerSetWeaponStateEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 138719
	}

	namespace PlayerSneakingChangeEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 129185
	}

	namespace PlayerTrespassEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107131
	}

	namespace PlayerUpdateEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 134924
	}

	namespace PowersMenu_ActivateEssence
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 130908
	}

	namespace PowersMenu_EquipPower
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 130909
	}

	namespace PowersMenu_FavoritePower
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 130910
	}

	namespace ProcessLists
	{
		inline constexpr REL::ID AreHostileActorsNear{ 0 };  // 154040
		inline constexpr REL::ID Singleton{ 0 };             // 878338
		inline constexpr REL::ID ToggleAI{ 0 };              // 154056
	}

	namespace REFR_LOCK
	{
		inline constexpr REL::ID GetLockLevel{ 0 };  // 84103
	}

	namespace Refuel_Accept
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140363
	}

	namespace Refuel_Cancel
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140364
	}

	namespace RegSettingCollection
	{
		inline constexpr REL::ID Singleton{ 944237 };
	}

	namespace ReloadWeaponEvent::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 151744
	}

	namespace Research::ResearchProgressEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 147163
	}

	namespace ResearchMenu_AddMaterial
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140018
	}

	namespace ResearchMenu_CategorySelected
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140019
	}

	namespace ResearchMenu_HideModel
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140021
	}

	namespace ResearchMenu_PreviewProject
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140022
	}

	namespace ResearchMenu_ProjectViewed
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140023
	}

	namespace ResearchMenu_ToggleTrackingProject
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140025
	}

	namespace Reticle_OnLongAnimFinished
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141816
	}

	namespace RuntimeComponentDBFactory::ReferenceDetach
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 77128
	}

	namespace RuntimeComponentDBFactory::ReferenceSet3d
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 88599
	}

	namespace SaveLoadEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 129747
	}

	namespace Scaleform
	{
		namespace GFx
		{
			namespace Value
			{
				namespace ObjectInterface
				{
					inline constexpr REL::ID AttachMovie{ 169785 };
					inline constexpr REL::ID CreateEmptyMovieClip{ 169784 };
					inline constexpr REL::ID GetArraySize{ 169754 };
					inline constexpr REL::ID GetElement{ 169756 };
					inline constexpr REL::ID GetMember{ 169748 };
					inline constexpr REL::ID GetParent{ 169771 };
					inline constexpr REL::ID GetText{ 169781 };
					inline constexpr REL::ID GotoAndPlayL{ 169786 };
					inline constexpr REL::ID GotoAndPlay{ 169787 };
					inline constexpr REL::ID HasMember{ 169747 };
					inline constexpr REL::ID Invoke{ 169750 };
					inline constexpr REL::ID ObjectAddRef{ 169745 };
					inline constexpr REL::ID ObjectRelease{ 169746 };
					inline constexpr REL::ID PopBack{ 169761 };
					inline constexpr REL::ID PushBack{ 169760 };
					inline constexpr REL::ID RemoveElements{ 169762 };
					inline constexpr REL::ID SetArraySize{ 169755 };
					inline constexpr REL::ID SetElement{ 169757 };
					inline constexpr REL::ID SetMember{ 169749 };
					inline constexpr REL::ID SetText{ 169782 };
					inline constexpr REL::ID SetTextW{ 169783 };
					inline constexpr REL::ID VisitMembers{ 169753 };
					inline constexpr REL::ID VisitElements{ 169758 };
				}
			}
		}

		namespace MemoryHeapPT
		{
			inline constexpr REL::ID Singleton{ 0 };  // 820297
		}
	}

	namespace ScrapHeap
	{
		inline constexpr REL::ID Allocate{ 0 };    // 34432
		inline constexpr REL::ID Deallocate{ 0 };  // 37624
	}

	namespace Script
	{
		inline constexpr REL::ID GetConsoleCommands{ 0 };  // 841465
		inline constexpr REL::ID GetScriptCommands{ 0 };   // 841467
	}

	namespace SecurityMenu_BackOutKey
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140244
	}

	namespace SecurityMenu_ConfirmExit
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140246
	}

	namespace SecurityMenu_EliminateUnusedKeys
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140247
	}

	namespace SecurityMenu_GetRingHint
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140248
	}

	namespace SecurityMenu_SelectNewKey
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140249
	}

	namespace SecurityMenu_TryUseKey
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140250
	}

	namespace ShipCameraStateToggled
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 120266
	}

	namespace ShipEditor_SystemSelected
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 75542
	}

	namespace ShipHud_AbortJump
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141818
	}

	namespace ShipHud_Activate
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137016
	}

	namespace ShipHud_BodyViewMarkerDimensions
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137017
	}

	namespace ShipHud_ChangeComponentSelection
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137018
	}

	namespace ShipHud_Deselect
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137020
	}

	namespace ShipHud_DockRequested
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141819
	}

	namespace ShipHud_FarTravel
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137021
	}

	namespace ShipHud_HailAccepted
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137022
	}

	namespace ShipHud_HailCancelled
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137023
	}

	namespace ShipHud_HailShip
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141820
	}

	namespace ShipHud_JumpToQuestMarker
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137023
	}

	namespace ShipHud_Land
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137025
	}

	namespace ShipHud_LandingMarkerMap
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137026
	}

	namespace ShipHud_Map
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137027
	}

	namespace ShipHud_OpenPhotoMode
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137029
	}

	namespace ShipHud_Repair
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137030
	}

	namespace ShipHud_SetTargetMode
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137031
	}

	namespace ShipHud_Target
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137032
	}

	namespace ShipHud_TargetShipSystem
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137033
	}

	namespace ShipHud_UntargetShipSystem
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137034
	}

	namespace ShipHud_UpdateComponentPower
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137035
	}

	namespace ShipHud_UpdateTargetPanelRect
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141821
	}

	namespace ShipHudQuickContainer_TransferItem
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141817
	}

	namespace ShipHudQuickContainer_TransferMenu
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137015
	}

	namespace ShowHUDMessageEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 133512
	}

	namespace ShowingQuestMarketTextEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 133279
	}

	namespace ShowLongShipBootup
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137014
	}

	namespace ShowSubtitleEvent::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 133631
	}

	namespace SkillsMenu_Accept
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140522
	}

	namespace SleepWaitMenu_InterruptRest
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 167219
	}

	namespace SleepWaitMenu_StartRest
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 167220
	}

	namespace Spaceship::TakeOffEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 37523
	}

	namespace Spaceship::GravJumpEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141814
	}

	namespace Spaceship::LandedSetEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141815
	}

	namespace Spaceship::BoughtEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174575
	}

	namespace Spaceship::ContrabandScanWarningEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174576
	}

	namespace Spaceship::DockEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174577
	}

	namespace Spaceship::DynamicNavmeshCompleted
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174578
	}

	namespace Spaceship::FarTravelEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174579
	}

	namespace Spaceship::LandingEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174580
	}

	namespace Spaceship::PlanetScanEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174581
	}

	namespace Spaceship::RampDownEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174582
	}

	namespace Spaceship::RefueledEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174583
	}

	namespace Spaceship::RegisteredEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174584
	}

	namespace Spaceship::ShieldEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174585
	}

	namespace Spaceship::ShipAddedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174586
	}

	namespace Spaceship::ShipCollisionEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174587
	}

	namespace Spaceship::ShipCustomizedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174588
	}

	namespace Spaceship::SoldEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174589
	}

	namespace Spaceship::SystemDamagedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174590
	}

	namespace Spaceship::SystemPowerAllocationEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174591
	}

	namespace Spaceship::SystemPowerChangeEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174592
	}

	namespace Spaceship::SystemRepairedBIEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174593
	}

	namespace Spaceship::SystemRepairedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174594
	}

	namespace Spaceship::TakeDamagEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 174595
	}

	namespace SpaceshipBIEvents::ShipPowerAllocationBIEventSent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 146094
	}

	namespace SpaceshipWeaponBinding::SpaceshipWeaponBindingChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 130322
	}

	namespace SpellsLearned::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 151932
	}

	namespace StarMap::PlanetTraitKnownEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 92502
	}

	namespace StarMapMenu_LandingInputInProgress
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142192
	}

	namespace StarMapMenu_MarkerGroupContainerVisibilityChanged
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142193
	}

	namespace StarMapMenu_MarkerGroupEntryClicked
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142194
	}

	namespace StarMapMenu_MarkerGroupEntryHoverChanged
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142195
	}

	namespace StarMapMenu_ScanPlanet
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142196
	}

	namespace StarMapMenu_SelectedLandingSite
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142197
	}

	namespace StarMapMenu_SelectedLandingSiteFailed
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142198
	}

	namespace StarMapMenu_ShowRealCursor
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142199
	}

	namespace StarMapMenu_QuickSelectChange
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142493
	}

	namespace StarMapMenu_Galaxy_FocusSystem
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142763
	}

	namespace StarMapMenu_OnGalaxyViewInitialized
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142764
	}

	namespace StarMapMenu_ExecuteRoute
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142945
	}

	namespace StarMapMenu_OnCancel
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142946
	}

	namespace StarMapMenu_OnClearRoute
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142947
	}

	namespace StarMapMenu_OnExitStarMap
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142948
	}

	namespace StarMapMenu_OnHintButtonClicked
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142949
	}

	namespace StarMapMenu_OnOutpostEntrySelected
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142950
	}

	namespace StarMapMenu_ReadyToClose
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 142951
	}

	namespace SurfaceMapMenu_MarkerClicked
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 143330
	}

	namespace SurfaceMapMenu_TryPlaceCustomMarker
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 143331
	}

	namespace SWFToCodeFunctionHandler
	{
		inline constexpr REL::ID RegisterNativeFunction{ 0 };  // 187274
	}

	namespace TakeoffMenu_ExitShip
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141823
	}

	namespace TakeoffMenu_Launch
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141824
	}

	namespace TargetHitEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 133346
	}

	namespace Terminal_CloseAllViews
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 143772
	}

	namespace Terminal_CloseTopView
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 143773
	}

	namespace Terminal_CloseView
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 143773
	}

	namespace TerminalHacked::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 153673
	}

	namespace TerminalMenu_CancelEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 143771
	}

	namespace TES
	{
		inline constexpr REL::ID GetDeadCount{ 0 };  // 84704
		inline constexpr REL::ID Singleton{ 0 };     // 881024
	}

	namespace TESActivateEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107136
	}

	namespace TESActorActivatedRefEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107139
	}

	namespace TESActorBaseData
	{
		inline constexpr REL::ID GetLevel{ 0 };                // 85868
		inline constexpr REL::ID GetUsesLeveledTemplate{ 0 };  // 85873
	}

	namespace TESActorLocationChangeEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107140
	}

	namespace TESBookReadEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107141
	}

	namespace TESCellFullyLoadedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107143
	}

	namespace TESCellNavmeshGeneratedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 34446
	}

	namespace TESCombatEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107148
	}

	namespace TESCondition
	{
		inline constexpr REL::ID CheckValue{ 0 };  // 116112
	}

	namespace TESConditionItem
	{
		inline constexpr REL::ID IsTrue{ 71429 };
	}

	namespace TESContainer
	{
		inline constexpr REL::ID AddObjectToContainer{ 0 };  // 85991
	}

	namespace TESContainerChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107155
	}

	namespace TESDataHandler
	{
		inline constexpr REL::ID Singleton{ 937572 };
	}

	namespace TESDeathEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107156
	}

	namespace TESEquipEvent
	{
		inline constexpr REL::ID GetEventSource{ 64135 };
	}

	namespace TESForm
	{
		inline constexpr REL::ID DecExternalRefCount{ 0 };  // 34165
		inline constexpr REL::ID DecRefCount{ 38742 };
		inline constexpr REL::ID LookupByID{ 47401 };
		inline constexpr REL::ID LookupByEditorID{ 47403 };
	}

	namespace TESFormDeleteEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107166
	}

	namespace TESFormIDRemapEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107167
	}

	namespace TESFurnitureEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107168
	}

	namespace TESGrabReleaseEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107169
	}

	namespace TESHarvestEvent::ItemHarvested
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 86518
	}

	namespace TESHitEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 34450
	}

	namespace TESLoadGameEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 1868757
	}

	namespace TESLockChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107174
	}

	namespace TESMissionAcceptedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107176
	}

	namespace TESNPC
	{
		inline constexpr REL::ID CopyAppearance{ 68122 };
		inline constexpr REL::ID DeriveGeneticParentAppearance{ 68123 };
	}

	namespace TESNPCData
	{
		namespace ChargenDataModel
		{
			inline constexpr REL::ID Singleton{ 938438 };
			inline constexpr REL::ID Update{ 92843 };
		}
	}

	namespace TESObjectARMO
	{
		inline constexpr REL::ID CanUseArmor{ 0 };  // 103501
	}

	namespace TESObjectLoadedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107177
	}

	namespace TESObjectREFR
	{
		inline constexpr REL::ID ActivateRef{ 0 };          // 106374
		inline constexpr REL::ID AddLockChange{ 0 };        // 106386
		inline constexpr REL::ID GetCalcLevel{ 0 };         // 107531
		inline constexpr REL::ID GetCurrentLocation{ 0 };   // 106554
		inline constexpr REL::ID GetDistance{ 0 };          // 106562
		inline constexpr REL::ID GetLinkedRef{ 0 };         // 107578
		inline constexpr REL::ID GetLock{ 0 };              // 107581
		inline constexpr REL::ID GetParentWorldSpace{ 0 };  // 106696
		inline constexpr REL::ID GetScale{ 0 };             // 106658
		inline constexpr REL::ID GetSpaceship{ 119881 };
		inline constexpr REL::ID GetSpaceshipParentDock{ 0 };  // 174134
		inline constexpr REL::ID GetSpaceshipPilot{ 0 };       // 173834
		inline constexpr REL::ID GetValue{ 0 };                // 107605
		inline constexpr REL::ID HasKeyword{ 42794 };
		inline constexpr REL::ID IsCrimeToActivate{ 0 };  // 106755
		inline constexpr REL::ID IsInSpace{ 63482 };
		inline constexpr REL::ID IsInSpaceship{ 119881 };
		inline constexpr REL::ID IsObjectEquipped{ 0 };   // 106991
		inline constexpr REL::ID IsSpaceshipDocked{ 0 };  // 174146
		inline constexpr REL::ID IsSpaceshipLanded{ 0 };  // 173880
		inline constexpr REL::ID WornHasKeyword{ 0 };     // 106992
	}

	namespace TESPickNewIdleEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107183
	}

	namespace TESPlayerFollowerWarpEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107186
	}

	namespace TESQuest
	{
		inline constexpr REL::ID IsStageDone{ 0 };  // 112585
	}

	namespace TESQuestRewardEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 95698
	}

	namespace TESResetEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107193
	}

	namespace TESResolveNPCTemplatesEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107194
	}

	namespace TESSleepStartEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107199
	}

	namespace TESSleepStopEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 107200
	}

	namespace TraitDiscoveryTextEvent::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 138718
	}

	namespace TryUpdateShipHudTarget::Event
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 137012
	}

	namespace TESWorldSpace
	{
		inline constexpr REL::ID GetLocationFromCoordinates{ 0 };  // 107914
	}

	namespace UI
	{
		inline constexpr REL::ID Singleton{ 937580 };
		inline constexpr REL::ID IsMenuOpen{ 130475 };
		inline constexpr REL::ID RegisterMenu{ 0 };  // 80375
	}

	namespace UIMenuChargenMenuDisablePaperdoll
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 141232
	}

	namespace UIMessageQueue
	{
		inline constexpr REL::ID Singleton{ 937897 };
		inline constexpr REL::ID AddMessage{ 130659 };
	}

	namespace UnlockedTerminalElementEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 140243
	}

	namespace UpdateActivateListenerEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 132635
	}

	namespace UpdateSceneRectEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 187249
	}

	namespace WeaponFiredEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 773902
	}

	namespace Workshop::CargoLinkAddedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119421
	}

	namespace Workshop::CargoLinkTargetChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119422
	}

	namespace Workshop::EnterOutpostBeaconModeEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119423
	}

	namespace Workshop::ItemGrabbedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119424
	}

	namespace Workshop::ItemMovedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119425
	}

	namespace Workshop::ItemPlacedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119426
	}

	namespace Workshop::ItemProducedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119427
	}

	namespace Workshop::ItemRemovedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119428
	}

	namespace Workshop::ItemRepairedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119429
	}

	namespace Workshop::ItemScrappedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119430
	}

	namespace Workshop::OutpostNameChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119431
	}

	namespace Workshop::OutpostPlacedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119432
	}

	namespace Workshop::PlacementStatusEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119434
	}

	namespace Workshop::PowerOffEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119435
	}

	namespace Workshop::PowerOnEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119436
	}

	namespace Workshop::SnapBehaviorCycledEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119437
	}

	namespace Workshop::WorkshopFlyCameraEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119438
	}

	namespace Workshop::WorkshopItemPlacedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119439
	}

	namespace Workshop::WorkshopModeEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119440
	}

	namespace Workshop::WorkshopOutputLinkEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119441
	}

	namespace Workshop::WorkshopStatsChangedEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119442
	}

	namespace Workshop::WorkshopUpdateStatsEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 119443
	}

	namespace WorkshopBuilderMenu_ChangeBuildItem
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144229
	}

	namespace WorkshopBuilderMenu_SelectedItem
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144230
	}

	namespace WorkshopBuilderMenu_ToggleTracking
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144231
	}

	namespace WorkshopMenu_AttemptBuild
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144358
	}

	namespace WorkshopMenu_ChangeVariant
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144360
	}

	namespace WorkshopMenu_ConnectionEvent
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144361
	}

	namespace WorkshopMenu_SelectedCategory
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144364
	}

	namespace WorkshopMenu_SelectedGridObject
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144365
	}

	namespace WorkshopMenu_ShowExtras
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144366
	}

	namespace WorkshopMenu_SwitchMode
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144367
	}

	namespace WorkshopMenu_ToggleDistance
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144368
	}

	namespace WorkshopMenu_ToggleTracking
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144369
	}

	namespace WorkshopMenu_ToggleView
	{
		inline constexpr REL::ID GetEventSource{ 0 };  // 144370
	}

	inline constexpr REL::ID NET_ErrorString{ 0 };      // 211261
	inline constexpr REL::ID Net_SockadrToNetadr{ 0 };  // 211262
	inline constexpr REL::ID NET_WaitForData{ 0 };      // 211263
	inline constexpr REL::ID RTDynamicCast{ 184372 };
	inline constexpr REL::ID Sys_InitNetworking{ 0 };  // 211265
}
