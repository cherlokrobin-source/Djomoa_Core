#include "SolarEngine.h"
#include "LunarEngine.h"
#include <iostream>


void testCycle(
    int solarYears,
    int lunarYears,
    long long solarDays,
    long long lunarDays
)
{
    long long difference = lunarDays - solarDays;

    std::cout
        << solarYears
        << " Solar Years / "
        << lunarYears
        << " Lunar Years\n";

    std::cout
        << "Solar Days: "
        << solarDays
        << "\n";

    std::cout
        << "Lunar Days: "
        << lunarDays
        << "\n";

    std::cout
        << "Difference: "
        << difference
        << " days\n";


    if(
        difference <= 0 &&
        difference >= -20
    )
    {
        std::cout
            << "Status: PASS\n\n";
    }
    else
    {
        std::cout
            << "Status: REVIEW\n\n";
    }
}


int main()
{
    std::cout
        << "Golden Calendar Long Cycle Synchronization Test\n";

    std::cout
        << "===============================================\n\n";


    std::cout
        << "Reference Model:\n";
    std::cout
        << "33 Solar Years ≈ 34 Lunar Years\n\n";


    testCycle(
        33,
        34,
        12053,
        12048
    );


    testCycle(
        66,
        68,
        24106,
        24096
    );


    testCycle(
        99,
        102,
        36159,
        36144
    );


    return 0;
}
