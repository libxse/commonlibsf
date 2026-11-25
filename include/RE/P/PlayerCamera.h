#pragma once

#include "RE/B/BSInputEventReceiver.h"
#include "RE/B/BSTEvent.h"
#include "RE/T/TESCamera.h"

namespace RE
{
	class BSWorldOriginShiftEvent;
	class OtherEventEnabledEvent;
	class UserEventEnabledEvent;
	struct IdleInputEvent;

	namespace Spaceship
	{
		struct TakeOffEvent;
		struct DockEvent;
		struct LandedSetEvent;
	}

	struct CameraStates
	{
		enum CameraState : std::uint32_t
		{
			kFirstPerson = 0,
			kAutoVanity,
			kVATS,
			kIronSights,
			kPCTransition,
			kTween,
			kUnk06,
			kVehicle,
			kFlight,
			kShipFarTravel,
			kShipAction,
			kShipTargeting,
			kShipCombatOrbit,
			kFreeWalk,
			kFreeAdvanced,
			kFreeFly,
			kFreeTethered,
			kDialogue,
			kWorkshopIsometric,
			kPhotoMode,
			kThirdPerson,
			kFurniture,
			kHorse,
			kBleedout,

			kTotal,
		};
	};
	using CameraState = CameraStates::CameraState;

	class PlayerCamera :
		public TESCamera,                                // 00
		public BSInputEventReceiver,                     // 48
		public BSTEventSink<IdleInputEvent>,             // 58
		public BSTEventSink<UserEventEnabledEvent>,      // 60
		public BSTEventSink<OtherEventEnabledEvent>,     // 68
		public BSTEventSink<Spaceship::TakeOffEvent>,    // 70
		public BSTEventSink<Spaceship::DockEvent>,       // 78
		public BSTEventSink<Spaceship::LandedSetEvent>,  // 80
		public BSTEventSink<BSWorldOriginShiftEvent>,    // 88
		public BSTSingletonSDM<PlayerCamera>             // 90
	{
	public:
		SF_RTTI_VTABLE(PlayerCamera);

		~PlayerCamera() override;  // 00

		// override (TESCamera)
		void SetCameraRoot(NiNode* a_root) override;  // 01
		void SetEnabled(bool a_enabled) override;     // 02
		void Unk_04() override;                       // 04

		[[nodiscard]] static PlayerCamera* GetSingleton()
		{
			static REL::Relocation<PlayerCamera**> singleton{ ID::PlayerCamera::Singleton };
			return *singleton;
		}

		void ForceFirstPerson()
		{
			using func_t = decltype(&PlayerCamera::ForceFirstPerson);
			static REL::Relocation<func_t> func{ ID::PlayerCamera::ForceFirstPerson };
			return func(this);
		}

		void ForceThirdPerson()
		{
			using func_t = decltype(&PlayerCamera::ForceThirdPerson);
			static REL::Relocation<func_t> func{ ID::PlayerCamera::ForceThirdPerson };
			return func(this);
		}

		bool IsInFirstPerson() const
		{
			return QCameraEquals(CameraState::kFirstPerson);
		}

		bool IsInThirdPerson() const
		{
			return QCameraEquals(CameraState::kThirdPerson);
		}

		void SetCameraState(CameraState a_cameraState)
		{
			using func_t = decltype(&PlayerCamera::SetCameraState);
			static REL::Relocation<func_t> func{ ID::PlayerCamera::SetCameraState };
			return func(this, a_cameraState);
		}

		void ToggleFreeCameraMode(std::uint32_t a_cameraStateIndex, bool a_flag)
		{
			using func_t = decltype(&PlayerCamera::ToggleFreeCameraMode);
			static REL::Relocation<func_t> func{ ID::PlayerCamera::ToggleFreeCameraMode };
			return func(this, a_cameraStateIndex, a_flag);
		}

		bool QCameraEquals(CameraState a_cameraState) const
		{
			return (currentState == cameraStates[a_cameraState]);
		}

		// members
		std::byte unkA0[0x188 - 0xA0];                // 0A0
		void*     cameraStates[CameraState::kTotal];  // 188

		// ...
	};
	static_assert(offsetof(PlayerCamera, cameraStates) == 0x188);
}
