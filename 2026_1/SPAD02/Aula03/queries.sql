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

-- • Bloquear o acesso a tabela employees ✅
-- • Proibir o DELETE na tabela products. ✅

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
    -- a. UPDATE northwind.products SET unitprice = 20 WHERE productid = 1; ✅
    -- b. DELETE FROM northwind.products WHERE productid = 1; ❌
    -- c. CREATE TABLE northwind.temp_teste_produtos ( id serial PRIMARY KEY,
    -- nome_teste varchar(50) ); ❌

-- Questão 5: Criação de Role Relatórios
-- A diretoria da Northwind contratou um analista de dados. Ele precisa extrair indicadores
-- de desempenho, mas jamais pode alterar um único dado ou ver informações privadas
-- de funcionários.

CREATE ROLE role_relatorios
-- Especificações da Role: role_relatorios
-- • Permitir que a role se conecte ao banco northwind
GRANT CONNECT ON DATABASE northwind TO role_relatorios

-- • Permitir que a role acesse o esquema northwind
GRANT USAGE ON SCHEMA northwind TO role_relatorios

-- • O analista deve conseguir ler todas as tabelas do schema
GRANT SELECT ON ALL TABLES IN SCHEMA northwind TO role_relatorios
REVOKE SELECT ON TABLE northwind.employees FROM role_relatorios

-- • A role não pode ter permissão de INSERT, UPDATE ou DELETE em nenhuma
-- hipótese. ✅

-- • Criar o usuário analista_bi e vinculá-lo a esta role.
CREATE USER analista_bi WITH PASSWORD '123'
GRANT role_relatorios TO analista_bi

-- Questão 6: Atualização de Schema
-- a. Volte no perfil DBA (usuário postgres) e crie a tabela abaixo
CREATE TABLE northwind.promocoes
( id serial PRIMARY KEY, nome_promo varchar(50) );

-- b. Logue no banco como o usuário analista_bi ✅
-- c. Qual comportamento as consultas abaixo geram?
    -- a. Selecionar os 10 primeiros registros da tabela produtos
    SELECT * FROM northwind.products LIMIT 10 -- ✅

    -- b. Selecionar todos os registros da tabela northwind.promocoes
    SELECT * FROM northwind.promocoes -- ❌
    -- permission denied pois a tabela foi criada após o grant

-- Questão 7: Avaliando privilégios do usuário.
select * from information_schema.role_table_grants where grantee= 'role_relatorios'; -- a)
select * from information_schema.role_table_grants where grantee= 'analista_bi'; -- b)
SELECT * FROM pg_roles -- c)
-- • Anotar o id de analista_bi e role_relatorios
-- 16677, 16676

SELECT * FROM pg_auth_members -- d)
GRANT DELETE ON northwind.products TO analista_bi -- e)
select * from information_schema.role_table_grants where grantee= 'analista_bi'; -- f)

SELECT r.rolname as usuario, g.rolname as grupo
    FROM pg_auth_members m
    JOIN pg_roles r ON m.member = r.oid
    JOIN pg_roles g ON m.roleid = g.oid
    WHERE r.rolname = 'analista_bi';

-- Questão 8: Removendo privilégios do usuário.
-- a. Remova da role 'programadores' o privilégio de inserir novos produtos no banco
REVOKE INSERT ON TABLE northwind.products FROM role_programadores

-- b. Teste a remoção do privilégio.
INSERT INTO northwind.products
	VALUES (666,'crack', 666, 666, 'bastante', 10, 4, 1, 1, 0)
-- ❌ permission denied ✅
