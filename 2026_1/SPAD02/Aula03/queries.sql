-- Questão 1: Restaure o banco de dados Northwind.

-- Questão 2 : Criação de usuário no banco de dados.
-- a) Crie um usuário com seu nome e senha
CREATE USER nwdsam WITH PASSWORD '123123';

-- b) Simule falhas de conexão
-- c) Faça login com esse novo usuário
-- d) Faça um select na tabela categorias
SELECT * FROM northwind.categories

-- e) Faça um insert na tabela categorias
INSERT INTO northwind.categories  VALUES (9, 'Liquids', 'Liquids categories')

-- Questão 3: Criação de Role Programadores
-- A empresa Northwind Traders contratou uma nova equipe de desenvolvedores. Você,
-- como DBA, deve configurar uma Role de Grupo chamada role_programadores para que
-- eles possam trabalhar no banco de dados, seguindo estritamente o Princípio do
-- Privilégio Mínimo.

CREATE ROLE role_programadores

-- Especificações da Role: role_programadores
-- • Permitir que a role se conecte ao banco northwind
GRANT CONNECT ON DATABASE northwind TO role_programadores

-- • Permitir que a role acesse o esquema northwind
GRANT USAGE ON SCHEMA northwind TO role_programadores

-- • Conceder acesso de apenas leitura para as tabelas: products, categories e
-- suppliers
GRANT SELECT ON TABLE northwind.products, northwind.categories, northwind.suppliers TO role_programadores

-- • Permitir que a role_programadores execute INSERT e UPDATE na tabela
-- products
GRANT INSERT, UPDATE ON TABLE northwind.products TO role_programadores

-- • Bloquear o acesso a tabela employees // ✅
-- • Proibir o DELETE na tabela products. // ✅

-- Questão 4: Concedendo privilégios ao usuário.
-- a) Considere que o usuário que você criou na questão 2 é um usuário do tipo
-- ‘programador’. Insira ele na role criada na questão 3.
GRANT role_programadores TO nwdsam

-- b) Verifique o que é possível realizar no banco
SELECT * FROM northwind.products -- ✅
SELECT * FROM northwind.categories -- ✅
SELECT * FROM northwind.suppliers -- ✅
INSERT INTO northwind.categories  VALUES (9, 'Liquids', 'Liquids categories') -- ❌
UPDATE northwind.products SET unitsinstock = 31 WHERE productid = 77 -- ✅

-- c) Simule falhas associadas a falta de privilégios por esse usuário.
-- d) Qual comportamento as consultas abaixo geram?
-- a. UPDATE northwind.products SET unitprice = 20 WHERE productid = 1;
-- b. DELETE FROM northwind.products WHERE productid = 1;
-- c. CREATE TABLE northwind.temp_teste_produtos ( id serial PRIMARY KEY,
-- nome_teste varchar(50) );