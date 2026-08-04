#ifndef GABARY_REPORT_FORMATTER_H
#define GABARY_REPORT_FORMATTER_H

#include <string>
#include "GlobalSolarDay.h"

namespace Gabary
{

class ReportFormatter
{
public:

    static std::string createShareReport(
        const GlobalSolarDay& day
    );

    static std::string createInspectReport(
        const GlobalSolarDay& day
    );

    static std::string createTextReport(
        const GlobalSolarDay& day
    );

};

}

#endif
