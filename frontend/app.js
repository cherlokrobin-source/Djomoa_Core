const API_BASE = "";


// =====================================
// Load Gabary V2 Engine Status
// =====================================

async function loadStatus(){

    try{

        const response =
            await fetch(
                `${API_BASE}/api/status`
            );

        const data =
            await response.json();


        document.getElementById(
            "engineStatus"
        ).textContent =
            data.status;


        document.getElementById(
            "engineVersion"
        ).textContent =
            data.core;


        document.getElementById(
            "engineTests"
        ).textContent =
            data.validation;


    }
    catch(error){

        document.getElementById(
            "engineStatus"
        ).textContent =
            "Offline";

    }

}



// =====================================
// Global Solar Day Query
// =====================================

async function searchDay(){

    console.log("SEARCH DAY CLICKED");


    const day =
        document.getElementById(
            "dayInput"
        ).value;


    if(!day)
        return;


    try{

        const response =
            await fetch(
                `${API_BASE}/api/json/day/${day}`
            );


        const data =
            await response.json();


        document.getElementById(
            "globalSolarDay"
        ).textContent =
            data.globalSolarDay;


        document.getElementById(
            "solarDate"
        ).textContent =
            `${data.solarDate.weekday}, ${data.solarDate.day} ${data.solarDate.monthName} ${data.solarDate.year}`;


        document.getElementById(
            "dayOfYear"
        ).textContent =
            data.solarDate.dayOfYear;


        document.getElementById(
            "weekIndex"
        ).textContent =
            data.calendarMetadata.weekIndex;


        document.getElementById(
            "cycleNumber"
        ).textContent =
            data.temporalMetadata.cycleNumber;


        document.getElementById(
            "historicalIndex"
        ).textContent =
            data.temporalMetadata.historicalIndex;


        document.getElementById(
            "engineName"
        ).textContent =
            data.architecture.engine;


        document.getElementById(
            "validationState"
        ).textContent =
            data.architecture.validation;


        document.getElementById(
            "result"
        ).textContent =
            JSON.stringify(
                data,
                null,
                4
            );



        const reportResponse =
            await fetch(
                `${API_BASE}/api/day/${day}`
            );


        const reportText =
            await reportResponse.text();


        document.getElementById(
            "textReport"
        ).textContent =
            reportText;


    }
    catch(error){

        document.getElementById(
            "result"
        ).textContent =
            "API CONNECTION ERROR";

    }

}
// =====================================
// Digital Clock
// =====================================

function updateClock(){

    const now =
        new Date();


    document.getElementById(
        "clock"
    ).textContent =
        now.toUTCString()
        .split(" ")[4];


    document.getElementById(
        "date"
    ).textContent =
        now.toDateString();

}


// =====================================
// Timeline Explorer V2
// =====================================

async function loadTimeline(){

    console.log("Gabary Timeline Explorer V2");


    const startInput =
        document.getElementById(
            "timelineStart"
        );

    const endInput =
        document.getElementById(
            "timelineEnd"
        );

    const outputElement =
        document.getElementById(
            "timelineResult"
        );


    const start =
        Number(startInput.value);

    const end =
        Number(endInput.value);


    // ==============================
    // Input Validation
    // ==============================

    if(
        !Number.isInteger(start) ||
        !Number.isInteger(end)
    ){

        outputElement.textContent =
            "Please enter valid Global Solar Day IDs.";

        return;
    }


    if(start < 1){

        outputElement.textContent =
            "Global Solar Day must be >= 1.";

        return;
    }


    if(end < start){

        outputElement.textContent =
            "End Day ID must be greater than or equal to Start Day ID.";

        return;
    }


    const count =
        end - start + 1;


    // ==============================
    // Safety Limit
    // ==============================

    if(count > 100){

        outputElement.textContent =
`
TIMELINE RANGE TOO LARGE

Requested days : ${count}

Maximum per query : 100

Please use a smaller range.
`;

        return;
    }


    // ==============================
    // Loading State
    // ==============================

    outputElement.textContent =
`
GABARY V2 TIMELINE EXPLORER

Loading...
----------------------------------
Start Day : ${start}
End Day   : ${end}
Days      : ${count}
`;


    let output =
`
GABARY V2 TIMELINE EXPLORER

Range
----------------------------------
Start Global Solar Day : ${start}
End Global Solar Day   : ${end}
Total Days             : ${count}

==================================
`;


    // ==============================
    // Query Timeline
    // ==============================

    for(
        let day = start;
        day <= end;
        day++
    ){

        try{

            const response =
                await fetch(
                    `${API_BASE}/api/json/day/${day}`
                );


            if(!response.ok){

                throw new Error(
                    `HTTP ${response.status}`
                );

            }


            const data =
                await response.json();


            output +=
`
----------------------------------
Global Solar Day : ${data.globalSolarDay}

Solar Date
${data.solarDate.weekday}, ${data.solarDate.day} ${data.solarDate.monthName} ${data.solarDate.year}

Day Of Year : ${data.solarDate.dayOfYear}
Week Index  : ${data.calendarMetadata.weekIndex}
Leap Year   : ${data.calendarMetadata.leapYear ? "YES" : "NO"}

Cycle Number     : ${data.temporalMetadata.cycleNumber}
Historical Index : ${data.temporalMetadata.historicalIndex}

Architecture : ${data.architecture.name}
Engine       : ${data.architecture.engine}
Validation   : ${data.architecture.validation}
`;

        }
        catch(error){

            output +=
`
----------------------------------
ERROR

Global Solar Day : ${day}
Message          : ${error.message}
`;

        }


        // Update display during long queries

        outputElement.textContent =
            output;

    }


    output +=
`
==================================

TIMELINE QUERY COMPLETE

Days Processed : ${count}
`;

    outputElement.textContent =
        output;

}
