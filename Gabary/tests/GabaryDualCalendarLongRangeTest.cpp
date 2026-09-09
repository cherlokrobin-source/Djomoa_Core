#include <cassert>
#include <cstdint>
#include <iostream>

#include "GabaryDualCalendarEngine.h"
#include "GabaryNavigationEngine.h"

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Dual Calendar Long-Range Test\n"
        << "============================================\n\n";

    GabaryDualCalendarEngine dual;
    GabaryNavigationEngine navigation;

    const int64_t MIN_DAY =
        GabaryNavigationEngine::MIN_GLOBAL_DAY;
    const int64_t MAX_DAY =
        GabaryNavigationEngine::MAX_GLOBAL_DAY;

    // ------------------------------------------------------------
    // Representative Global Day coordinates
    // ------------------------------------------------------------
    const int64_t testDays[] =
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

    const std::size_t testCount =
        sizeof(testDays) / sizeof(testDays[0]);

    // ------------------------------------------------------------
    // Global Day -> Dual Calendar integrity
    // ------------------------------------------------------------
    for (std::size_t i = 0; i < testCount; ++i)
    {
        const int64_t dayId = testDays[i];

        DualCalendarDate result =
            dual.getDate(dayId);

        assert(result.dayId == dayId);
        assert(result.solar.dayId == dayId);
        assert(result.solar.solarYear >= 1);
        assert(result.solar.solarYear <= 49999);
        assert(result.solar.solarMonth >= 1);
        assert(result.solar.solarMonth <= 12);
        assert(result.solar.solarDay >= 1);
        assert(result.solar.solarDay <= 31);

        constexpr int64_t LUNAR_LAST_DAY = 17716312;
        if (dayId <= LUNAR_LAST_DAY)
        {
            assert(result.lunar.dayId == dayId);
            assert(result.lunar.year >= 1);
            assert(result.lunar.year <= 49999);
            assert(result.lunar.month >= 1);
            assert(result.lunar.month <= 12);
            assert(result.lunar.day >= 1);
            assert(result.lunar.day <= 30);
        }
        else
        {
            assert(result.lunar.dayId == 0);
            assert(result.lunar.year == 0);
            assert(result.lunar.month == 0);
            assert(result.lunar.day == 0);
        }

        std::cout
            << "[PASS] Global Day "
            << dayId
            << " -> valid dual-calendar coordinate\n";
    }

    // ------------------------------------------------------------
    // Solar -> Global Day -> Solar round-trip
    // ------------------------------------------------------------
    for (std::size_t i = 0; i < testCount; ++i)
    {
        const int64_t dayId = testDays[i];

        DualCalendarDate result =
            dual.getDate(dayId);

        const int64_t reconstructed =
            dual.solarToDayId(
                result.solar.solarYear,
                result.solar.solarMonth,
                result.solar.solarDay
            );

        assert(reconstructed == dayId);

        std::cout
            << "[PASS] Solar round-trip at Day "
            << dayId << "\n";
    }

    // ------------------------------------------------------------
    // Lunar -> Global Day -> Lunar round-trip
    // ------------------------------------------------------------
    for (std::size_t i = 0; i < testCount; ++i)
    {
        const int64_t dayId = testDays[i];

        DualCalendarDate result =
            dual.getDate(dayId);

        constexpr int64_t LUNAR_LAST_DAY = 17716312;
        if (dayId <= LUNAR_LAST_DAY)
        {
            const int64_t reconstructed =
                dual.lunarToDayId(
                    result.lunar.year,
                    result.lunar.month,
                    result.lunar.day
                );

            assert(reconstructed == dayId);

            std::cout
                << "[PASS] Lunar round-trip at Day "
                << dayId << "\n";
        }
        else
        {
            assert(result.lunar.dayId == 0);
            assert(result.lunar.year == 0);
            assert(result.lunar.month == 0);
            assert(result.lunar.day == 0);

            std::cout
                << "[PASS] Lunar unsupported after Day "
                << LUNAR_LAST_DAY
                << " at Day "
                << dayId << "\n";
        }
    }

    // ------------------------------------------------------------
    // Navigation coordinate integrity
    // ------------------------------------------------------------
    for (std::size_t i = 1; i < testCount - 1; ++i)
    {
        const int64_t dayId = testDays[i];

        DualCalendarDate current =
            navigation.getDate(dayId);

        DualCalendarDate next =
            navigation.nextDay(dayId);

        DualCalendarDate previous =
            navigation.previousDay(dayId);

        assert(current.dayId == dayId);
        assert(next.dayId == dayId + 1);
        assert(previous.dayId == dayId - 1);

        std::cout
            << "[PASS] Navigation continuity at Day "
            << dayId << "\n";
    }

    // ------------------------------------------------------------
    // Global boundary integrity
    // ------------------------------------------------------------
    {
        DualCalendarDate first =
            dual.getDate(MIN_DAY);

        DualCalendarDate last =
            dual.getDate(MAX_DAY);

        assert(first.dayId == MIN_DAY);
        assert(last.dayId == MAX_DAY);

        assert(first.solar.solarYear == 1);
        assert(first.solar.solarMonth == 1);
        assert(first.solar.solarDay == 1);

        assert(last.solar.solarYear == 49999);
        assert(last.solar.solarMonth == 12);
        assert(last.solar.solarDay == 31);

        std::cout
            << "[PASS] Global timeline boundaries\n";
    }

    // ------------------------------------------------------------
    // Final result
    // ------------------------------------------------------------
    std::cout
        << "\n============================================\n"
        << " Gabary V2 Dual Calendar Long-Range: PASSED\n"
        << "============================================\n";

    return 0;
}
