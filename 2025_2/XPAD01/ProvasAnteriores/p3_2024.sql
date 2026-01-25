SELECT * from multa
SELECT * from proprietario
SELECT * from tipomulta
SELECT * from veiculo

-- Questao 1)
-- Retorne o cpf e o nome do proprietário, placa, qtdemultas e somamultas do
-- veículo, a data e o status da multa com o nome e a descrição do tipo de multa) para todos os
-- proprietários incluindo aqueles que não tiveram multas.

CREATE MATERIALIZED VIEW q1 AS (
	SELECT
		p.cpf, p.nome as nome_p, v.placa, v.qtdemultas, v.somamultas, m.data, m.status, t.nome as t_multa, t.descricao
	FROM proprietario p
		JOIN veiculo v ON p.codigo = v.codproprietario
		LEFT JOIN  multa m ON v.codigo = m.codveiculo
		LEFT JOIN tipomulta t ON m.codtipo = t.codigo
)

-- Questao 2)
-- Elabore um gatilho para validar a seguinte regra de negócio: uma multa já existente só pode ser
-- cancelada (ter o status alterado para C), se o tipo for diferente de grave (código do tipo grave =
-- 10). Você deve analisar a regra de negócio e decidir qual o tipo do gatilho, o (s) evento (s) que
-- dispara e o momento.

CREATE OR REPLACE FUNCTION checa_multa()
RETURNS TRIGGER AS $$
BEGIN
	IF NEW.status = 'C' AND OLD.codtipo = 10 THEN
		RAISE EXCEPTION 'Multa grave não pode ser cancelada!';
	END IF;

	RETURN NEW;
END;
$$ LANGUAGE plpgsql;


CREATE TRIGGER q2
BEFORE UPDATE
ON multa FOR EACH ROW
EXECUTE PROCEDURE checa_multa()


-- Questao 2 remake)
-- A questão 2 será alterada para contemplar os dados que foram inseridos no banco de dados.
-- Elabore um gatilho para validar a seguinte regra de negócio: uma multa já existente só pode ser
-- cancelada (ter o status alterado para C), se o nome do tipo for diferente de 'Excesso de
-- velocidade'. Você deve analisar a regra de negócio e decidir qual o tipo do gatilho, o (s) evento
-- (s) que dispara e o momento.

CREATE OR REPLACE FUNCTION checa_multa()
RETURNS TRIGGER AS
$$ DECLARE tipo tipomulta.codigo%TYPE;
BEGIN
	SELECT codigo INTO tipo FROM tipomulta WHERE nome = 'Excesso de velocidade';
	IF NEW.status = 'C' AND OLD.codtipo = tipo THEN
		RAISE EXCEPTION 'Multa grave não pode ser cancelada!';
	END IF;

	RETURN NEW;
END;
$$ LANGUAGE plpgsql;
--
CREATE TRIGGER q2
BEFORE UPDATE ON multa
FOR EACH ROW EXECUTE PROCEDURE checa_multa()

-- DROP TRIGGER q2 ON multa
-- DROP FUNCTION checa_multa()


------------------------------------------------------------------------------------------------------------------------

-- Questao 1)
-- Retorne o cpf e o nome do proprietário, placa, qtdemultas e somamultas do
-- veículo, a data e o status da multa com o nome e a descrição do tipo de multa) para todos os
-- proprietários incluindo aqueles que não tiveram multas.

CREATE MATERIALIZED VIEW q1 AS (
	SELECT
		p.cpf, p.nome,
		v.placa, v.qtdemultas, v.somamultas,
		m.data, m.status,
		t.nome as tipomulta, t.descricao
		FROM proprietario p
			JOIN veiculo v ON p.codigo = v.codproprietario
			LEFT JOIN multa m ON m.codveiculo = v.codigo
			LEFT JOIN tipomulta t ON t.codigo = m.codtipo
)

-- Questao 2)
-- Elabore um gatilho para validar a seguinte regra de negócio: uma multa já existente só pode ser
-- cancelada (ter o status alterado para C), se o nome do tipo for diferente de 'Excesso de
-- velocidade'. Você deve analisar a regra de negócio e decidir qual o tipo do gatilho, o (s) evento
-- (s) que dispara e o momento.


CREATE OR REPLACE FUNCTION checa_multa()
RETURNS TRIGGER AS
$$ DECLARE tipo tipomulta.codigo%TYPE;
BEGIN
	SELECT codigo INTO tipo FROM tipomulta WHERE nome = 'Excesso de velocidade';

	IF NEW.status = 'C' AND OLD.codtipo = tipo THEN
		RAISE EXCEPTION 'Não pode cancelar multa grave!';
	END IF;

	RETURN NEW;
END;
$$ LANGUAGE plpgsql;


CREATE OR REPLACE TRIGGER q2
BEFORE UPDATE ON multa
FOR EACH ROW EXECUTE PROCEDURE checa_multa()


UPDATE multa SET status = 'R' WHERE codigo = 3

-- Questao 3)
-- Suponha que os atributos qtdemultas e somamultas sejam atualizados periodicamente. Elabore
-- um procedimento armazenado para fazer a atualização dos atributos qtdemultas e somamultas
-- de todos os veículos cadastrados.
CREATE OR REPLACE FUNCTION q3()
RETURNS VOID AS
$$ DECLARE v veiculo%ROWTYPE; soma veiculo.somamultas%TYPE;
BEGIN
	FOR v IN SELECT * FROM veiculo LOOP
		UPDATE veiculo
		SET qtdemultas = (SELECT COUNT(*) FROM multa m WHERE m.codveiculo = v.codigo)
		WHERE codigo = v.codigo;

		SELECT SUM(t.valor) INTO soma
		FROM tipomulta t JOIN multa m ON m.codtipo = t.codigo
		WHERE m.codveiculo = v.codigo;

		IF soma IS NULL THEN
			soma := 0;
		END IF;

		UPDATE veiculo SET somamultas = soma WHERE codigo = v.codigo;
	END LOOP;

END;
$$ LANGUAGE plpgsql;

-- SELECT q3()
-- SELECT * FROM veiculo

-- 5 a) Retorne a placa dos veículos que não possuem multas;
SELECT placa
FROM veiculo
WHERE qtdemultas = 0
-- ou
SELECT v.placa
FROM veiculo v LEFT JOIN multa m ON v.codigo = m.codveiculo
WHERE m.codveiculo IS NULL
-- ou
SELECT placa
FROM veiculo
WHERE codigo NOT IN (SELECT codveiculo FROM multa)


-- b) Retorne o CPF dos proprietários e a soma da quantidade de multas
-- que tiveram todos os seus veículos.
SELECT p.cpf, SUM(v.qtdemultas)
FROM proprietario p JOIN veiculo v ON p.codigo = v.codproprietario
GROUP BY p.cpf
-- ou
SELECT p.cpf, COUNT(m.codigo)
FROM proprietario p
	JOIN veiculo v ON p.codigo = v.codproprietario
	JOIN multa m ON m.codveiculo = v.codigo
GROUP BY p.cpf

