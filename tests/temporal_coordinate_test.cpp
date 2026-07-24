#include <iostream>

#include "TemporalCoordinateEngine.h"

using namespace std;


int main()
{

    cout << "Golden Calendar Temporal Coordinate Test" << endl;
    cout << "========================================" << endl;


    TemporalCoordinateEngine engine;


    long long testDays[] =
    {
        1,
        760436,
        18261760
    };


    for(long long day : testDays)
    {

        Chronology result =
            engine.getCoordinate(day);


        cout << "------------------------" << endl;

        cout << "Day ID: "
             << result.dayId
             << endl;


        cout << "Solar: "
             << result.solar.day
             << "/"
             << result.solar.month
             << "/"
             << result.solar.year
             << endl;


        cout << "Lunar: "
             << result.lunar.day
             << "/"
             << result.lunar.month
             << "/"
             << result.lunar.year
             << endl;


        cout << "Week: "
             << result.weekName
             << endl;

    }


    cout << "========================" << endl;
    cout << "Temporal Coordinate Test Completed" << endl;


    return 0;
}
