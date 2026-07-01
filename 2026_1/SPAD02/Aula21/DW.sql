CREATE SCHEMA IF NOT EXISTS dw;

--**CRIAÇÃO DAS TABELAS DIMENSÃO--**
CREATE TABLE dw.dim_tempo (
    sk_tempo      SERIAL PRIMARY KEY,

    data          DATE NOT NULL UNIQUE,
    dia           INTEGER NOT NULL,
    dia_semana    VARCHAR(20),
    mes           INTEGER NOT NULL,
    nome_mes      VARCHAR(20),
    trimestre     INTEGER NOT NULL,
    ano           INTEGER NOT NULL
);

CREATE TABLE dw.dim_produto (
    sk_produto     SERIAL PRIMARY KEY,

    productid      INTEGER,
    produto        VARCHAR(100),
    categoria      VARCHAR(100),
    fornecedor     VARCHAR(100)
);

CREATE TABLE dw.dim_funcionario (
    sk_funcionario  SERIAL PRIMARY KEY,

    employeeid      INTEGER,
    funcionario     VARCHAR(100),
    cargo           VARCHAR(100)
);

--**CRIAÇÃO DA TABELA FATO**--
CREATE TABLE dw.fato_vendas (

    sk_tempo        INTEGER NOT NULL,
    sk_produto      INTEGER NOT NULL,
    sk_funcionario  INTEGER NOT NULL,

    quantidade_vendida INTEGER NOT NULL,
    qtd_pedidos        INTEGER NOT NULL,

    valor_bruto        NUMERIC(14,2) NOT NULL,
    valor_desconto     NUMERIC(14,2) NOT NULL,
    valor_liquido      NUMERIC(14,2) NOT NULL,

    PRIMARY KEY (
        sk_tempo,
        sk_produto,
        sk_funcionario
    ),

    FOREIGN KEY (sk_tempo)
        REFERENCES dw.dim_tempo(sk_tempo),

    FOREIGN KEY (sk_produto)
        REFERENCES dw.dim_produto(sk_produto),

    FOREIGN KEY (sk_funcionario)
        REFERENCES dw.dim_funcionario(sk_funcionario)
);

--**CARGA DOS DADOS**--
INSERT INTO dw.dim_tempo (
    data,
    dia,
    dia_semana,
    mes,
    nome_mes,
    trimestre,
    ano
)
SELECT DISTINCT
    DATE(orderdate) AS data,
    EXTRACT(DAY FROM orderdate),
    TO_CHAR(orderdate,'Day'),
    EXTRACT(MONTH FROM orderdate),
    TO_CHAR(orderdate,'Month'),
    EXTRACT(QUARTER FROM orderdate),
    EXTRACT(YEAR FROM orderdate)
FROM northwind.orders
ORDER BY data;

INSERT INTO dw.dim_produto (
    productid,
    produto,
    categoria,
    fornecedor
)
SELECT
    p.productid,
    p.productname,
    c.categoryname,
    s.companyname
FROM northwind.products p
JOIN northwind.categories c
    ON p.categoryid = c.categoryid
JOIN northwind.suppliers s
    ON p.supplierid = s.supplierid;


INSERT INTO dw.dim_funcionario (
    employeeid,
    funcionario,
    cargo
)
SELECT
    employeeid,
    firstname || ' ' || lastname,
    title
FROM northwind.employees;

INSERT INTO dw.fato_vendas
(
    sk_tempo,
    sk_produto,
    sk_funcionario,

    quantidade_vendida,
    qtd_pedidos,

    valor_bruto,
    valor_desconto,
    valor_liquido
)
SELECT

    dt.sk_tempo,
    dp.sk_produto,
    df.sk_funcionario,

    SUM(od.quantity) AS quantidade_vendida,

    COUNT(DISTINCT o.orderid) AS qtd_pedidos,

    SUM(
        od.quantity * od.unitprice
    ) AS valor_bruto,

    SUM(
        od.quantity * od.unitprice * od.discount
    ) AS valor_desconto,

    SUM(
        od.quantity * od.unitprice * (1 - od.discount)
    ) AS valor_liquido

FROM northwind.orders o

JOIN northwind.order_details od
    ON o.orderid = od.orderid

JOIN dw.dim_tempo dt
    ON dt.data = DATE(o.orderdate)

JOIN dw.dim_produto dp
    ON dp.productid = od.productid

JOIN dw.dim_funcionario df
    ON df.employeeid = o.employeeid

GROUP BY
    dt.sk_tempo,
    dp.sk_produto,
    df.sk_funcionario;

--***CONSULTAS OLAP**--

--**ROLL-UP**--
--Qual foi o valor líquido total de vendas por mês e por ano?
-- O ROLLUP cria automaticamente os subtotais hierárquicos de uma consulta.
--ROLLUP(ano, mes) cria automaticamente:
--Ano + Mês
--Ano
--Total Geral como NULL -- Os NULL representam níveis superiores da hierarquia.
SELECT
    t.ano,
    t.mes,
    SUM(f.valor_liquido) AS total_vendas
