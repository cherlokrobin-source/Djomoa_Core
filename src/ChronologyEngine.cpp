#include "ChronologyEngine.h"


ChronologyEngine::ChronologyEngine()
{
}


// الوصول إلى SolarEngine
SolarEngine& ChronologyEngine::getSolarEngine()
{
    return solar;
}


// الحصول على التسلسل الكامل بواسطة Day ID
Chronology ChronologyEngine::getChronology(long long day)
{
    Chronology result;

    result.dayId = day;


    // التاريخ الشمسي
    result.solar =
        solar.getDate(day);


    // التاريخ القمري
    result.lunar =
        lunar.getDate(day);


    // تجميد التقويم القمري عند نهاية المجال
    if(result.lunar.year >= 50000)
    {
        result.lunar.year  = 49999;
        result.lunar.month = 12;
        result.lunar.day   = 30;
    }


    // الأسبوع
    result.weekIndex =
        week.getWeekIndex(day);

    result.weekName =
        week.getWeekName(day);


    return result;
}




// إنشاء الهوية الزمنية العالمية
GlobalTemporalID ChronologyEngine::generateGlobalID(long long day)
{
    Chronology result = getChronology(day);

    GlobalTemporalID id;


    // المعرف الأساسي
    id.dayId = result.dayId;


    // الإحداثيات الشمسية
    id.solarYear  = result.solar.year;
    id.solarMonth = result.solar.month;
    id.solarDay   = result.solar.day;


    // الإحداثيات القمرية
    id.lunarYear  = result.lunar.year;
    id.lunarMonth = result.lunar.month;
    id.lunarDay   = result.lunar.day;


    // إحداثية الأسبوع
    id.weekIndex = result.weekIndex;


    // الحقبة الزمنية
// Temporal Metadata

id.yearIndex = result.solar.year;


// دورة 33/34 سنة تقريبية
id.cycleNumber =
    (result.solar.year - 1) / 33 + 1;


// اليوم داخل الدورة
id.cycleDay =
    day % 12053;


// المؤشر التاريخي
id.historicalIndex = day;


    return id;
}





// البحث بالتاريخ الشمسي
Chronology ChronologyEngine::getBySolar(
    int year,
    int month,
    int day
)
{

    long long id =
        solar.getDayId(
            year,
            month,
            day
        );


    return getChronology(id);
}





// البحث بالتاريخ القمري
Chronology ChronologyEngine::getByLunar(
    int year,
    int month,
    int day
)
{

    long long id =
        lunar.getDayId(
            year,
            month,
            day
        );


    return getChronology(id);
}





// تحويل التاريخ الشمسي إلى Day ID
long long ChronologyEngine::getDayId(
    int year,
    int month,
    int day
)
{

    return solar.getDayId(
        year,
        month,
        day
    );
}
