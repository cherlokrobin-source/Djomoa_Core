/*
==========================================
 GOLDEN CALENDAR
 CONVERTER COMPONENT
==========================================
*/


import { getSolar } from "../api/solar.js";
import { getLunar } from "../api/lunar.js";



export async function searchSolar(
    year,
    month,
    day
)
{

    const result =
        await getSolar(
            year,
            month,
            day
        );


    displayResult(result);

}




export async function searchLunar(
    year,
    month,
    day
)
{

    const result =
        await getLunar(
            year,
            month,
            day
        );


    displayResult(result);

}




function displayResult(data)
{

    const output =
        document.getElementById(
            "result"
        );


    if(output)
    {

        output.textContent =
            JSON.stringify(
                data,
                null,
                4
            );

    }

}
