#include "../include/WeekCycleEngine.h"
#include <iostream>

using namespace Gabary;

int main()
{
    std::cout << "Gabary Week Cycle Test\n";
    std::cout << "======================\n\n";


    struct TestDay
    {
        long long id;
        std::string expected;
    };


    TestDay tests[] =
    {
        {1, "Friday"},
        {2, "Saturday"},
        {3, "Sunday"},
        {4, "Monday"},
        {5, "Tuesday"},
        {6, "Wednesday"},
        {7, "Thursday"},
        {8, "Friday"},
        {100, "Saturday"},
        {1000, "Wednesday"}
    };


    for(auto &test : tests)
    {
        std::string result =
            WeekCycleEngine::weekdayName(test.id);


        std::cout
            << "Day ID: "
            << test.id
            << " -> "
            << result;


        if(result == test.expected)
        {
            std::cout << "  PASS\n";
        }
        else
        {
            std::cout
                << "  FAIL (Expected "
                << test.expected
                << ")\n";

            return 1;
        }
    }


    std::cout
        << "\nWeek Cycle Engine Validation PASSED\n";


    return 0;
}
