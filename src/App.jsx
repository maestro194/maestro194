import { useState } from 'react'
import { BrowserRouter, Routes, Route } from 'react-router-dom'

import Home from './pages/home/Home'
import Balatro from './pages/home/Balatro'

function App() {
  return <BrowserRouter>
    <Routes>
      <Route path="/maestro194" element={<Home/>}/>
      <Route path="/maestro194/balatro" element={<Balatro/>} />
    </Routes>
  </BrowserRouter>
}

export default App
