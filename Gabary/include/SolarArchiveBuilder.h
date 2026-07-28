#ifndef GABARY_SOLAR_ARCHIVE_BUILDER_H
#define GABARY_SOLAR_ARCHIVE_BUILDER_H

#include "SolarCycleArchive.h"

namespace Gabary
{

class SolarArchiveBuilder
{

private:

    SolarCycleArchive archive;


public:

    void build(
        int startCycle,
        int endCycle
    );

    SolarCycleArchive& getArchive();

    const SolarCycleArchive& getArchive() const;

};

}

#endif