FROM dw.fato_vendas f
JOIN dw.dim_tempo t
    ON f.sk_tempo = t.sk_tempo
GROUP BY ROLLUP (t.ano, t.mes)
ORDER BY
    t.ano NULLS LAST, --coloca os NULL no final
    t.mes NULLS LAST;
-- ou
SELECT t.ano, t.mes, SUM(f.valor_liquido)
FROM dw.fato_vendas f
JOIN dw.dim_tempo t ON f.sk_tempo = t.sk_tempo
GROUP BY ROLLUP(t.ano, t.mes)
ORDER BY 1, 2 NULLS LAST;

--Qual foi o faturamento total por categoria de produto?
SELECT
    p.categoria,
    SUM(f.valor_liquido) AS faturamento_total
FROM dw.fato_vendas f
JOIN dw.dim_produto p
    ON f.sk_produto = p.sk_produto
GROUP BY
    p.categoria
ORDER BY
    faturamento_total DESC;

--com subtotais por produto
SELECT
    p.categoria,
    p.produto,
    SUM(f.valor_liquido) AS faturamento_total
FROM dw.fato_vendas f
JOIN dw.dim_produto p
    ON f.sk_produto = p.sk_produto
GROUP BY ROLLUP (
    p.categoria,
    p.produto
)
ORDER BY
    p.categoria NULLS LAST,
    p.produto NULLS LAST;
-- ou
SELECT p.categoria, p.produto, SUM(f.valor_liquido) AS faturamento
FROM dw.fato_vendas f
JOIN dw.dim_produto p ON f.sk_produto = p.sk_produto
GROUP BY ROLLUP(p.categoria, p.produto)
ORDER BY 1, 2 NULLS LAST;

--*usando GROUPING SETS**--
--permite definir quais agregações você deseja gerar
SELECT
    p.categoria,
    p.produto,
    SUM(f.valor_liquido) AS faturamento_total
FROM dw.fato_vendas f
JOIN dw.dim_produto p
    ON f.sk_produto = p.sk_produto
GROUP BY GROUPING SETS ( --vai gerar faturamento agregado por categoria e depois por produto
    p.categoria,
    p.produto
)
ORDER BY
    p.categoria NULLS LAST,
    p.produto NULLS LAST;

--**usando o CUBE**--
SELECT
    p.categoria,
    p.produto,
    SUM(f.valor_liquido) AS faturamento_total
FROM dw.fato_vendas f
JOIN dw.dim_produto p
    ON f.sk_produto = p.sk_produto
GROUP BY CUBE (
    p.categoria,
    p.produto
)
ORDER BY
    p.categoria NULLS LAST,
    p.produto NULLS LAST;

--Com todas as dimensões do cubo
SELECT
    t.ano,
    p.categoria,
    fu.cargo,
    SUM(f.valor_liquido) AS total_vendas
FROM dw.fato_vendas f
JOIN dw.dim_tempo t
    ON f.sk_tempo = t.sk_tempo
JOIN dw.dim_produto p
    ON f.sk_produto = p.sk_produto
JOIN dw.dim_funcionario fu
    ON f.sk_funcionario = fu.sk_funcionario
GROUP BY CUBE (
    t.ano,
    p.categoria,
    fu.cargo
);

--Qual o valor líquido de vendas por ano e por cargo dos funcionários?
SELECT
    t.ano,
    f.cargo,
    SUM(v.valor_liquido) AS valor_liquido_total
FROM dw.fato_vendas v
JOIN dw.dim_tempo t
    ON v.sk_tempo = t.sk_tempo
JOIN dw.dim_funcionario f
    ON v.sk_funcionario = f.sk_funcionario
GROUP BY
    t.ano,
    f.cargo
ORDER BY
    t.ano,
    f.cargo;

--Com subtotais
SELECT
    t.ano,
    f.cargo,
    SUM(v.valor_liquido) AS valor_liquido_total
FROM dw.fato_vendas v
JOIN dw.dim_tempo t
    ON v.sk_tempo = t.sk_tempo
JOIN dw.dim_funcionario f
    ON v.sk_funcionario = f.sk_funcionario
GROUP BY ROLLUP (
    t.ano,
    f.cargo
)
ORDER BY
    t.ano NULLS LAST,
    f.cargo NULLS LAST;

-- Determine a quantidade vendida por funcionário, incluindo os subtotais
-- por cargo e o total geral.
SELECT f.cargo, f.funcionario, SUM(v.quantidade_vendida)
FROM dw.fato_vendas v
JOIN dw.dim_funcionario f ON v.sk_funcionario = f.sk_funcionario
GROUP BY ROLLUP(f.cargo, f.funcionario)
ORDER BY 1, 2 NULLS LAST;

-- Gere todas as combinações possíveis de agregação entre ano e categoria.
-- 💩💩💩💩 venda liquida??? 💩💩💩💩
SELECT t.ano, p.categoria, SUM(v.valor_liquido)
FROM dw.fato_vendas v
	JOIN dw.dim_tempo t ON v.sk_tempo = t.sk_tempo
	JOIN dw.dim_produto p ON v.sk_produto = p.sk_produto
