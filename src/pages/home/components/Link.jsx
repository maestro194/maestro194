import React from 'react'
import { Navigate, useNavigate } from 'react-router'

const links = [
  {
    name: 'Balatro Stuff',
    url: '/maestro194/balatro',
  },
]

export default function Link() {
  
  return (
    <div className='linksBlock grid row-start-4 row-span-2 col-start-1 col-span-4' id='linksBlock'>
      <div className="linksBlockLeft row-start-1 row-span-2 col-start-1 col-span-2" id="linksBlockLeft">
        <ul className="linksList">
          {links.map((link, index) => (
            <ul key={index}>
              <a href={link.url} className='mt-2 text-black px-2 py-3 text-bold text-center w-[3/4] bg-white rounded-md shadow-md hover:bg-gray-200'>
                {link.name}
              </a>
            </ul>
          ))}
        </ul>
      </div>

      <div className="linksBlockRight row-start-1 row-span-2 col-start-3 col-span-2" id="linksBlockRight"></div>
    </div>
  )
}
