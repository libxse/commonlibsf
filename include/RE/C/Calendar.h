#pragma once

#include "RE/B/BSTSingleton.h"
#include "RE/T/TESGlobal.h"

namespace RE
{
	class Calendar :
		public BSTSingletonSDM<Calendar>  // 00
	{
	public:
		[[nodiscard]] static auto GetSingleton()
		{
			static REL::Relocation<Calendar**> singleton{ ID::Calendar::Singleton };
			return *singleton;
		}

		std::uint32_t GetDay() const noexcept
		{
			return gameDay ? static_cast<std::uint32_t>(gameDay->value) : 17u;
		}

		std::uint32_t GetDaysPassed() const noexcept
		{
			return gameDaysPassed ? static_cast<std::uint32_t>(gameDaysPassed->value) : 0u;
		}

		float GetDaysPassedExact() const noexcept
		{
			return gameDaysPassed ? gameDaysPassed->value : 0.0f;
		}

		float GetHour() const noexcept
		{
			return gameHour ? gameHour->value : 12.0f;
		}

		float GetHourFromDaysPassed(float a_daysPassed) const noexcept
		{
			return std::fmodf(a_daysPassed, 1.0f) * 24.0f;
		}

		float GetHoursPassedExact() const noexcept
		{
			return gameDaysPassed ? gameDaysPassed->value * 24.0f : 0.0f;
		}

		std::uint16_t GetMonth() const noexcept
		{
			return gameMonth ? static_cast<std::uint16_t>(gameMonth->value) : 8u;
		}

		float GetTimeScale() const
		{
			return timeScale->value;
		}

		std::uint32_t GetYear() const noexcept
		{
			return gameYear ? static_cast<std::uint32_t>(gameYear->value) : 77u;
		}

		// members
		TESGlobal*    gameYear;         // 10
		TESGlobal*    gameMonth;        // 18
		TESGlobal*    gameDay;          // 20
		TESGlobal*    gameHour;         // 28
		TESGlobal*    gameDaysPassed;   // 30
		TESGlobal*    timeScale;        // 38
		std::uint32_t midnightsPassed;  // 40
		float         rawDaysPassed;    // 44
	};
	static_assert(sizeof(Calendar) == 0x48);
}
