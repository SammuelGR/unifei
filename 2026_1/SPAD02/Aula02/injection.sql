-- Remover tabelas caso já existam
DROP TABLE IF EXISTS cadastro_usuario;
DROP TABLE IF EXISTS usuarios;

-- Tabela de autenticação
CREATE TABLE usuarios (
    id_usuario SERIAL PRIMARY KEY,
    login VARCHAR(50) UNIQUE NOT NULL,
    senha VARCHAR(100) NOT NULL
);

-- Tabela com dados sensíveis do usuário
CREATE TABLE cadastro_usuario (
    id_cadastro SERIAL PRIMARY KEY,
    id_usuario INTEGER REFERENCES usuarios(id_usuario),
    nome VARCHAR(100) NOT NULL,
    cpf CHAR(11) NOT NULL,
    email VARCHAR(100),
    telefone VARCHAR(20),
    data_nascimento DATE
);

-- Inserção de usuários (login e senha)
INSERT INTO usuarios (login, senha) VALUES
('user1', 'senha123'),
('user2', 'abc123'),
('user3', 'teste123'),
('user4', 'senha456'),
('user5', 'qwerty'),
('user6', '123456'),
('user7', 'admin123'),
('user8', 'pass789'),
('user9', 'login321'),
('user10', 'segredo');

-- Inserção dos dados sensíveis
INSERT INTO cadastro_usuario (id_usuario, nome, cpf, email, telefone, data_nascimento) VALUES
(1, 'Ana Silva', '12345678901', 'ana@email.com', '11999990001', '1995-03-12'),
(2, 'Bruno Costa', '23456789012', 'bruno@email.com', '11999990002', '1992-07-21'),
(3, 'Carla Mendes', '34567890123', 'carla@email.com', '11999990003', '1988-11-09'),
(4, 'Daniel Souza', '45678901234', 'daniel@email.com', '11999990004', '1990-05-14'),
(5, 'Eduarda Lima', '56789012345', 'eduarda@email.com', '11999990005', '1997-01-30'),
(6, 'Felipe Rocha', '67890123456', 'felipe@email.com', '11999990006', '1985-09-18'),
(7, 'Gabriela Alves', '78901234567', 'gabriela@email.com', '11999990007', '1993-12-02'),
(8, 'Henrique Martins', '89012345678', 'henrique@email.com', '11999990008', '1991-06-11'),
(9, 'Isabela Ferreira', '90123456789', 'isabela@email.com', '11999990009', '1996-04-27'),
(10, 'João Pereira', '01234567890', 'joao@email.com', '11999990010', '1989-08-15');