SELECT * FROM northwind.orders
EXPLAIN ANALYZE SELECT * FROM northwind.orders
EXPLAIN ANALYZE SELECT * FROM northwind.orders WHERE shipname = 'Simons bistro'

CREATE INDEX ord_shipname ON northwind.orders (shipname)
EXPLAIN ANALYZE SELECT * FROM northwind.orders WHERE shipname = 'Simons bistro'

SELECT * FROM northwind.products
EXPLAIN ANALYZE SELECT * FROM northwind.products WHERE productname = 'Tofu'
CREATE INDEX prod_name ON northwind.products (productname)
EXPLAIN ANALYZE SELECT * FROM northwind.products WHERE productname = 'Tofu'

EXPLAIN (FORMAT JSON) SELECT * FROM northwind.orders WHERE shipname = 'Simons bistro'