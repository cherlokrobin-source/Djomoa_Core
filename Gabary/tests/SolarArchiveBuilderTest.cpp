#include "../include/SolarArchiveBuilder.h"
#include <iostream>

using namespace Gabary;

int main()
{

    SolarArchiveBuilder builder;


    builder.build(
        1,
        10
    );


    auto& archive =
        builder.getArchive();


    if(archive.size() == 0)
    {
        std::cerr
        << "Archive build failed\n";

        return 1;
    }


    std::cout
    << "SolarArchiveBuilder OK\n";

    std::cout
    << "Days: "
    << archive.size()
    << "\n";


    return 0;
}
