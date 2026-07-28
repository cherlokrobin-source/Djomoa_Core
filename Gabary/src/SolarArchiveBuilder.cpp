#include "../include/SolarArchiveBuilder.h"

namespace Gabary
{

void SolarArchiveBuilder::build(
    int startCycle,
    int endCycle
)
{
    archive.buildCycles(
        startCycle,
        endCycle
    );
}


SolarCycleArchive& SolarArchiveBuilder::getArchive()
{
    return archive;
}

}
