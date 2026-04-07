-- Questão 1: Testando o ‘WITH GRANT OPTION’.

-- a) Crie um novo usuario no banco chamado ‘user1’ e dê a ele privilégios de CRUD
-- nas tabelas categories, customers e products. Utilize o ‘with grant option’.
CREATE USER user1 WITH PASSWORD '123123';

GRANT SELECT, INSERT, UPDATE, DELETE
    ON TABLE northwind.categories, northwind.customers, northwind.products
    TO user1
    WITH GRANT OPTION

-- b) Crie um novo usuario no banco chamado ‘user2’ e dê a ele privilégios de CRUD
-- nas tabelas orders e orderdetails. Utilize o ‘with grant option’.
CREATE USER user2 WITH PASSWORD '123123';

GRANT SELECT, INSERT, UPDATE, DELETE
    ON TABLE northwind.orders, northwind.order_details
    TO user2
    WITH GRANT OPTION

-- c) Crie um novo usuario no banco chamado ‘user3’ e dê a ele privilégios de SELECT
-- em todas as tabelas do schema northwind.
CREATE USER user3 WITH PASSWORD '123123';

GRANT SELECT ON ALL TABLES IN SCHEMA northwind WITH GRANT OPTION



----
-- u2 to u3
GRANT SELECT, INSERT, UPDATE, DELETE
    ON TABLE northwind.orders, northwind.order_details
    TO user3
    WITH GRANT OPTION

-- u1 to u2
GRANT SELECT, INSERT, UPDATE, DELETE
    ON TABLE northwind.categories, northwind.customers, northwind.products
    TO user2
    WITH GRANT OPTION

-----

GRANT CONNECT ON DATABASE northwind TO user2
GRANT USAGE ON SCHEMA northwind TO user2

-----


-- Questão 2: GRANT + VIEW

-- a) Escreva a view ordersBr que filtre os registros de compra do Brasil na tabela
-- orders.

CREATE VIEW northwind.ordersBr AS (
    SELECT * FROM northwind.orders WHERE shipcountry = 'Brazil'
)

-- b) Remova da role role_relatorios o privilégio de select na tabela orders
-- 💩
CREATE ROLE role_relatorios

-- c) Inclua na role_relatorios o privilégio de CRUD na view ordersBr

GRANT SELECT, INSERT, UPDATE, DELETE ON northwind.ordersBr TO role_relatorios

-- d) Acesse o banco como o usuário analista_bi e teste esses privilégios
-- 💩
CREATE USER analista_bi WITH PASSWORD '123123'

GRANT role_relatorios to analista_bi
GRANT CONNECT ON DATABASE northwind TO analista_bi
GRANT USAGE ON SCHEMA northwind TO analista_bi