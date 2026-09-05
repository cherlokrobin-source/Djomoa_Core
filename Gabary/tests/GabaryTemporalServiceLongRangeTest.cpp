#include "GabaryTemporalService.h"

#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Temporal Service Long-Range Test\n"
        << "============================================\n";

    GabaryTemporalService service;

    constexpr int64_t MIN_DAY = 1;
    constexpr int64_t MAX_DAY = 18261759;

    const std::vector<int64_t> days =
    {
        1,
        354,
        355,
        11693,
        11694,
        739823,
        5000000,
        10000000,
        15000000,
        18261758,
        18261759
    };

    // ------------------------------------------------
    // Global Day -> Dual Calendar
    // ------------------------------------------------
    for (int64_t day : days)
    {
        const auto result = service.queryDay(day);

        assert(result.dayId == day);

        assert(result.solar.solarYear >= 1);
        assert(result.solar.solarYear <= 49999);
        assert(result.solar.solarMonth >= 1);
        assert(result.solar.solarMonth <= 12);
        assert(result.solar.solarDay >= 1);

        constexpr int64_t LUNAR_MAX_DAY = 17716312;

        if (day <= LUNAR_MAX_DAY)
        {
            assert(result.lunar.dayId == day);
            assert(result.lunar.year >= 1);
            assert(result.lunar.year <= 49999);
            assert(result.lunar.month >= 1);
            assert(result.lunar.month <= 12);
            assert(result.lunar.day >= 1);
        }
        else
        {
            // Lunar timeline has already ended.
            assert(result.lunar.dayId == 0);
            assert(result.lunar.year == 0);
            assert(result.lunar.month == 0);
            assert(result.lunar.day == 0);
        }

        std::cout
            << "[PASS] Service query at Global Day "
            << day << "\n";
    }

    // ------------------------------------------------
    // Solar round-trip
    // ------------------------------------------------
    for (int64_t day : days)
    {
        const auto original = service.queryDay(day);

        const auto restored = service.querySolar(
            original.solar.solarYear,
            original.solar.solarMonth,
            original.solar.solarDay
        );

        assert(restored.dayId == day);

        std::cout
            << "[PASS] Service Solar round-trip at Day "
            << day << "\n";
    }

    // ------------------------------------------------
    // Lunar round-trip
    // ------------------------------------------------
    constexpr int64_t LUNAR_LAST_DAY = 17716312;

    for (int64_t day : days)
    {
        const auto original = service.queryDay(day);

        if (day <= LUNAR_LAST_DAY)
        {
            const auto restored = service.queryLunar(
                original.lunar.year,
                original.lunar.month,
                original.lunar.day
            );

            assert(restored.dayId == day);

            std::cout
                << "[PASS] Service Lunar round-trip at Day "
                << day << "\n";
        }
        else
        {
            assert(original.lunar.dayId == 0);
            assert(original.lunar.year == 0);
            assert(original.lunar.month == 0);
            assert(original.lunar.day == 0);

            std::cout
                << "[PASS] Service Lunar unsupported after Day "
                << LUNAR_LAST_DAY
                << " at Day "
                << day << "\n";
        }
    }

    // ------------------------------------------------
    // Shared Global Day integrity
    // ------------------------------------------------
    for (int64_t day : days)
    {
        const auto byDay = service.queryDay(day);

        const auto solar = service.querySolar(
            byDay.solar.solarYear,
            byDay.solar.solarMonth,
            byDay.solar.solarDay
        );

        assert(solar.dayId == day);

        if (day <= LUNAR_LAST_DAY)
        {
            const auto lunar = service.queryLunar(
                byDay.lunar.year,
                byDay.lunar.month,
                byDay.lunar.day
            );

            assert(lunar.dayId == day);
            assert(solar.dayId == lunar.dayId);

            std::cout
                << "[PASS] Shared Global Day integrity at Day "
                << day << "\n";
        }
        else
        {
            assert(byDay.lunar.dayId == 0);
            assert(byDay.lunar.year == 0);
            assert(byDay.lunar.month == 0);
            assert(byDay.lunar.day == 0);

            std::cout
                << "[PASS] Shared Global Day solar-only integrity at Day "
                << day << "\n";
        }
    }

    // ------------------------------------------------
    // Report integrity
    // ------------------------------------------------
    {
        const auto report = service.reportByDay(739823);

        assert(!report.empty());
        assert(
            report.find("Global Day ID : 739823")
            != std::string::npos
        );
        assert(
            report.find("SOLAR CALENDAR")
            != std::string::npos
        );
        assert(
            report.find("LUNAR CALENDAR")
            != std::string::npos
        );

        std::cout
            << "[PASS] Report integrity at Day 739823\n";
    }

    // ------------------------------------------------
    // Global timeline boundaries
    // ------------------------------------------------
    {
        const auto first = service.queryDay(MIN_DAY);

        assert(first.dayId == MIN_DAY);
        assert(first.solar.solarYear == 1);
        assert(first.solar.solarMonth == 1);
        assert(first.solar.solarDay == 1);

        assert(first.lunar.year == 1);
        assert(first.lunar.month == 1);
        assert(first.lunar.day == 1);

        const auto last = service.queryDay(MAX_DAY);

        assert(last.dayId == MAX_DAY);
        assert(last.solar.solarYear == 49999);
        assert(last.solar.solarMonth == 12);
        assert(last.solar.solarDay == 31);

        std::cout
            << "[PASS] Global timeline boundaries\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 Temporal Service Long-Range: PASSED\n"
        << "============================================\n";

    return 0;
}
