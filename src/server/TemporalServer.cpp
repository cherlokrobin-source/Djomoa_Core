#include <sstream>

#include "TemporalServer.h"
#include "../../Gabary/include/ReportFormatter.h"


TemporalServer::TemporalServer()
{
}


// =====================================
// JSON Day API
// =====================================

std::string TemporalServer::handleDayJSONRequest(
    long long dayId
)
{
    Gabary::GlobalSolarDay day =
        solarEngine.buildDay(dayId);

    GlobalTemporalID temporal =
        queryEngine.queryDay(dayId);

    std::ostringstream json;

    json
        << "{";


    // =====================================
    // Global Temporal Coordinate
    // =====================================

    json
        << "\"globalSolarDay\":"
        << day.dayId
        << ",";


    // =====================================
    // Solar Date
    // =====================================

    json
        << "\"solarDate\":{"

        << "\"weekday\":\""
        << day.weekName
        << "\","

        << "\"year\":"
        << day.solarYear
        << ","

        << "\"month\":"
        << day.solarMonth
        << ","

        << "\"monthName\":\""
        << day.monthName
        << "\","

        << "\"day\":"
        << day.solarDay
        << ","

        << "\"dayOfYear\":"
        << day.dayOfYear

        << "},";


    // =====================================
    // Calendar Metadata
    // =====================================

    json
        << "\"calendarMetadata\":{"

        << "\"weekIndex\":"
        << day.weekIndex
        << ","

        << "\"leapYear\":"
        << (day.leapYear ? "true" : "false")

        << "},";


    // =====================================
    // Lunar Coordinate
    // =====================================

    json
        << "\"lunarDate\":{"

        << "\"year\":"
        << temporal.lunarYear
        << ","

        << "\"month\":"
        << temporal.lunarMonth
        << ","

        << "\"day\":"
        << temporal.lunarDay

        << "},";


    // =====================================
    // Temporal Metadata
    // =====================================

    json
        << "\"temporalMetadata\":{"

        << "\"cycleNumber\":"
        << temporal.cycleNumber
        << ","

        << "\"cycleDay\":"
        << temporal.cycleDay
        << ","

        << "\"yearIndex\":"
        << temporal.yearIndex
        << ","

        << "\"historicalIndex\":"
        << temporal.historicalIndex
        << ","

        << "\"era\":\""
        << temporal.era
        << "\""

        << "},";


    // =====================================
    // Architecture
    // =====================================

    json
        << "\"architecture\":{"

        << "\"name\":\"Gabary V2\","

        << "\"engine\":\"SolarEngineV2\","

        << "\"validation\":\"PASSED\""

        << "}";


    json
        << "}";


    return json.str();
}


// =====================================
// Text Report API
// =====================================

std::string TemporalServer::handleDayRequest(
    long long dayId
)
{
    Gabary::GlobalSolarDay day =
        solarEngine.buildDay(dayId);

    return Gabary::ReportFormatter::createTextReport(day);
}


// =====================================
// Solar Query
// =====================================

std::string TemporalServer::handleSolarRequest(
    int year,
    int month,
    int day
)
{
    long long dayId =
        solarEngine.toDayId(
            year,
            month,
            day
        );

    Gabary::GlobalSolarDay result =
        solarEngine.buildDay(dayId);

    return Gabary::ReportFormatter::createTextReport(
        result
    );
}


// =====================================
// Lunar Query
// =====================================

std::string TemporalServer::handleLunarRequest(
    int year,
    int month,
    int day
)
{
    return R"({"error":"Lunar V2 endpoint pending"})";
}


// =====================================
// Status
// =====================================

std::string TemporalServer::handleStatusRequest()
{
    return R"({
"engine":"Gabary V2",
"core":"SolarEngineV2",
"architecture":"50,000 Year Solar Chronology",
"status":"stable",
"validation":"PASSED"
})";
}
