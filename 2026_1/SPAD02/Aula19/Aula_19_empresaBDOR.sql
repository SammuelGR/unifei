CREATE SCHEMA IF NOT EXISTS empresaBDOR;

CREATE TYPE empresaBDOR.tp_cargo AS (
	cod int, nome varchar(30),
	salariobase numeric(5,2),
	quantfunc int);

CREATE TYPE empresaBDOR.tp_dependente AS (
	nome varchar(30),
	sexo char(1),
	datanasc date,
	parentesco varchar(20));

CREATE TYPE empresaBDOR.tp_salario AS (
	data date,
	valor numeric(5,2));

DROP TABLE empresaBDOR.funcionario_obj;

CREATE TABLE empresaBDOR.funcionario_obj (
	cpf varchar(11) PRIMARY KEY,
	nome varchar(30),
	endereco varchar(30),
	telefone varchar[],
	cargo empresaBDOR.tp_cargo,
	dependentes empresaBDOR.tp_dependente[],
	historico_salarial empresaBDOR.tp_salario[]);

INSERT INTO empresaBDOR.funcionario_obj (cpf, nome, endereco, telefone, cargo, dependentes, historico_salarial) VALUES
('12345678901', 'João Silva', 'Rua A, 10', ARRAY['999998888'],
 	ROW(1, 'Analista de Sistemas', 500.00, 1)::empresaBDOR.tp_cargo,
 	ARRAY[ROW('Ana Silva', 'F', '2014-05-10', 'Filha')::empresaBDOR.tp_dependente],
 	ARRAY[ROW('2022-01-01', 850.00)::empresaBDOR.tp_salario]);

INSERT INTO empresaBDOR.funcionario_obj (cpf, nome, endereco, telefone, cargo, dependentes, historico_salarial) VALUES
	('23456789012', 'Maria Souza', 'Rua B, 20', ARRAY['988887777'],
	 ROW(2, 'Gerente de Projetos', 850.00, 1)::empresaBDOR.tp_cargo,
	 ARRAY[ROW('Carlos Souza', 'M', '2019-08-26', 'Filho')::empresaBDOR.tp_dependente],
	 ARRAY[ROW('2023-01-01', 520.00)::empresaBDOR.tp_salario, ROW('2018-01-01', 450.00)::empresaBDOR.tp_salario, ROW('2026-06-09', 950.00)::empresaBDOR.tp_salario]);

INSERT INTO empresaBDOR.funcionario_obj (cpf, nome, endereco, telefone, cargo, dependentes, historico_salarial) VALUES
	('34567890123', 'Pedro Santos', 'Rua C, 30', ARRAY['977776666'],
	 ROW(3, 'Desenvolvedor Junior', 300.00, 1)::empresaBDOR.tp_cargo, NULL,
	 ARRAY[ROW('2023-01-01', 310.00)::empresaBDOR.tp_salario]);


--Selecionar funcionários que sejam do cargo 'Desenvolvedor Junior'
SELECT nome FROM empresaBDOR.funcionario_obj WHERE (cargo).nome = 'Desenvolvedor Junior';
-- ou
SELECT *
	FROM empresabdor.funcionario_obj
	WHERE (cargo).nome = 'Desenvolvedor Junior';

--Funcionários que tenham tido o último ajuste salarial em 2023
-- UNNEST(f.historico_salarial): Esta função transforma o array de tipos compostos em linhas temporárias para manipulá-las individualmente.
SELECT f.* FROM empresaBDOR.funcionario_obj f
	WHERE (SELECT (h).data FROM UNNEST(f.historico_salarial) AS h
		   ORDER BY (h).data DESC LIMIT 1) >= '2023-01-01' AND
		   (SELECT (h).data FROM UNNEST(f.historico_salarial) AS h ORDER BY (h).data DESC LIMIT 1) <= '2023-12-31';
-- ou
SELECT *
	FROM empresabdor.funcionario_obj f
	WHERE (
		SELECT MAX(h.data)
		FROM UNNEST(f.historico_salarial) h
	) >= '2023-01-01'
	AND (
		SELECT MAX(h.data)
		FROM UNNEST(f.historico_salarial) h
	) <= '2023-12-31';

--Incluir uma atualização salarial para o funcionário Pedro Santos para o ano de 2026
-- Operador ||: Adiciona o novo objeto tp_salario ao final da coleção historico_salarial => Concatenação
-- Construtor ROW: Cria a instância do tipo composto com a data desejada (2026-06-09) e o novo valor.
UPDATE empresaBDOR.funcionario_obj SET historico_salarial = historico_salarial || ARRAY[ROW('2026-06-09', 950.00)::empresaBDOR.tp_salario]
		WHERE nome = 'Pedro Santos';
