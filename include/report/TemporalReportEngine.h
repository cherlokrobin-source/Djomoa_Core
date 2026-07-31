#ifndef TEMPORAL_REPORT_ENGINE_H
#define TEMPORAL_REPORT_ENGINE_H

#include "TemporalReport.h"
#include "ChronologyEngine.h"

class TemporalReportEngine
{
public:

    TemporalReportEngine();

    TemporalReport generate(long long dayId);

private:

    ChronologyEngine chronology;
};

#endif
