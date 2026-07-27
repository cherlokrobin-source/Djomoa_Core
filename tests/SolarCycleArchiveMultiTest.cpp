#include "../Gabary/include/SolarCycleArchive.h"

#include <iostream>
#include <cassert>


using namespace Gabary;


int main()
{

    SolarCycleArchive archive;


    // بناء أول ثلاث دورات
    archive.buildCycles(
        1,
        3
    );


    // يجب أن يحتوي الأرشيف على أيام
    assert(
        archive.size() > 0
    );


    std::cout
        << "Archived days: "
        << archive.size()
        << std::endl;


    // فحص أول يوم
    GlobalSolarDay first =
        archive.getDay(0);


    // فحص آخر يوم
    GlobalSolarDay last =
        archive.getDay(
            archive.size() - 1
        );


    std::cout
        << "First day ID: "
        << first.dayId
        << std::endl;


    std::cout
        << "Last day ID: "
        << last.dayId
        << std::endl;


    std::cout
        << "SolarCycleArchiveMultiTest Passed"
        << std::endl;


    return 0;
}
