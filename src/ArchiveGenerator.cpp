#include "ArchiveGenerator.h"

#include <fstream>
#include <iostream>


ArchiveGenerator::ArchiveGenerator()
{

}


//
// توليد رؤوس السنوات
//
void ArchiveGenerator::generateCSV(
    int startYear,
    int endYear,
    const std::string& filename
)
{
    std::ofstream file(filename);


    if(!file.is_open())
    {
        std::cout
            << "Cannot create archive file\n";
        return;
    }


    file
        << "Year,"
        << "DayID,"
        << "Solar,"
        << "SolarMonth,"
        << "Lunar,"
        << "LunarMonth,"
        << "Week\n";


    for(int year = startYear; year <= endYear; year++)
    {

        Chronology result =
            archive.getBySolar(
                year,
                1,
                1
            );


        file
            << year
            << ","
            << result.dayId
            << ","
            << result.solar.day
            << "/"
            << result.solar.month
            << "/"
            << result.solar.year
            << ","
            << result.solar.monthName
            << ","
            << result.lunar.day
            << "/"
            << result.lunar.month
            << "/"
            << result.lunar.year
            << ","
            << result.lunar.monthName
            << ","
            << result.weekName
            << "\n";
    }


    file.close();


    std::cout
        << "Archive generated: "
        << filename
        << "\n";
}





//
// توليد سنة كاملة بكل أيامها
//
void ArchiveGenerator::generateYear(
    int year,
    std::ofstream& file
)
{

    long long firstDay =
        archive.getDayId(
            year,
            1,
            1
        );


    int totalDays =
        archive.daysInSolarYear(
            year
        );


    for(int i = 0; i < totalDays; i++)
    {

        long long dayId =
            firstDay + i;


        Chronology result =
            archive.getDay(
                dayId
            );


        file
            << result.dayId
            << ","

            << result.solar.day
            << "/"
            << result.solar.month
            << "/"
            << result.solar.year
            << ","
            << result.solar.monthName
            << ","

            << result.lunar.day
            << "/"
            << result.lunar.month
            << "/"
            << result.lunar.year
            << ","
            << result.lunar.monthName
            << ","

            << result.weekName
            << "\n";

    }

}





//
// توليد أرشيف كامل
//
void ArchiveGenerator::generateFullArchive(
    int startYear,
    int endYear,
    const std::string& filename
)
{

    std::ofstream file(filename);


    if(!file.is_open())
    {
        std::cout
            << "Cannot create archive file\n";
        return;
    }


    file
        << "DayID,"
        << "Solar,"
        << "SolarMonth,"
        << "Lunar,"
        << "LunarMonth,"
        << "Week\n";



    long long totalYears =
        endYear - startYear + 1;



    for(int year = startYear; year <= endYear; year++)
    {

        generateYear(
            year,
            file
        );


        if((year - startYear) % 100 == 0)
        {

            double progress =
                ((double)(year - startYear)
                / totalYears) * 100.0;


            std::cout
                << "Progress: "
                << progress
                << "%  Year: "
                << year
                << "\n";
        }

    }


    file.close();


    std::cout
        << "Full archive generated: "
        << filename
        << "\n";
}
