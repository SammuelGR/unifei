-- Essa prática deve ser executada no SGBD PostgreSQL, utilizando o banco de dados
-- Northwind.
-- Questão 1: Testando o ‘WITH GRANT OPTION’.
-- a) Crie um novo usuario no banco chamado ‘user1’ e dê a ele privilégios de CRUD
-- nas tabelas categories, customers e products. Utilize o ‘with grant option’.
CREATE USER user1;
GRANT INSERT, SELECT, UPDATE, DELETE
    ON northwind.categories, northwind.customers, northwind.products
    TO user1
    WITH GRANT OPTION;

-- b) Crie um novo usuario no banco chamado ‘user2’ e dê a ele privilégios de CRUD
-- nas tabelas orders e orderdetails. Utilize o ‘with grant option’.
CREATE USER user2;
GRANT INSERT, SELECT, UPDATE, DELETE
    ON northwind.orders, northwind.order_details
    TO user2
    WITH GRANT OPTION;

-- c) Crie um novo usuario no banco chamado ‘user3’ e dê a ele privilégios de SELECT
-- em todas as tabelas do schema northwind.
CREATE USER user3;
GRANT SELECT ON ALL TABLES IN SCHEMA northwind TO USER3;

-- d) Agora, o user1 vai repassar os privilégios dele para o user3.
GRANT CONNECT ON DATABASE northwind TO user1;
GRANT USAGE ON SCHEMA northwind TO user1;

GRANT INSERT, SELECT, UPDATE, DELETE
    ON northwind.categories, northwind.customers, northwind.products
    TO user3
    WITH GRANT OPTION;

-- e) De forma análoga, o user2 repassará os privilégios dele para o user3.
GRANT CONNECT ON DATABASE northwind TO user2;
GRANT USAGE ON SCHEMA northwind TO user2;

GRANT INSERT, SELECT, UPDATE, DELETE
    ON northwind.orders, northwind.order_details
    TO user3
    WITH GRANT OPTION;

-- f) Qual o efeito das operações executadas nas letras d e e no banco?
-- 🤝 broderagem 🤝

-- g) Logado como postgres, remova os privilégios no user3. O que acontece? Como
-- resolver?
REVOKE SELECT ON ALL TABLES IN SCHEMA northwind FROM USER3;
-- O DBA consegue remover sua concessao, porém user3 continua com basicamente
-- os mesmos privilegios, que foram concedidos pelos outros usuarios

----------------------------------------------------------
-- Questão 2: GRANT + VIEW
-- a) Escreva a view ordersBr que filtre os registros de compra do Brasil na tabela
-- orders.
CREATE OR REPLACE VIEW northwind.ordersBr AS (
    SELECT * FROM northwind.orders WHERE shipcountry = 'Brazil'
);

-- b) Remova da role role_relatorios o privilégio de select na tabela orders
REVOKE SELECT ON TABLE northwind.orders FROM role_relatorios;

-- c) Inclua na role_relatorios o privilégio de CRUD na view ordersBr
GRANT INSERT, SELECT, UPDATE, DELETE
    ON northwind.ordersBr
    TO role_relatorios;

-- d) Acesse o banco como o usuário analista_bi e teste esses privilégios
INSERT INTO northwind.ordersBr VALUES (666,	'HANAR', 4, '1994-08-08 00:00:00', '1994-09-05 00:00:00', '1994-08-12 00:00:00', 65.8300, 'Hanari Carnes', 'Rua do Tormento, 67', 'Rio de Janeiro', 'RJ', '05454-876', 'Brazil');
SELECT * FROM northwind.ordersBr;
UPDATE northwind.ordersBr SET shipname = 'hormuzinados' WHERE orderid = 666;
DELETE FROM northwind.ordersBr WHERE orderid = 666;
----------------------------------------------------------
-- Questão 3 : GRANT + VIEW
-- a) Crie uma view chamada ‘relatorio’, sobre as tabelas Orders e OrderDetails, cujo
-- resultado seja idêntico à figura 1. Onde:
-- • Total_produtos é a total de produtos comprados no pedido
-- • Total_pedido é a soma dos valores de todos os produtos comprados
CREATE OR REPLACE VIEW northwind.relatorio AS (
    SELECT o.orderid, o.customerid, o.employeeid, COUNT(o.orderid) AS total_produtos, SUM(d.unitprice) as total_pedido
        FROM northwind.orders o JOIN northwind.order_details d
        ON o.orderid = d.orderid
        GROUP BY o.orderid
);

-- b. Conceda o privilégio de leitura sobre a View para a role role_relatorios.
GRANT SELECT ON northwind.relatorio TO role_relatorios;

-- c. Inclua na role_relatorios os privilégios que achar conveniente
-- 😴

-- d. Acesse o banco como o usuário analista_bi e teste esses privilégios
-- como a view não é atualizável, não é possível conceder nenhum privilégio
-- além da leitura.
