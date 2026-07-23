#ifndef WEEK_ENGINE_H
#define WEEK_ENGINE_H

#include "Names.h"


class WeekEngine
{

public:


    WeekEngine()
    {
    }



    int getWeekIndex(long long day)
    {
        return static_cast<int>((day - 1) % 7);
    }



    const char* getWeekName(long long day)
    {
        return CalendarNames::WEEKDAYS[
            getWeekIndex(day)
        ].c_str();
    }

};


#endif
