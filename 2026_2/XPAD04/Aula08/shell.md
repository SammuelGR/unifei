Mostrar o `id` e o `order_date` dos pedidos realizados pelo funcionário 4.

`$match`, `$project`

```js
db.orders.aggregate([{ $match: { customer_id: 4 } }, { $project: { order_date: true } }]);
```

Total de pedidos por cliente.

`$group`, `$count`

```js
db.orders.aggregate([
  {
    $group: {
      _id: "$customer_id",
      total: { $count: {} },
    },
  },
  { $sort: { total: -1, _id: 1 } },
]);
```

```js
db.orders.aggregate([{ $sortByCount: "$customer_id" }]);
```

Criar um índice sobre o atributo customer_id da coleção orders.

```js
db.orders.createIndex({ customer_id: 1 });
```

Verificar com getIndexes.

```js
db.orders.getIndexes();
```

Realizar a consulta nos pedidos que tem o customer_id
igual a 4.

```js
db.orders.find({ customer_id: 4 }).explain("executionStats");
```

Apagar o índice sobre o atributo customer_id.

```js
db.orders.dropIndex({ customer_id: 1 });

db.orders.getIndexes();
```
