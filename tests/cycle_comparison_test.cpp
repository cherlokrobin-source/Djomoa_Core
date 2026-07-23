#include <iostream>

struct LunarDate
{
    int year;
    int month;
    int day;
};


bool isLeap30(int year)
{
    return ((year * 11) % 30) < 11;
}


bool isLeap33(int year)
{
    return ((year * 11) % 33) < 11;
}


LunarDate calculateLunar(long long totalDays)
{
    LunarDate date;

    date.year = 1;

    while(true)
    {
        int days = isLeap30(date.year) ? 355 : 354;

        if(totalDays < days)
            break;

        totalDays -= days;
        date.year++;
    }


    int months[] =
    {
        30,29,30,29,30,29,
        30,29,30,29,30,29
    };


    date.month = 1;

    while(totalDays >= months[date.month-1])
    {
        totalDays -= months[date.month-1];
        date.month++;
    }


    date.day = totalDays + 1;

    return date;
}


long long lunarCycle30(int years)
{
    return (long long)years * 354 +
           (years * 11) / 30;
}


long long lunarCycle33(int years)
{
    return (long long)years * 354 +
           (years * 11) / 33;
}


void printDate(LunarDate d)
{
    std::cout
    << d.day << "/"
    << d.month << "/"
    << d.year << "\n";
}


int main()
{
    int years = 2083;

    std::cout
    << "Golden Calendar Final Lunar Comparison\n";

    std::cout
    << "=====================================\n\n";


    LunarDate d30 =
        calculateLunar(lunarCycle30(years));

    LunarDate d33 =
        calculateLunar(lunarCycle33(years));


    std::cout
    << "After "
    << years
    << " Solar Years:\n\n";


    std::cout
    << "30 Year Cycle Lunar Date:\n";

    printDate(d30);


    std::cout
    << "\n33 Year Cycle Lunar Date:\n";

    printDate(d33);


    return 0;
}
