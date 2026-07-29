#include "../include/SolarEngineV2.h"

#include <iostream>
#include <vector>

using namespace Gabary;

struct TestCase
{
    int year;
    int month;
    int day;
};

int main()
{
    SolarEngineV2 engine;

    std::vector<TestCase> tests =
    {
        {1, 1, 1},
        {2083, 1, 1},
        {10000, 1, 1},
        {50000, 12, 31}
    };

    for(const auto& t : tests)
    {
        int64_t dayId =
            engine.toDayId(
                t.year,
                t.month,
                t.day
            );

        GlobalSolarDay result =
            engine.buildDay(dayId);

        if(result.solarYear != t.year)
        {
            std::cerr << "Year mismatch: "
                      << t.year << std::endl;
            return 1;
        }

        if(result.solarMonth != t.month)
        {
            std::cerr << "Month mismatch: "
                      << t.month << std::endl;
            return 1;
        }

        if(result.solarDay != t.day)
        {
            std::cerr << "Day mismatch: "
                      << t.day << std::endl;
            return 1;
        }

        std::cout
            << "OK: "
            << t.year << "-"
            << t.month << "-"
            << t.day
            << " DayID="
            << dayId
            << std::endl;
    }

    std::cout
        << "Solar50KYearBoundaryTest PASSED"
        << std::endl;

    return 0;
}
