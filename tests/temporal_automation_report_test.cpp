#include <iostream>
#include "automation/TemporalAutomationEngine.h"

int main()
{
    long long dayId = 739823;

    auto result =
        TemporalAutomationEngine::Generate(dayId);

    std::cout << "Temporal Automation Report\n";
    std::cout << "=========================\n";

    std::cout << "Day ID: "
              << result.dayId
              << "\n";

    std::cout << "Solar Year: "
              << result.solar.year
              << "\n";

    std::cout << "Solar Month: "
              << result.solar.month
              << "\n";

    std::cout << "Solar Day: "
              << result.solar.day
              << "\n";

    std::cout << "Weekday: "
              << result.weekName
              << "\n";

    return 0;
}
