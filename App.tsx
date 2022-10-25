import { useState } from 'react'
import reactLogo from './assets/react.svg'
import './App.css'
import HelloWorld from './componentes/hello world'
import Soma from './componentes/soma';

function App() {
  const [count, setCount] = useState(0);
  const [a, setA] = useState(0);
  const [b, setB] = useState(0);

  return (
    <div className="App">
      <div>
      </div>
      <input type='number' onChange={(e) => setA(parseInt(e.currentTarget.value))}/>
      <Soma num={a}/>
      <input type='number' onChange={(e) => setB(parseInt(e.currentTarget.value))}/>
      <Soma num={b}/>
      <div className="card">
        <button onClick={() => setCount((count) => a + b)}>
          +</button>
        <button onClick={() => setCount((count) => a - b)}>
          -</button>
        <button onClick={() => setCount((count) => a * b)}>
          *</button>
        <button onClick={() => setCount((count) => a / b)}>
          /</button>
          <button onClick={() => setCount((count) => 0)}>
          RES</button>
        <Soma num={count}/>
      </div>
    </div>
  )
}

export default App
