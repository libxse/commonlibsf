#pragma once

#include "RE/B/BGSReflectedForm.h"
#include "RE/I/IAddressControllerStore.h"

namespace RE
{
	class TESImageSpace :
		public BGSReflectedForm,                // 00
		public BSBind::IAddressControllerStore  // 30
	{
	public:
		SF_RTTI_VTABLE(TESImageSpace);
		SF_FORMTYPE(IMGS);

		struct ImageSpaceSettings
		{
			struct SunAndSkySettings
			{
				BSBlendable::FloatValue DirectionalLightIlluminanceOverride;            // 00
				BSBlendable::FloatValue IndirectLightingSkyScaleOverride;               // 0C
				BSBlendable::FloatValue IndirectLightingSkyTargetEv100;                 // 18
				BSBlendable::FloatValue IndirectLightingSkyTargetStrength;              // 24
				BSBlendable::FloatValue SkyLightingMultiplier;                          // 30
				BSBlendable::FloatValue CelestialBodyIlluminanceScaleOverride;          // 3C
				BSBlendable::FloatValue CelestialBodyIndirectIlluminanceScaleOverride;  // 48
				BSBlendable::FloatValue SunDiskIlluminanceScaleOverride;                // 54
				BSBlendable::FloatValue SunDiskIndirectIlluminanceScaleOverride;        // 60
				BSBlendable::FloatValue StarfieldBackgroundScaleOverride;               // 6C
				BSBlendable::FloatValue StarfieldStarBrightnessScaleOverride;           // 78
				BSBlendable::FloatValue SpaceGlowBackgroundScaleOverride;               // 84
				BSBlendable::FloatValue CloudDirectLightingContribution;                // 90
				BSBlendable::FloatValue CloudIndirectLightingContribution;              // 9C
			};

			static_assert(sizeof(SunAndSkySettings) == 0xA8);

			struct ExposureSettings
			{
				struct LuminanceHistogramSettings
				{
					BSBlendable::FloatValue IgnoredDarksPercentile;    // 00
					BSBlendable::FloatValue IgnoredBrightsPercentile;  // 0C
				};

				static_assert(sizeof(LuminanceHistogramSettings) == 0x18);

				struct AutoExposureSettings
				{
					bool                       EnableCompensationCurve;    // 00
					BSFloatCurve               ExposureCompensationCurve;  // 08
					BSBlendable::FloatValue    ExposureMin;                // 48
					BSBlendable::FloatValue    ExposureMax;                // 54
					BSBlendable::FloatValue    AdaptSpeedDown;             // 60
					BSBlendable::FloatValue    AdaptSpeedUp;               // 6C
					LuminanceHistogramSettings LuminanceHistogram;         // 78
					std::byte                  pad[16];                    // 90
				};

				static_assert(sizeof(AutoExposureSettings) == 0xA0);

				struct CameraExposureSettings
				{
					BSBlendable::FloatValue Aperture;  // 00
					BSBlendable::FloatValue Time;      // 0C
					BSBlendable::FloatValue ISO;       // 18
				};

				static_assert(sizeof(CameraExposureSettings) == 0x24);

				std::uint32_t           CameraExposureMode;  // 00
				AutoExposureSettings    AutoExposure;        // 08
				BSBlendable::FloatValue FixedValue;          // A8
				CameraExposureSettings  CameraExposure;      // B4
			};

			static_assert(sizeof(ExposureSettings) == 0xD8);

			struct BloomSettings
			{
				BSBlendable::FloatValue BloomThresholdOffset;  // 00
				BSBlendable::FloatValue BloomScale;            // 0C
				BSBlendable::FloatValue BloomRangeScale;       // 18
			};

			static_assert(sizeof(BloomSettings) == 0x24);

			struct CinematicSettings
			{
				BSBlendable::FloatValue Saturation;           // 00
				BSBlendable::FloatValue Brightness;           // 0C
				BSBlendable::FloatValue Contrast;             // 18
				BSBlendable::ColorValue TintColourValue;      // 24
				BSBlendable::ColorValue FadeColourValue;      // 3C
				BSFixedString*          ColorGradingTexture;  // 58
				float                   ColourGradingAmount;  // 60
			};

			static_assert(sizeof(CinematicSettings) == 0x68);

			struct DepthOfFieldSettings
			{
				std::uint32_t           Mode;                      // 00
				bool                    NoSky;                     // 04
				BSBlendable::FloatValue StrengthValue;             // 08
				BSBlendable::FloatValue FarStartValue;             // 14
				BSBlendable::FloatValue FarPlaneValue;             // 20
				BSBlendable::FloatValue FarOpacityValue;           // 2C
				BSBlendable::FloatValue NearStartValue;            // 38
				BSBlendable::FloatValue NearPlaneValue;            // 44
				BSBlendable::FloatValue NearOpacityValue;          // 50
				bool                    UseTargetForDepthOfField;  // 5C
			};

			static_assert(sizeof(DepthOfFieldSettings) == 0x60);

			struct BlurSettings
			{
				BSBlendable::FloatValue BlurRadiusValue;            // 00
				BSBlendable::FloatValue DoubleVisionStrengthValue;  // 0C
				BSBlendable::FloatValue MotionBlurStrengthValue;    // 18
			};

			static_assert(sizeof(BlurSettings) == 0x24);

			struct RadialBlurSettings
			{
				BSBlendable::FloatValue StrengthValue;           // 00
				BSBlendable::FloatValue RampUpValue;             // 0C
				BSBlendable::FloatValue RampDownValue;           // 18
				BSBlendable::FloatValue StartValue;              // 24
				BSBlendable::FloatValue DownStartValue;          // 30
				BSBlendable::FloatValue CenterXValue;            // 3C
				BSBlendable::FloatValue CenterYValue;            // 48
				bool                    UseTargetForRadialBlur;  // 54
			};

			static_assert(sizeof(RadialBlurSettings) == 0x58);

			struct AmbientOcclusionSettings
			{
				BSBlendable::FloatValue IntensityValue;  // 00
			};

			struct FogSettings
			{
				BSBlendable::FloatValue FogScaleValue;  // 00
			};

			struct VolumetricLightingSettings
			{
				BSBlendable::FloatValue FogMapContribution;                       // 00
				BSBlendable::FloatValue VolumetricLightingDirectionalLightScale;  // 0C
				BSBlendable::FloatValue VolumetricLightingDirectionalAnisoScale;  // 18
				BSBlendable::FloatValue VolumetricIndirectLightContribution;      // 24
			};

			static_assert(sizeof(VolumetricLightingSettings) == 0x30);

			struct IndirectLightingSettings
			{
				BSBlendable::FloatValue IndirectDiffuseMultiplier;        // 00
				BSBlendable::FloatValue IndirectSpecularMultiplier;       // 0C
				BSBlendable::FloatValue WaterIndirectSpecularMultiplier;  // 18
				bool                    UseAsInteriorCriteria;            // 24
				bool                    BlockClothWindIfInterior;         // 25
			};

			static_assert(sizeof(IndirectLightingSettings) == 0x28);

			struct ToneMappingSettings
			{
				std::uint32_t           CurveType;              // 00
				BSBlendable::FloatValue WhitePointValue;        // 04
				BSBlendable::FloatValue ToneMapE;               // 10
				BSBlendable::FloatValue HableToeStrength;       // 1C
				BSBlendable::FloatValue HableToeLength;         // 28
				BSBlendable::FloatValue HableShoulderStrength;  // 34
				BSBlendable::FloatValue HableShoulderLength;    // 40
				BSBlendable::FloatValue HableShoulderAngle;     // 4C
			};

			static_assert(sizeof(ToneMappingSettings) == 0x58);

			//0x150 in TESImageSpace
			float                      OverallBlendAmount;   // 00
			bool                       UseOutdoorExposure;   // 04
			ExposureSettings           Exposure;             // 08
			SunAndSkySettings          SunAndSky;            // E0
			BloomSettings              Bloom;                // 188
			CinematicSettings          Cinematic;            // 1B0
			std::byte                  pad[8];               // 218
			DepthOfFieldSettings       DepthOfField;         // 220
			BlurSettings               Blur;                 // 280
			RadialBlurSettings         RadialBlur;           // 2A4
			AmbientOcclusionSettings   AmbientOcclusion;     // 2FC
			FogSettings                Fog;                  // 308
			VolumetricLightingSettings VolumetricLighting;   // 314
			IndirectLightingSettings   IndirectLighting;     // 344
			bool                       OverrideToneMapping;  // 36C
			ToneMappingSettings        ToneMapping;          // 370
		};

		static_assert(sizeof(ImageSpaceSettings) == 0x3C8);

		std::byte          pad[272];
		ImageSpaceSettings settings;

		~TESImageSpace() override;  // 00
	};
	static_assert(offsetof(TESImageSpace, settings) == 0x150);
	// static_assert(sizeof(TESImageSpace) == 0x528);
}
