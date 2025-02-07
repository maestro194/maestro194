import { useState } from 'react'
import { BrowserRouter } from 'react-router'
import { Route } from 'react-router-dom'

import Home from './pages/home/Home'

function App() {
  return <BrowserRouter>
    <Route path="/" element={<Home/>}></Route>
  </BrowserRouter>
}

export default App
