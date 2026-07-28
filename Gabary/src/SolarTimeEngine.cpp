#include "../include/SolarTimeEngine.h"

namespace Gabary
{

void SolarTimeEngine::loadCycles(
    int startCycle,
    int endCycle
)
{
    builder.build(
        startCycle,
        endCycle
    );
}

int64_t SolarTimeEngine::size() const
{
    return builder.getArchive().size();
}

GlobalSolarDay SolarTimeEngine::getDay(
    int64_t dayId
) const
{
    return builder.getArchive().getDay(
        dayId - 1
    );
}

}
