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

e)

```js
db.orders.find({ _id: 65 });
```

f)

```js
db.orders.find(
  {
    "customer.first_name": "Christina",
    "customer.last_name": "Lee",
  },
  { _id: true },
);
```

g)

```js
db.orders.find({ payment_type: "Credit Card" }, { _id: true });
```

h)

```js
db.orders.find({ $or: [{ payment_type: "Credit Card" }, { shipping_fee: 0 }] }, { _id: true });
```

i)

```js
db.orders.find({ $and: [{ "customer.company": "Company D" }, { shipping_fee: { $gt: 0 } }] }, { _id: true });
```

j)

```js
db.orders.find({ payment_type: { $ne: "Cash" } }, { _id: true });
```

k)

```js
db.orders.find({ "details.product.product_name": "Northwind Traders Chai" }, { _id: true });
```

l)

```js
db.orders.find({ shipping_fee: { $gt: 0 } }, { _id: true });
```

m)

```js
db.orders.findOne({ "customer.company": "Company D" }, { _id: true });
```

n)

```js
db.orders.find({ _id: 50 });

db.orders.updateOne({ _id: 50 }, { $set: { payment_type: "Debit Card" } });

db.orders.find({ _id: 50 });
```

o)

```js
db.orders.updateMany(
  { "customer.company": "Company L" },
  {
    $set: {
      shipping_fee: 0,
    },
  },
);
```

p)

```js
db.orders.find({ shipped_date: { $exists: false } }, { _id: true });

db.orders.updateOne({ _id: 777 }, { $set: { shipped_date: new Date() } });

db.orders.find({ shipped_date: { $exists: false } }, { _id: true });
```

q)

```js
db.orders.updateOne(
  { _id: 65 },
  {
    $push: {
      details: {
        quantity: 2,
        unit_price: 18.5,
        discount: 0,
        status_id: 1,
        inventory_id: 999,
        product: {
          _id: 999,
          product_code: "NWTB-999",
          product_name: "Northwind Traders Lemon Tea",
          standard_cost: 13.5,
          list_price: 18.5,
          discontinued: false,
          category: "Beverages",
        },
      },
    },
  },
);
```

r)

```js
db.orders.findOne({ _id: 65 }, { taxes: true });

db.orders.updateOne({ _id: 65 }, { $unset: { taxes: "" } });

db.orders.findOne({ _id: 65 }, { taxes: true });
```

s)

```js
db.orders.deleteOne({ _id: 65 });

db.orders.findOne({ _id: 65 });
```

t)

```js
db.orders.find({ "customer.first_name": "Run", "customer.last_name": "Liu" }, { _id: true });

db.orders.deleteMany({ "customer.first_name": "Run", "customer.last_name": "Liu" });

db.orders.find({ "customer.first_name": "Run", "customer.last_name": "Liu" }, { _id: true });
```

u)

```js
db.orders.find({ shipping_fee: { $exists: false } }, { _id: true });

db.orders.deleteMany({ shipping_fee: { $exists: false } });

db.orders.find({ shipping_fee: { $exists: false } }, { _id: true });
```
