import React from 'react'
import ReactDOM from 'react-dom/client'
import App from './App.jsx'
import './index.css'

//Configuracoes do React Router (npm install react-router-dom)
import {createBrowserRouter, RouterProvider} from 'react-router-dom';
//Importando rotas
import Login from './login/Login.jsx';
import CreateUser from './login/CreateUser.jsx';
import ListaCursos from './curso/ListaCursos.jsx';
//Adicionando as rotas
const router = createBrowserRouter([
  {
    path: '/', //pagina home é para logar
    element: <App />,
    children: [
      {
        path: '/',
        element: <Login />
      },
      {
        path: 'criar-user',
        element: <CreateUser />
      }   
    ]
  },
  {
    path: 'cursos',
    element: <ListaCursos />
  },
  {
    path: 'cursos/:nome',
    element: <ListaCursos />
  }
]);

ReactDOM.createRoot(document.getElementById('root')).render(
  <React.StrictMode>
    <RouterProvider router={router}/>
  </React.StrictMode>,
)