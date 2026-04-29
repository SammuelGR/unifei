-- Nonrepeatable read
--TRANSAÇÃO 1
START TRANSACTION ISOLATION LEVEL REPEATABLE READ;
UPDATE northwind.categories SET description = 'banana' WHERE categoryid = 4;
SELECT * FROM northwind.categories WHERE categoryid = 4;
COMMIT

--TRANSAÇÃO 2
START TRANSACTION ISOLATION LEVEL REPEATABLE READ;
SELECT * FROM northwind.categories WHERE categoryid = 4;
SELECT * FROM northwind.categories WHERE categoryid = 4;
COMMIT

--Phanton Read
--TRANSAÇÃO 1
START TRANSACTION ISOLATION LEVEL REPEATABLE READ;
INSERT INTO northwind.categories VALUES (100, 'Teste', 'teste');
SELECT * FROM northwind.categories;
COMMIT

--TRANSAÇÃO 2
START TRANSACTION ISOLATION LEVEL REPEATABLE READ;
SELECT * FROM northwind.categories;
SELECT * FROM northwind.categories;
COMMIT

DELETE FROM northwind.categories WHERE categoryid = 100

--SERIALIZATION ANOMALY
--TRANSAÇÃO 1
START TRANSACTION ISOLATION LEVEL Serializable;
SELECT SUM(unitprice) FROM northwind.order_details WHERE orderid=10248;
INSERT INTO northwind.order_details VALUES(10249, 10, 50, 10, 0);
COMMIT

DELETE FROM northwind.order_details WHERE orderid = 10249 and productid = 10

--TRANSAÇÃO 2
START TRANSACTION ISOLATION LEVEL Serializable;
SELECT SUM(unitprice) FROM northwind.order_details WHERE orderid=10249;
INSERT INTO northwind.order_details VALUES(10248, 10, 50, 10, 0);
COMMIT


DELETE FROM northwind.order_details WHERE orderid = 10248 and productid = 10
