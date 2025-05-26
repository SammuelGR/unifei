import '../styles/CreateUser.css';
import {set, useForm} from 'react-hook-form';
import axios, * as others from 'axios';
import { useState } from 'react';
import { Link } from 'react-router-dom';

export default function CreateUser(){

    const [msg, setMsg] = useState();
    const [userCriado,setUserCriado] = useState(false);
    const form = useForm();

    const { register, control, handleSubmit, formState } = form;

    const {errors} = formState;

    const submit = async (data) => {
        
        try {
            const response = await axios.post('http://localhost:3000/create', data);
            setMsg(response.data);
            if(response.data.includes('sucesso'))
                setUserCriado(true);
        } catch (error) {
            setMsg(error.response.data);
        }   
        
        
    }

    return (
        <>
            <h2>Crie uma nova conta</h2>
            <form onSubmit={handleSubmit(submit)} noValidate>
                <label htmlFor="username" placeholder="usuário">Usuário</label>
                <input type="text" id="username" {...register('username')} />
                
                <label htmlFor="email" placeholder="email">Email</label>
                <input type="text" id="email" {...register('email')} />
                
                <label htmlFor="password">Senha</label>
                <input type="password" id="password" {...register('password')} />
                                
                <button>Criar Usuário</button>
            </form>

            <p className='server-response'>{msg}</p>
            <Link to="/"
            style={{visibility : userCriado ? 'visible' : 'hidden' }}
            >Fazer Login</Link>
            
        </>
    )

}