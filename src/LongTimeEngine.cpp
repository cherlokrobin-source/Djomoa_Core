#include "LongTimeEngine.h"


LongTimeEngine::LongTimeEngine()
{
}


// بداية السنة الشمسية
Chronology LongTimeEngine::getYearStart(int year)
{
    return engine.getBySolar(
        year,
        1,
        1
    );
}


// تاريخ كامل
Chronology LongTimeEngine::getDate(
    int year,
    int month,
    int day
)
{
    return engine.getBySolar(
        year,
        month,
        day
    );
}
