#include "ArchiveEngine.h"
#include <iostream>


ArchiveEngine::ArchiveEngine()
{

}


// جلب يوم بواسطة Day ID
Chronology ArchiveEngine::getDay(long long dayId)
{
    return engine.getChronology(dayId);
}


// جلب تاريخ شمسي
Chronology ArchiveEngine::getBySolar(
    int year,
    int month,
    int day
)
{
    return engine.getBySolar(
        year,
        month,
        day
    );
}


// جلب تاريخ قمري
Chronology ArchiveEngine::getByLunar(
    int year,
    int month,
    int day
)
{
    return engine.getByLunar(
        year,
        month,
        day
    );
}


// الحصول على Day ID من تاريخ شمسي
long long ArchiveEngine::getDayId(
    int year,
    int month,
    int day
)
{
    return engine.getDayId(
        year,
        month,
        day
    );
}


// طباعة بداية سنة
void ArchiveEngine::printYear(int year)
{

    Chronology result =
        engine.getBySolar(
            year,
            1,
            1
        );


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
int ArchiveEngine::daysInSolarYear(int year)
{
    return engine.getSolarEngine().daysInYear(year);
}
