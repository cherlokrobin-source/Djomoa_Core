#include "ExportManager.h"

#include "report/TemporalReportEngine.h"
#include "report/TemporalReportJSON.h"

#include <fstream>


bool ExportManager::exportTXT(
    const TemporalReport& report,
    const std::string& filename
) const
{
    std::ofstream file(filename);

    if (!file)
        return false;

    file << TemporalReportJSON::toJSON(report);

    return true;
}


bool ExportManager::exportJSON(
    const TemporalReport& report,
    const std::string& filename
) const
{
    std::ofstream file(filename);

    if (!file)
        return false;

    file << TemporalReportJSON::toJSON(report);

    return true;
}


bool ExportManager::exportCSV(
    const TemporalReport& report,
    const std::string& filename
) const
{
    std::ofstream file(filename);

    if (!file)
        return false;

    file << "format,data\n";
    file << "json,\""
         << TemporalReportJSON::toJSON(report)
         << "\"\n";

    return true;
}
