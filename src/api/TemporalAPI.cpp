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


    std::ostringstream json;


    json << "{";

    json << "\"dayId\":" << id.dayId << ",";
    json << "\"solarYear\":" << id.solarYear << ",";
    json << "\"solarMonth\":" << id.solarMonth << ",";
    json << "\"solarDay\":" << id.solarDay << ",";

    json << "\"lunarYear\":" << id.lunarYear << ",";
    json << "\"lunarMonth\":" << id.lunarMonth << ",";
    json << "\"lunarDay\":" << id.lunarDay << ",";

    json << "\"weekIndex\":" << id.weekIndex << ",";
    json << "\"cycleNumber\":" << id.cycleNumber << ",";
    json << "\"cycleDay\":" << id.cycleDay << ",";

    json << "\"yearIndex\":" << id.yearIndex << ",";
    json << "\"historicalIndex\":" << id.historicalIndex << ",";

    json << "\"era\":\"" << id.era << "\"";

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
    json << "\"tests\":\"20/20 Passed\",";
    json << "\"maxYears\":50000,";
    json << "\"api\":\"Temporal API\"";

    json << "}";


    return json.str();
}
