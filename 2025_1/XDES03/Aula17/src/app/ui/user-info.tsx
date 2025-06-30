import '@/app/styles/user-info.css';


export interface IUserInfo{
    userEmail: string
}

export default function UserInfo(userInfo: IUserInfo){

    const regex = /@.*/i;
    const atIndex = userInfo.userEmail.replace(regex,"");

    return(
        <p className='p'>Olá {atIndex}</p>
    )

}