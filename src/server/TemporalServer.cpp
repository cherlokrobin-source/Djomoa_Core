#include "TemporalServer.h"

TemporalServer::TemporalServer()
{
}

// طلب بواسطة Day ID
std::string TemporalServer::handleDayRequest(
    long long dayId
)
{
    return api.getDayAsJSON(dayId);
}

// طلب بواسطة التاريخ الشمسي
std::string TemporalServer::handleSolarRequest(
    int year,
    int month,
    int day
)
{
    return api.getSolarAsJSON(
        year,
        month,
        day
    );
}

// طلب بواسطة التاريخ القمري
std::string TemporalServer::handleLunarRequest(
    int year,
    int month,
    int day
)
{
    return api.getLunarAsJSON(
        year,
        month,
        day
    );
}

// طلب حالة المحرك
std::string TemporalServer::handleStatusRequest()
{
    return api.getStatusJSON();
}
