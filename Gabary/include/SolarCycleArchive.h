#ifndef GABARY_SOLAR_CYCLE_ARCHIVE_H
#define GABARY_SOLAR_CYCLE_ARCHIVE_H

#include "GlobalSolarDay.h"
#include "SolarCycle.h"

#include <vector>
#include <cstdint>

namespace Gabary
{

class SolarCycleArchive
{

private:

    std::vector<GlobalSolarDay> days;


public:

    // بناء دورة شمسية واحدة
    void buildCycle(
        int cycleId
    );


    // بناء مجموعة دورات شمسية
    void buildCycles(
        int startCycle,
        int endCycle
    );


    // عدد الأيام المخزنة
    int64_t size() const;


    // الحصول على يوم حسب الفهرس
    GlobalSolarDay getDay(
        int64_t index
    ) const;

};

}

#endif
