# Golden Calendar 50000 Chronology Engine

## A High-Precision Temporal Computing System

Golden Calendar is an advanced chronology engine designed to explore, calculate, and index time across a 50,000-year temporal range.

The project provides a unified temporal framework combining:

- Solar chronology
- Lunar chronology
- Global temporal indexing
- Long-range date conversion
- HTTP API access
- Web-based exploration interface


---

# Project Vision

Traditional calendar systems are designed for limited historical periods.
Golden Calendar explores a different approach:

A computational temporal architecture capable of managing a complete chronological timeline extending to 50,000 years.

The goal is to create a stable digital framework for:

- Temporal research
- Historical exploration
- Calendar computation
- Long-range chronology analysis


---

# Architecture

The system is divided into independent layers:
Golden Calendar Engine
├── Core Temporal Engine │   ├── ChronologyEngine │   ├── SolarEngine │   ├── LunarEngine │   ├── TemporalQueryEngine │   └── GlobalTemporalID │ ├── API Layer │   └── Temporal API │ ├── HTTP Server │   └── TemporalServer │ └── Frontend ├── Dashboard ├── Temporal Explorer ├── Timeline Explorer └── API Interface


---

# Main Features

## 50,000-Year Timeline

The engine supports chronological calculations from:
                 Year 1 to Year 50000


## Temporal Query System

Query the timeline using:

- Global Day ID
- Solar Date
- Lunar Date


## API Endpoints

### Engine Status
                 GET /api/status

Example:

```json
{
 "engine":"Golden Calendar 50000 Chronology Engine",
 "version":"1.1-dev",
 "status":"stable",
 "tests":"20/20 Passed",
 "maxYears":50000
}
Day Query
GET /api/day/{id}
Example:
/api/day/1000
Solar Query
GET /api/solar/{year}/{month}/{day}
Example:
/api/solar/50000/12/31
Lunar Query
GET /api/lunar/{year}/{month}/{day}
Example:
/api/lunar/2083/1/1
                   Validation
Current engine validation:
20/20 Tests Passed
The system has been tested across:
Temporal queries
Solar calculations
Lunar calculations
API responses
Long-range dates
Technology Stack
Core Engine
C++
CMake
Modular architecture
Server
HTTP Server Layer
REST-style API
Frontend
HTML5
CSS3
JavaScript
API Integration
                  Running The Project
Build
mkdir build
cd build

cmake ..
cmake --build .
                     Start Server
./TemporalServer
Server:
http://localhost:8080
Start Frontend
cd frontend

python -m http.server 3000
Open:
http://localhost:3000
Example Output
Day 18250000:
{
 "dayId":18250000,
 "solarYear":49967,
 "lunarYear":49999,
 "historicalIndex":18250000
}
Final solar date:
Solar:
Year 50000
Month 12
Day 31
                      Project Status


               ## License

This project is licensed under the MIT License.

Current Version:
v1.0.0 Development Release
Status:
Stable Core
Working API
Working Frontend
Author
Developed by:
Nemimeche Benaissa
@2026__1448
