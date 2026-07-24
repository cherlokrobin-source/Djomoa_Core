#ifndef TEMPORAL_API_H
#define TEMPORAL_API_H

#include <string>

#include "../TemporalQueryEngine.h"

class TemporalAPI
{
public:

    TemporalAPI();

    std::string getDayAsJSON(long long dayId);

    std::string getSolarAsJSON(
        int year,
        int month,
        int day
    );

    std::string getLunarAsJSON(
        int year,
        int month,
        int day
    );

private:

    TemporalQueryEngine query;
};

#endif
