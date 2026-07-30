#include "../include/SolarEngineV2.h"
#include "../include/LeapYearRules.h"

#include <array>
#include <cstdint>
#include <iostream>

using namespace Gabary;

int main()
{
    SolarEngineV2 engine;

    std::array<int64_t, 7> weekdayCount = {0,0,0,0,0,0,0};

    int64_t dayId = 1;

    int64_t totalDays = 0;
    int64_t leapYears = 0;
    int64_t commonYears = 0;


    for(int year = 1; year <= 50000; ++year)
    {
        const bool leap =
            LeapYearRules::isLeapYear(year);

        if(leap)
            leapYears++;
        else
            commonYears++;


        int monthsDays[12] =
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
            for(int day = 1;
                day <= monthsDays[month-1];
                ++day)
            {

                int weekIndex =
                    WeekCycleEngine::weekdayIndex(dayId);


                if(weekIndex < 0 ||
                   weekIndex > 6)
                {
                    std::cerr
                        << "Invalid weekday index at DayID "
                        << dayId
                        << std::endl;

                    return 1;
                }


                weekdayCount[weekIndex]++;

                dayId++;
                totalDays++;
            }
        }
    }


    const char* weekdayNames[7] =
    {
        "Friday",
        "Saturday",
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday"
    };


    std::cout
        << "\n====================================\n"
        << "   GABARY SOLAR STATISTICS REPORT\n"
        << "====================================\n\n";


    std::cout
        << "Total Days : "
        << totalDays
        << "\n";

    std::cout
        << "Leap Years : "
        << leapYears
        << "\n";

    std::cout
        << "Common Years : "
        << commonYears
        << "\n\n";


    std::cout
        << "Weekday Distribution\n"
        << "--------------------\n";


    int64_t weekdayTotal = 0;

    for(int i = 0; i < 7; ++i)
    {
        std::cout
            << weekdayNames[i]
            << " : "
            << weekdayCount[i]
            << "\n";

        weekdayTotal += weekdayCount[i];
    }


    std::cout
        << "\nValidation\n"
        << "----------\n";


    if(weekdayTotal != totalDays)
    {
        std::cerr
            << "Weekday total mismatch\n";

        return 1;
    }


    if(leapYears + commonYears != 50000)
    {
        std::cerr
            << "Year count mismatch\n";

        return 1;
    }


    std::cout
        << "SolarStatisticsValidationTest PASSED\n"
        << std::endl;


    return 0;
}
