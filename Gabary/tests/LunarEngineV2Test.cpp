#include "LunarEngineV2.h"

#include <iostream>
#include <cassert>

int main()
{
    Gabary::LunarEngineV2 lunar;

    std::cout
        << "========================================\n"
        << " Gabary LunarEngineV2 Boundary Test\n"
        << "========================================\n\n";

    // --------------------------------------------------------
    // Boundary 1: Global Day 1
    // Expected: Lunar 1/1/1
    // --------------------------------------------------------

    Date day1 = lunar.getDate(1);

    assert(day1.year == 1);
    assert(day1.month == 1);
    assert(day1.day == 1);

    std::cout
        << "[PASS] Day 1 -> "
        << day1.day << "/"
        << day1.month << "/"
        << day1.year << "\n";


    // --------------------------------------------------------
    // Boundary 2: End of normal lunar year
    // --------------------------------------------------------

    Date day354 = lunar.getDate(354);

    assert(day354.year == 1);
    assert(day354.month == 12);
    assert(day354.day == 29);

    std::cout
        << "[PASS] Day 354 -> "
        << day354.day << "/"
        << day354.month << "/"
        << day354.year << "\n";


    // --------------------------------------------------------
    // Boundary 3: Beginning of leap year 2
    // --------------------------------------------------------

    Date day355 = lunar.getDate(355);

    assert(day355.year == 2);
    assert(day355.month == 1);
    assert(day355.day == 1);

    std::cout
        << "[PASS] Day 355 -> "
        << day355.day << "/"
        << day355.month << "/"
        << day355.year << "\n";


    // --------------------------------------------------------
    // Boundary 4: End of first 33-year cycle
    // --------------------------------------------------------

    Date cycleEnd = lunar.getDate(11693);

    assert(cycleEnd.year == 33);
    assert(cycleEnd.month == 12);
    assert(cycleEnd.day == 30);

    std::cout
        << "[PASS] Day 11693 -> "
        << cycleEnd.day << "/"
        << cycleEnd.month << "/"
        << cycleEnd.year << "\n";


    // --------------------------------------------------------
    // Boundary 5: Beginning of cycle 2
    // --------------------------------------------------------

    Date cycleNext = lunar.getDate(11694);

    assert(cycleNext.year == 34);
    assert(cycleNext.month == 1);
    assert(cycleNext.day == 1);

    std::cout
        << "[PASS] Day 11694 -> "
        << cycleNext.day << "/"
        << cycleNext.month << "/"
        << cycleNext.year << "\n";


    // --------------------------------------------------------
    // 50,000-year solar timeline endpoint
    // --------------------------------------------------------

    Date finalDay = lunar.getDate(18262125);

    std::cout
        << "\n50,000-Year Endpoint:\n"
        << "Day ID: " << finalDay.dayId << "\n"
        << "Lunar Date: "
        << finalDay.day << "/"
        << finalDay.month << "/"
        << finalDay.year << "\n";


    // --------------------------------------------------------
    // Reverse conversion
    // --------------------------------------------------------

    long long dayId =
        lunar.getDayId(1, 1, 1);

    assert(dayId == 1);

    std::cout
        << "\n[PASS] Lunar 1/1/1 -> Day ID "
        << dayId << "\n";


    long long cycleId =
        lunar.getDayId(34, 1, 1);

    assert(cycleId == 11694);

    std::cout
        << "[PASS] Lunar 34/1/1 -> Day ID "
        << cycleId << "\n";


    std::cout
        << "\n========================================\n"
        << " LunarEngineV2 Boundary Test PASSED\n"
        << "========================================\n";

    return 0;
}
