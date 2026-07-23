#include "SolarEngine.h"
#include "LunarEngine.h"
#include <iostream>


long long lunarYearsDays(
    LunarEngine& lunar,
    int years
)
{
    long long days = 0;

    for(int y = 1; y <= years; y++)
    {
        // حساب طول السنة القمرية حسب قاعدة المحرك
        long long start =
            lunar.getDayId(y,1,1);

        long long next =
            lunar.getDayId(y+1,1,1);

        days += (next - start);
    }

    return days;
}



int main()
{

    std::cout
        << "Golden Calendar Cycle Accuracy Test\n";

    std::cout
        << "===================================\n\n";


    SolarEngine solar;
    LunarEngine lunar;



int year  = 49999;
int month = 1;
int day   = 1;



    long long dayId =
        solar.getDayId(
            year,
            month,
            day
        );


    std::cout
        << "Reference Solar Date:\n";

    std::cout
        << day << "/"
        << month << "/"
        << year
        << "\n\n";


    std::cout
        << "Day ID: "
        << dayId
        << "\n\n";



    Date lunarDate =
        lunar.getDate(dayId);



    std::cout
        << "Engine Lunar Result:\n";


    std::cout
        << lunarDate.day
        << "/"
        << lunarDate.month
        << "/"
        << lunarDate.year
        << " ";

    std::cout
        << lunarDate.monthName
        << "\n\n";




    std::cout
        << "Cycle Comparison:\n";


    // 33 سنة شمسية
    long long solar33 =
        solar.daysUntilYear(2046)
        -
        solar.daysUntilYear(2013);



    std::cout
        << "33 Solar Years Days: "
        << solar33
        << "\n";



       int cycles[] =
      {
    30,
    31,
    32,
    33,
    34
};


    for(int c : cycles)
    {

        long long lunarDays =
            lunarYearsDays(
                lunar,
                c
            );


        std::cout
            << c
            << " Lunar Years Days: "
            << lunarDays;


        std::cout
            << "  Difference from 33 Solar: "
            << (lunarDays - solar33)
            << " days\n";
    }



    std::cout
        << "\nTest completed.\n";


    return 0;
}
