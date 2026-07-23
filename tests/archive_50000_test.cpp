#include <iostream>
#include "../include/ArchiveEngine.h"

int main()
{
    std::cout << "Golden Calendar 50000 Years Archive Test\n";
    std::cout << "=======================================\n\n";


    ArchiveEngine archive;


    int years[] =
    {
        1,
        2083,
        5000,
        10000,
        25000,
        50000
    };


    for (int year : years)
    {
        long long dayId = archive.getDayId(
            year,
            1,
            1
        );


        Chronology result = archive.getDay(dayId);


        std::cout
        << "Year: "
        << year
        << "\nDay ID: "
        << dayId
        << "\nSolar: "
        << result.solar.day
        << "/"
        << result.solar.month
        << "/"
        << result.solar.year
        << "\nLunar: "
        << result.lunar.day
        << "/"
        << result.lunar.month
        << "/"
        << result.lunar.year
        << "\n-----------------\n";
    }


    std::cout << "\nFinal 50000 Year Validation\n";
    std::cout << "===========================\n";


    long long finalDayId = archive.getDayId(
        50000,
        1,
        1
    );


    Chronology finalResult = archive.getDay(finalDayId);


    std::cout
    << "Day ID: "
    << finalDayId
    << "\nSolar Year: "
    << finalResult.solar.year
    << "\nLunar Year: "
    << finalResult.lunar.year
    << "\n";


    if (finalResult.solar.year == 50000)
    {
        std::cout
        << "\n50000 Years Archive Validation PASSED\n";
    }
    else
    {
        std::cout
        << "\n50000 Years Archive Validation FAILED\n";
        return 1;
    }


    return 0;
}
