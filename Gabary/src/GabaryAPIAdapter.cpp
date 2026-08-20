#include "GabaryAPIAdapter.h"

#include <sstream>

namespace Gabary
{

GabaryAPIAdapter::GabaryAPIAdapter()
{
}

std::string
GabaryAPIAdapter::getDay(int64_t dayId)
{
    DualCalendarDate date =
        service.queryDay(dayId);

    std::ostringstream out;

    out << "{";
    out << "\"dayId\":" << date.dayId << ",";
    out << "\"solar\":{";
    out << "\"year\":" << date.solar.solarYear << ",";
    out << "\"month\":" << date.solar.solarMonth << ",";
    out << "\"day\":" << date.solar.solarDay;
    out << "},";
    out << "\"lunar\":{";
    out << "\"year\":" << date.lunar.year << ",";
    out << "\"month\":" << date.lunar.month << ",";
    out << "\"day\":" << date.lunar.day;
    out << "}";
    out << "}";

    return out.str();
}

std::string
GabaryAPIAdapter::getSolar(
    int year,
    int month,
    int day
)
{
    DualCalendarDate date =
        service.querySolar(year, month, day);

    std::ostringstream out;

    out << "{";
    out << "\"dayId\":" << date.dayId << ",";
    out << "\"solar\":{";
    out << "\"year\":" << date.solar.solarYear << ",";
    out << "\"month\":" << date.solar.solarMonth << ",";
    out << "\"day\":" << date.solar.solarDay;
    out << "},";
    out << "\"lunar\":{";
    out << "\"year\":" << date.lunar.year << ",";
    out << "\"month\":" << date.lunar.month << ",";
    out << "\"day\":" << date.lunar.day;
    out << "}";
    out << "}";

    return out.str();
}

std::string
GabaryAPIAdapter::getLunar(
    int year,
    int month,
    int day
)
{
    DualCalendarDate date =
        service.queryLunar(year, month, day);

    std::ostringstream out;

    out << "{";
    out << "\"dayId\":" << date.dayId << ",";
    out << "\"solar\":{";
    out << "\"year\":" << date.solar.solarYear << ",";
    out << "\"month\":" << date.solar.solarMonth << ",";
    out << "\"day\":" << date.solar.solarDay;
    out << "},";
    out << "\"lunar\":{";
    out << "\"year\":" << date.lunar.year << ",";
    out << "\"month\":" << date.lunar.month << ",";
    out << "\"day\":" << date.lunar.day;
    out << "}";
    out << "}";

    return out.str();
}

}
