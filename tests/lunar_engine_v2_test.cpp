#include "../Gabary/include/LunarEngineV2.h"

#include <iostream>

int main()
{
    Gabary::LunarEngineV2 lunar;

    bool passed = true;

    auto check =
        [&](bool condition, const char* name)
        {
            if (condition)
            {
                std::cout << "[PASS] " << name << "\n";
            }
            else
            {
                std::cout << "[FAIL] " << name << "\n";
                passed = false;
            }
        };

    // ========================================================
    // Basic epoch
    // ========================================================

    auto day1 = lunar.getDate(1);

    check(
        day1.year == 1 &&
        day1.month == 1 &&
        day1.day == 1,
        "Day 1 = Lunar 1/1/1"
    );

    check(
        lunar.getDayId(1, 1, 1) == 1,
        "Lunar 1/1/1 = Day 1"
    );

    // ========================================================
    // Year 1 boundary
    // ========================================================

    check(
        lunar.getDayId(1, 12, 29) == 354,
        "End of normal Lunar Year 1"
    );

    auto year2 = lunar.getDate(355);

    check(
        year2.year == 2 &&
        year2.month == 1 &&
        year2.day == 1,
        "Day 355 = Lunar 1/1/2"
    );

    // ========================================================
    // Leap year 3
    // ========================================================

    check(
        lunar.isLeap(3),
        "Lunar Year 3 is leap"
    );

    check(
        !lunar.isLeap(1),
        "Lunar Year 1 is normal"
    );

    check(
        lunar.isLeap(31),
        "Lunar Year 31 is leap"
    );

    check(
        !lunar.isLeap(32),
        "Lunar Year 32 is normal"
    );

    // ========================================================
    // 33-year cycle
    // ========================================================

    check(
        lunar.daysUntilYear(34) == 11693,
        "33 Lunar years = 11693 days"
    );

    check(
        lunar.getDayId(34, 1, 1) == 11694,
        "Day 11694 = Lunar 1/1/34"
    );

    auto cycleStart = lunar.getDate(11694);

    check(
        cycleStart.year == 34 &&
        cycleStart.month == 1 &&
        cycleStart.day == 1,
        "Cycle 2 starts at Lunar Year 34"
    );

    // ========================================================
    // Leap month/day
    // ========================================================

    check(
        lunar.getDayId(3, 12, 30) != -1,
        "Leap Year 3 has 30-day Dhul-Hijjah"
    );

    check(
        lunar.getDayId(1, 12, 30) == -1,
        "Normal Year 1 rejects day 30 of Dhul-Hijjah"
    );

    // ========================================================
    // Round-trip conversion
    // ========================================================

    const long long testDay = 11693;

    auto date = lunar.getDate(testDay);

    const long long roundTrip =
        lunar.getDayId(
            date.year,
            date.month,
            date.day
        );

    check(
        roundTrip == testDay,
        "Global Day -> Lunar Date -> Global Day"
    );

    // ========================================================
    // Final result
    // ========================================================

    std::cout << "\n========================================\n";

    if (passed)
    {
        std::cout
            << "LunarEngineV2 Test: PASSED\n";
        return 0;
    }

    std::cout
        << "LunarEngineV2 Test: FAILED\n";

    return 1;
}
