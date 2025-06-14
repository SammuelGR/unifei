import "@/app/styles/create-pokemon.css";

import Image from "next/image";
import { redirect } from "next/navigation";

import ConexaoBD from "@/app/libs/conexao-bd";
import { PokemonProps } from "@/app/ui/pokemon-card";

const arquivo = "pokemon-db.json";

interface EditPokemonProps {
  params: Promise<{ id: string }>;
}

export default async function EditPokemon({ params }: EditPokemonProps) {
  const { id } = await params;

  const pokemonsList = await ConexaoBD.retornaBD(arquivo);
  const pokemonToEdit: PokemonProps = pokemonsList.find(
    (pokemon) => pokemon.id === id
  );

  const updatePokemonHandler = async (formData: FormData) => {
    "use server";

    const newPokemon: PokemonProps = {
      id,
      nome: String(formData.get("nome")),
      descricao: String(formData.get("descricao")),
      img: String(formData.get("img")),
    };

    const pokemonIdx = pokemonsList.findIndex((pokemon) => pokemon.id === id);
    const newPokemonsList = pokemonsList.toSpliced(pokemonIdx, 1, newPokemon);

    await ConexaoBD.armazenaBD(arquivo, newPokemonsList);

    redirect("/dashboard");
  };

  return (
    <div className="create-pokemon-container">
      <h2>{pokemonToEdit.nome}</h2>

      <div style={{ textAlign: "center" }}>
        <Image
          alt={`Imagem do pokémon ${pokemonToEdit.nome}`}
          height={100}
          src={pokemonToEdit.img}
          width={100}
        />
      </div>

      <form action={updatePokemonHandler} className="create-pokemon-form">
        <section className="pokemon-input">
          <input
            aria-label="Nome do Pokémon"
            defaultValue={pokemonToEdit.nome}
            id="nome"
            name="nome"
            type="text"
          />
        </section>

        <section className="pokemon-input">
          <input
            aria-label="Descrição do pokémon"
            defaultValue={pokemonToEdit.descricao}
            id="descricao"
            name="descricao"
            placeholder="Descrição do Pokémon"
            type="text"
          />
        </section>

        <section className="pokemon-input">
          <input
            aria-label="Link com Imagem do pokémon"
            defaultValue={pokemonToEdit.img}
            id="img"
            name="img"
            placeholder="Link com Imagem do Pokémon"
            type="text"
          />
        </section>
        <button>Atualizar</button>
      </form>
    </div>
  );
}
