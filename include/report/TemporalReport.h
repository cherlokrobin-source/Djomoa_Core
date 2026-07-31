#ifndef TEMPORAL_REPORT_H
#define TEMPORAL_REPORT_H

#include "Calendar.h"
#include <string>

struct TemporalReport
{
    long long dayId;

    Date solar;
    Date lunar;

    int weekIndex;
    std::string weekName;

    int cycleNumber;
    long long cycleDay;

    long long historicalIndex;
};

#endif
