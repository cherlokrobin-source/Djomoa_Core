#include "../include/SolarEngineV2.h"

#include <iostream>
#include <vector>

using namespace Gabary;

struct YearCase
{
    int year;
    int expectedDays;
};

int main()
{
    SolarEngineV2 engine;

    const std::vector<YearCase> tests =
    {
        {1, 365},
        {4, 366},
        {100, 365},
        {400, 366},
        {1900, 365},
        {2000, 366},
        {2001, 365},
        {2400, 366},
        {10000, 366},
        {49999, 365},
        {50000, 366}
    };

    for(const auto& test : tests)
    {
        int totalDays = 0;

        for(int month = 1; month <= 12; ++month)
        {
            const int days =
                engine.daysInMonth(test.year, month);

            if(days < 28 || days > 31)
            {
                std::cerr
                    << "Invalid month length at Year "
                    << test.year
                    << ", Month "
                    << month
                    << ": "
                    << days
                    << std::endl;

                return 1;
            }

            totalDays += days;
        }

        if(totalDays != test.expectedDays)
        {
            std::cerr
                << "Year/month sum mismatch at Year "
                << test.year
                << ": expected "
                << test.expectedDays
                << ", got "
                << totalDays
                << std::endl;

            return 1;
        }

        if(engine.daysInYear(test.year) != totalDays)
        {
            std::cerr
                << "daysInYear mismatch at Year "
                << test.year
                << std::endl;

            return 1;
        }
    }

    std::cout
        << "SolarMonthYearSumIntegrityTest PASSED"
        << std::endl;

    return 0;
}
