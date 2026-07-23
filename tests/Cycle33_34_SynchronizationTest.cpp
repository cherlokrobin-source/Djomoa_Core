#include "SolarEngine.h"
#include "LunarEngine.h"
#include <iostream>


int main()
{
    std::cout
        << "Golden Calendar 99/102 Cycle Synchronization Test\n";

    std::cout
        << "================================================\n\n";


    SolarEngine solar;
    LunarEngine lunar;


    int year  = 49999;
    int month = 1;
    int day   = 1;


    long long dayId =
        solar.getDayId(
            year,
            month,
            day
        );


    std::cout
        << "Reference Solar Date: "
        << day << "/"
        << month << "/"
        << year
        << "\n";


    std::cout
        << "Day ID: "
        << dayId
        << "\n\n";


    /*
        Long Synchronization Cycle

        33 Solar Years  ≈ 34 Lunar Years

        Triple Cycle:

        99 Solar Years  ≈ 102 Lunar Years
    */


    long long solar99 =
        12053 * 3;


    long long lunar102 =
        12048 * 3;



    std::cout
        << "99 Solar Years: "
        << solar99
        << " days\n";


    std::cout
        << "102 Lunar Years: "
        << lunar102
        << " days\n";


    std::cout
        << "Difference: "
        << (lunar102 - solar99)
        << " days\n\n";


    if(
        (solar99 - lunar102) <= 20 &&
        (solar99 - lunar102) >= 0
    )
    {
        std::cout
            << "Cycle Status: PASS\n";
    }
    else
    {
        std::cout
            << "Cycle Status: REVIEW\n";
    }


    return 0;
}
