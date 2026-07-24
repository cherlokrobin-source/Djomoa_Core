#ifndef GLOBAL_TEMPORAL_ID_H
#define GLOBAL_TEMPORAL_ID_H

#include <string>


struct GlobalTemporalID
{
    long long dayId;

    int solarYear;
    int solarMonth;
    int solarDay;

    int lunarYear;
    int lunarMonth;
    int lunarDay;

    int weekIndex;

    std::string era;

};


#endif
