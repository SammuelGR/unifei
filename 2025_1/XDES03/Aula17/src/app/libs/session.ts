"use server";

import { jwtVerify, SignJWT } from "jose";
import { cookies } from "next/headers";

async function openSessionToken(token: string) {
  //Para que isso funcione é necessário criar o arquivo oculto ".env"
  //Coloque uma chave "TOKEN" e um valor aleatório para ela
  //Por exemplo pode usar o próprio node para isso diretamente no terminal. require('crypto').randomBytes(64).toString('hex').
  //Para acessar o terminal "node", digite "node".
  //Para retornar ao terminal bash, digite ".exit"
  const encodedKey = new TextEncoder().encode(process.env.TOKEN);
  //Aqui a lib "jose" irá verificar se há um token válido e extrair o payload (carga útil)
  try {
    const { payload } = await jwtVerify(token, encodedKey, {
      algorithms: ["HS256"],
    });
    return payload;
  } catch (e) {
    console.log("Erro ao verificar session token", e);
  }
}

export async function createSessionToken(userId: string, userEmail: string) {
  const encodedKey = new TextEncoder().encode(process.env.TOKEN);
  const expiresAt = Date.now() + 3600;

  //Cria  session. É feita uma "assinatura" do payload
  //Aqui também espeficifamos o algoritmo de criptografia como HS256
  const session = await new SignJWT({ userId, userEmail })
    .setProtectedHeader({
      alg: "HS256",
    })
    .setExpirationTime("1h") //Define um tempo para expirar
    .sign(encodedKey); //Assina o token

  //Seguindo a documentação do next, precisamos primeiro criar o cookieStore, pois é async
  const cookieStore = await cookies();

  //Através da cookieStore conseguimos buscar (get) e salvar (set) cookies no navegador.
  cookieStore.set("session", session, {
    expires: expiresAt * 1000,
    path: "/",
    httpOnly: true,
  });
}

export async function isSessionValid() {
  const sessionCookie = (await cookies()).get("session");

  if (sessionCookie) {
    const { value } = sessionCookie;
    const session = await openSessionToken(value);
    return session;
  }

  return false;
}

export async function deleteSessionCookie() {
  //Seguindo a documentação do next, precisamos primeiro criar o cookieStore, pois é async
  const cookieStore = await cookies();

  cookieStore.delete("session");
}
