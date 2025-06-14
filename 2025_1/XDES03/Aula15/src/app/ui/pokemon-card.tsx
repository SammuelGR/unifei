import "@/app/styles/pokemon-card.css";

import Image from "next/image";
import Link from "next/link";

import ConexaoBD from "../libs/conexao-bd";

const bd: string = "pokemon-db.json";

export interface PokemonProps {
  id: string;
  nome: string;
  img: string;
  descricao: string;
}

export default function Pokemon(props: PokemonProps) {
  const deletePokemonHandler = async () => {
    "use server";

    const pokemonsList = await ConexaoBD.retornaBD(bd);

    const filteredPokemonsList = pokemonsList.filter(
      (pokemon) => pokemon.id !== props.id
    );

    return;
  };

  return (
    <div className="pokemonCard">
      <h2>{props.nome}</h2>
      <Image
        src={props.img}
        width={200}
        height={200}
        alt={`Imagem do pokémon ${props.nome}`}
      />
      <p>{props.descricao}</p>

      <div className="pokemon-buttons-container">
        <Link id="btn-edit" href="/dashboard/edit">
          Editar
        </Link>

        <form action={deletePokemonHandler}>
          <button id="btn-delete">Excluir</button>
        </form>
      </div>
    </div>
  );
}
