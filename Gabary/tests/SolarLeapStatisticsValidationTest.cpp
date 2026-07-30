#include "../include/LeapYearRules.h"

#include <cstdint>
#include <iostream>

using namespace Gabary;

int main()
{
    int64_t leapYears = 0;
    int64_t commonYears = 0;


    for(int year = 1; year <= 50000; ++year)
    {
        bool leap =
            LeapYearRules::isLeapYear(year);


        if(leap)
            leapYears++;
        else
            commonYears++;


        // Validation of Gregorian-style leap rules
        if(year % 400 == 0)
        {
            if(!leap)
            {
                std::cerr
                    << "400-year rule failure at "
                    << year
                    << std::endl;

                return 1;
            }
        }
        else if(year % 100 == 0)
        {
            if(leap)
            {
                std::cerr
                    << "100-year rule failure at "
                    << year
                    << std::endl;

                return 1;
            }
        }
        else if(year % 4 == 0)
        {
            if(!leap)
            {
                std::cerr
                    << "4-year rule failure at "
                    << year
                    << std::endl;

                return 1;
            }
        }
        else
        {
            if(leap)
            {
                std::cerr
                    << "Unexpected leap year at "
                    << year
                    << std::endl;

                return 1;
            }
        }
    }


    std::cout
        << "\n====================================\n"
        << " GABARY LEAP STATISTICS REPORT\n"
        << "====================================\n\n";


    std::cout
        << "Total Years  : 50000\n"
        << "Leap Years   : "
        << leapYears
        << "\n"
        << "Common Years : "
        << commonYears
        << "\n";


    if(leapYears + commonYears != 50000)
    {
        std::cerr
            << "\nYear count mismatch\n";

        return 1;
    }


    std::cout
        << "\nSolarLeapStatisticsValidationTest PASSED\n"
        << std::endl;


    return 0;
}
