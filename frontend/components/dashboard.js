/*
==========================================
 GOLDEN CALENDAR
 DASHBOARD COMPONENT
==========================================
*/


import { getStatus } from "../api/status.js";



export async function loadDashboard()
{

    const status =
        await getStatus();



    const engineStatus =
        document.getElementById(
            "engineStatus"
        );


    const engineVersion =
        document.getElementById(
            "engineVersion"
        );


    const engineTests =
        document.getElementById(
            "engineTests"
        );



    if(engineStatus)
    {
        engineStatus.textContent =
            status.status || "Unknown";
    }



    if(engineVersion)
    {
        engineVersion.textContent =
            status.version || "-";
    }



    if(engineTests)
    {
        engineTests.textContent =
            status.tests || "-";
    }


}
