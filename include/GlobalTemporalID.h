#ifndef GLOBAL_TEMPORAL_ID_H
#define GLOBAL_TEMPORAL_ID_H

#include <string>


struct GlobalTemporalID
{
    long long dayId;


    // Solar Coordinate
    int solarYear;
    int solarMonth;
    int solarDay;


    // Lunar Coordinate
    int lunarYear;
    int lunarMonth;
    int lunarDay;


    // Week Coordinate
    int weekIndex;


    // Temporal Metadata

    int cycleNumber;

    int cycleDay;

    int yearIndex;


    long long historicalIndex;


    // Epoch
    std::string era;

};


#endif
