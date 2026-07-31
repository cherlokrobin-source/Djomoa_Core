#ifndef TEMPORAL_REPORT_JSON_H
#define TEMPORAL_REPORT_JSON_H

#include "TemporalReport.h"
#include <string>

class TemporalReportJSON
{
public:

    static std::string toJSON(
        const TemporalReport& report
    );

};

#endif
