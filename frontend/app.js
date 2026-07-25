window.onload = function()
{

    loadStatus();

    loadDashboard();

    initializeTimeline();

};
import { loadDashboard } from "./components/dashboard.js";
================================================
 GOLDEN CALENDAR
 50000-Year Chronology Engine
 Frontend Application v1.0
================================================
*/


const API_BASE = "http://localhost:8080";



/*
===========================
 API STATUS
===========================
*/

async function loadStatus() {

    try {

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
            data.version;


        document.getElementById(
            "engineTests"
        ).textContent =
            data.tests;


    }

    catch(error) {

        console.error(
            "Status Error:",
            error
        );


        document.getElementById(
            "engineStatus"
        ).textContent =
            "Offline";

    }

}



/*
===========================
 DAY QUERY
===========================
*/


async function searchDay() {


    const day =
        document.getElementById(
            "dayInput"
        ).value;



    if(!day)
    {
        return;
    }



    try {


        const response =
            await fetch(
                `${API_BASE}/api/day/${day}`
            );


        const data =
            await response.json();



        document.getElementById(
            "result"
        ).textContent =
            JSON.stringify(
                data,
                null,
                4
            );


    }


    catch(error)
    {

        document.getElementById(
            "result"
        ).textContent =
            "API Error";

    }

}



/*
===========================
 TIMELINE
===========================
*/


const timeline =
    document.getElementById(
        "timelineRange"
    );


const yearValue =
    document.getElementById(
        "yearValue"
    );


if(timeline)
{

    timeline.addEventListener(
        "input",
        function()
        {

            yearValue.textContent =
                this.value;

        }
    );

}



/*
===========================
 START APPLICATION
===========================
*/


window.onload = function()
{

    loadStatus();

    loadDashboard();

};
