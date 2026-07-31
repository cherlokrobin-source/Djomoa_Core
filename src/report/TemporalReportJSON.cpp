#include "report/TemporalReportJSON.h"

#include <sstream>


std::string TemporalReportJSON::toJSON(
    const TemporalReport& report
)
{
    std::ostringstream json;


    json << "{";

    json << "\"dayId\":"
         << report.dayId
         << ",";


    json << "\"solar\":{";
    json << "\"year\":"
         << report.solar.year
         << ",";
    json << "\"month\":"
         << report.solar.month
         << ",";
    json << "\"day\":"
         << report.solar.day;
    json << "},";


    json << "\"lunar\":{";
    json << "\"year\":"
         << report.lunar.year
         << ",";
    json << "\"month\":"
         << report.lunar.month
         << ",";
    json << "\"day\":"
         << report.lunar.day;
    json << "},";


    json << "\"week\":{";
    json << "\"index\":"
         << report.weekIndex
         << ",";
    json << "\"name\":\""
         << report.weekName
         << "\"";
    json << "},";


    json << "\"cycle\":"
         << report.cycleNumber
         << ",";


    json << "\"historicalIndex\":"
         << report.historicalIndex;


    json << "}";


    return json.str();
}
