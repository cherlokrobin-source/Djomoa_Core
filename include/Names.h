#ifndef NAMES_H
#define NAMES_H

#include <string>


namespace CalendarNames
{

// بداية الحقبة: الجمعة 1 يناير سنة 1
static const std::string WEEKDAYS[7] =
{
    "الجمعة",
    "السبت",
    "الأحد",
    "الإثنين",
    "الثلاثاء",
    "الأربعاء",
    "الخميس"
};


static const std::string SOLAR_MONTHS[12] =
{
    "يناير",
    "فبراير",
    "مارس",
    "أبريل",
    "مايو",
    "يونيو",
    "يوليو",
    "أغسطس",
    "سبتمبر",
    "أكتوبر",
    "نوفمبر",
    "ديسمبر"
};


static const std::string LUNAR_MONTHS[12] =
{
    "محرم",
    "صفر",
    "ربيع الأول",
    "ربيع الآخر",
    "جمادى الأولى",
    "جمادى الآخرة",
    "رجب",
    "شعبان",
    "رمضان",
    "شوال",
    "ذو القعدة",
    "ذو الحجة"
};


inline std::string getWeekday(long long day)
{
    int index = (day - 1) % 7;

    return WEEKDAYS[index];
}


}

#endif
