#include <iostream>
#include <cassert>

#include "SolarEngine.h"

int main()
{
    std::cout << "Solar Metadata Test\n";

    SolarEngine solar;

    // بداية السنة الأولى
    Date day1 = solar.getDate(1);

    assert(day1.year == 1);
    assert(day1.month == 1);
    assert(day1.day == 1);
    assert(day1.dayOfYear == 1);
    assert(day1.leapYear == false);


    // نهاية سنة عادية
    Date endNormal = solar.getDate(
        solar.getDayId(3, 12, 31)
    );

    assert(endNormal.year == 3);
    assert(endNormal.dayOfYear == 365);
    assert(endNormal.leapYear == false);


    // سنة كبيسة
    Date leapEnd = solar.getDate(
        solar.getDayId(4, 12, 31)
    );

    assert(leapEnd.year == 4);
    assert(leapEnd.dayOfYear == 366);
    assert(leapEnd.leapYear == true);


    std::cout << "Solar Metadata Test Passed\n";

    return 0;
}
