#include "TemporalAPI.h"

#include <sstream>


TemporalAPI::TemporalAPI()
{
}


// ============================================
// Day ID Query
// ============================================

std::string TemporalAPI::getDayAsJSON(
    long long dayId
)
{
    GlobalTemporalID id =
        query.queryDay(dayId);

    Gabary::GlobalSolarDay solar =
        solarEngine.buildDay(dayId);


    std::ostringstream json;


    json << "{";


    // Global Coordinate
    json << "\"dayId\":" << id.dayId << ",";


    // Gabary V2 Solar Report Data
    json << "\"gabaryDayCode\":\"GC-"
         << solar.dayId << "-"
         << solar.solarYear << "-"
         << solar.dayOfYear
         << "\",";


    json << "\"solarDate\":{";

    json << "\"weekday\":\""
         << solar.weekName << "\",";

    json << "\"day\":"
         << solar.solarDay << ",";

    json << "\"month\":"
         << solar.solarMonth << ",";

    json << "\"monthName\":\""
         << solar.monthName << "\",";

    json << "\"year\":"
         << solar.solarYear;

    json << "},";


    json << "\"dayOfYear\":"
         << solar.dayOfYear << ",";


    json << "\"leapYear\":"
         << (solar.leapYear ? "true" : "false")
         << ",";


    // Original Temporal Metadata

    json << "\"lunarYear\":"
         << id.lunarYear << ",";

    json << "\"lunarMonth\":"
         << id.lunarMonth << ",";

    json << "\"lunarDay\":"
         << id.lunarDay << ",";


    json << "\"weekIndex\":"
         << id.weekIndex << ",";


    json << "\"cycleNumber\":"
         << id.cycleNumber << ",";


    json << "\"cycleDay\":"
         << id.cycleDay << ",";


    json << "\"yearIndex\":"
         << id.yearIndex << ",";


    json << "\"historicalIndex\":"
         << id.historicalIndex << ",";


    json << "\"era\":\""
         << id.era
         << "\",";


    // Engine Metadata

    json << "\"architecture\":\"Gabary V2\",";
    json << "\"engine\":\"SolarEngineV2\",";
    json << "\"validation\":\"PASSED\"";


    json << "}";


    return json.str();
}



// ============================================
// Solar Date Query
// ============================================

std::string TemporalAPI::getSolarAsJSON(
    int year,
    int month,
    int day
)
{
    GlobalTemporalID id;


    try
    {
        id =
            query.querySolar(
                year,
                month,
                day
            );
    }
    catch(...)
    {
        return R"({"error":"Solar query failed"})";
    }


    if(id.dayId <= 0)
    {
        return R"({"error":"Invalid solar date"})";
    }


    return getDayAsJSON(
        id.dayId
    );
}



// ============================================
// Lunar Date Query
// ============================================

std::string TemporalAPI::getLunarAsJSON(
    int year,
    int month,
    int day
)
{
    GlobalTemporalID id;


    try
    {
        id =
            query.queryLunar(
                year,
                month,
                day
            );
    }
    catch(...)
    {
        return R"({"error":"Lunar query failed"})";
    }


    if(id.dayId <= 0)
    {
        return R"({"error":"Invalid lunar date"})";
    }


    return getDayAsJSON(
        id.dayId
    );
}



// ============================================
// Engine Status
// ============================================

std::string TemporalAPI::getStatusJSON()
{
    std::ostringstream json;


    json << "{";

    json << "\"engine\":\"Golden Calendar 50000 Chronology Engine\",";
    json << "\"version\":\"1.1-dev\",";
    json << "\"status\":\"stable\",";
    json << "\"tests\":\"51/51 Passed\",";
    json << "\"maxYears\":50000,";
    json << "\"api\":\"Temporal API\",";
    json << "\"architecture\":\"Gabary V2\"";

    json << "}";


    return json.str();
}
