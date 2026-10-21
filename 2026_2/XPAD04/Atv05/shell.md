```js
mongoimport --db=xpad04_atv05 --collection=produtos --file=./produtos_ecommerce.json --jsonArray
```

1. O departamento de marketing deseja listar todos os itens classificados
   exatamente na categoria "gamer". Escreva uma consulta utilizando find().

```js
db.produtos.find({ categorias: "gamer" });
```

2. Um cliente buscou no campo de pesquisa rápida pela palavra "fone". Utilize o
   operador $regex para buscar produtos onde a palavra "fone" apareça na
   descricao ou no nome, garantindo que a busca seja insensível a
   maiúsculas/minúsculas.

```js
db.produtos.find({ $or: [{ descricao: /\bfone\b/i }, { nome: /\bfone\b/i }] });
```

3. Escreva uma consulta com Regex para encontrar produtos cujo nome comece
   com a palavra "Smart".

```js
db.produtos.find({ nome: /^Smart/ });
```

4. Para permitir buscas textuais eficientes em todo o catálogo, crie um índice de
   texto (text index) composto pelos campos nome, categorias e descricao. Defina
   o idioma padrão do índice como "portuguese".

```js
db.produtos.createIndex(
  {
    nome: "text",
    categorias: "text",
    descricao: "text",
  },
  { default_language: "portuguese" },
);
```

5. Realize uma consulta utilizando $text procurando por "monitor para jogos".

```js
db.produtos.find({
  $text: { $search: "monitor para jogos" },
});
```
