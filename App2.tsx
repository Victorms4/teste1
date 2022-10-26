import { useEffect, useState } from 'react'
import reactLogo from './assets/react.svg'
import './App.css'
import { Pokemon } from './componentes/type/pokemon';

function App() {
  const [pokemons, setPokemons] = useState<Pokemon[]>([])

  const fetchPokemonList = async (page: number) => {

    const response: Response = await fetch("https://pokeapi.co/api/v2/pokemon");

    const data = await response.json();

    const promises = data.results.map(
      async(pokemon: Pokemon) => pokemon
      //async (pokemon: { name: string }) => (await fetchPokemon(pokemon.name).data)
    );

    const pokemonList = Promise.all(promises);

    console.log(pokemonList)

    return pokemonList;
  }

  useEffect(() => {
    (async() => {setPokemons(await fetchPokemonList(1)); })();
  }, []) 

  

  return (
    <div className="App">
      {pokemons.map((pokemon) => (
      <p>{pokemon.name}</p>
      ))}
    </div>
  )
}

export default App
