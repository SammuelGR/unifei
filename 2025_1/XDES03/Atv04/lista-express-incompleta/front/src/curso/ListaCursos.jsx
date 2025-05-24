import { useEffect, useState } from "react";
import Curso from "./Curso";
import axios, * as others from 'axios';
import '../styles/ListaCursos.css';
import { useForm } from "react-hook-form";
import Erro from "./Erro";

export default function ListaCursos(){

    const [curso, setCursos] = useState(<p>...</p>);
    const view = [];
    const [msg,setMsg] = useState(<p></p>);

    const form = useForm();
    const { register, handleSubmit } = form;

    
    const submit = async (data) => {
        let endPoint = 'http://localhost:3000/cursos';
        if(data.curso !== ' ') //buscar todas
            endPoint = `${endPoint}/${data.curso}`;
        try {
            const dados = await axios.get(`${endPoint}`);
            if(Array.isArray(dados.data)){
                for(let curso of dados.data){
                    view.push(<Curso curso={curso}/>)
                }
            }
            else{
                view.push(<Curso curso={dados.data}/>);
            }    
            setCursos(view);
            setMsg(<p></p>);
        } catch (error) {
            console.log(error);
            setMsg(<Erro msg={error.response.data}/>)
            setCursos(<p></p>);
        }        
    }

    return(
        <>  
            <h2>Busque o curso pelo nome ou deixe vazio para retornar todos.</h2>
            <form onSubmit={handleSubmit(submit)} noValidate>

                <label htmlFor="curso" placeholder="curso">Curso</label>
                <input type="text" id="curso" {...register('curso')} />
             
            <button>Listar</button>
            </form>
            {curso}
            {msg}
        </>   
    )
}