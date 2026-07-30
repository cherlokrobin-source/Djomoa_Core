#include "../include/SolarEngineV2.h"
#include "../include/LeapYearRules.h"

#include <cstdint>
#include <iostream>

using namespace Gabary;

int main()
{
    SolarEngineV2 engine;

    int64_t totalDays = 0;
    int64_t leapYears = 0;
    int64_t commonYears = 0;


    for(int year = 1; year <= 50000; ++year)
    {
        if(LeapYearRules::isLeapYear(year))
            leapYears++;
        else
            commonYears++;

        totalDays +=
            LeapYearRules::isLeapYear(year)
            ? 366
            : 365;
    }


    SolarDate first =
        engine.fromDayId(1);


    SolarDate last =
        engine.fromDayId(totalDays);


    std::cout
        << "\n====================================\n"
        << " GABARY 50000 YEAR CHRONOLOGY REPORT\n"
        << "====================================\n\n";


    std::cout
        << "Years       : 50000\n"
        << "Total Days  : "
        << totalDays
        << "\n"
        << "Leap Years  : "
        << leapYears
        << "\n"
        << "Common Years: "
        << commonYears
        << "\n\n";


    std::cout
        << "First Day\n"
        << "---------\n"
        << first.year << "-"
        << first.month << "-"
        << first.day
        << "\n\n";


    std::cout
        << "Last Day\n"
        << "--------\n"
        << last.year << "-"
        << last.month << "-"
        << last.day
        << "\n";


    if(first.year != 1 ||
       first.month != 1 ||
       first.day != 1)
    {
        std::cerr
            << "First day mismatch\n";

        return 1;
    }


    if(last.year != 50000)
    {
        std::cerr
            << "Endpoint year mismatch\n";

        return 1;
    }


    if(leapYears + commonYears != 50000)
    {
        std::cerr
            << "Year total mismatch\n";

        return 1;
    }


    if(totalDays <= 0)
    {
        std::cerr
            << "Invalid total days\n";

        return 1;
    }


    std::cout
        << "\nSolar50KChronologyReportTest PASSED\n";

    return 0;
}
