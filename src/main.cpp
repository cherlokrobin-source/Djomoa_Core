#include "ChronologyEngine.h"

#include <iostream>


long long calculateSolarDaysUntilYear(int year)
{
    long long days = 0;


    for(int y = 1; y < year; y++)
    {
        bool leap;


        if(y % 400 == 0)
            leap = true;
        else if(y % 100 == 0)
            leap = false;
        else if(y % 4 == 0)
            leap = true;
        else
            leap = false;


        if(leap)
            days += 366;
        else
            days += 365;
    }


    return days;
}



int main()
{

    std::cout
    << "Golden Calendar 50000-Year Chronology Engine Core\n";

    std::cout
    << "=========================\n\n";


    ChronologyEngine engine;


    std::cout
    << "Epoch Start\n";
    std::cout
    << "-----------\n";

    engine.printDay(1);



    std::cout << "\n";


    long long day2083 =
        calculateSolarDaysUntilYear(2083) + 1;



    std::cout
    << "Year 2083 Reference\n";

    std::cout
    << "-------------------\n";


    engine.printDay(day2083);



    return 0;
}
