import React, { useEffect, useState } from 'react'

import backgroundImage from './components/assets/background.jpg';
import Clock from './components/Clock.jsx';
import Weather from './components/Weather.jsx';
import SearchBar from './components/SearchBar.jsx';
import Link from './components/Link.jsx';

// icon import

export default function Home() {

  return (
    <div className='w-[100vw] h-[100vh] flex items-center justify-center font-(Nunito)'>
        <button id="themeButton" className='absolute top-2 right-2 cursor-pointer'>
            <img src='maestro194/Bento/assets/icons/OneDark/01d.png' className='w-6 h-6'></img>
        </button>

        <img src={backgroundImage} className='bg-cover absolute w-full h-full opacity-45 -z-1'/>

        <div className="container w-[145vh] h-[85vh] grid grid-cols-4 grid-rows-5 gap-8 p-5">
            <Clock/>
            <Weather/>
            <SearchBar/>
            <Link/>
        </div>
    </div>

  )
}
