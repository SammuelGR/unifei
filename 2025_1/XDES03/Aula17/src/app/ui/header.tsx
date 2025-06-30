import pokeLogo from 'public/pokemon-logo.png';
import Image from 'next/image'

import "@/app/styles/header.css";
import React from 'react';
import { isSessionValid } from '../libs/session';
import LogoutButton from './logout-btn';
import UserInfo from './user-info';

export default async function Header(){

    //verifica se user esta logado
    const isLogged = await isSessionValid();
    let userEmail: string = "";
    if(isLogged)
    {
        userEmail = isLogged?.userEmail as string;
    }
   
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
            <section className='user-info-logout'>
                {isLogged && <UserInfo userEmail={userEmail}/>}
                {isLogged && <LogoutButton/>}
            </section>
            
        </header>
    )
}