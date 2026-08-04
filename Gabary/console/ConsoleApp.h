#ifndef GABARY_CONSOLE_APP_H
#define GABARY_CONSOLE_APP_H

#include <cstdint>
#include <string>

#include "SolarEngineV2.h"
#include "ExportManager.h"

#include "report/TemporalReportEngine.h"
#include "report/TemporalReportJSON.h"


class ConsoleApp
{
public:

    int run();


private:

    void showBanner() const;


    void showDay(
        int64_t dayId
    );


    void shareDay(
        int64_t dayId
    );


    void exportDay(
        int64_t dayId
    );


    void inspectDay(
        int64_t dayId
    );


    void reportDay(
        int64_t dayId
    );


private:

    Gabary::SolarEngineV2 solarEngine;

    TemporalReportEngine reportEngine;

    ExportManager exportManager;

};


#endif // GABARY_CONSOLE_APP_H
