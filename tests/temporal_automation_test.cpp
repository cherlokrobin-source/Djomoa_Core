#include <iostream>
#include <cassert>

#include "automation/TemporalAutomationEngine.h"

int main()
{
    std::cout << "Temporal Automation Test\n";

    // اختبار بواسطة GlobalSolarDay
    Chronology day =
        TemporalAutomationEngine::Generate(1000);

    assert(day.dayId == 1000);

    // اختبار بواسطة التاريخ الشمسي
    Chronology solar =
        TemporalAutomationEngine::FromSolar(
            day.solar.year,
            day.solar.month,
            day.solar.day
        );

    assert(solar.dayId == day.dayId);


    // اختبار بواسطة التاريخ القمري
    Chronology lunar =
        TemporalAutomationEngine::FromLunar(
            day.lunar.year,
            day.lunar.month,
            day.lunar.day
        );

    assert(lunar.dayId == day.dayId);


    std::cout << "Temporal Automation Test Passed\n";

    return 0;
}
