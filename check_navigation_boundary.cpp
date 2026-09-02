#include "GabaryNavigationEngine.h"
#include <iostream>

int main()
{
    Gabary::GabaryNavigationEngine engine;

    const long long day29 =
        engine.jumpToLunarDate(49999, 12, 29);

    const long long day30 =
        engine.jumpToLunarDate(49999, 12, 30);

    std::cout << "49999/12/29 = "
              << day29 << "\n";

    std::cout << "49999/12/30 = "
              << day30 << "\n";

    if (day29 == 17716312)
        std::cout << "[PASS] 29/12/49999\n";
    else
        std::cout << "[FAIL] 29/12/49999\n";

    if (day30 == -1)
        std::cout << "[PASS] 30/12/49999 rejected\n";
    else
        std::cout << "[FAIL] 30/12/49999 returned "
                  << day30 << "\n";

    return 0;
}
