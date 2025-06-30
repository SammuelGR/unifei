
import ConexaoBD from "@/app/libs/conexao-bd";
import "@/app/styles/create-pokemon.css";
import { PokemonProps } from "@/app/ui/pokemon-card";
import Image from "next/image";
import { redirect } from "next/navigation";

const arquivo = 'pokemon-db.json';

interface EditPokemonProps{
    params: Promise<{id: string}>;
}

export default async function EditPokemon({params}: EditPokemonProps){

    const {id} = await params;
    
    const pokemonDB = await ConexaoBD.retornaBD(arquivo);

    const pokemonToEdit: PokemonProps = pokemonDB.find((p: PokemonProps) => p.id === id);
    const pokemonToEditIndex: number = pokemonDB.findIndex((p) => p.id === id);

    const updatePokemon = async (formData : FormData) => {
        'use server';

        //
        const updatedPokemon: PokemonProps = {
            id,
            nome: formData.get('nome') as string,
            descricao: formData.get('descricao') as string,
            img: formData.get('img') as string
        }

        pokemonDB.splice(pokemonToEditIndex,1,updatedPokemon);

        await ConexaoBD.armazenaBD(arquivo,pokemonDB);

        redirect('/dashboard');

    }


    return(
        <div className="create-pokemon-container">
            <h2>{pokemonToEdit.nome}</h2>
            <form action={updatePokemon} className="create-pokemon-form">
                    <Image src={pokemonToEdit.img}
                        alt=""
                        width={100}
                        height={100}
                        style={{margin: "0 auto"}}
                    /> 
                    <section className="pokemon-input">
                          <input type="text"
                            id="nome"
                            name="nome" 
                            placeholder="Nome do Pokémon"
                            defaultValue={pokemonToEdit.nome}
                            />
                    </section>
                    <section className="pokemon-input">
                          <input type="text"
                            id="descricao"
                            name="descricao" 
                            placeholder="Descrição do Pokémon"
                            defaultValue={pokemonToEdit.descricao}
                            />
                    </section>
                    <section className="pokemon-input">
                          <input type="text"
                            id="img"
                            name="img" 
                            placeholder="Imagem do Pokémon"
                            defaultValue={pokemonToEdit.img}
                            />
                    </section>
                    <button>Atualizar</button>

            </form>
        </div>
    )

}