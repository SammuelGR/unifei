import '../styles/CreateUser.css';
import {useForm} from 'react-hook-form';
import axios, * as others from 'axios';
import { useState } from 'react';
import { Link, Navigate } from 'react-router-dom';


export default function Login(){

    const [msg, setMsg] = useState(' ');

    const form = useForm();

    const { register, handleSubmit, formState } = form;

    const {errors} = formState;

    const submit = async (data) => {
        
        try {
            const response = await axios.post('http://localhost:3000/login', data);
            setMsg(response.data);
        } catch (error) {
            setMsg(error.response.data);
        }   
        
    }

    if(msg.includes('Autenticado')){
        return <Navigate to='/cursos' />
    }

    return (
        <>  
            <h2>Entre para acessar os serviços</h2>
            <form onSubmit={handleSubmit(submit)} noValidate>

                <label htmlFor="email" placeholder="email">Email</label>
                <input type="text" id="email" {...register('email')} />
                
                <label htmlFor="password">Senha</label>
                <input type="password" id="password" {...register('password')} />
                
                <button>Entrar</button>
            </form>
            <p className="server-response">{msg}</p>
            <div className="realizar-cadastro">
                Não possui conta? 
                <Link to="/criar-user">Cadastro</Link>
            </div>
        </>
    )
}