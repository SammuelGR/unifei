
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

    

    return(
        <div className="create-pokemon-container">
            <h2>{pokemonToEdit.nome}</h2>
            <form className="create-pokemon-form">
                    
                    <button>Atualizar</button>

            </form>
        </div>
    )

}