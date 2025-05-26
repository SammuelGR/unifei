import '../styles/Cursos.css';
export default function Curso({curso}){

    return (
        <ul>
            <h2>{curso.nome}</h2>
            <li>Duração: {curso.duracao}</li>
            <li>Período: {curso.periodo}</li>
        </ul>
    )
}