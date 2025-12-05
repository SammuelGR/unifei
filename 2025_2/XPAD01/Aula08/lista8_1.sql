-- a. Retorne o nome do funcionário, salário e o nome do departamento;
SELECT f.nome, f.salario, d.nome
FROM funcionario f JOIN departamento d ON f.dept = d.codigo

-- b. Retorne o nome do departamento e a quantidade de funcionários;
SELECT d.nome, COUNT (f.codigo) AS qtd_func
FROM departamento d JOIN funcionario f ON d.codigo = f.dept
GROUP BY d.nome

-- c. Retorne o nome do departamento e a quantidade de funcionários somente para
-- aqueles departamentos que possuem mais de 3 funcionários;
SELECT d.nome, COUNT(f.codigo) as qtd_func
FROM departamento d JOIN funcionario f ON d.codigo = f.dept
GROUP BY d.nome HAVING COUNT(f.codigo) > 3

-- d. Retorne o código do funcionário e a soma de horas trabalhadas em todos os
-- projetos.
SELECT codf, SUM(horas) as total_horas
FROM alocacao
GROUP BY codf
ORDER BY codf

-- e. Retorne o nome do funcionário e a soma de horas trabalhadas em todos os
-- projetos.
SELECT f.nome, SUM(a.horas)
FROM funcionario f JOIN alocacao a ON f.codigo = a.codf
GROUP BY f.codigo, f.nome
ORDER BY f.nome

-- f. Retorne o código dos departamentos com os nomes dos seus respectivos
-- funcionários.
SELECT dept, nome FROM funcionario

-- g. Retorne o código dos departamentos com os nomes dos seus respectivos
-- funcionários incluindo aqueles departamentos que não possuem funcionários;
SELECT d.codigo AS dept, f.nome
FROM departamento d LEFT JOIN funcionario f ON d.codigo = f.dept

-- h. Retorne os nomes que constam na tabela funcionário e/ou departamento;
SELECT nome FROM funcionario
UNION
SELECT nome FROM departamento

-- i. Retorne o nome dos funcionários que ganham mais que a média.
SELECT nome
FROM funcionario
WHERE salario > (
	SELECT AVG(salario) FROM funcionario
)

-- j. Retorne o nome dos funcionários que estão alocados em todos os projetos;
SELECT f.nome
FROM funcionario f JOIN alocacao a ON f.codigo = a.codf
GROUP BY f.nome
HAVING COUNT(DISTINCT a.codp) = (SELECT COUNT(*) FROM projeto)
-- ou entao
SELECT nome
FROM funcionario
WHERE codigo NOT IN (
	SELECT f.codigo
	FROM funcionario f
		CROSS JOIN projeto p
		LEFT JOIN alocacao a ON a.codf = f.codigo AND a.codp = p.codigo
	WHERE a.codf IS NULL
)

-- k. Retorne o nome dos projetos que possuem todos os funcionários alocados;
SELECT p.nome
FROM projeto p JOIN alocacao a ON p.codigo = a.codp
GROUP BY p.nome
HAVING COUNT (DISTINCT a.codf) = (SELECT COUNT(*) FROM funcionario)
-- ou
SELECT nome
FROM projeto
WHERE codigo NOT IN (
	SELECT p.codigo
	FROM projeto p
		CROSS JOIN funcionario f
		LEFT JOIN alocacao a ON a.codp = p.codigo AND a.codf = f.codigo
	WHERE a.codf IS NULL
)
-- ou
SELECT p.nome
FROM projeto p
WHERE NOT EXISTS (
	SELECT f.codigo
	FROM funcionario f
	WHERE NOT EXISTS (
		SELECT 1
		FROM alocacao a
		WHERE a.codp = p.codigo AND a.codf = f.codigo
	)
)
