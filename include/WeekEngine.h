#ifndef WEEK_ENGINE_H
#define WEEK_ENGINE_H


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
        static const char* names[7] =
        {
            "Friday",
            "Saturday",
            "Sunday",
            "Monday",
            "Tuesday",
            "Wednesday",
            "Thursday"
        };

        return names[getWeekIndex(day)];
    }
};


#endif
