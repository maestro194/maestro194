import React, { useEffect, useState } from 'react'

import backgroundImage from './components/background.jpg'

export default function Home() {
    const [time, setTime] = useState({
        "hour": 0,
        "separator": ":",
        "minutes": 0,
        "separator2": ":",
        "seconds": 0,
        "month": "",
        "day": ""
    })

    const [greeting, setGreeting] = useState("");

    const displayClock = () => {
        const monthNames = ['Jan', 'Feb', 'Mar', 'Apr', 'May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec'];
        
        const timer = setInterval(() => {
            var d = new Date();
            var mm = monthNames[d.getMonth()];
            var dd = d.getDate();
            var min = (('0' + d.getMinutes()).slice(-2));
            var hh = d.getHours();
            var ss = (('0' + d.getSeconds()).slice(-2));
            
            setTime({
                "hour": hh,
                "separator": ":",
                "minutes": min,
                "separator2": ":",
                "seconds": ss,
                "month": mm,
                "day": dd
            })
        }, 1000);
    }
    
    const greetingText = () => {
        var d = new Date();
        var hour = d.getHours();
        var name = "Maestro";

        var greetingMorning = 'Good morning,';
        var greetingAfternoon = 'Good afternoon,';
        var greetingEvening = 'Good evening,';
        var greetingNight = 'Go to Sleep!';

        if (hour >= 23 || hour < 6) {
            return greetingNight + name;
        } else if (hour >= 6 && hour < 12) {
            return greetingMorning + name;
        } else if (hour >= 12 && hour < 18) {
            return greetingAfternoon + name;
        } else {
            return greetingEvening + name;
        }
    }

    useEffect(() => {
        displayClock();
        setGreeting(greetingText);

        return () => {
            clearInterval(displayClock)
        }
    },[]);

  return (
    <div className='w-[100vw] h-[100vh] flex items-center justify-center font-(Nunito) text-black text-5xl
        
    '>
        <button id="themeButton" className='absolute top-2 right-2 cursor-pointer'>
            <img src='maestro194/Bento/assets/icons/OneDark/01d.png' className='w-6 h-6'></img>
        </button>

        <img src={backgroundImage} className='bg-cover w-[100vw] absolute h-full opacity-45 -z-1'/>

        <div className="container w-[145vh] h-[85vh] grid grid-cols-4 grid-rows-5 gap-8 p-5">
            <div className="flex flex-col items-center justify-center col-start-1 col-span-2 row-start-1 row-span-2">
                <div className="flex items-center justify-center text-[130px] mb-10">
                    <div className='font-bold'>{time.hour}</div>
                    <div className='font-bold'>{time.separator}</div>
                    <div className='font-bold'>{time.minutes}</div>
                    <div className='font-bold'>{time.separator2}</div>
                    <div className='font-bold'>{time.seconds}</div>
                </div>
                <div id="greetings" className="text-black text-3xl">{greeting}</div>
            </div>

            <div className="weatherBlock flex flex-col items-center justify-center col-start-3 col-span-2 row-start-1 row-span-2">
                <div className="date flex items-center justify-center mt-8">
                    <div className='font-bold'>{time.month}</div>
                    <div className='font-bold'>{time.day}</div>
                </div>
                <div className="weather flex items-center justify-center">
                    <div className="weatherIcon">
                        <img src="maestro194/Bento/assets/icons/OneDark/unknown.png" />
                    </div>
                    <div className="weatherValue">
                        <p>- °<span className="g">c</span></p>
                    </div>
                    <div className="weatherDescription">
                        <p></p>
                    </div>
                </div>
            </div>

            <div className="linksBlock grid row-start-3 row-span-2 col-start-1 col-span-4" id="linksBlock">
                <div className="linksBlockLeft row-start-1 row-span-2 col-start-1 col-span-2" id="linksBlockLeft">
                    
                </div>
                <div className="linksBlockRight row-start-1 row-span-2 col-start-3 col-span-2" id="linksBlockRight"></div>
            </div>
        </div>

        <script>
            lucide.createIcons();
        </script>
    </div>

  )
}
