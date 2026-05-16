select avg(salario),percentile_cont(0.5) within group (order by
salario) from funcionario

select codept, AVG(salario) as media, stddev(salario) as desvio_padrão
from funcionario group by codept

-- qtd de projetos
select tipo, count(*) as qtd_p from projeto group by tipo

-- qtd func por projeto
select codp, count(codf) as qtd_f from alocacao group by codp order by 1


-- distribuicao frequencia func x proj

WITH t_qtd_func_por_proj AS (
	SELECT codp, COUNT(codf) AS qtd_func_por_proj
	FROM alocacao GROUP BY 1
) SELECT qtd_func_por_proj, COUNT(codp) AS qtd_proj
	FROM t_qtd_func_por_proj GROUP BY 1


--- CASE

SELECT nome, CASE
	WHEN salario >= 10000 THEN 'alta'
	WHEN salario >= 5000 THEN 'média'
	ELSE 'baixa'
	END AS faixa_salarial
from funcionario

------------

WITH t_qtd_func_por_proj AS (
	SELECT p.nome, COUNT(a.codf) AS qtd_f
	FROM projeto p JOIN alocacao a ON a.codp = p.codigo
	GROUP BY p.nome
),
t_classificacao AS (
	SELECT nome, CASE
		WHEN qtd_f > 6 THEN 'muito'
		WHEN qtd_f > 3 THEN 'medio'
		ELSE 'pouco'
		END AS classificacao
	FROM t_qtd_func_por_proj
) SELECT classificacao, COUNT(*)
	FROM t_classificacao
	GROUP BY 1

---- WHEN EXISTS

SELECT p.nome, CASE WHEN EXISTS (
	SELECT 1 FROM alocacao a WHERE a.codp = p.codigo
	)
	THEN 'Já alocado' ELSE 'Não alocado'
	END AS status_alocacao
FROM projeto p

--------
-- EX 1

SELECT nome, salario, CASE
	WHEN salario >= 10000 THEN 'Alta'
	WHEN salario >= 5000 THEN 'Média'
	ELSE 'Baixa'
	END AS faixa_salarial
FROM funcionario

-- EX 2
SELECT f.nome, CASE
	WHEN EXISTS (
		SELECT 1 FROM funcionario fodase WHERE fodase.gerente = f.codigo
	) THEN 'Gerente'
	ELSE 'Comum'
	END AS tipo_funcionario
FROM funcionario f
ORDER BY f.codigo

----------- CTE recursivo

WITH RECURSIVE get_gerente AS (
	SELECT codigo, nome, 'Gerente geral'::varchar AS gerente, 1 AS nivel
	FROM funcionario
	WHERE gerente IS NULL

	UNION

	SELECT f.codigo, f.nome, g.nome, g.nivel + 1
	FROM funcionario f JOIN get_gerente g ON f.gerente = g.codigo
)
SELECT nome, gerente, nivel FROM get_gerente
ORDER BY nivel, nome

------------ Ex 1

WITH t_qtd_func_por_proj AS (
	SELECT codp, COUNT(codf) AS qtd_f
	FROM alocacao
	GROUP BY codp
), t_classificacao AS (
	SELECT codp, CASE
		WHEN qtd_f <= 3 THEN 'pouco'
		WHEN qtd_f <= 6 THEN 'medio'
		ELSE 'muito'
		END classificacao
	FROM t_qtd_func_por_proj
)
SELECT classificacao, COUNT(codp)
FROM t_classificacao
GROUP BY classificacao

-- EX 2

WITH RECURSIVE hierarquia_depto AS (
	SELECT codigo, nome, 'Direção'::varchar AS dept_pai, 1 AS nivel
	FROM departamento
	WHERE deptp IS NULL

	UNION ALL

	SELECT d.codigo, d.nome, p.nome, p.nivel + 1
	FROM departamento d
		JOIN hierarquia_depto p ON d.deptp = p.codigo
)
SELECT codigo, nome, dept_pai, nivel
FROM hierarquia_depto
ORDER BY nivel

----- RANK

SELECT nome, salario,
	RANK() OVER(ORDER BY salario DESC)
FROM funcionario

---- CTE + JANELA

WITH soma_horas AS (
	SELECT codp, SUM(horas) AS total_horas
	FROM alocacao
	GROUP BY codp
)
SELECT codp, total_horas,
	DENSE_RANK() OVER (ORDER BY total_horas DESC)
FROM soma_horas

---- ROWS BETWEEN + Média móvel

SELECT nome, salario,
	AVG(salario) OVER (
		ROWS BETWEEN 5 PRECEDING AND CURRENT ROW
	) AS media_movel
FROM funcionario

---- GROUP BY
-- Total por tipo, status e datai
SELECT tipo, status, datai, COUNT(*) AS qtd
FROM projeto
GROUP BY GROUPING SETS(tipo, status, datai)
ORDER BY 1, 2, 3

-- Total por (tipo, status e datai) e por (tipo, status)
SELECT tipo, status, COALESCE (datai::text, 'Total') AS datai, COUNT(*) AS qtd
FROM projeto
GROUP BY GROUPING SETS ((tipo, status, datai), (tipo, status))
ORDER BY tipo, status, datai

-- Total de todas as combinações
SELECT COALESCE(tipo::text, 'Todos') AS tipo,
	COALESCE(status::text, 'Todos') AS status,
	COALESCE (datai::text, 'Todos') AS datai,
	COUNT(*)
FROM projeto
GROUP BY CUBE(tipo, status, datai)
ORDER BY 1, 2, 3
