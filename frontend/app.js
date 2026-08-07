const API_BASE = "http://localhost:8080";


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
// Timeline Explorer
// =====================================

async function loadTimeline(){

    console.log("Timeline button clicked");


    const start =
        document.getElementById(
            "timelineStart"
        ).value;


    const end =
        document.getElementById(
            "timelineEnd"
        ).value;


    if(!start || !end)
        return;


    let output = "";


    for(
        let day = Number(start);
        day <= Number(end);
        day++
    ){

        try{

            const response =
                await fetch(
                    `${API_BASE}/api/json/day/${day}`
                );


            const data =
                await response.json();


            output +=
`
-----------------------------
Global Solar Day : ${data.globalSolarDay}

Date :
${data.solarDate.weekday}
${data.solarDate.day} ${data.solarDate.monthName} ${data.solarDate.year}

Day Of Year :
${data.solarDate.dayOfYear}

Cycle :
${data.temporalMetadata.cycleNumber}

Historical Index :
${data.temporalMetadata.historicalIndex}

Architecture :
${data.architecture.name}

Engine :
${data.architecture.engine}

Validation :
${data.architecture.validation}

`;

        }
        catch(error){

            output +=
            "\nERROR loading day " + day;

        }

    }


    document.getElementById(
        "timelineResult"
    ).textContent =
        output;

}



// =====================================
// Day Navigation
// =====================================

function jumpDay(value){

    const input =
        document.getElementById(
            "dayInput"
        );


    let current =
        Number(input.value) || 1;


    current += value;


    input.value =
        current;


    searchDay();

}



// =====================================
// Startup
// =====================================

setInterval(
    updateClock,
    1000
);


updateClock();

loadStatus();
