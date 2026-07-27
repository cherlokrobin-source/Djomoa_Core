#include "../include/SolarCycleArchive.h"
#include <iostream>

using namespace Gabary;

int main()
{

    SolarCycleArchive archive;


    archive.buildCycle(1);


    std::cout
    << "Days: "
    << archive.size()
    << "\n";


    if(
        archive.size() > 22900 &&
        archive.size() < 23000
      )
    {
        std::cout<<"PASS\n";
        return 0;
    }


    std::cout<<"FAIL\n";

    return 1;
}
