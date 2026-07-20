# GoldenCalendar 2083 Core
# Lunar Rules Specification

## Epoch

Start point:

Friday 1 January Year 1 Solar

=

1 Muharram Year 1 Lunar


## Solar System

Solar calendar:

- Normal solar year.
- Leap year follows Gregorian rule.
- Year length:
  - 365 days normal.
  - 366 days leap.


## Lunar System

The lunar model is based on:

- Lunar cycle: 33 years.
- Synchronization is calculated from the fixed epoch.
- Every lunar year contains:
  - 354 days normal.
  - 355 days leap.


## Lunar Cycle

Cycle length:

33 lunar years


Leap year positions:

(To be finalized after verification)


## Synchronization Goal

The engine must calculate:

Solar date
+
Lunar date
+
Weekday

from one continuous day index.


## Verification

Tests:

- Day 1:
  Friday 1 January Year 1
  =
  1 Muharram Year 1

- 33 lunar year cycle test

- 2083 year reference test
Proposed 33 Year Lunar Cycle:

Leap years:
3, 6, 9, 11, 14,
17, 20, 22, 25,
28, 31
