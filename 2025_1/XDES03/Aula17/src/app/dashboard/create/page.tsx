

import ConexaoBD from "@/app/libs/conexao-bd";
import "@/app/styles/create-pokemon.css";
import { PokemonProps } from "@/app/ui/pokemon-card";
import { redirect } from "next/navigation";

const arquivo = 'pokemon-db.json';

export default function CreatePokemon(){
    
    const addPokemon = async (formData: FormData) => {
        "use server";

        const novoPokemon : PokemonProps = {
            id: crypto.randomUUID(),
            nome: formData.get('nome') as string,
            descricao : formData.get('descricao') as string,
            img : formData.get('img') as string
        }

        const pokemonDb = await ConexaoBD.retornaBD(arquivo);
        pokemonDb.push(novoPokemon);
        await ConexaoBD.armazenaBD(arquivo,pokemonDb);
        redirect('/dashboard');
    }


    return(
        <section className="create-pokemon-container">
            <h2>Inserir Novo Pokémon</h2>
            <form action={addPokemon} className="create-pokemon-form">
                <section className="pokemon-input">
                    <input type="text"
                        id="nome"
                        name="nome" 
                        placeholder="Nome do Pokémon"
                        aria-label="Nome do Pokémon"
                        />
                </section>
                <section className="pokemon-input">
                    <input type="text"
                        id="descricao"
                        name="descricao" 
                        placeholder="Descrição do Pokémon"
                        aria-label="Descrição do pokémon"
                        />
                </section>
                <section className="pokemon-input">
                    <input type="text"
                        id="img"
                        name="img" 
                        placeholder="Link com Imagem do Pokémon"
                        aria-label="Link com Imagem do pokémon"
                        />
                </section>
                <button>Adicionar</button>
            </form>
        </section>
    );

}