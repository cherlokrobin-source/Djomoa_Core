/*
==========================================
 GOLDEN CALENDAR
 LUNAR QUERY API MODULE
==========================================
*/


const API_BASE = "";



export async function getLunar(
    year,
    month,
    day
)
{

    try
    {

        const response =
            await fetch(
                `${API_BASE}/api/lunar/${year}/${month}/${day}`
            );


        if(!response.ok)
        {
            throw new Error(
                "Lunar query failed"
            );
        }


        return await response.json();

    }

    catch(error)
    {

        console.error(
            "Lunar API Error:",
            error
        );


        return {
            error: error.message
        };

    }

}