GROUP BY CUBE(t.ano, p.categoria)
ORDER BY 1, 2;

-- Produza em uma única consulta:
-- 👉 vendas por ano;
-- 👉 vendas por categoria;
-- 👉 vendas por cargo.
SELECT t.ano, p.categoria, f.cargo, SUM(v.valor_liquido)
FROM dw.fato_vendas v
	JOIN dw.dim_tempo t ON v.sk_tempo = t.sk_tempo
	JOIN dw.dim_produto p ON v.sk_produto = p.sk_produto
	JOIN dw.dim_funcionario f ON v.sk_funcionario = f.sk_funcionario
GROUP BY GROUPING SETS(1, 2, 3)
ORDER BY 1, 2, 3;

--**SLICE**--
--Qual foi o valor líquido das vendas realizadas pelo funcionário Nancy Davolio?
SELECT
    t.ano,
    t.mes,
    p.produto,
    SUM(f.valor_liquido) AS valor_liquido
FROM dw.fato_vendas f
JOIN dw.dim_tempo t
    ON f.sk_tempo = t.sk_tempo
JOIN dw.dim_produto p
    ON f.sk_produto = p.sk_produto
JOIN dw.dim_funcionario fu
    ON f.sk_funcionario = fu.sk_funcionario
WHERE fu.funcionario = 'Nancy Davolio'
GROUP BY
    t.ano,
    t.mes,
    p.produto;

--Qual foi o faturamento dos produtos ao longo do ano de 1995?
SELECT
    p.produto,
    fu.funcionario,
    SUM(f.valor_liquido) AS valor_liquido
FROM dw.fato_vendas f
JOIN dw.dim_tempo t
    ON f.sk_tempo = t.sk_tempo
JOIN dw.dim_produto p
    ON f.sk_produto = p.sk_produto
JOIN dw.dim_funcionario fu
    ON f.sk_funcionario = fu.sk_funcionario
WHERE t.ano = 1995
GROUP BY
    p.produto,
    fu.funcionario;

--**DICE**--
-- Qual foi o valor líquido das vendas dos produtos da categoria Beverages realizadas por Nancy Davolio e Andrew Fuller durante 1995?
SELECT
    p.categoria,
    fu.funcionario,
    t.ano,
    SUM(f.valor_liquido) AS valor_liquido
FROM dw.fato_vendas f
JOIN dw.dim_tempo t
    ON f.sk_tempo = t.sk_tempo
JOIN dw.dim_produto p
    ON f.sk_produto = p.sk_produto
JOIN dw.dim_funcionario fu
    ON f.sk_funcionario = fu.sk_funcionario
WHERE p.categoria = 'Beverages'
  AND fu.funcionario IN (
      'Nancy Davolio',
      'Andrew Fuller'
  )
  AND t.ano = 1995
GROUP BY
    p.categoria,
    fu.funcionario,
    t.ano;

--💩-💩-💩-💩-💩-💩-💩-💩-💩-💩-💩-💩-💩-💩-💩-💩-💩-💩-💩
-- Qual foi o valor líquido das vendas por ano e mês?
-- 👉 Consulta utilizando GROUP BY
-- 👉 Consulta utilizando ROLLUP
-- 👉 Compare os resultados

-- qual a diferença entre calcular a soma de valor_liquido por ano e mês usando
--  group by e rollup? 💩-💩-💩 traduzido por megabrain modo turbo
SELECT t.ano, t.mes, SUM(v.valor_liquido)
FROM dw.fato_vendas v
	JOIN dw.dim_tempo t ON v.sk_tempo = t.sk_tempo
GROUP BY 1, 2 -- 👈 GROUP BY 😱
ORDER BY 1, 2;

SELECT t.ano, t.mes, SUM(v.valor_liquido)
FROM dw.fato_vendas v
	JOIN dw.dim_tempo t ON v.sk_tempo = t.sk_tempo
GROUP BY ROLLUP(1, 2) -- 👈 ROLLUP 🙀
ORDER BY 1, 2;

-- Deseja-se analisar as vendas por ano e categoria.
-- 👉 Consulta utilizando GROUP SETS
-- 👉 Consulta utilizando CUBE
-- 👉 Compare a quantidade de agrupamentos gerados
SELECT t.ano, p.categoria, SUM(v.valor_liquido)
FROM dw.fato_vendas v
	JOIN dw.dim_tempo t ON v.sk_tempo = t.sk_tempo
	JOIN dw.dim_produto p ON v.sk_produto = p.sk_produto
GROUP BY GROUPING SETS (1, 2) -- 👈 GROUPING SETS 🚨
ORDER BY 1, 2;

SELECT t.ano, p.categoria, SUM(v.valor_liquido)
FROM dw.fato_vendas v
	JOIN dw.dim_tempo t ON v.sk_tempo = t.sk_tempo
	JOIN dw.dim_produto p ON v.sk_produto = p.sk_produto
GROUP BY CUBE (1, 2) -- 👈 CUBE ⚠️
ORDER BY 1, 2;
