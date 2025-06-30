import { NextRequest, NextResponse } from "next/server";

import { isSessionValid } from "@/app/libs/session";

//regex retirada diretamente da documentação do NextJS
export const config = {
  // https://nextjs.org/docs/app/building-your-application/routing/middleware#matcher
  matcher: ["/((?!api|_next/static|_next/image|.*\\.png$).*)"],
};

const publicRoutes = ["/", "/login", "/create"];

export async function middleware(req: NextRequest) {
  const pathname = req.nextUrl.pathname;

  //verificar se a requisicao possui credenciais validas para criar uma session
  const session = await isSessionValid();

  if (publicRoutes.includes(pathname) && session) {
    return NextResponse.redirect(new URL("/dashboard", req.nextUrl));
  }

  if (!session && !publicRoutes.includes(pathname)) {
    return NextResponse.redirect(new URL("/login", req.nextUrl));
  }

  return NextResponse.next();
}
