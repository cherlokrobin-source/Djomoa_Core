#include <iostream>
#include "TimeEngine.h"

int main()
{
    TimeEngine engine;

    Chronology c = engine.getByDayId(760436);

    std::cout << "Golden Calendar TimeEngine Test\n";
    std::cout << "==============================\n\n";

    std::cout << "Day ID: "
              << c.dayId << "\n\n";

    std::cout << "Solar: "
              << c.solar.day << "/"
              << c.solar.month << "/"
              << c.solar.year << "\n\n";

    std::cout << "Lunar: "
              << c.lunar.day << "/"
              << c.lunar.month << "/"
              << c.lunar.year << "\n";

    return 0;
}
