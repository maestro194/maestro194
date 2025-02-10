import React from 'react'
import { useState } from 'react'

export default function SearchBar() {
    const [searchText, setSearchText] = useState('');

    const handleChange = (e) => {
        setSearchText(e.target.value);
    }

    const handleSearch = (e) => {
        e.preventDefault();
        
        // navigate to google search
        window.location.href = `https://www.google.com/search?q=${searchText}`;
    }

    return (
        <div className='grid row-start-3 row-span-1 col-start-1 col-span-4'>
            <div className='flex items-center justify-center w-full h-full'>
                <form onSubmit={handleSearch} className='flex items-center justify-center w-2/3'>
                    <input 
                        type='text' 
                        placeholder='Search' 
                        value={searchText} 
                        onChange={handleChange}
                        onSubmit={handleSearch}
                        className='w-5/6 h-10 p-2 text-black bg-gray-100 opacity-50 border-2 border-black rounded-lg'
                    />
                    <button type="submit" className='w-1/6'>Search</button>
                </form>
            </div>       
        </div>
    )
}
