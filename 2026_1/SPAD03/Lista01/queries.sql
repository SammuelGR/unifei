-- pg_restore --verbose --no-owner --no-acl -d "postgresql://usr:pwd@host/db" ".\loja.backup"

-- 1. Liste o código dos clientes que fizeram pedidos com valor total acima da média, mostrando
-- também quantos pedidos cada um fez que atendem a esta condição.

WITH avg_total_pedido AS (
    SELECT AVG(valor_total) AS media
    FROM pedido
  )
SELECT cliente_id, COUNT(pedido_id) AS qtd_pedidos
FROM pedido CROSS JOIN avg_total_pedido m
WHERE valor_total > m.media
GROUP BY cliente_id
ORDER BY cliente_id

-- 2. Calcule o valor total de indicações por cidade (considerando que cada cliente indicado gera
-- um crédito fictício de R$10 para quem indicou). Para as cidades que não possuem clientes
-- que fizeram indicação, deve ser exibido o valor 0. Ordene o resultado por cidade.

WITH indicacoes_por_cliente AS (
    SELECT indicado_por, COUNT(indicacao_id) AS qtd_indicacoes
    FROM indicacao
    GROUP BY indicado_por
)
SELECT c.cidade, COALESCE(SUM(i.qtd_indicacoes), 0) * 10 AS valor_total_indicacoes
FROM cliente c LEFT JOIN indicacoes_por_cliente i
    ON c.cliente_id = i.indicado_por
    GROUP BY c.cidade
    ORDER BY c.cidade

-- 3. Classifique os clientes em categorias (Bronze, Prata, Ouro) baseado no valor total gasto em
-- pedidos (Bronze < 3000, 3000 ≤ Prata < 15000, Ouro ≥ 15000

WITH total_pedidos_por_cliente AS (
    SELECT cliente_id, SUM(valor_total) soma_total
    FROM pedido
    GROUP BY cliente_id
)
SELECT c.nome, CASE
    WHEN t.soma_total >= 15000 THEN 'Ouro'
    WHEN t.soma_total >= 3000 THEN 'Prata'
    ELSE 'Bronze'
    END AS classificacao
FROM total_pedidos_por_cliente t
    RIGHT JOIN cliente c ON c.cliente_id = t.cliente_id

-- 4. Para cada produto, mostre o nome e se seu preço base está "Acima", "Abaixo" ou "Na"
-- média dos preços dos produtos. Ordene pelo nome do produto.

WITH media_precos AS (
    SELECT AVG(preco_base) media
    FROM produto
)
SELECT p.nome, CASE
    WHEN p.preco_base > m.media THEN 'Acima'
    WHEN p.preco_base = m.media THEN 'Na média'
    ELSE 'Abaixo'
    END AS faixa_de_preco
FROM produto p CROSS JOIN media_precos m
ORDER BY p.nome

-- 5. Classifique os produtos por quantidade total vendida (usando DENSE_RANK), mostrando
-- também a posição no ranking. No resultado, devem aparecer as seguintes informações,
-- código do produto, nome do produto, quantidade total vendida do produto, posição no
-- ranking. O produto na primeira posição deve ser aquele com a maior quantidade vendida.

WITH qtd_venda_por_produto AS (
    SELECT produto_id, SUM(quantidade) AS qtd_total
    FROM itempedido
    GROUP BY produto_id
)
SELECT p.produto_id, p.nome, q.qtd_total,
    DENSE_RANK() OVER (ORDER BY q.qtd_total DESC)
FROM produto p
    JOIN qtd_venda_por_produto q ON p.produto_id = q.produto_id

-- 6. Para cada cidade, classifique os clientes por valor total gasto. No resultado da consulta,
-- devem ser apresentados o nome da cidade, o nome do cliente, o valor total gasto e a
-- posição no ranking.

WITH valor_total_por_cliente AS (
    SELECT cliente_id, SUM(valor_total) AS total
    FROM pedido
    GROUP BY cliente_id
)
SELECT c.cidade, c.nome, COALESCE(t.total, 0),
    DENSE_RANK() OVER (PARTITION BY c.cidade ORDER BY COALESCE(t.total, 0) DESC)
FROM cliente c
    LEFT JOIN valor_total_por_cliente t ON c.cliente_id = t.cliente_id

-- 7. Para cada pedido, mostre o id do pedido, o id do cliente, valor total do pedido e a média de
-- valores de pedidos do mesmo cliente. Ordene o resultado pelo id do cliente e id do pedido.

SELECT pedido_id, cliente_id, valor_total,
    ROUND(AVG(valor_total) OVER (PARTITION BY cliente_id)::numeric, 2) AS media_cliente
FROM pedido
ORDER BY cliente_id, pedido_id

-- 8. Para cada pedido, mostre o id do pedido, o id do cliente, a data do pedido, a data do
-- próximo pedido do mesmo cliente (usando LEAD).

SELECT pedido_id, cliente_id, data_pedido,
    LEAD(data_pedido) OVER (PARTITION BY cliente_id ORDER BY data_pedido) AS data_prox_pedido
FROM pedido

-- 9. Para cada pedido, mostre o id do pedido, o id do cliente, a data do pedido, a data do
-- próximo pedido do mesmo cliente (usando LEAD) e a diferença entre as datas.

WITH pedidos_por_cliente_e_data AS (
    SELECT pedido_id, cliente_id, data_pedido,
        LEAD(data_pedido) OVER (PARTITION BY cliente_id ORDER BY data_pedido) AS data_prox_pedido
    FROM pedido
)
SELECT pedido_id, cliente_id, data_pedido, data_prox_pedido,
    data_prox_pedido - data_pedido AS intervalo
FROM pedidos_por_cliente_e_data

-- 10. Retorne o valor total de pedidos agrupado por: 1) cidade, 2) ano do pedido, 3) cidade e
-- ano combinados, e 4) total geral.

SELECT c.cidade,
    DATE_PART('year', p.data_pedido) AS ano_pedido,
    SUM(p.valor_total) AS soma_total
FROM cliente c JOIN pedido p ON c.cliente_id = p.cliente_id
GROUP BY CUBE (c.cidade, ano_pedido)
