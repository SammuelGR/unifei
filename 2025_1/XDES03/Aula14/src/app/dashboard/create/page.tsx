import "@/app/styles/create-pokemon.css";

import { redirect } from "next/navigation";

import ConexaoBD from "@/app/libs/conexao-bd";
import { PokemonProps } from "@/app/ui/pokemon-card";

const arquivo = "pokemon-db.json";

export default function CreatePokemon() {
  const addPokemon = async (formData: FormData) => {
    "use server";

    const newPokemon: PokemonProps = {
      id: crypto.randomUUID(),
      nome: formData.get("nome") as string,
      descricao: formData.get("descricao") as string,
      img: formData.get("img") as string,
    };

    const currentPokemons = await ConexaoBD.retornaBD(arquivo);

    await ConexaoBD.armazenaBD(arquivo, [...currentPokemons, newPokemon]);

    redirect("/dashboard");
  };

  return (
    <section className="create-pokemon-container">
      <h2>Inserir Novo Pokémon</h2>

      <form action={addPokemon} className="create-pokemon-form">
        <section className="pokemon-input">
          <input
            aria-label="Nome do Pokemon"
            id="nome-input"
            name="nome"
            placeholder="Nome do Pokemon"
            type="text"
          />
        </section>

        <section className="pokemon-input">
          <input
            aria-label="Descricao do Pokemon"
            id="descricao-input"
            name="descricao"
            placeholder="Descricao do Pokemon"
            type="text"
          />
        </section>

        <section className="pokemon-input">
          <input
            aria-label="Url com imagem do Pokemon"
            id="img-input"
            name="img"
            placeholder="Url com imagem do Pokemon"
            type="text"
          />
        </section>

        <button type="submit">Adicionar</button>
      </form>
    </section>
  );
}
