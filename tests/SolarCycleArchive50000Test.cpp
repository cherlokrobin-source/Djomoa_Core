#include "../Gabary/include/SolarCycleArchive.h"

#include <iostream>
#include <cassert>


using namespace Gabary;


int main()
{

    SolarCycleArchive archive;


    archive.buildCycles(
        1,
        794
    );


    long long totalDays =
        archive.size();


    std::cout
        << "Total Archived Days: "
        << totalDays
        << std::endl;


    assert(
        totalDays > 18000000
    );


    std::cout
        << "SolarCycleArchive50000Test Passed"
        << std::endl;


    return 0;
}
