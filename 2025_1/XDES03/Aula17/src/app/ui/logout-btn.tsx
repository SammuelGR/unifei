
import '@/app/styles/logout.css';
import { redirect } from "next/navigation";
import { deleteSessionCookie } from "../libs/session"

export default function LogoutButton(){

    const logout = async () => {
        'use server';
        await deleteSessionCookie();
        redirect('/login');
    }

    return(
        <form action={logout} className='logoutForm'>
            <button>Logout</button>
        </form>
    )
    
}