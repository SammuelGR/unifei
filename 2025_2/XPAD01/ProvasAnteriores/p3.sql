-- Criação das tabelas
CREATE TABLE proprietario (
 codigo INT PRIMARY KEY,
 cpf CHAR(11) NOT NULL,
 nome VARCHAR(60) NOT NULL,
 identidade VARCHAR(20) NOT NULL,
 datanasc DATE NOT NULL,
 tipo CHAR(1) NOT NULL
);
CREATE TABLE tipomulta (
 codigo INT PRIMARY KEY,
 nome VARCHAR(50) NOT NULL,
 descricao VARCHAR(200) NOT NULL,
 valor NUMERIC(10,2) NOT NULL
);
CREATE TABLE veiculo (
 codigo INT PRIMARY KEY,
 placa CHAR(7) NOT NULL,
 qtdemultas INT NOT NULL,
 somamultas NUMERIC(10,2) NOT NULL,
 codproprietario INT NOT NULL,
 CONSTRAINT fk_veiculo_proprietario
 FOREIGN KEY (codproprietario)
 REFERENCES proprietario(codigo)
);
CREATE TABLE multa (
 codigo INT PRIMARY KEY,
 data DATE NOT NULL,
 codtipo INT NOT NULL,
 codveiculo INT NOT NULL,
 status CHAR(1) NOT NULL,
 CONSTRAINT ck_multa_status
 CHECK (status IN ('R','A','C','P')),
 CONSTRAINT fk_multa_veiculo
 FOREIGN KEY (codveiculo)
 REFERENCES veiculo(codigo),
 CONSTRAINT fk_multa_tipomulta
 FOREIGN KEY (codtipo)
 REFERENCES tipomulta(codigo)
);
----------------------------------------------------
-- Inclusão de dados
----------------------------------------------------
-- 5 proprietários
INSERT INTO proprietario (codigo, cpf, nome, identidade, datanasc, tipo) VALUES
(1, '11111111111', 'Ana Silva', 'MG123456', '1985-03-10', 'F'),
(2, '22222222222', 'Bruno Souza', 'MG234567', '1979-07-21', 'F'),
(3, '33333333333', 'Carla Ferreira', 'MG345678', '1990-11-05', 'F'),
(4, '44444444444', 'Daniel Oliveira', 'MG456789', '1982-01-18', 'F'),
(5, '55555555555', 'Eduardo Santos', 'MG567890', '1995-09-30', 'F');
-- 3 tipos de multa
INSERT INTO tipomulta (codigo, nome, descricao, valor) VALUES
(1, 'Excesso de velocidade', 'Velocidade acima do limite permitido', 200.00),
(2, 'Estacionamento irregular', 'Veículo estacionado em local proibido', 150.00),
(3, 'Cinto de segurança', 'Conduzir sem o uso do cinto de segurança', 180.00);
-- 5 veículos (qtdemultas e somamultas iniciam em 0)
-- Obs.: vamos deixar pelo menos um veículo sem multa (por exemplo, o veículo 5)
INSERT INTO veiculo (codigo, placa, qtdemultas, somamultas, codproprietario) VALUES
(1, 'ABC1234', 0, 0.00, 1),
(2, 'DEF5678', 0, 0.00, 2),
(3, 'GHI9012', 0, 0.00, 3),
(4, 'JKL3456', 0, 0.00, 4),
(5, 'MNO7890', 0, 0.00, 5); -- este ficará sem multa
-- 10 multas (respeitando os FKs e os status; veículo 5 não recebe multa)
INSERT INTO multa (codigo, data, codtipo, codveiculo, status) VALUES
(1, '2025-01-10', 1, 1, 'A'), -- veiculo 1
(2, '2025-01-15', 2, 1, 'P'),
(3, '2025-02-05', 3, 1, 'R'),
(4, '2025-02-20', 1, 2, 'A'), -- veiculo 2
(5, '2025-03-01', 2, 2, 'C'),
(6, '2025-03-10', 3, 3, 'A'), -- veiculo 3
(7, '2025-03-18', 1, 3, 'P'),
(8, '2025-04-02', 2, 3, 'R'),
(9, '2025-04-10', 1, 4, 'A'), -- veiculo 4
(10, '2025-04-15', 3, 4, 'P');
