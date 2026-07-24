#ifndef TEMPORAL_QUERY_ENGINE_H
#define TEMPORAL_QUERY_ENGINE_H

#include "ChronologyEngine.h"

class TemporalQueryEngine
{
private:

    ChronologyEngine chronology;

public:

    TemporalQueryEngine();

    GlobalTemporalID queryDay(long long dayId);

    GlobalTemporalID querySolar(
        int year,
        int month,
        int day
    );

    GlobalTemporalID queryLunar(
        int year,
        int month,
        int day
    );
};

#endif
