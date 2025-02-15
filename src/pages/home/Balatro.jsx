import React from 'react'

export default function Balatro() {
  return (
    <div className='w-[60vw] flex flex-col justify-center font-(Nunito)'>
        <h1 className='text-center'>Balatro</h1>

        <h2>Resources</h2>

        {/* Calculator */}
        <a href="https://efhiii.github.io/balatro-calculator/" target='_blank'
           className='mt-2 text-black px-2 py-3 text-bold text-center w-[3/4] bg-white rounded-md shadow-md hover:bg-gray-200'>
            Point Calculator
        </a>

        {/* mods */}
        <a href="https://github.com/jie65535/awesome-balatro" target='_blank'
            className='mt-2 text-black px-2 py-3 text-bold text-center w-[3/4] bg-white rounded-md shadow-md hover:bg-gray-200'>
            Mods
        </a>
        
        {/* save editor */}
        <a href="https://balatro.shorty.systems/" target='_blank'
            className='mt-2 text-black px-2 py-3 text-bold text-center w-[3/4] bg-white rounded-md shadow-md hover:bg-gray-200'>
            Save Editor
        </a>


        
    </div>
  )
}
