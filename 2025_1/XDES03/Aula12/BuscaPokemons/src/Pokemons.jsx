import "./styles/Pokemons.css";

import { useState } from "react";

import axios from "axios";

import Pokemon from "./Pokemon";

export default function Pokemons() {
  const [pokeData, setPokeData] = useState([]);

  const getPokemon = async () => {
    const pokeId = Math.trunc(Math.random() * 100) + 1; // 1 - 101

    const { data } = await axios.get(
      `https://pokeapi.co/api/v2/pokemon/${pokeId}`
    );

    return { name: data.name, imgUrl: data.sprites.front_default };
  };

  const addPokemon = async () => {
    const newPokes = await Promise.all([
      getPokemon(),
      getPokemon(),
      getPokemon(),
    ]);

    setPokeData(newPokes);
  };

  return (
    <>
      <button onClick={addPokemon}>Busca Pokemon</button>

      <section className="cards-container">
        {pokeData.map((pokemon) => (
          <Pokemon
            key={pokemon.name}
            name={pokemon.name}
            imgUrl={pokemon.imgUrl}
          />
        ))}
      </section>
    </>
  );
}
