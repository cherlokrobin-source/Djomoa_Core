#ifndef TEMPORAL_API_H
#define TEMPORAL_API_H

#include <string>

#include "../TemporalQueryEngine.h"
#include "../../Gabary/include/SolarEngineV2.h"
class TemporalAPI
{
public:

    TemporalAPI();

    // البحث بواسطة رقم اليوم العالمي
    std::string getDayAsJSON(long long dayId);

    // البحث بواسطة التاريخ الشمسي
    std::string getSolarAsJSON(
        int year,
        int month,
        int day
    );

    // البحث بواسطة التاريخ القمري
    std::string getLunarAsJSON(
        int year,
        int month,
        int day
    );

    // ===============================
    // Temporal API v1.1
    // ===============================

    // معلومات المحرك والإصدار
    std::string getStatusJSON();

private:

    TemporalQueryEngine query;
    Gabary::SolarEngineV2 solarEngine;
};

#endif
