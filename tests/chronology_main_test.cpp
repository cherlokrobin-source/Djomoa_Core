#include "ChronologyEngine.h"
#include <iostream>

int main()
{
    std::cout << "Golden Calendar Chronology Test\n";
    std::cout << "==============================\n\n";

    ChronologyEngine engine;

    long long day = 760436;

    Chronology c = engine.getChronology(day);

    std::cout << "Solar Input\n";
    std::cout << "-----------\n";

    std::cout << "Day ID: "
              << c.dayId
              << "\n";

    std::cout << "Solar: "
              << c.solar.day << "/"
              << c.solar.month << "/"
              << c.solar.year
              << "\n";

    std::cout << "Lunar: "
              << c.lunar.day << "/"
              << c.lunar.month << "/"
              << c.lunar.year
              << "\n";

    std::cout << "Week: "
              << c.weekName
              << "\n\n";


    std::cout << "Lunar Input\n";
    std::cout << "-----------\n";

    std::cout << "Day ID: "
              << c.dayId
              << "\n";

    std::cout << "Solar: "
              << c.solar.day << "/"
              << c.solar.month << "/"
              << c.solar.year
              << "\n";

    std::cout << "Lunar: "
              << c.lunar.day << "/"
              << c.lunar.month << "/"
              << c.lunar.year
              << "\n";

    std::cout << "Week: "
              << c.weekName
              << "\n";


    return 0;
}
