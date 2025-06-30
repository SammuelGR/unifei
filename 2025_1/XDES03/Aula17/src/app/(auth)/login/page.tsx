'use client'

import '@/app/styles/login.css';
import Image from 'next/image';


import pokemonLogo from 'public/pokemon-logo.png';
import userIcon from 'public/user.png';
import passwordIcon from 'public/padlock.png';
import z from 'zod';
import toast from 'react-hot-toast';
import Link from 'next/link';
import { validateCredentials } from '@/app/libs/credentials';


export interface LoginCredentials {
    email: string,
    password: string
}

const LoginSchema = z.object({
    email: z.string().trim().email('Email com formato incorreto'),
    password: z.string({message: 'Insira uma senha'}).trim().min(2, {message: 'Senha requer no mínimo 2 caracteres'})
})

export default function LoginPage(){

    const loginAction = async (formData: FormData) => {

        const loginData: LoginCredentials = {
            email: formData.get('email') as string,
            password: formData.get('password') as string
        }

        const result = LoginSchema.safeParse(loginData);

        if(!result.success){

            let errorMsg = '';

            result.error.issues.forEach((issue) => {
                errorMsg = errorMsg + issue.message + '. ';
            });

            toast.error(errorMsg);

            return;
        }
        

        const loginValidacao = await validateCredentials(loginData);

        if(loginValidacao){
            toast.error(loginValidacao.error);
            return;
        }
        
    }


    return (
        <form className='login-form' action={loginAction}>

            <div>
                <Image 
                    src={pokemonLogo}
                    alt='Logo oficial do Pokémon'
                    className='form-image'
                />
            </div>
            <div>
                <section className="user-input">
                    <Image 
                        src={userIcon}
                        alt='Icone representando login de usuário(a)'
                    />
                    <input type="email" name="email" id="email" placeholder="Email" aria-label="Email" />
                </section>
                <section className="user-input">
                    <Image 
                        src={passwordIcon}
                        alt='Icone representando compo com senha'
                    />
                    <input type="password" name="password" id="password" placeholder="Senha" aria-label="Senha" />
                </section>
            </div>
            <button>Entrar</button>
            <div className='link-cadastrar'>
                Não tem conta? Clique <Link className='btn-criar-conta' href="/create">aqui</Link>
            </div>
        </form>
    )
}