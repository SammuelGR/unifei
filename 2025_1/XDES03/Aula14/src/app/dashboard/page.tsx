import "@/app/styles/dashboard.css";

import Link from "next/link";

import ConexaoBD from "@/app/libs/conexao-bd";
import Pokemon from "@/app/ui/pokemon-card";

const bd: string = "pokemon-db.json";

export default async function DisplayPokemons() {
  const pokemons = await ConexaoBD.retornaBD(bd);

  return (
    <div className="dashboard-container">
      <Link className="add-pokemon" href="/dashboard/create">
        Adicionar Pokemon
      </Link>

      <div className="cardContainer">
        {pokemons.map((pokemon) => (
          <Pokemon key={pokemon.id} {...pokemon} />
        ))}
      </div>
    </div>
  );
}
