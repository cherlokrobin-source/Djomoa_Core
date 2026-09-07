#include "GabaryNavigationEngine.h"

#include <cassert>
#include <cstdint>
#include <iostream>

using namespace Gabary;

int main()
{
    std::cout
        << "============================================\n"
        << " Gabary V2 Navigation Engine Contract Test\n"
        << "============================================\n";

    GabaryNavigationEngine engine;

    const int64_t MIN = GabaryNavigationEngine::MIN_GLOBAL_DAY;
    const int64_t MAX = GabaryNavigationEngine::MAX_GLOBAL_DAY;

    // ------------------------------------------------
    // 1. Valid minimum boundary
    // ------------------------------------------------
    {
        auto date = engine.getDate(MIN);

        assert(date.dayId == MIN);

        std::cout << "[PASS] Minimum Global Day contract\n";
    }

    // ------------------------------------------------
    // 2. Valid maximum boundary
    // ------------------------------------------------
    {
        auto date = engine.getDate(MAX);

        assert(date.dayId == MAX);

        std::cout << "[PASS] Maximum Global Day contract\n";
    }

    // ------------------------------------------------
    // 3. Previous-day boundary stability
    // ------------------------------------------------
    {
        auto date = engine.previousDay(MIN);

        assert(date.dayId == MIN);

        std::cout << "[PASS] previousDay(MIN) stability\n";
    }

    // ------------------------------------------------
    // 4. Next-day boundary stability
    // ------------------------------------------------
    {
        auto date = engine.nextDay(MAX);

        assert(date.dayId == MAX);

        std::cout << "[PASS] nextDay(MAX) stability\n";
    }

    // ------------------------------------------------
    // 5. Forward/backward identity
    // ------------------------------------------------
    {
        const int64_t testDays[] = {
            1,
            2,
            365,
            366,
            1000,
            36525,
            100000,
            1000000,
            5000000,
            10000000,
            15000000,
            MAX - 1,
        };

        for (int64_t day : testDays)
        {
            auto next = engine.nextDay(day);
            auto restored = engine.previousDay(next.dayId);

            assert(restored.dayId == day);
        }

        std::cout
            << "[PASS] previous(next(D)) == D across contract points\n";
    }

    // ------------------------------------------------
    // 6. Backward/forward identity
    // ------------------------------------------------
    {
        const int64_t testDays[] = {
            2,
            365,
            366,
            1000,
            36525,
            100000,
            1000000,
            5000000,
            10000000,
            15000000,
            MAX - 1,
        };

        for (int64_t day : testDays)
        {
            auto previous = engine.previousDay(day);
            auto restored = engine.nextDay(previous.dayId);

            assert(restored.dayId == day);
        }

        std::cout
            << "[PASS] next(previous(D)) == D across contract points\n";
    }

    // ------------------------------------------------
    // 7. Sequential navigation
    // ------------------------------------------------
    {
        const int64_t start = 100000;

        auto current = engine.getDate(start);

        for (int i = 1; i <= 1000; ++i)
        {
            current = engine.nextDay(current.dayId);

            assert(current.dayId == start + i);
        }

        std::cout
            << "[PASS] Sequential forward navigation contract\n";
    }

    // ------------------------------------------------
    // 8. Sequential reverse navigation
    // ------------------------------------------------
    {
        const int64_t start = 101000;

        auto current = engine.getDate(start);

        for (int i = 1; i <= 1000; ++i)
        {
            current = engine.previousDay(current.dayId);

            assert(current.dayId == start - i);
        }

        std::cout
            << "[PASS] Sequential backward navigation contract\n";
    }

    // ------------------------------------------------
    // 9. Solar coordinate continuity
    // ------------------------------------------------
    {
        const int64_t day = 1000;

        auto current = engine.getDate(day);
        auto next = engine.nextDay(day);

        assert(next.dayId == current.dayId + 1);

        std::cout
            << "[PASS] Global Solar Day continuity\n";
    }

    // ------------------------------------------------
    // 10. Final boundary integrity
    // ------------------------------------------------
    {
        auto finalDay = engine.getDate(MAX);
        auto previous = engine.previousDay(MAX);

        assert(finalDay.dayId == MAX);
        assert(previous.dayId == MAX - 1);

        std::cout
            << "[PASS] Final boundary integrity\n";
    }

    std::cout
        << "============================================\n"
        << " Gabary V2 Navigation Contract: PASSED\n"
        << "============================================\n";

    return 0;
}
