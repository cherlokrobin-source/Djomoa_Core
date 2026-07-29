#include "../include/SolarEngineV2.h"

#include <iostream>
#include <vector>

using namespace Gabary;

struct YearCase
{
    int year;
    bool expectedLeap;
};

int main()
{
    SolarEngineV2 engine;

    const std::vector<YearCase> tests =
    {
        {1, false},
        {4, true},
        {100, false},
        {400, true},
        {800, true},
        {1200, true},
        {1600, true},
        {1900, false},
        {2000, true},
        {2083, false},
        {10000, true},
        {20000, true},
        {30000, true},
        {40000, true},
        {49996, true},
        {50000, true}
    };

    for(const auto& t : tests)
    {
        const int days =
            engine.daysInYear(t.year);

        const bool actualLeap =
            (days == 366);

        if(actualLeap != t.expectedLeap)
        {
            std::cerr
                << "Leap-year mismatch at Year "
                << t.year
                << ": expected "
                << (t.expectedLeap ? "leap" : "normal")
                << ", got "
                << (actualLeap ? "leap" : "normal")
                << std::endl;

            return 1;
        }

        if(t.expectedLeap && days != 366)
        {
            std::cerr
                << "Leap year does not contain 366 days: "
                << t.year
                << std::endl;

            return 1;
        }

        if(!t.expectedLeap && days != 365)
        {
            std::cerr
                << "Normal year does not contain 365 days: "
                << t.year
                << std::endl;

            return 1;
        }

        const int64_t firstDayId =
            engine.toDayId(t.year, 1, 1);

        const int64_t lastDayId =
            engine.toDayId(t.year, 12, 31);

        if(lastDayId - firstDayId + 1 != days)
        {
            std::cerr
                << "Day ID year-length mismatch at Year "
                << t.year
                << std::endl;

            return 1;
        }

        const SolarDate lastDate =
            engine.fromDayId(lastDayId);

        if(lastDate.year != t.year ||
           lastDate.month != 12 ||
           lastDate.day != 31)
        {
            std::cerr
                << "Year-end round-trip failure at Year "
                << t.year
                << std::endl;

            return 1;
        }
    }

    std::cout
        << "SolarLeapYearConsistencyTest PASSED"
        << std::endl;

    return 0;
}
