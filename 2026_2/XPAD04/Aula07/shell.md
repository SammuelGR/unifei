### basics

```js
mongosh

show dbs
use db_name
db.dropDatabase()
```

### collections

```js
mongosh

show collections

db.createCollection('collection_name')
db.collection_name.drop()

db.collection_name.insertOne()
db.collection_name.insertMany()

db.collection_name.updateOne(<query>, {$set: {}}) // or $unset
db.collection_name.updateMany(<query>, {$set: {}}) // or $unset

db.collection_name.deleteOne({})
db.collection_name.deleteMany({})

db.collection_name.bulkWrite()
```

update and rename

```js
db.collection_name.updateMany(<query>, {$rename: {"old": "new"}})
```

### utils

```js
mongoimport --db=<db_name> --collection=<collection_name> --file=<file_name>
```

### queries

```js
db.collection_name.find({"field"}, {"show/hide"});
db.collection_name.find().pretty();
db.collection_name.findOne();
```

### nested docs

```js
db.collection.findOne({ "foo.bar": "value" });
```

### exercise

Selecionar o id dos pedidos que tenham o produto 48 e cuja
quantidade é maior que 10

```js
db.orders.find(
  {
    "details.product_id": 48,
    "details.quantity": { $gt: 10 },
  },
  { _id: true },
);
```

```js
db.employees.find({ _id: 7 });

db.employees.updateOne({ _id: 7 }, { $set: { state_province: "WA" } });
```

Alterar o unit_price do produto 48 nos pedidos

```js
db.orders.find({ "details.product_id": 48 });

db.orders.updateMany(
  { "details.product_id": 48 },
  {
    $set: {
      "details.$[].unit_price": 100.25,
    },
  },
);
```
