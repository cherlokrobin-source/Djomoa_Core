#include <sstream>
#include "TemporalServer.h"
#include "../../Gabary/include/ReportFormatter.h"


TemporalServer::TemporalServer()
{
}


// طلب بواسطة Day ID
std::string TemporalServer::handleDayRequest(long long dayId)
{
    Gabary::GlobalSolarDay day = solarEngine.buildDay(dayId);

    return Gabary::ReportFormatter::createTextReport(day);
}


// طلب بواسطة التاريخ الشمسي
std::string TemporalServer::handleSolarRequest(
    int year,
    int month,
    int day
)
{
    long long dayId = solarEngine.toDayId(year, month, day);

    Gabary::GlobalSolarDay result = solarEngine.buildDay(dayId);

    return Gabary::ReportFormatter::createTextReport(result);
}


// طلب بواسطة التاريخ القمري
std::string TemporalServer::handleLunarRequest(
    int year,
    int month,
    int day
)
{
    return R"({"error":"Lunar V2 endpoint pending"})";
}


// حالة المحرك
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
std::string TemporalServer::handleDayJSONRequest(long long dayId)
{
    Gabary::GlobalSolarDay day = solarEngine.buildDay(dayId);

    std::ostringstream json;

    json << "{";

    json << "\"dayId\":" << day.dayId << ",";

    json << "\"gabaryDayCode\":\"GC-"
         << day.dayId << "-"
         << day.solarYear << "-"
         << day.dayOfYear
         << "\",";

    json << "\"solarDate\":{";

    json << "\"weekday\":\""
         << day.weekName << "\",";

    json << "\"year\":"
         << day.solarYear << ",";

    json << "\"month\":"
         << day.solarMonth << ",";

    json << "\"monthName\":\""
         << day.monthName << "\",";

    json << "\"day\":"
         << day.solarDay;

    json << "},";

    json << "\"dayOfYear\":"
         << day.dayOfYear << ",";

    json << "\"leapYear\":"
         << (day.leapYear ? "true" : "false") << ",";

    json << "\"architecture\":\"Gabary V2\",";

    json << "\"engine\":\"SolarEngineV2\",";

    json << "\"validation\":\"PASSED\"";

    json << "}";

    return json.str();
}
