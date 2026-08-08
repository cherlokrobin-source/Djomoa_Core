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


    // ============================================
    // English Weekday Name
    // ============================================

    static const char* ENGLISH_WEEKDAYS[7] =
    {
        "Friday",
        "Saturday",
        "Sunday",
        "Monday",
        "Tuesday",
        "Wednesday",
        "Thursday"
    };

    report.weekName =
        ENGLISH_WEEKDAYS[data.weekIndex];


    // ============================================
    // Temporal Metadata
    // ============================================

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
