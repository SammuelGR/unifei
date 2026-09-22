Questão 1

a)

```js
db.orders.aggregate([{ $group: { _id: "$ship_city", total: { $count: {} } } }, { $sort: { total: -1 } }]);
```

b)

```js
db.orders.aggregate([{ $sortByCount: "$ship_city" }]);
```

c)

```js
db.orders.aggregate([
  { $sample: { size: 10 } },
  { $project: { _id: 1, order_date: 1, ship_city: 1, "customer.company": 1, "employee.address": 1 } },
  { $out: "teste" },
]);
```

d)

```js
db.orders
  .find(
    { order_date: { $gte: ISODate("2006-01-01"), $lt: ISODate("2006-02-01") } },
    { _id: 1, order_date: 1, ship_name: 1, ship_city: 1, payment_type: 1 },
  )
  .sort({ order_date: 1 });
```

e)

```js
db.orders.aggregate([
  { $match: { order_date: { $gte: ISODate("2006-01-01"), $lt: ISODate("2006-02-01") } } },
  { $project: { _id: 1, order_date: 1, ship_name: 1, ship_city: 1, payment_type: 1 } },
  { $sort: { order_date: 1 } },
]);
```

f)

```js
db.orders.aggregate([
  { $unwind: "$details" },
  {
    $project: {
      _id: 1,
      nome_produto: "$details.product.product_name",
      quantidade: "$details.quantity",
      preco_unitario: "$details.unit_price",
      total_item: { $multiply: ["$details.unit_price", "$details.quantity"] },
    },
  },
]);
```

g)

```js
db.orders.aggregate([
  { $unwind: "$details" },
  {
    $project: {
      _id: 1,
      total_item: { $multiply: ["$details.unit_price", "$details.quantity"] },
      nome_produto: "$details.product.product_name",
      quantidade: "$details.quantity",
      preco_unitario: "$details.unit_price",
    },
  },
  { $match: { total_item: { $gt: 500 } } },
]);
```

h)

```js
db.orders.aggregate([
  { $unwind: "$details" },
  {
    $project: {
      _id: 1,
      total_produto: { $multiply: ["$details.quantity", "$details.unit_price"] },
    },
  },
  { $group: { _id: "$_id", total_pedido: { $sum: "$total_produto" } } },
  { $sort: { total_pedido: -1, _id: -1 } },
]);
```

i)

```js
db.orders.aggregate([
  { $unwind: "$details" },
  {
    $project: {
      _id: 1,
      nome_produto: "$details.product.product_name",
      quantidade: "$details.quantity",
      preco_unitario: "$details.unit_price",
      total_item: { $multiply: ["$details.unit_price", "$details.quantity"] },
    },
  },
  { $count: "quantidade_registros" },
]);

db.orders.countDocuments();
```
