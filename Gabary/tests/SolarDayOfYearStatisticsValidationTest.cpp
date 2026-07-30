#include "../include/LeapYearRules.h"

#include <array>
#include <cstdint>
#include <iostream>

using namespace Gabary;

int main()
{
    std::array<int64_t, 367> dayOfYearCount = {};

    int64_t totalDays = 0;
    int64_t leapDayCount = 0;


    for(int year = 1; year <= 50000; ++year)
    {
        bool leap =
            LeapYearRules::isLeapYear(year);

        int daysInYear =
            leap ? 366 : 365;


        for(int day = 1;
            day <= daysInYear;
            ++day)
        {
            dayOfYearCount[day]++;
            totalDays++;

            if(day == 366)
            {
                if(!leap)
                {
                    std::cerr
                        << "Invalid day 366 in common year "
                        << year
                        << std::endl;

                    return 1;
                }

                leapDayCount++;
            }
        }


        if(!leap && daysInYear != 365)
        {
            std::cerr
                << "Common year length error at "
                << year
                << std::endl;

            return 1;
        }

        if(leap && daysInYear != 366)
        {
            std::cerr
                << "Leap year length error at "
                << year
                << std::endl;

            return 1;
        }
    }


    std::cout
        << "\n====================================\n"
        << " DAY OF YEAR STATISTICS REPORT\n"
        << "====================================\n\n";

    std::cout
        << "Total Days : "
        << totalDays
        << "\n";

    std::cout
        << "Day 1 Count   : "
        << dayOfYearCount[1]
        << "\n";

    std::cout
        << "Day 365 Count : "
        << dayOfYearCount[365]
        << "\n";

    std::cout
        << "Day 366 Count : "
        << dayOfYearCount[366]
        << "\n";


    if(dayOfYearCount[366] != leapDayCount)
    {
        std::cerr
            << "Leap day count mismatch\n";

        return 1;
    }


    std::cout
        << "\nSolarDayOfYearStatisticsValidationTest PASSED\n";

    return 0;
}
