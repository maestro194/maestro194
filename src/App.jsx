import { useState } from 'react'
import { BrowserRouter } from 'react-router'

function App() {
  return <BrowserRouter>
    <Route path="/" element={<Home/>}></Route>
  </BrowserRouter>
}

export default App
