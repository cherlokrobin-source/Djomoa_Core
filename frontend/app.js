const API_BASE = "http://localhost:8080";


// =====================================
// Load Engine Status
// =====================================

async function loadStatus() {

    try {

        const response = await fetch(
            `${API_BASE}/api/status`
        );

        const data = await response.json();


        document.getElementById(
            "engineStatus"
        ).textContent = data.status;


        document.getElementById(
            "engineVersion"
        ).textContent = data.version;


        document.getElementById(
            "engineTests"
        ).textContent = data.tests;


    } catch(error) {

        document.getElementById(
            "engineStatus"
        ).textContent = "Offline";

    }

}


// =====================================
// Global Solar Day Query
// =====================================

async function searchDay(){

    const day =
    document.getElementById("dayInput").value;


    if(!day)
        return;


    try{

        const response =
        await fetch(
            `${API_BASE}/api/day/${day}`
        );


        const data =
        await response.json();


        let output = "";


        output +=
        "╔══════════════════════════════════╗\n";
        output +=
        "║       GABARY V2 INSPECTOR        ║\n";
        output +=
        "╚══════════════════════════════════╝\n\n";


        output +=
        "GLOBAL TEMPORAL COORDINATE\n";
        output +=
        "----------------------------------\n";
        output +=
        "Global Solar Day : "
        + data.dayId
        + "\n\n";


        output +=
        "SOLAR TIMELINE\n";
        output +=
        "----------------------------------\n";
        output +=
        "Year  : "
        + data.solarYear
        + "\n";

        output +=
        "Month : "
        + data.solarMonth
        + "\n";

        output +=
        "Day   : "
        + data.solarDay
        + "\n\n";


        output +=
        "LUNAR MAPPING\n";
        output +=
        "----------------------------------\n";

        output +=
        "Year  : "
        + data.lunarYear
        + "\n";

        output +=
        "Month : "
        + data.lunarMonth
        + "\n";

        output +=
        "Day   : "
        + data.lunarDay
        + "\n\n";


        output +=
        "CYCLE ANALYSIS\n";
        output +=
        "----------------------------------\n";

        output +=
        "Cycle Number : "
        + data.cycleNumber
        + "\n";

        output +=
        "Cycle Day    : "
        + data.cycleDay
        + "\n\n";


        output +=
        "ENGINE\n";
        output +=
        "----------------------------------\n";

        output +=
        "Architecture : Gabary V2\n";

        output +=
        "Coordinate   : Global Solar Day ID\n";

        output +=
        "Status       : VALIDATED\n";


        document.getElementById(
            "result"
        ).textContent = output;


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


setInterval(
    updateClock,
    1000
);


updateClock();

loadStatus();
