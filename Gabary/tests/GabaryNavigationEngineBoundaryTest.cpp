#include "GabaryNavigationEngine.h"
#include <iostream>
#include <cassert>

using namespace Gabary;

int main()
{
    std::cout << "============================================\n";
    std::cout << " Gabary V2 Navigation Engine Boundary Test\n";
    std::cout << "============================================\n\n";

    GabaryNavigationEngine engine;

    // --------------------------------------------------
    // 1. Minimum Global Day
    // --------------------------------------------------
    {
        auto date = engine.getDate(
            GabaryNavigationEngine::MIN_GLOBAL_DAY
        );

        assert(date.dayId ==
               GabaryNavigationEngine::MIN_GLOBAL_DAY);

        std::cout << "[PASS] Minimum Global Day\n";
    }

    // --------------------------------------------------
    // 2. Epoch previous-day protection
    // --------------------------------------------------
    {
        auto date = engine.previousDay(
            GabaryNavigationEngine::MIN_GLOBAL_DAY
        );

        assert(date.dayId ==
               GabaryNavigationEngine::MIN_GLOBAL_DAY);

        std::cout << "[PASS] Epoch boundary protection\n";
    }

    // --------------------------------------------------
    // 3. Next / Previous identity
    // --------------------------------------------------
    {
        const int64_t day = 1000;

        auto next = engine.nextDay(day);
        auto restored = engine.previousDay(
            next.dayId
        );

        assert(restored.dayId == day);

        std::cout << "[PASS] previous(next(D)) == D\n";
    }

    // --------------------------------------------------
    // 4. Previous / Next identity
    // --------------------------------------------------
    {
        const int64_t day = 1000;

        auto previous = engine.previousDay(day);
        auto restored = engine.nextDay(
            previous.dayId
        );

        assert(restored.dayId == day);

        std::cout << "[PASS] next(previous(D)) == D\n";
    }

    // --------------------------------------------------
    // 5. Year boundary
    // --------------------------------------------------
    {
        auto day365 = engine.getDate(365);
        auto day366 = engine.nextDay(365);

        assert(day366.dayId == 366);

        std::cout << "[PASS] Global Day 365 -> 366\n";
    }

    // --------------------------------------------------
    // 6. Long-range navigation
    // --------------------------------------------------
    {
        const int64_t day = 100000;

        auto next = engine.nextDay(day);
        auto previous = engine.previousDay(
            next.dayId
        );

        assert(next.dayId == day + 1);
        assert(previous.dayId == day);

        std::cout << "[PASS] Long-range navigation\n";
    }

    // --------------------------------------------------
    // 7. Maximum Global Day
    // --------------------------------------------------
    {
        auto date = engine.getDate(
            GabaryNavigationEngine::MAX_GLOBAL_DAY
        );

        assert(date.dayId ==
               GabaryNavigationEngine::MAX_GLOBAL_DAY);

        std::cout << "[PASS] Maximum Global Day\n";
    }

    // --------------------------------------------------
    // 8. Maximum boundary protection
    // --------------------------------------------------
    {
        auto date = engine.nextDay(
            GabaryNavigationEngine::MAX_GLOBAL_DAY
        );

        assert(date.dayId ==
               GabaryNavigationEngine::MAX_GLOBAL_DAY);

        std::cout << "[PASS] Maximum boundary protection\n";
    }

    std::cout << "\n============================================\n";
    std::cout << " Gabary V2 Navigation Boundary Test: PASSED\n";
    std::cout << "============================================\n";

    return 0;
}
