#ifndef GABARY_CONSOLE_APP_H
#define GABARY_CONSOLE_APP_H

#include <cstdint>
#include "SolarEngineV2.h"

class ConsoleApp
{
public:

    int run();

private:

    void showBanner() const;

    void showDay(int64_t dayId);

    void shareDay(int64_t dayId);

    void exportDay(int64_t dayId);

    void inspectDay(int64_t dayId);

    Gabary::SolarEngineV2 solarEngine;
};

#endif
