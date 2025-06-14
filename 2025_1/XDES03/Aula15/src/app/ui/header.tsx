
import pokeLogo from 'public/pokemon-logo.png';
import Image from 'next/image'

import "@/app/styles/header.css";
import React from 'react';

export default async function Header(){

    return(
        <header>
            <section className='section'>
            <Image className='img-logo' src={pokeLogo} alt='Logo do pokémon'/>
            <nav>
                <ul className='ul-right-side'>
                <li><a href="https://pokeapi.co/?ref=public-apis" target='_blank'>Poké API</a></li>
                <li><a href="https://www.pokemon.com/br" target='_blank'>Página Oficial</a></li>
                </ul>
            </nav>
            </section>
            <nav className='nav'>
            </nav>
        </header>
    )
}