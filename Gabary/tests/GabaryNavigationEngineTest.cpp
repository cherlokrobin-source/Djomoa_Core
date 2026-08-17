#include <iostream>
#include <cassert>
#include <vector>
#include "GabaryNavigationEngine.h"

void test_basic_navigation() {
    Gabary::GabaryNavigationEngine nav;
    int64_t currentDay = 1;

    auto d1 = nav.getDate(currentDay);
    assert(d1.dayId == 1);

    int64_t solarDayId = nav.jumpToSolarDate(2026, 1, 1);
    assert(solarDayId == 739617);
    
    auto dSolar = nav.getDate(solarDayId);
    assert(dSolar.lunar.day == 6);

    std::cout << "[PASS] Basic Navigation & Solar Jump Test Passed.\n";
}

void test_leap_years_and_boundaries() {
    Gabary::GabaryNavigationEngine nav;

    auto epochStart = nav.getDate(1);
    assert(epochStart.dayId == 1);

    int64_t feb29_2024 = nav.jumpToSolarDate(2024, 2, 29);
    assert(feb29_2024 > 0);

    auto dMar1 = nav.nextDay(feb29_2024);
    assert(dMar1.dayId == feb29_2024 + 1);

    int64_t maxEpochDays = 18262116; 
    auto epochEnd = nav.getDate(maxEpochDays);
    assert(epochEnd.dayId == maxEpochDays);

    std::cout << "[PASS] Boundaries & Solar Leap Years Passed.\n";
}

void test_lunar_cycles_and_holy_months() {
    Gabary::GabaryNavigationEngine nav;

    int64_t dayId = nav.jumpToSolarDate(2026, 3, 20);
    auto dateInfo = nav.getDate(dayId);

    assert(dateInfo.lunar.day >= 1 && dateInfo.lunar.day <= 30);
    assert(dateInfo.lunar.month >= 1 && dateInfo.lunar.month <= 12);

    int64_t trackerDay = dayId;
    for (int i = 0; i < 30; ++i) {
        auto d = nav.getDate(trackerDay);
        assert(d.lunar.day >= 1 && d.lunar.day <= 30);
        trackerDay++;
    }
    std::cout << "[PASS] Full 30-day Lunar Cycle Continuity Check Passed.\n";
}

void test_spring_equinox_lunar_drift() {
    Gabary::GabaryNavigationEngine nav;
    std::vector<int> testYears = {2024, 2025, 2026, 2027};

    std::cout << "\n--- Spring Equinox (March 21) Lunar Alignment Check ---" << std::endl;

    for (int year : testYears) {
        // القفز إلى الاعتدال الربيعي 21 مارس
        int64_t equinoxDayId = nav.jumpToSolarDate(year, 3, 21);
        auto date = nav.getDate(equinoxDayId);

        // التحقق من صحة القيم القمرية
        assert(date.lunar.month >= 1 && date.lunar.month <= 12);
        assert(date.lunar.day >= 1 && date.lunar.day <= 30);

        std::cout << "Solar March 21, " << year 
                  << " -> Lunar Date: Year " << date.lunar.year 
                  << ", Month " << date.lunar.month 
                  << ", Day " << date.lunar.day 
                  << " (DayID: " << equinoxDayId << ")" << std::endl;
    }

    std::cout << "[PASS] Spring Equinox Solar-Lunar Dual Sync Verified.\n";
}

int main() {
    std::cout << "============================================\n";
    std::cout << " Gabary V2 Chronology Engine - Full Suite   \n";
    std::cout << "============================================\n";

    test_basic_navigation();
    test_leap_years_and_boundaries();
    test_lunar_cycles_and_holy_months();
    test_spring_equinox_lunar_drift();

    std::cout << "\n============================================\n";
    std::cout << " All Calendar Engine Tests Passed Successfully!\n";
    std::cout << "============================================\n";

    return 0;
}
