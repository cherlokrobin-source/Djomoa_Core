/*
==========================================
 GOLDEN CALENDAR
 DAY QUERY API MODULE
==========================================
*/


const API_BASE = "";


export async function getDay(dayId)
{

    try
    {

        const response =
            await fetch(
                `${API_BASE}/api/day/${dayId}`
            );


        if(!response.ok)
        {
            throw new Error(
                "Day query failed"
            );
        }


        return await response.json();

    }

    catch(error)
    {

        console.error(
            "Day API Error:",
            error
        );


        return {
            error: error.message
        };

    }

}
