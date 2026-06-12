CREATE SCHEMA IF NOT EXISTS empresa;

CREATE TABLE IF NOT EXISTS empresa.cargo
(
    cod integer NOT NULL,
    nome character varying(30) COLLATE pg_catalog."default" NOT NULL,
    salariobase numeric(5,2) NOT NULL,
    quantfunc integer NOT NULL DEFAULT 0,
    CONSTRAINT cargo_pkey PRIMARY KEY (cod),
    CONSTRAINT cargo_nome_key UNIQUE (nome)
);

CREATE TABLE IF NOT EXISTS empresa.funcionario
(
    cpf character varying(11) COLLATE pg_catalog."default" NOT NULL,
    nome character varying(30) COLLATE pg_catalog."default" NOT NULL,
    endereco character varying(30) COLLATE pg_catalog."default" NOT NULL,
    telefone character varying(10) COLLATE pg_catalog."default" NOT NULL,
    cargo integer NOT NULL,
    CONSTRAINT funcionario_pkey PRIMARY KEY (cpf),
    CONSTRAINT funcionario_nome_key UNIQUE (nome),
    CONSTRAINT funcionario_cargo_fkey FOREIGN KEY (cargo)
        REFERENCES empresa.cargo (cod) MATCH FULL
        ON UPDATE CASCADE
        ON DELETE RESTRICT
);

CREATE TABLE IF NOT EXISTS empresa.dependentes
(
    nome character varying(30) COLLATE pg_catalog."default" NOT NULL,
    sexo character(1) COLLATE pg_catalog."default" NOT NULL,
    datanasc date NOT NULL,
    parentesco character varying(20) COLLATE pg_catalog."default" NOT NULL,
    cpffuncionario character varying(11) COLLATE pg_catalog."default" NOT NULL,
    CONSTRAINT dependentes_pkey PRIMARY KEY (nome, cpffuncionario),
    CONSTRAINT dependentes_nome_key UNIQUE (nome),
    CONSTRAINT dependentes_cpffuncionario_fkey FOREIGN KEY (cpffuncionario)
        REFERENCES empresa.funcionario (cpf) MATCH SIMPLE
        ON UPDATE CASCADE
        ON DELETE RESTRICT
);

CREATE TABLE IF NOT EXISTS empresa.salario
(
    data date NOT NULL,
    func character varying(11) COLLATE pg_catalog."default" NOT NULL,
    valor numeric(5,2) NOT NULL,
    CONSTRAINT salario_pkey PRIMARY KEY (data, func),
    CONSTRAINT salario_func_fkey FOREIGN KEY (func)
        REFERENCES empresa.funcionario (cpf) MATCH SIMPLE
        ON UPDATE CASCADE
        ON DELETE RESTRICT
);

DELETE FROM empresa.cargo;
DELETE FROM empresa.funcionario;
DELETE FROM empresa.dependentes;
DELETE FROM empresa.salario;

SELECT * FROM empresa.cargo;

INSERT INTO empresa.cargo VALUES
    (1, 'Analista de Sistemas', 500, 1),
    (2, 'Gerente de Projetos', 850, 1),
    (3, 'Desenvolvedor Junior', 300, 1);

INSERT INTO empresa.funcionario (cpf, nome, endereco, telefone, cargo) VALUES
    ('12345678901', 'Joao Silva', 'Rua A, 10', '999998888', 1),
    ('23456789012', 'Maria Souza', 'Rua B, 20', '988887777', 2),
    ('34567890123', 'Pedro Santos', 'Rua C, 30', '977776666', 3);

INSERT INTO empresa.salario VALUES
    ('01/01/2022', '12345678901', 850.00),
    ('01/01/2023', '23456789012', 520.00),
    ('01/01/2023', '34567890123', 310.00);

INSERT INTO empresa.dependentes VALUES
    ('Ana Silva', 'F', '2014/05/10', 'Filha', '12345678901'),
    ('Carlos Souza', 'M', '2019/08/26', 'Filho', '23456789012');

--Selecionar funcionários que sejam do cargo 'Desenvolvedor Junior'
SELECT f.nome FROM empresa.funcionario f JOIN empresa.cargo c on c.cod = f.cargo
	WHERE c.nome = 'Desenvolvedor Junior'


--Funcionários que tenham tido o último ajuste salarial em 2023
SELECT f.nome FROM empresa.funcionario f JOIN (
		SELECT func, MAX(data) AS ultima_data
		FROM empresa.salario
		GROUP BY func
	) ult ON f.cpf = ult.func
	WHERE EXTRACT(YEAR FROM ult.ultima_data) = 2023;

--Incluir uma atualização salarial para o funcionário Pedro Santos para o ano de 2026
INSERT INTO empresa.salario VALUES ('2026/06/09', '34567890123', 950.00)

