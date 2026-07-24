#ifndef CHRONOLOGY_ENGINE_H
#define CHRONOLOGY_ENGINE_H

#include "GlobalTemporalID.h"

#include "SolarEngine.h"
#include "LunarEngine.h"
#include "Chronology.h"
#include "WeekEngine.h"


class ChronologyEngine
{

public:

    ChronologyEngine();


    // الوصول إلى المحرك الشمسي
    SolarEngine& getSolarEngine();


    // استخراج التسلسل الكامل بواسطة Day ID
    Chronology getChronology(long long day);


    // إنشاء الهوية الزمنية العالمية
    GlobalTemporalID generateGlobalID(long long day);


    // البحث بالتاريخ الشمسي
    Chronology getBySolar(
        int year,
        int month,
        int day
    );


    // البحث بالتاريخ القمري
    Chronology getByLunar(
        int year,
        int month,
        int day
    );


    // تحويل التاريخ إلى Day ID
    long long getDayId(
        int year,
        int month,
        int day
    );


    // طباعة يوم كامل
    void printDay(long long day);



private:

    SolarEngine solar;

    LunarEngine lunar;

    WeekEngine week;

};


#endif
