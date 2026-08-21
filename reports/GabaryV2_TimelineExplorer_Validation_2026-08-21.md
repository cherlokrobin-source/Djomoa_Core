# Gabary V2 — Timeline Explorer Validation

## Validation Status

**PASSED**

The Digital Astrolabe Timeline Explorer was validated against the
Gabary V2 API using multiple Global Solar Day ranges.

## Tests

| Test | Range | Result |
|---|---:|---|
| Beginning of chronology | Day 1 | PASSED |
| Year boundary | 365 → 366 | PASSED |
| Reference date | Day 739823 | PASSED |
| Final boundary | Day 18262125 | PASSED |
| 1-day range | 1 → 1 | PASSED |
| 7-day range | 1000 → 1006 | PASSED |
| 30-day range | 1000 → 1029 | PASSED |
| Maximum allowed range | 1000 → 1099 | PASSED |
| Safety rejection | 1000 → 1100 | PASSED |

## Safety Limit

The Timeline Explorer correctly accepts a maximum of 100 days per query.

A request for 101 days was rejected:

Requested days : 101
Maximum per query : 100

No oversized query was executed.

## API Validation

The frontend successfully retrieves validated chronology data from:

- Gabary V2
- SolarEngineV2
- Global Solar Day coordinates
- Solar calendar
- Lunar calendar
- Temporal metadata
- Architecture metadata

## Boundary Validation

Final chronology boundary verified:

Global Solar Day: 18262125
Solar Date: Thursday, 31 December 50000
Day Of Year: 366
Year Type: Leap Year
Cycle: 1516
Validation: PASSED

## Final Status

Gabary V2 Digital Astrolabe Timeline Explorer Validation: PASSED

No source-code modifications were required during this validation stage.
