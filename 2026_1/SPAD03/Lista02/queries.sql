-- 1. Considere o esquema de banco de dados descrito abaixo e responsa as perguntas

CREATE TABLE categoria (
    codigo INT PRIMARY KEY,
    nome VARCHAR(100),
    categoria_pai INT REFERENCES categoria(codigo)
);

CREATE TABLE produto (
    codigo INT PRIMARY KEY,
    nome VARCHAR(100),
    categoria_codigo INT REFERENCES categoria(codigo)
);

CREATE TABLE venda (
    codigo INT PRIMARY KEY,
    produto_codigo INT REFERENCES produto(codigo),
    data_venda DATE,
    valor NUMERIC(10,2)
);

-- a. Retorne a hierarquia das categorias, mostrando o nome da categoria, o nome
-- da categoria pai e o nível hierárquico. Quando a categoria não possuir pai,
-- exiba “Categoria principal”.

WITH RECURSIVE hierarquia AS (
    SELECT codigo, nome, 'Categoria principal'::varchar AS nome_pai, 1 AS nivel
    FROM categoria
    WHERE categoria_pai IS NULL

    UNION ALL

    SELECT c.codigo, c.nome, p.nome, p.nivel + 1
    FROM categoria c
        JOIN hierarquia p ON c.categoria_pai = p.codigo
)
SELECT nome, nome_pai, nivel
FROM hierarquia
ORDER BY nivel, nome

-- b. Retorne o ranking dos produtos considerando o valor total vendido por
-- produto.

WITH total_vendas_produto AS (
    SELECT produto_codigo, SUM(valor) AS total_vendas
    FROM venda
    GROUP BY produto_codigo
)
SELECT p.nome, t.total_vendas,
    DENSE_RANK() OVER (ORDER BY t.total_vendas DESC) AS ranking
FROM produto p
    JOIN total_vendas_produto t ON p.codigo = t.produto_codigo

-- c. Retorne a média móvel mensal das vendas considerando o mês atual e os dois
-- meses anteriores.

WITH vendas_mensais AS (
    SELECT DATE_TRUNC('month', data_venda)::date AS mes, SUM(valor) AS valor_total
    FROM venda
    GROUP BY DATE_TRUNC('month', data_venda)::date
)
SELECT mes, valor_total,
    ROUND(
        AVG(valor_total) OVER(ORDER BY mes ROWS BETWEEN 2 PRECEDING AND CURRENT ROW),
        2
    ) AS media_movel
FROM vendas_mensais
ORDER BY mes
