const API_BASE = "https://chess-macintosh-temporary-toward.trycloudflare.com";


// =====================================
// Load Gabary V2 Engine Status
// =====================================

async function loadStatus() {

    try {

        const response = await fetch(
            `${API_BASE}/api/status`
        );

        const data = await response.json();


        document.getElementById(
            "engineStatus"
        ).textContent =
            data.status || "Unknown";


        document.getElementById(
            "engineVersion"
        ).textContent =
            data.core || "SolarEngineV2";


        document.getElementById(
            "engineTests"
        ).textContent =
            data.validation || "PASSED";


    }
    catch(error){

        document.getElementById(
            "engineStatus"
        ).textContent =
            "Offline";

        document.getElementById(
            "engineVersion"
        ).textContent =
            "---";

        document.getElementById(
            "engineTests"
        ).textContent =
            "---";
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
            await response.text();


        document.getElementById(
            "result"
        ).textContent = data;


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
// Startup
// =====================================

setInterval(
    updateClock,
    1000
);


updateClock();

loadStatus();
