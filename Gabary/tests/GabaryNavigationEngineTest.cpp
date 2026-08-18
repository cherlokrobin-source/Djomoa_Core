#include <iostream>
#include <cassert>
#include <cstdint>

#include "GabaryNavigationEngine.h"

int main()
{
    Gabary::GabaryNavigationEngine navigation;

    std::cout
        << "============================================\n"
        << " Gabary V2 Navigation Engine Test\n"
        << "============================================\n\n";

    // 1. Global Day 1
    auto day1 = navigation.getDate(1);
    assert(day1.dayId == 1);
    std::cout << "[PASS] Navigation -> Global Day 1\n";

    // 2. Next Day
    auto day2 = navigation.nextDay(1);
    assert(day2.dayId == 2);
    std::cout << "[PASS] Next day navigation\n";

    // 3. Previous Day
    auto backToDay1 = navigation.previousDay(2);
    assert(backToDay1.dayId == 1);
    std::cout << "[PASS] Previous day navigation\n";

    // 4. Epoch boundary protection
    auto epoch = navigation.previousDay(1);
    assert(epoch.dayId == 1);
    std::cout << "[PASS] Epoch boundary protection\n";

    // 5. Solar date jump
    const int64_t solarDay = navigation.jumpToSolarDate(2026, 7, 26);
    auto solarResult = navigation.getDate(solarDay);
    assert(solarResult.dayId == solarDay);
    std::cout << "[PASS] Solar date navigation\n";

    std::cout
        << "\n============================================\n"
        << " Gabary V2 Navigation Engine: PASSED\n"
        << "============================================\n";

    return 0;
}
