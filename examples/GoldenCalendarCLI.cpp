#include <iostream>
#include "../include/ChronologyEngine.h"

int main()
{
    std::cout << "Golden Calendar CLI\n";
    std::cout << "===================\n\n";

    ChronologyEngine engine;

    long long dayId = 760436;

    Chronology result = engine.getChronology(dayId);

    std::cout << "Day ID: "
              << result.dayId
              << "\n\n";

    std::cout << "Solar:\n";
    std::cout << result.solar.day << "/"
              << result.solar.month << "/"
              << result.solar.year << "\n\n";

    std::cout << "Lunar:\n";
    std::cout << result.lunar.day << "/"
              << result.lunar.month << "/"
              << result.lunar.year << "\n\n";

    std::cout << "Week: "
              << result.weekName
              << "\n";

    return 0;
}
