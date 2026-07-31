#include "report/TemporalReportEngine.h"


TemporalReportEngine::TemporalReportEngine()
{
}


TemporalReport TemporalReportEngine::generate(long long dayId)
{
    Chronology data =
        chronology.getChronology(dayId);


    TemporalReport report;

    report.dayId =
        data.dayId;

    report.solar =
        data.solar;

    report.lunar =
        data.lunar;

    report.weekIndex =
        data.weekIndex;

    report.weekName =
        data.weekName;


    GlobalTemporalID id =
        chronology.generateGlobalID(dayId);


    report.cycleNumber =
        id.cycleNumber;

    report.cycleDay =
        id.cycleDay;

    report.historicalIndex =
        id.historicalIndex;


    return report;
}
