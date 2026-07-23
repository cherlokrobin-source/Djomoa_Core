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
