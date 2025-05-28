import "./App.css";

import axios from "axios";

import Pokemon from "./Pokemon";

export default function App() {
  const getPokemon = async () => {
    const pokemon = await axios.get("https://pokeapi.co/api/v2/pokemon/1");

    const { name } = pokemon.data;

    console.log(name);
  };

  return (
    <>
      <button onClick={getPokemon}>Busca Pokemon</button>

      <Pokemon
        name="Bulbasaur"
        imgUrl="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/1.png"
      />

      <Pokemon
        name="Ivysaur"
        imgUrl="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/2.png"
      />

      <Pokemon
        name="Venusaur"
        imgUrl="https://raw.githubusercontent.com/PokeAPI/sprites/master/sprites/pokemon/3.png"
      />
    </>
  );
}
