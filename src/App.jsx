import { useState } from 'react'
import { BrowserRouter, Routes, Route } from 'react-router-dom'

import Home from './pages/home/Home'

function App() {
  return <BrowserRouter>
    <Routes>
      <Route path="/maestro194" element={<Home/>}></Route>
    </Routes>
  </BrowserRouter>
}

export default App
