#include "ArchiveGenerator.h"
#include <iostream>

int main()
{
    std::cout
        << "Golden Calendar 10000 Years Archive Test\n";

    std::cout
        << "========================================\n\n";


    ArchiveGenerator generator;


    generator.generateFullArchive(
        1,
        10000,
        "../data/archive_10000_years.csv"
    );


    std::cout
        << "\n10000 Years archive generation completed successfully.\n";


    return 0;
}
