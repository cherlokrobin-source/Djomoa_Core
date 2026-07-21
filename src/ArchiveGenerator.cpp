#include "ArchiveGenerator.h"
#include <fstream>
#include <iostream>


ArchiveGenerator::ArchiveGenerator()
{

}


void ArchiveGenerator::generateCSV(
    int startYear,
    int endYear,
    const std::string& filename
)
{

    std::ofstream file(filename);


    if(!file.is_open())
    {
        std::cout << "Cannot create archive file\n";
        return;
    }


    file
    << "Year,"
    << "DayID,"
    << "Solar,"
    << "Lunar,"
    << "Week\n";


    for(int year=startYear; year<=endYear; year++)
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
        << result.lunar.day
        << "/"
        << result.lunar.month
        << "/"
        << result.lunar.year
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
