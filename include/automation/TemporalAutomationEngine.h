#ifndef TEMPORAL_AUTOMATION_ENGINE_H
#define TEMPORAL_AUTOMATION_ENGINE_H

#include "Chronology.h"

class TemporalAutomationEngine
{
public:

    static Chronology Generate(long long dayId);

    static Chronology FromSolar(
        int year,
        int month,
        int day
    );

    static Chronology FromLunar(
        int year,
        int month,
        int day
    );

};

#endif
