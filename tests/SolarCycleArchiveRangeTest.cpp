#include "../Gabary/include/SolarCycleArchive.h"
#include <iostream>
#include <cassert>

using namespace Gabary;

int main()
{
    SolarCycleArchive archive;


    // اختبار الدورة الأولى (63 سنة)
    archive.buildCycle(1);


    // يجب أن يحتوي الأرشيف على أيام
    assert(archive.size() > 0);


    std::cout
        << "Cycle 1 days: "
        << archive.size()
        << "\n";


    // أول يوم
    auto firstDay = archive.getDay(0);

    assert(firstDay.dayId == 1);


    // اختبار دورة ثانية
    archive.buildCycle(2);


    assert(archive.size() > 0);


    std::cout
        << "Cycle 2 days: "
        << archive.size()
        << "\n";


    std::cout
        << "SolarCycleArchiveRangeTest Passed\n";


    return 0;
}
