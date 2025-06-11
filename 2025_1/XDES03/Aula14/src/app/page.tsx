import "@/app/page.css";

import Link from "next/link";

export default function Home() {
  return (
    <main>
      <h1>Bem vindo ao mundo do Pokemon</h1>

      <Link className="entrar" href="/dashboard">
        Entrar
      </Link>
    </main>
  );
}
