#ifndef GABARY_EXPORT_MANAGER_H
#define GABARY_EXPORT_MANAGER_H

#include <string>

struct TemporalReport;

class ExportManager
{
public:
    ExportManager() = default;
    ~ExportManager() = default;

    bool exportTXT(
        const TemporalReport& report,
        const std::string& filename
    ) const;

    bool exportJSON(
        const TemporalReport& report,
        const std::string& filename
    ) const;

    bool exportCSV(
        const TemporalReport& report,
        const std::string& filename
    ) const;
};

#endif // GABARY_EXPORT_MANAGER_H
