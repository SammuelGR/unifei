import './styles/CreateUser.css';

//imagens
import logoImc from './assets/logo-imc.png';
import logoUnifei from './assets/logo-unifei.png';

//Ponto onde as paginas serão inseridas
import { Outlet } from 'react-router-dom'

function App() {

  return (
    <>
      <section className='LoginUser'>
        <header className='titulo'>
            <img src={logoImc}/>
            <h1>Bem vindo ao sistema de cadastro da UNIFEI</h1>
            <img src={logoUnifei}/>
        </header>
        <Outlet/>
    </section>
    </>
  )
}

export default App