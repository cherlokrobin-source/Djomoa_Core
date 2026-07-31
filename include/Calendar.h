#ifndef CALENDAR_H
#define CALENDAR_H

#include <string>

struct Date
{
    long long dayId;

    int year;
    int month;
    int day;

    // معلومات إضافية
    int dayOfYear;
    bool leapYear;

    std::string monthName;
    std::string weekday;
};

struct Chronology
{
    long long dayId;

    Date solar;
    Date lunar;

    int weekIndex;
    const char* weekName;
};

#endif
