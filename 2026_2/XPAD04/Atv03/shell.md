Questão 1

```js
mongoimport --db=xpad04_atv03 --collection=orders --file=./ordersCompleto.json --jsonArray
```

Questão 2

a)

```js
db.orders.insertOne({
  order_date: new Date(),
  ship_name: "Alien Nigena",
  shipping_fee: 12.5,
  payment_type: "Credit Card",
  status_id: 0,
  customer: {
    company: "Company X",
    first_name: "Alien",
    last_name: "Nigena",
  },
});
```

b)

```js
db.orders.insertMany([
  {
    order_date: new Date(),
    ship_name: "Cliente Da Silva",
    shipping_fee: 12.5,
    payment_type: "Credit Card",
    status_id: 0,
    customer: {
      company: "Company X",
      first_name: "Cliente",
      last_name: "Silva",
    },
  },
  {
    order_date: new Date(),
    ship_name: "Fidelizado Souza",
    shipping_fee: 12.5,
    payment_type: "Credit Card",
    status_id: 0,
    customer: {
      company: "Company X",
      first_name: "Fidelizado",
      last_name: "Souza",
    },
  },
]);
```

c)

```js
db.orders.insertOne({
  _id: 777,
  customer: {
    first_name: "Apenas",
    last_name: "Essencial",
  },
  order_date: new Date(),
});
```

d)

```js
db.orders.find();
```
