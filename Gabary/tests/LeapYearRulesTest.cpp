#include "../include/LeapYearRules.h"
#include <iostream>

using namespace Gabary;

int main()
{
    std::cout << "Gabary Leap Year Rules Test\n";
    std::cout << "===========================\n\n";


    struct Test
    {
        int year;
        bool expected;
    };


    Test tests[] =
    {
        {1, false},
        {4, true},
        {100, false},
        {400, true},
        {2000, true},
        {2100, false},
        {50000, true}
    };


    for(auto &t : tests)
    {
        bool result =
            LeapYearRules::isLeapYear(t.year);


        std::cout
            << "Year "
            << t.year
            << " : "
            << (result ? "Leap" : "Normal");


        if(result == t.expected)
        {
            std::cout << " PASS\n";
        }
        else
        {
            std::cout << " FAIL\n";
            return 1;
        }
    }


    std::cout
        << "\nLeap Year Rules Validation PASSED\n";


    return 0;
}
