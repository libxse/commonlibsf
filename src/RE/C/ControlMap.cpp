#include "RE/C/ControlMap.h"

#include "RE/B/BSStringT.h"

namespace RE
{
	std::string ControlMap::FormatMappingRow(
		const char* a_event, const char* a_keyboard, const char* a_mouse, const char* a_gamepad,
		bool a_keyboardVisible, bool a_mouseVisible, bool a_gamepadVisible,
		std::uint32_t a_controlMask, std::uint32_t a_groupMask, bool a_required)
	{
		using func_t = BSString* (*)(BSString*, const char*, const char*, const char*, const char*,
			bool, bool, bool, std::uint32_t, std::uint32_t, bool);
		static REL::Relocation<func_t> func{ ID::ControlMap::FormatMappingRow };
		BSString                       text;
		func(&text, a_event, a_keyboard, a_mouse, a_gamepad,
			a_keyboardVisible, a_mouseVisible, a_gamepadVisible, a_controlMask, a_groupMask, a_required);
		return text.c_str();
	}

	std::string ControlMap::FormatMappingRow(
		const char* a_event, std::uint32_t a_keyboard, std::uint32_t a_mouse, std::uint32_t a_gamepad,
		bool a_keyboardVisible, bool a_mouseVisible, bool a_gamepadVisible,
		std::uint32_t a_controlMask, std::uint32_t a_groupMask, bool a_required)
	{
		using func_t = BSString* (*)(BSString*, const char*, std::uint32_t, std::uint32_t, std::uint32_t,
			bool, bool, bool, std::uint32_t, std::uint32_t, bool);
		static REL::Relocation<func_t> func{ ID::ControlMap::FormatMappingRowWithKeyCodes };
		BSString                       text;
		func(&text, a_event, a_keyboard, a_mouse, a_gamepad,
			a_keyboardVisible, a_mouseVisible, a_gamepadVisible, a_controlMask, a_groupMask, a_required);
		return text.c_str();
	}

	void ControlMap::LoadMappings()
	{
		using func_t = decltype(&ControlMap::LoadMappings);
		static REL::Relocation<func_t> func{ ID::ControlMap::LoadMappings };
		func(this);
	}

	void ControlMap::ParseMappings(const char* a_text)
	{
		using func_t = decltype(&ControlMap::ParseMappings);
		static REL::Relocation<func_t> func{ ID::ControlMap::ParseMappings };
		func(this, a_text);
	}

	void ControlMap::ResolveLinkedMappings()
	{
		using func_t = decltype(&ControlMap::ResolveLinkedMappings);
		static REL::Relocation<func_t> func{ ID::ControlMap::ResolveLinkedMappings };
		func(this);
	}
}
