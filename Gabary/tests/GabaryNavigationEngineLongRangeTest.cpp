#include "GabaryNavigationEngine.h"
#include <iostream>
#include <cassert>
#include <vector>

using namespace Gabary;

int main()
{
    std::cout << "============================================\n";
    std::cout << " Gabary V2 Navigation Engine Long-Range Test\n";
    std::cout << "============================================\n\n";

    GabaryNavigationEngine engine;

    const int64_t MAX =
        GabaryNavigationEngine::MAX_GLOBAL_DAY;

    const std::vector<int64_t> testDays = {
        1,
        2,
        365,
        366,
        1000,
        10000,
        36525,
        100000,
        500000,
        1000000,
        5000000,
        10000000,
        15000000,
        MAX - 2,
        MAX - 1,
    };

    // --------------------------------------------------
    // 1. Forward / backward identity
    // --------------------------------------------------
    for (int64_t day : testDays)
    {
        auto next = engine.nextDay(day);
        auto restored = engine.previousDay(next.dayId);

        assert(restored.dayId == day);
    }

    std::cout
        << "[PASS] previous(next(D)) == D across timeline\n";

    // --------------------------------------------------
    // 2. Backward / forward identity
    // --------------------------------------------------
    for (int64_t day : testDays)
    {
        if (day == GabaryNavigationEngine::MIN_GLOBAL_DAY)
            continue;

        auto previous = engine.previousDay(day);
        auto restored = engine.nextDay(previous.dayId);

        assert(restored.dayId == day);
    }

    std::cout
        << "[PASS] next(previous(D)) == D across timeline\n";

    // --------------------------------------------------
    // 3. Sequential forward navigation
    // --------------------------------------------------
    {
        const int64_t start = 100000;

        auto current = engine.getDate(start);

        for (int i = 1; i <= 1000; ++i)
        {
            current = engine.nextDay(current.dayId);

            assert(current.dayId == start + i);
        }
    }

    std::cout
        << "[PASS] 1000-day forward navigation\n";

    // --------------------------------------------------
    // 4. Sequential backward navigation
    // --------------------------------------------------
    {
        const int64_t start = 101000;

        auto current = engine.getDate(start);

        for (int i = 1; i <= 1000; ++i)
        {
            current = engine.previousDay(current.dayId);

            assert(current.dayId == start - i);
        }
    }

    std::cout
        << "[PASS] 1000-day backward navigation\n";

    // --------------------------------------------------
    // 5. Maximum boundary stability
    // --------------------------------------------------
    {
        auto current = engine.nextDay(MAX);

        assert(current.dayId == MAX);
    }

    std::cout
        << "[PASS] Maximum Global Day stability\n";

    // --------------------------------------------------
    // 6. Minimum boundary stability
    // --------------------------------------------------
    {
        auto current = engine.previousDay(
            GabaryNavigationEngine::MIN_GLOBAL_DAY
        );

        assert(
            current.dayId ==
            GabaryNavigationEngine::MIN_GLOBAL_DAY
        );
    }

    std::cout
        << "[PASS] Minimum Global Day stability\n";

    std::cout << "\n============================================\n";
    std::cout << " Gabary V2 Navigation Long-Range: PASSED\n";
    std::cout << "============================================\n";

    return 0;
}
