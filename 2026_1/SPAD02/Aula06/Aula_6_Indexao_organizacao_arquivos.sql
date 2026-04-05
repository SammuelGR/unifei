--QUESTÃO 1A
CREATE DATABASE indexacao;
show data_directory;

--QUESTÃO 1B
CREATE TABLE departamento(
	numeroDepto int,
	nomeDepto varchar(30) not null,
	primary key(numeroDepto)
)

--QUESTÃO 1C
INSERT INTO departamento VALUES (1, 'Recursos Humanos');
INSERT INTO departamento VALUES (2, 'Producao');
INSERT INTO departamento VALUES (3, 'Financeiro');
INSERT INTO departamento VALUES (4, 'Almoxarifado');

--QUESTÃO 2A
SELECT * FROM departamento;

--QUESTÃO 2B
SELECT ctid, numerodepto, nomedepto FROM departamento;

--QUESTÃO 2C
SELECT ctid, * FROM northwind.order_details;

--QUESTÃO 2D
DELETE FROM departamento;

--QUESTÃO 2E
INSERT INTO departamento VALUES (2, 'Producao');
INSERT INTO departamento VALUES (1, 'Recursos Humanos');
INSERT INTO departamento VALUES (4, 'Almoxarifado');
INSERT INTO departamento VALUES (3, 'Financeiro');

--QUESTÃO 2F
SELECT * FROM departamento;
SELECT ctid, numerodepto, nomedepto FROM departamento;