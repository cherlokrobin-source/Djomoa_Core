#include "ChronologyEngine.h"
#include <iostream>


long long lunarCycle30(int years)
{
    long long cycles = years / 30;
    int rest = years % 30;

    long long days = cycles * 10631;

    // متوسط تقريبي للسنوات المتبقية
    days += rest * 354;

    return days;
}


long long lunarCycle33(int years)
{
    long long cycles = years / 33;
    int rest = years % 33;

    long long days = cycles * 11693;

    days += rest * 354;

    return days;
}


int main()
{
    std::cout
    << "Golden Calendar Full Cycle Comparison\n"
    << "====================================\n\n";


    ChronologyEngine engine;


    Chronology ref =
        engine.getBySolar(2083,4,3);


    int years = 2083;


    std::cout
    << "Reference:\n"
    << "Day ID: "
    << ref.dayId
    << "\n";


    std::cout
    << "Solar: "
    << ref.solar.day << "/"
    << ref.solar.month << "/"
    << ref.solar.year
    << "\n";


    std::cout
    << "Engine Lunar: "
    << ref.lunar.day << "/"
    << ref.lunar.month << "/"
    << ref.lunar.year
    << "\n\n";


    long long c30 = lunarCycle30(years);
    long long c33 = lunarCycle33(years);


    std::cout
    << "30 Year Model Days: "
    << c30
    << "\n";


    std::cout
    << "33 Year Model Days: "
    << c33
    << "\n";


    std::cout
    << "30/33 Difference: "
    << c33-c30
    << " days\n";


    std::cout
    << "\nSolar Reference Days: "
    << ref.dayId
    << "\n";


    std::cout
    << "30 Drift: "
    << ref.dayId-c30
    << " days\n";


    std::cout
    << "33 Drift: "
    << ref.dayId-c33
    << " days\n";


    return 0;
}
