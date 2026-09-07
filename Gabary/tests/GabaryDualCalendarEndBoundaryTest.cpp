#include <cassert>
#include <cstdint>
#include <iostream>

#include "GabaryNavigationEngine.h"
#include "GabaryDualCalendarEngine.h"

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Final Solar Boundary Test\n"
        << "============================================\n";

    GabaryNavigationEngine navigation;
    GabaryDualCalendarEngine dual;

    const int64_t minDay = GabaryNavigationEngine::MIN_GLOBAL_DAY;
    const int64_t maxDay = GabaryNavigationEngine::MAX_GLOBAL_DAY;

    // ------------------------------------------------
    // Boundary constants
    // ------------------------------------------------
    {
        assert(minDay == 1);
        assert(maxDay == 18262125);
        assert(maxDay > minDay);

        std::cout << "[PASS] Global Day range constants\n";
    }

    // ------------------------------------------------
    // Last Global Day
    // ------------------------------------------------
    {
        DualCalendarDate result = dual.getDate(maxDay);

        assert(result.dayId == maxDay);
        assert(result.solar.solarYear > 0);
        assert(result.lunar.year > 0);

        std::cout << "[PASS] Last Global Day resolves\n";
    }

    // ------------------------------------------------
    // Navigation at final boundary
    // ------------------------------------------------
    {
        DualCalendarDate result =
            navigation.getDate(maxDay);

        assert(result.dayId == maxDay);

        std::cout << "[PASS] Navigation reaches final Global Day\n";
    }

    // ------------------------------------------------
    // Previous day from final boundary
    // ------------------------------------------------
    {
        DualCalendarDate previous =
            navigation.previousDay(maxDay);

        assert(previous.dayId == maxDay - 1);

        std::cout << "[PASS] Previous day from final boundary\n";
    }

    // ------------------------------------------------
    // Shared coordinate integrity at end
    // ------------------------------------------------
    {
        DualCalendarDate result =
            dual.getDate(maxDay);

        DualCalendarDate same =
            navigation.getDate(result.dayId);

        assert(same.dayId == maxDay);

        assert(
            same.solar.solarYear ==
            result.solar.solarYear
        );

        assert(
            same.solar.solarMonth ==
            result.solar.solarMonth
        );

        assert(
            same.solar.solarDay ==
            result.solar.solarDay
        );

        assert(
            same.lunar.year ==
            result.lunar.year
        );

        assert(
            same.lunar.month ==
            result.lunar.month
        );

        assert(
            same.lunar.day ==
            result.lunar.day
        );

        std::cout
            << "[PASS] Final Solar/Lunar shared coordinate\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 Final Boundary: PASSED\n"
        << "============================================\n";

    return 0;
}
