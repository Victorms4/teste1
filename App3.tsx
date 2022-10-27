import { useEffect, useState } from 'react'
import reactLogo from './assets/react.svg'
import './App.css'
import { Pokemon } from './componentes/pokemon/pokemon'


function App() {
  const [pokemons, setPokemons] = useState<Pokemon[]>([])
  const [page, setPage] = useState(1);

  const fetchPokemon = async (pokemon: string) => {
    const URL = `https://pokeapi.co/api/v2/pokemon/${pokemon}`;

    let response;
    let data: Pokemon | null;
    let error;

    try {
      response = await fetch(URL);
      data = await response.json();
      error = false;
    } catch {
      data = null;
      error = true;
    }
    return { response, data, error };
  }

  const fetchPokemonList = async (page: number) => {
    const offset = (page - 1) * 20 + 1;
    const URL = `https://pokeapi.co/api/v2/pokemon?offset=${offset}&limit=19`

    const response: Response = await fetch(URL);

    const data = await response.json();

    const promises = data.results.map(
      // async(pokemon: Pokemon) => pokemon
      async (pokemon: { name: string }) => (await fetchPokemon(pokemon.name)).data
    );

    const pokemonList = Promise.all(promises);

    console.log(pokemonList)

    return pokemonList;
  }

  useEffect(() => {
    (async () => { setPokemons(await fetchPokemonList(1)); })();
  }, [])



  return (
    <>
      <div className="App">
        <>
          <div>
            {pokemons.map((pokemon) => (
              <>
                <img src={`https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/versions/generation-i/red-blue/${pokemon.id}.png`} />
                <p>nome: {pokemon.name}</p>
                <p>altura: {pokemon.height}</p>
                <p>peso: {pokemon.weight}</p>
                <p>tipos: {pokemon.types[0].type.name}</p>
              </>
            ))}
          </div>
          <div>
            <>
            <button onClick={() => fetchPokemonList(1)}>1</button>
            <button onClick={() => fetchPokemonList(2)}>2</button>
            </>
        </div>
      </>
    </div>


    </>
  )
}

export default App