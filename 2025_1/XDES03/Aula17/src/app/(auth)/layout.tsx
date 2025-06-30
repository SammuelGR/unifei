export default function AuthLayout({ children }: { children: React.ReactNode }) {
  return (
  
    <main>
      <h1>Bem vindo ao Mundo do Pokémon</h1>
      {children}
    </main>

  );
}