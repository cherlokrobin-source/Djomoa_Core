/*
==========================================
 GOLDEN CALENDAR
 SOLAR QUERY API MODULE
==========================================
*/


const API_BASE = "";



export async function getSolar(
    year,
    month,
    day
)
{

    try
    {

        const response =
            await fetch(
                `${API_BASE}/api/solar/${year}/${month}/${day}`
            );


        if(!response.ok)
        {
            throw new Error(
                "Solar query failed"
            );
        }


        return await response.json();

    }

    catch(error)
    {

        console.error(
            "Solar API Error:",
            error
        );


        return {
            error: error.message
        };

    }

}
