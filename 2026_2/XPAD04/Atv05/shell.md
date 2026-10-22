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

6. O sistema precisa buscar apenas produtos que possuam a expressão exata
   "cancelamento ativo de ruído". Como deve ser formatada a string de busca
   dentro do $text para garantir a correspondência da frase exata?

```js
db.produtos.find({
  $text: {
    $search: '"cancelamento ativo de ruído"',
  },
});
```

7. Execute uma busca textual por "notebook gamer com alta performance"
   ordenando os resultados da maior para a menor relevância utilizando o
   textScore ($meta).

```js
db.produtos
  .find(
    {
      $text: { $search: "notebook gamer com alta performance" },
    },
    { score: { $meta: "textScore" } },
  )
  .sort({ score: { $meta: "textScore" } });
```

8. Um usuário digitou erroneamente "smartfon" no campo de busca do aplicativo.
   Utilizando o estágio $search no aggregate com a opção fuzzy (maxEdits: 2),
   escreva uma busca que localize os celulares e dispositivos correspondentes
   mesmo com o erro de digitação.

```js
db.produtos.createSearchIndex("produtos_search_idx", {
  mappings: {
    dynamic: false,
    fields: {
      nome: [{ type: "string" }, { type: "autocomplete" }],
      categorias: [{ type: "string" }, { type: "autocomplete" }],
      descricao: { type: "string" },
    },
  },
});
```

```js
db.produtos.aggregate([
  {
    $search: {
      index: "produtos_search_idx",
      compound: {
        should: [
          {
            autocomplete: {
              fuzzy: { maxEdits: 2 },
              path: "nome",
              query: "smartfon",
            },
          },
          {
            autocomplete: {
              fuzzy: { maxEdits: 2 },
              path: "categorias",
              query: "smartfon",
            },
          },
          {
            text: {
              fuzzy: { maxEdits: 2 },
              path: "descricao",
              query: "smartfon",
            },
          },
        ],
      },
    },
  },
]);
```

9. Construa uma busca usando o operador compound dentro do $search para
   atender aos seguintes requisitos de um filtro de e-commerce:
   a. must: O campo descricao deve obrigatoriamente conter a palavra "sem
   fio" ou "bluetooth".
   b. mustNot: Não deve trazer produtos da categoria "wearables".
   c. should: Se a descrição contiver a palavra "cancelamento", o produto
   deve receber destaque (maior searchScore).

```js
db.produtos.aggregate([
  {
    $search: {
      index: "produtos_search_idx",
      compound: {
        must: [
          {
            phrase: {
              path: "descricao",
              query: ["sem fio", "bluetooth"],
            },
          },
        ],
        mustNot: [
          {
            text: {
              path: "categorias",
              query: "wearables",
            },
          },
        ],
        should: [
          {
            text: {
              path: "descricao",
              query: "cancelamento",
            },
          },
        ],
      },
    },
  },
]);
```
