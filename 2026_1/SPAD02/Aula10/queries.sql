-- Questão 1: Crie uma transação que permita cancelar um pedido de um cliente. O
-- cancelamento deve excluir os itens do pedido da tabela order_details e depois remover
-- o pedido da tabela orders.

BEGIN;

DELETE FROM northwind.order_details WHERE orderid = 666;

DELETE FROM northwind.orders WHERE orderid = 666;

COMMIT;

-- Questão 2 : Crie uma transação que aumente o salário de todos os funcionários de um
-- determinado país na tabela employees.

-- ??????????????????????????????? nao tem salario no banco!!!!!!!!!!!!!!

UPDATE northwind.employees
SET salario = salario * 1.1
WHERE country = MAC;

-- Questão 3 : Um gerente de vendas decidiu reajustar os preços dos produtos de uma
-- determinada categoria em 10%. Além disso, os pedidos que contêm esses produtos e
-- foram realizados a partir de uma data específica também devem refletir esse novo
-- preço. Implemente uma transação que:
-- • Atualize os preços dos produtos de uma categoria específica, aumentando-os em
-- 10%.
-- • Atualize os preços dos itens nos pedidos que contêm esses produtos, mas apenas
-- para pedidos realizados a partir de uma data informada.

BEGIN;

UPDATE northwind.products
SET unitprice = unitprice * 1.1
WHERE categoryid = 666;

UPDATE northwind.order_details
SET unitprice = unitprice * 1.1
WHERE (productid, orderid) IN (
    SELECT p.productid, o.orderid
	FROM northwind.products p
        JOIN northwind.order_details d ON p.productid = d.productid
        JOIN northwind.orders o ON o.orderid = d.orderid
	WHERE p.categoryid = 666 AND o.orderdate > date('2006-06-06')
);

COMMIT;