-- ou
UPDATE empresabdor.funcionario_obj
	SET historico_salarial = historico_salarial || ARRAY[
		ROW('2026-06-09', 777.77)::empresabdor.tp_salario
	]
	WHERE nome = 'Pedro Santos';

--Incluir uma atualização salarial para o funcionário Pedro Santos para o ano de 2018, na primeira posição do vetor
-- Operador ||: Adiciona o novo objeto tp_salario ao final da coleção historico_salarial => Concatenação
UPDATE empresaBDOR.funcionario_obj SET historico_salarial = ARRAY[ROW('2018-01-01'::date, 450.00::numeric)::empresaBDOR.tp_salario] || historico_salarial
		WHERE nome = 'Pedro Santos';
-- ou
UPDATE empresabdor.funcionario_obj
	SET historico_salarial = ARRAY[ROW('2018-12-31', 500.00)::empresabdor.tp_salario]
		|| historico_salarial
	WHERE nome = 'Pedro Santos';

--Incluir uma atualização salarial para o funcionário Pedro Santos na segunda posição do vetor
UPDATE empresaBDOR.funcionario_obj
SET historico_salarial =
    historico_salarial[1:1] ||
    ARRAY[ROW('2020-01-01', 600.00)::empresaBDOR.tp_salario] ||
    historico_salarial[2:array_length(historico_salarial, 1)]
WHERE nome = 'Pedro Santos';
-- ou.....
UPDATE empresabdor.funcionario_obj
	SET historico_salarial =
		historico_salarial[:1] ||
		ARRAY[ROW('2026-01-01', 999.91)::empresabdor.tp_salario] ||
		historico_salarial[2:]
	WHERE nome = 'Pedro Santos';

SELECT historico_salarial FROM empresaBDOR.funcionario_obj WHERE nome = 'Pedro Santos';

-- Verificar se o funcionario possui um dependente especifico no array 'dependentes'
-- valor operador ANY (array) retorna verdadeiro se a comparação for verdadeira para pelo menos um dos elementos do array.
SELECT nome, cpf
FROM empresaBDOR.funcionario_obj
WHERE 'Ana Silva' = ANY (SELECT (d).nome FROM UNNEST(dependentes) AS d);
-- owl
SELECT nome, cpf
	FROM empresabdor.funcionario_obj
	WHERE 'Ana Silva' = ANY(
		SELECT d.nome
		FROM UNNEST(dependentes) AS d
	);

--***********Manipulação direta de array****************--

--consultar o telefone '977776666' nos funcionários
--Operador @>: Verifica se o conjunto à esquerda contém todos os elementos do conjunto à direita.
--O uso do operador de contenção em arrays de tipos primitivos (como varchar) é a forma mais performática e legível de realizar buscas em modelos objeto-relacionais
SELECT nome, cpf
FROM empresaBDOR.funcionario_obj
WHERE telefone @> ARRAY['977776666']::varchar[];
--🦉
SELECT nome, cpf
	FROM empresabdor.funcionario_obj
	WHERE telefone @> ARRAY['977776666'::varchar];
--🦉
SELECT nome, cpf
	FROM empresabdor.funcionario_obj
	WHERE '977776666' = ANY(telefone);

SELECT telefone FROM empresaBDOR.funcionario_obj WHERE nome = 'Pedro Santos';

--inserir um novo telefone no final do array usando array_apend
UPDATE empresaBDOR.funcionario_obj
SET telefone = array_append(telefone, '33334444')
WHERE nome = 'Pedro Santos';

--alterar o telefone '33334444' para '55556666' usando array_replace
UPDATE empresaBDOR.funcionario_obj
SET telefone = array_replace(telefone, '33334444', '55556666')
WHERE nome = 'Pedro Santos';

--ordenar os telefones de Pedro Santos usando array_sort
UPDATE empresaBDOR.funcionario_obj
SET telefone = array_sort(telefone)
WHERE nome = 'Pedro Santos';

--*******INDEXAÇÃO DE ARRAY*********--
--Para indexar arrays utilizamos o índice GIN (Generalized Inverted Index).
--Diferente de um índice B-tree convencional, o índice GIN "quebra" o array e indexa os elementos individualmente.
--No caso de tipos compostos, ele indexa o objeto inteiro.

--criar um índice para o histórico salarial do funcionário
CREATE INDEX idx_funcionario_historico_gin
ON empresaBDOR.funcionario_obj
USING GIN (historico_salarial);

--Funcionários que tenham salário menor que 300
EXPLAIN ANALYZE
SELECT DISTINCT nome,s
FROM empresaBDOR.funcionario_obj,
     UNNEST(historico_salarial) AS s
WHERE s.valor < 500;
