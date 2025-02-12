import React from 'react'

const links = [
  {
    name: 'GitHub',
    url: 'github.com/maestro194'
  },
  {
    name: 'Reddit',
    url: 'reddit.com'
  },
  {
    name: 'YouTube',
    url: 'youtube.com'
  },
  {
    name: 'Gmail',
    url: 'mail.google.com'
  }
]

export default function Link() {
  return (
    <div className='linksBlock grid row-start-4 row-span-2 col-start-1 col-span-4' id='linksBlock'>
      <div className="linksBlockLeft row-start-1 row-span-2 col-start-1 col-span-2" id="linksBlockLeft">
        <ul className="linksList">
          {links.map((link, index) => (
            <li key={index}>
              <a href={link.url} target="_blank" className='mt-2 text-black px-2 py-3 text-bold text-center w-[3/4] bg-white rounded-md shadow-md hover:bg-gray-200'>
                {link.name}
              </a>
            </li>
          ))}
        </ul>
      </div>

      <div className="linksBlockRight row-start-1 row-span-2 col-start-3 col-span-2" id="linksBlockRight"></div>
    </div>
  )
}
