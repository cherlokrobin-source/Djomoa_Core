# Gabary V2 Architecture Documentation

## 1. Overview
## Version Information

Architecture:

Gabary V2

Engine:

SolarEngineV2

Validation:

54/54 Tests Passed

Branch:

v2-engine
Gabary V2 is the temporal computation architecture
inside GoldenCalendar 50000 Chronology Engine.

Its purpose is to provide a unified solar chronology
coordinate system based on Global Solar Day.

Core principles:

- Solar Day ID is the primary temporal coordinate.
- SolarEngineV2 generates deterministic solar dates.
- TemporalServer exposes engine capabilities through APIs.
- JSON and Text reports are presentation layers.

---

# 2. Architecture Layers


GoldenCalendar Engine

        |
        v

Gabary V2 Core Layer

        |
        |
        +----------------+
        |                |
        v                v

SolarEngineV2       WeekCycleEngine

        |
        v

GlobalSolarDay

        |
        v

TemporalServer

        |
        +----------------+
        |                |
        v                v

Text Report        JSON API


---

# 3. Gabary V2 Components


## SolarEngineV2

Location:

Gabary/include/SolarEngineV2.h

Responsibilities:

- Convert Day ID to Solar Date.
- Generate GlobalSolarDay.
- Handle 50,000 year solar chronology.
- Apply leap year rules.


---

## GlobalSolarDay

Represents a complete solar coordinate.

Contains:

- dayId
- solarYear
- solarMonth
- solarDay
- dayOfYear
- monthName
- weekName
- leapYear


---

## ReportFormatter

Responsibilities:

- Convert GlobalSolarDay into human-readable reports.
- Generate Gabary chronology reports.


Example:

GABARY V2 ENGINE

SOLAR CHRONOLOGY REPORT


---

# 4. TemporalServer


Location:

src/server/TemporalServer.cpp


Role:

API service layer between HTTP requests
and Gabary V2 engine.


Functions:


## handleDayRequest()

Input:

Global Solar Day ID


Output:

Text chronology report.


---

## handleDayJSONRequest()

Input:

Global Solar Day ID


Output:

JSON temporal object.


Example endpoint:

/api/json/day/739823


Response:


{
 "dayId":739823,
 "gabaryDayCode":"GC-739823-2026-207",
 "solarDate":{
    "weekday":"Thursday",
    "year":2026,
    "month":7,
    "monthName":"July",
    "day":26
 },
 "dayOfYear":207,
 "leapYear":false,
 "architecture":"Gabary V2",
 "engine":"SolarEngineV2",
 "validation":"PASSED"
}


---

# 5. HTTP API Endpoints


## Engine Status

GET:

/api/status


Returns:

- Engine status
- Architecture information
- Validation state


---

## Solar Day Report

GET:

/api/day/{dayId}


Example:

/api/day/739823


Returns:

Gabary text report.


---

## Solar Day JSON

GET:

/api/json/day/{dayId}


Example:

/api/json/day/739823


Returns:

Structured JSON data.


---

# 6. Validation


Current validation status:


CTest:

54/54 Passed


Validated components:

- Solar chronology
- Leap year rules
- GlobalSolarDay consistency
- Temporal API
- JSON API


---

# 7. Future Extensions


Planned:

- Extended temporal metadata JSON.
- Lunar mapping layer.
- Digital Astrolabe frontend integration.
- Historical timeline exploration.
---

Document Signature

Project: GoldenCalendar 50000 Chronology Engine
Architecture: Gabary V2
Document: Gabary V2 Architecture Documentation

Developed by:
Nemimeche Benaissa

Validation Status:
54/54 Tests Passed

Branch:
v2-engine

Date:
2026
