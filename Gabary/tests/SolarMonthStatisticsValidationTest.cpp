#include "../include/LeapYearRules.h"

#include <array>
#include <cstdint>
#include <iostream>

using namespace Gabary;

int main()
{
    std::array<int64_t, 12> monthCount =
    {
        0,0,0,0,0,0,
        0,0,0,0,0,0
    };

    int64_t totalDays = 0;
    int64_t february28Count = 0;
    int64_t february29Count = 0;


    for(int year = 1; year <= 50000; ++year)
    {
        bool leap =
            LeapYearRules::isLeapYear(year);


        int daysInMonth[12] =
        {
            31,
            leap ? 29 : 28,
            31,
            30,
            31,
            30,
            31,
            31,
            30,
            31,
            30,
            31
        };


        for(int month = 1; month <= 12; ++month)
        {
            monthCount[month - 1]++;

            totalDays += daysInMonth[month - 1];


            if(month == 2)
            {
                if(daysInMonth[month - 1] == 29)
                    february29Count++;
                else
                    february28Count++;
            }
        }
    }


    const char* monthNames[12] =
    {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };


    std::cout
        << "\n====================================\n"
        << "  GABARY MONTH STATISTICS REPORT\n"
        << "====================================\n\n";


    for(int i = 0; i < 12; ++i)
    {
        std::cout
            << monthNames[i]
            << " : "
            << monthCount[i]
            << " occurrences\n";
    }


    std::cout
        << "\nFebruary 28 days : "
        << february28Count
        << "\n";

    std::cout
        << "February 29 days : "
        << february29Count
        << "\n";


    std::cout
        << "Total Days : "
        << totalDays
        << "\n";


    if(february28Count + february29Count != 50000)
    {
        std::cerr
            << "February statistics mismatch\n";

        return 1;
    }


    std::cout
        << "\nSolarMonthStatisticsValidationTest PASSED\n";

    return 0;
}
