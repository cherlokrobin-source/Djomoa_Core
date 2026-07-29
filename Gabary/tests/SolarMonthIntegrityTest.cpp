#include "../include/SolarEngineV2.h"

#include <iostream>

using namespace Gabary;

int main()
{
    SolarEngineV2 engine;

    struct MonthTest
    {
        int year;
        int month;
    };

    MonthTest tests[] =
    {
        {1, 1},
        {1, 2},
        {4, 2},
        {100, 2},
        {400, 2},
        {2083, 6},
        {10000, 12},
        {50000, 12}
    };

    for(const auto& t : tests)
    {
        int days =
            engine.daysInMonth(
                t.year,
                t.month
            );

        if(days < 28 || days > 31)
        {
            std::cerr
                << "Invalid month length: "
                << t.year
                << "-"
                << t.month
                << std::endl;

            return 1;
        }

        int64_t startDay =
            engine.toDayId(
                t.year,
                t.month,
                1
            );

        int64_t nextMonthDay;

        if(t.month == 12)
        {
            nextMonthDay =
                engine.toDayId(
                    t.year + 1,
                    1,
                    1
                );
        }
        else
        {
            nextMonthDay =
                engine.toDayId(
                    t.year,
                    t.month + 1,
                    1
                );
        }

        if(nextMonthDay - startDay != days)
        {
            std::cerr
                << "Month boundary mismatch: "
                << t.year
                << "-"
                << t.month
                << std::endl;

            return 1;
        }

        std::cout
            << "Month "
            << t.year
            << "-"
            << t.month
            << " OK Days="
            << days
            << std::endl;
    }

    std::cout
        << "SolarMonthIntegrityTest PASSED"
        << std::endl;

    return 0;
}
