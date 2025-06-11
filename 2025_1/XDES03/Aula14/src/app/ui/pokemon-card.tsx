import Image from "next/image";
import "@/app/styles/pokemon-card.css";

export interface PokemonProps{
    id: string,
    nome: string,
    img: string,
    descricao: string,
}

export default function Pokemon(props: PokemonProps)
{

    return(
        <div className="pokemonCard">
            <h2>{props.nome}</h2>
            <Image
                src={props.img}
                width={200}
                height={200}
                alt={`Imagem do pokémon ${props.nome}`}
            />
            <p>{props.descricao}</p>
        </div>
    )

}