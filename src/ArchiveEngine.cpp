#include "ArchiveEngine.h"
#include <iostream>


ArchiveEngine::ArchiveEngine()
{

}



Chronology ArchiveEngine::getDay(long long dayId)
{
    return engine.getChronology(dayId);
}



void ArchiveEngine::printYear(int year)
{

    Chronology result =
        engine.getBySolar(year,1,1);



    std::cout
        << "Year: "
        << year
        << "\n";


    std::cout
        << "Day ID: "
        << result.dayId
        << "\n";


    std::cout
        << "Solar: "
        << result.solar.day
        << "/"
        << result.solar.month
        << "/"
        << result.solar.year
        << "\n";


    std::cout
        << "Lunar: "
        << result.lunar.day
        << "/"
        << result.lunar.month
        << "/"
        << result.lunar.year
        << "\n";


    std::cout
        << "Week: "
        << result.weekName
        << "\n";


    std::cout
        << "-----------------\n";

}
