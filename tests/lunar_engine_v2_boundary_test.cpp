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
    // Year 1 boundaries
    // ========================================================

    check(
        lunar.getDate(354).year == 1 &&
        lunar.getDate(354).month == 12 &&
        lunar.getDate(354).day == 29,
        "Day 354 = final day of Lunar Year 1"
    );

    check(
        lunar.getDate(355).year == 2 &&
        lunar.getDate(355).month == 1 &&
        lunar.getDate(355).day == 1,
        "Day 355 = first day of Lunar Year 2"
    );

    check(
        lunar.getDayId(1, 12, 29) == 354,
        "Lunar 1/12/29 = Day 354"
    );

    check(
        lunar.getDayId(2, 1, 1) == 355,
        "Lunar 2/1/1 = Day 355"
    );

    // ========================================================
    // Leap Year 3 boundaries
    // ========================================================

    check(
        lunar.isLeap(3),
        "Lunar Year 3 is leap"
    );

    check(
        lunar.getDayId(3, 12, 30) != -1,
        "Leap Year 3 accepts Dhul-Hijjah day 30"
    );

    const long long leapYear3End =
        lunar.getDayId(3, 12, 30);

    auto leapEndDate =
        lunar.getDate(leapYear3End);

    check(
        leapEndDate.year == 3 &&
        leapEndDate.month == 12 &&
        leapEndDate.day == 30,
        "Leap Year 3 round-trip final day"
    );

    check(
        lunar.getDate(leapYear3End + 1).year == 4 &&
        lunar.getDate(leapYear3End + 1).month == 1 &&
        lunar.getDate(leapYear3End + 1).day == 1,
        "Day after Leap Year 3 starts Year 4"
    );

    // ========================================================
    // Normal Year 4 boundary
    // ========================================================

    check(
        lunar.getDayId(4, 12, 29) == leapYear3End + 354,
        "Year 4 follows Leap Year 3 correctly"
    );

    check(
        lunar.getDayId(4, 12, 30) == -1,
        "Normal Year 4 rejects Dhul-Hijjah day 30"
    );

    // ========================================================
    // 33-year cycle boundary
    // ========================================================

    const long long cycleEnd =
        lunar.daysUntilYear(34);

    check(
        cycleEnd == 11693,
        "First 33-year cycle = 11693 days"
    );

    check(
        lunar.getDate(11693).year == 33,
        "Day 11693 belongs to Lunar Year 33"
    );

    check(
        lunar.getDate(11694).year == 34 &&
        lunar.getDate(11694).month == 1 &&
        lunar.getDate(11694).day == 1,
        "Day 11694 starts Lunar Year 34"
    );

    check(
        lunar.getDayId(34, 1, 1) == 11694,
        "Lunar 34/1/1 = Day 11694"
    );

    // ========================================================
    // Cycle boundary round-trip
    // ========================================================

    const long long cycleBoundaryDays[] =
    {
        1,
        354,
        355,
        11693,
        11694,
        11695
    };

    for (long long dayId : cycleBoundaryDays)
    {
        auto date = lunar.getDate(dayId);

        const long long roundTrip =
            lunar.getDayId(
                date.year,
                date.month,
                date.day
            );

        check(
            roundTrip == dayId,
            "Boundary Global Day round-trip"
        );
    }

    // ========================================================
    // Second cycle boundary
    // ========================================================

    const long long secondCycleStart =
        lunar.getDayId(67, 1, 1);

    check(
        secondCycleStart == (11693LL * 2) + 1,
        "Third cycle start position is correct"
    );

    auto secondCycleDate =
        lunar.getDate(secondCycleStart);

    check(
        secondCycleDate.year == 67 &&
        secondCycleDate.month == 1 &&
        secondCycleDate.day == 1,
        "Cycle 3 starts at Lunar Year 67"
    );

    // ========================================================
    // Invalid dates
    // ========================================================

    check(
        lunar.getDayId(0, 1, 1) == -1,
        "Year 0 is rejected"
    );

    check(
        lunar.getDayId(1, 0, 1) == -1,
        "Month 0 is rejected"
    );

    check(
        lunar.getDayId(1, 13, 1) == -1,
        "Month 13 is rejected"
    );

    check(
        lunar.getDayId(1, 12, 30) == -1,
        "Normal year day 30 is rejected"
    );

    check(
        lunar.getDate(0).year == 0 &&
        lunar.getDate(0).month == 0 &&
        lunar.getDate(0).day == 0,
        "Global Day 0 returns invalid date"
    );

    // ========================================================
    // Final result
    // ========================================================

    std::cout << "\n========================================\n";

    if (passed)
    {
        std::cout
            << "LunarEngineV2 Boundary Test: PASSED\n";
        return 0;
    }

    std::cout
        << "LunarEngineV2 Boundary Test: FAILED\n";

    return 1;
}
