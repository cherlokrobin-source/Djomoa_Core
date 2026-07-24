#ifndef TEMPORAL_COORDINATE_ENGINE_H
#define TEMPORAL_COORDINATE_ENGINE_H

#include "ChronologyEngine.h"

class TemporalCoordinateEngine
{

private:

    ChronologyEngine chronology;


public:

    TemporalCoordinateEngine();


    Chronology getCoordinate(long long dayId);


    Chronology getCoordinateBySolar(
        int year,
        int month,
        int day
    );


    Chronology getCoordinateByLunar(
        int year,
        int month,
        int day
    );

};

#endif
