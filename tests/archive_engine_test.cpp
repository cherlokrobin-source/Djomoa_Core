#include <iostream>
#include "ArchiveEngine.h"

int main()
{
    std::cout << "Golden Calendar Archive Engine Test\n";
    std::cout << "=================================\n\n";

    ArchiveEngine archive;

    archive.printYear(2083);

    archive.printYear(5000);

    archive.printYear(10000);

    archive.printYear(50000);

    return 0;
}
