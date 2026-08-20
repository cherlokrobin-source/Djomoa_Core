#ifndef GABARY_DUAL_REPORT_FORMATTER_H
#define GABARY_DUAL_REPORT_FORMATTER_H

#include <string>
#include "GabaryDualCalendarEngine.h"

namespace Gabary
{

class GabaryDualReportFormatter
{
public:
    static std::string createReport(
        const DualCalendarDate& date
    );
};

} // namespace Gabary

#endif // GABARY_DUAL_REPORT_FORMATTER_H
