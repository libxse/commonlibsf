#pragma once

//statically linked so no RTTI

namespace RE::BGSAudio
{
	// Wwise 2021.1 codec IDs (AkCodecID). The engine's default external-source is kVorbis (voice .wem are Vorbis).
	// File/encoding types of Audiokinetic. Pulled from AkTypes.h of wwise sdk 2021.1.14
	enum class AkCodecID : std::uint32_t
	{
		kBank = 0,
		kPCM = 1,
		kADPCM = 2,
		kXMA = 3,
		kVorbis = 4,
		kWiiADPCM = 5,
		kPCMEX = 7,
		kExternalSource = 8,
		kXWMA = 9,
		kAAC = 10,
		kFilePackage = 11,
		kATRAC9 = 12,
		kVAG = 13,
		kProfilerCapture = 14,
		kAnalysisFile = 15,
		kMIDI = 16,
		kOpusNX = 17,
		kCAF = 18,
		kAkOpus = 20,
		kAkOpusWem = 20,
		kAkMemoryMgrDump = 21,
	};

	// hash of "External_Source" - the cookie engine uses for its own VO posts.
	inline constexpr std::uint32_t kExternalSourceCookie = 0x24DB9834;

	//AkExternalSourceInfo from wwise 2021.1.
	struct AkExternalSourceInfo
	{
		std::uint32_t iExternalSrcCookie;  /// 00 - Cookie identifying the source, given by hashing the name of the source given in the project.
		std::uint32_t idCodec;             /// 04 - Codec ID for the file.  One of the audio formats defined in AkCodecID
		wchar_t*      szFile;              /// 08 - File path for the source.  If not NULL, the source will be streaming from disk.  Set pInMemory to NULL. If idFile is set, this field is used as stream name (for profiling purposes).
		void*         pInMemory;           /// 10 - Pointer to the in-memory file.  If not NULL, the source will be read from memory.  Set szFile and idFile to NULL.
		std::uint32_t uiMemorySize;        /// 18 - Size of the data pointed by pInMemory
		std::uint32_t idFile;              /// 1C - File ID.  If not zero, the source will be streaming from disk.  This ID can be anything.
	};
	static_assert(sizeof(AkExternalSourceInfo) == 0x20);

	// Wwise 2021.1 3D vector (AkTypes.h).
	struct AkVector
	{
		float X;
		float Y;
		float Z;
	};
	static_assert(sizeof(AkVector) == 0x0C);

	// Wwise 2021.1 AkSoundPosition (== AkTransform, AkTypes.h). Param of SetPosition.
	struct AkSoundPosition
	{
		AkVector orientationFront;  // 00 - must be normalized
		AkVector orientationTop;    // 0C - must be normalized, orthogonal to front
		AkVector position;          // 18
	};
	static_assert(sizeof(AkSoundPosition) == 0x24);

	//Thin binding over wwise AK::SoundEngine entry points.
	//Posted events ride game mix (volume, pause, ducking, etc...) for "free"
	class AkSoundEngine
	{
	public:
		using AkUniqueID = std::uint32_t;
		using AkGameObjectID = std::uint64_t;
		using AkPlayingID = std::uint32_t;
		using AkBankID = std::uint32_t;
		using AKRESULT = std::uint32_t;  // AK_Success == 1

		// The player TESObjectREFR is the engine special case: AkGameObjectID 2
		//Positioned 3d audio resolve via WwiseGameObjectMgr::GetOrCreateGameObjectId
		static constexpr AkGameObjectID kPlayerGameObject = 2;
		static constexpr AKRESULT       kAkSuccess = 1;

		// Lets you resolve a custom event name with no WWED Form
		static AkUniqueID GetIDFromString(const char* a_name)
		{
			using func_t = decltype(&AkSoundEngine::GetIDFromString);
			static REL::Relocation<func_t> func{ ID::AkSoundEngine::GetIDFromString };
			return func(a_name);
		}

		// PostEvent from wwise. To play pass in_cExternals=1 and
		// in_pExternalSources pointing at an AkExternalSourceInfo whose iExternalSrcCookie matches a placeholder in in_eventID.
		// Returns AkPlayingID (0 = rejected — usually a_event not in any loadedd bank, or no matching external-source slot).
		// Enqueue-only and should be safe to call from any thread.
		static AkPlayingID PostEvent(
			AkUniqueID            in_eventID,                     ///< Unique ID of the event
			AkGameObjectID        in_gameObjectID,                ///< Associated game object ID
			std::uint32_t         in_uFlags = 0,                  ///< Bitmask: see \ref AkCallbackType
			void*                 in_pfnCallback = nullptr,       ///< Callback function
			void*                 in_pCookie = nullptr,           ///< Callback cookie that will be sent to the callback function along with additional information
			std::uint32_t         in_cExternals = 0,              ///< Optional count of external source structures
			AkExternalSourceInfo* in_pExternalSources = nullptr,  ///< Optional array of external source resolution information
			AkPlayingID           in_PlayingID = 0                ///< Optional (advanced users only) Specify the playing ID to target with the event.
		)
		{
			using func_t = decltype(&AkSoundEngine::PostEvent);
			static REL::Relocation<func_t> func{ ID::AkSoundEngine::PostEvent };
			return func(in_eventID, in_gameObjectID, in_uFlags, in_pfnCallback, in_pCookie, in_cExternals, in_pExternalSources, in_PlayingID);
		}

		// Load a SoundBank by name. The engine appends ".bnk" and resolves it
		static AKRESULT LoadBank(const char* a_name, AkBankID& a_outBankID)
		{
			using func_t = decltype(&AkSoundEngine::LoadBank);
			static REL::Relocation<func_t> func{ ID::AkSoundEngine::LoadBank };
			return func(a_name, a_outBankID);
		}

		// Unloads a SoundBank by name. a_inMemoryBankPtr must be the pointer the
		// bank was loaded from, or nullptr for name/file-loaded banks (our case).
		// NOTE: this build has NO memory-load (LoadBankMemoryView) overload — it was
		// dead-code-eliminated — so a mod bank is always name/file-loaded, and this
		// is the matching unload. Returns AKRESULT (kAkSuccess == 1). AddrLib 150434.

		//unload a sound bank. a_inMemoryBankPtr must be the pointer bank loaded from, or nullptr for name/file-loaded banks
		//Pretty sure banks are always name/file-loaded
		static AKRESULT UnloadBank(const char* a_name, const void* a_inMemoryBankPtr = nullptr)
		{
			using func_t = decltype(&AkSoundEngine::UnloadBank);
			static REL::Relocation<func_t> func{ ID::AkSoundEngine::UnloadBank };
			return func(a_name, a_inMemoryBankPtr);
		}

		//Sets a registered game object's 3D position/orientationa so its spacialized.
		static AKRESULT SetPosition(AkGameObjectID a_gameObject, const AkSoundPosition& a_position)
		{
			using func_t = decltype(&AkSoundEngine::SetPosition);
			static REL::Relocation<func_t> func{ ID::AkSoundEngine::SetPosition };
			return func(a_gameObject, a_position);
		}
	};
}
