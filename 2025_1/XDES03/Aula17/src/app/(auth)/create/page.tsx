'use client';

import Image from "next/image";
import userIcon from "public/user.png";
import passwordIcon from "public/padlock.png";
import pokeLogo from "public/pokemon-logo.png";

import '@/app/styles/login.css';
import {z} from "zod"; //import do zod para apoio nas validações do front: npm i zod 
import toast from 'react-hot-toast'; //import do react-hot-toast:  npm i react-hot-toast
import { createUser } from "@/app/libs/credentials";
import { LoginCredentials } from "../login/page";
import { redirect } from "next/navigation";


//Criação do schema para colocarmos as regras de validação do zod para os campos de createUser
//Retirado diretamente da documentação do "zod" em https://zod.dev/
const CreateUserSchema = z.object({
    email: z.string().trim().email('Email com formato incorreto'),
    password: z.string({message: 'Insira uma senha'}).trim().min(4, {message: 'Senha precisa no mínimo 4 caracteres'}),
    confPassword: z.string({message: 'Insira uma confirmação de senha'}).trim().min(1, {message: 'Confirmar Senha não pode ser vazia'}),
}).refine((data) => data.password === data.confPassword, {
    message: "Senhas não conferem",
    path: ["confPassword"]
});


export default function CreateUser(){

    const createUserClient = async (formData: FormData) =>{

        const createUserData = {
            email: formData.get('email') as string,
            password: formData.get('password') as string,
            confPassword: formData.get('conf-password') as string
        }

        const result = CreateUserSchema.safeParse(createUserData);

         if(!result.success){

            let errorMsg = "";

            //Acumulando todas as mensagens de error
            //Retirado da documentação do zod: https://www.zod.dev
            result.error.issues.forEach((issue) => {
                errorMsg = errorMsg + issue.message + '. ';
            })
            //Passa a mensagem de erro para o "toast" mostrar para o usuário
            toast.error(errorMsg);
            return;
        }

        const retorno = await createUser(createUserData as LoginCredentials);

        if(retorno.error){
            toast.error(retorno.error);
            return;
        }else if(retorno.success){
            toast.success(retorno.success);
            redirect('/login');
        }
    }
        

    return(
        <form action={createUserClient} className="login-form">
            <div>
                <Image className="form-image" src={pokeLogo} alt="pokémon logo" />
            </div>
            <div>
                <section className="user-input">
                    <Image src={userIcon} alt="user icon"/>
                    <input type="email" name="email" id="email" placeholder="Email" aria-label="Email" required/>
                </section>

                <section className="user-input">
                    <Image src={passwordIcon} alt="user icon"/>
                    <input type="password" name="password" id="password" placeholder="Senha" aria-label="Senha" required/>
                </section>

                <section className="user-input">
                    <Image src={passwordIcon} alt="user icon"/>
                    <input type="password" name="conf-password" id="conf-password" placeholder="Confirmar Senha" aria-label="Confirmar Senha" required/>
                </section>
            </div>    
            <button>Cadastrar</button>
        </form>
    )
}