#include "ArchiveGenerator.h"
#include <iostream>

int main()
{
    std::cout << "Golden Calendar Archive Generator Test\n";
    std::cout << "====================================\n\n";

    ArchiveGenerator generator;

    generator.generateCSV(
        2083,
        2090,
        "../data/test_archive.csv"
    );

    return 0;
}
