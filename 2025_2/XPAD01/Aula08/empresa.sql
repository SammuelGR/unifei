-- a. Retorne o nome do funcionário, salário e o nome do departamento

SELECT f.nome, f.salario, d.nome
FROM funcionario f, departamento d
WHERE f.dept = d.codigo

-- ou
SELECT f.nome, f.salario, d.nome
FROM funcionario f JOIN departamento d
ON f.dept = d.codigo

-- b. Retorne o nome do departamento e a quantidade de funcionários;

SELECT d.nome, COUNT(f.codigo)
FROM funcionario f join departamento d
ON f.dept = d.codigo
GROUP BY d.nome

-- c. Retorne o nome do departamento e a quantidade de funcionários somente para
--    aqueles departamentos que possuem mais de 3 funcionários;

SELECT d.nome, COUNT(f.codigo)
FROM funcionario f JOIN departamento d
ON f.dept = d.codigo
GROUP BY d.nome
HAVING COUNT(f.codigo) > 3

-- d. Retorne o código do funcionário e a soma de horas trabalhadas em todos os
--    projetos.

SELECT a.codf, SUM(a.horas)
FROM alocacao a
GROUP BY a.codf
ORDER BY a.codf -- optional

-- e. Retorne o nome do funcionário e a soma de horas trabalhadas em todos os
--    projetos.

SELECT f.nome, SUM(a.horas)
FROM alocacao a
JOIN funcionario f ON a.codf = f.codigo
GROUP BY f.nome

-- f. Retorne o código dos departamentos com os nomes dos seus respectivos
--    funcionários.

SELECT dept, nome FROM funcionario
ORDER BY dept

-- g. Retorne o código dos departamentos com os nomes dos seus respectivos
--    funcionários incluindo aqueles departamentos que não possuem funcionários;

SELECT d.codigo, f.nome
FROM funcionario f
RIGHT JOIN departamento d
ON f.dept = d.codigo

-- h. Retorne os nomes que constam na tabela funcionário e/ou departamento;
-- ????????????????????

-- i. Retorne o nome dos funcionários que ganham mais que a média.

SELECT f.nome
FROM funcionario f
WHERE f.salario > (
	SELECT AVG(salario)
	FROM funcionario
)

-- j. Retorne o nome dos funcionários que estão alocados em todos os projetos;

SELECT f.nome
FROM funcionario f
WHERE (
	SELECT COUNT (codigo) from projeto
) = (
	SELECT COUNT (a.codp) FROM alocacao a
	WHERE a.codf = f.codigo
)


-- k. Retorne o nome dos projetos que possuem todos os funcionários alocados;

