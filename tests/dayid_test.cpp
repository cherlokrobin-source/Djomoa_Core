#include <iostream>
#include "SolarEngine.h"

int main()
{
    SolarEngine solar;

    std::cout << "Golden Calendar - Solar Day ID Test\n";
    std::cout << "===================================\n\n";

    long long day1 = solar.getDayId(1, 1, 1);
    long long day2083 = solar.getDayId(2083, 1, 1);

    std::cout << "Epoch\n";
    std::cout << "-----\n";
    std::cout << "Date   : 1/1/1\n";
    std::cout << "Day ID : " << day1 << "\n\n";

    std::cout << "Reference\n";
    std::cout << "---------\n";
    std::cout << "Date   : 1/1/2083\n";
    std::cout << "Day ID : " << day2083 << "\n\n";

    Date epoch = solar.getDate(day1);
    Date ref = solar.getDate(day2083);

    std::cout << "Verification\n";
    std::cout << "------------\n";

    std::cout << "Day ID " << day1
              << " -> "
              << epoch.day << "/"
              << epoch.month << "/"
              << epoch.year << "\n";

    std::cout << "Day ID " << day2083
              << " -> "
              << ref.day << "/"
              << ref.month << "/"
              << ref.year << "\n";

    return 0;
}
