#include "LunarEngineV2.h"
#include <iostream>

int main()
{
    Gabary::LunarEngineV2 lunar;

    std::cout << "49999/12/29 = "
              << lunar.getDayId(49999, 12, 29)
              << "\n";

    std::cout << "49999/12/30 = "
              << lunar.getDayId(49999, 12, 30)
              << "\n";

    std::cout << "isLeap(49999) = "
              << lunar.isLeap(49999)
              << "\n";

    auto d29 = lunar.getDate(
        lunar.getDayId(49999, 12, 29)
    );

    std::cout << "Day 17716312 = "
              << d29.day << "/"
              << d29.month << "/"
              << d29.year << "\n";

    return 0;
}
