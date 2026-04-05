--Criar um novo schema
CREATE SCHEMA laboratorio;

-- Criando a tabela de Pacientes
CREATE TABLE laboratorio.pacientes (
    cod_paciente SERIAL PRIMARY KEY,
    nome VARCHAR(100) NOT NULL,
    endereco TEXT,
    sexo CHAR(1), -- M/F/O
    cor VARCHAR(20), -- Raça/Cor (IBGE)
    genero VARCHAR(50), -- Identidade de Gênero
    data_nascimento DATE NOT NULL
);

-- Criando a tabela de Exames (Catálogo)
CREATE TABLE laboratorio.exames (
    cod_exame SERIAL PRIMARY KEY,
    descricao VARCHAR(150) NOT NULL
);

-- Criando a tabela de Relação (Resultados de Exames)
CREATE TABLE laboratorio.resultados_exames (
    cod_resultado SERIAL PRIMARY KEY,
    cod_paciente INT REFERENCES laboratorio.pacientes(cod_paciente) ON DELETE CASCADE,
    cod_exame INT REFERENCES laboratorio.exames(cod_exame),
    data_exame TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    resultado TEXT NOT NULL
);

-- Inserindo Pacientes
INSERT INTO laboratorio.pacientes (nome, endereco, sexo, cor, genero, data_nascimento) VALUES
('João Silva Sauro', 'Rua das Flores, 123, São Paulo - SP', 'M', 'Parda', 'Homem Cis', '1985-04-12'),
('Maria Oliveira', 'Av. Paulista, 900, Apto 42, São Paulo - SP', 'F', 'Branca', 'Mulher Cis', '1992-08-25'),
('Alex Santos', 'Rua sem Nome, s/n, Curitiba - PR', 'O', 'Preta', 'Não-binário', '2000-01-10');

-- Inserindo Tipos de Exames
INSERT INTO laboratorio.exames (descricao) VALUES 
('Hemograma Completo'),
('Teste COVID-19 RT-PCR'),
('Glicemia em Jejum');

-- Relacionando Exames a Pacientes
INSERT INTO laboratorio.resultados_exames (cod_paciente, cod_exame, data_exame, resultado) VALUES
(1, 1, '2023-10-01 08:30:00', 'Hemoglobina normal: 14g/dL'),
(1, 2, '2023-10-05 10:00:00', 'Negativo'),
(2, 3, '2023-11-12 07:15:00', '95 mg/dL');

--Visualizar como os dados estão armazenados no banco
SELECT * FROM laboratorio.pacientes;
SELECT * FROM laboratorio.exames;
SELECT * FROM laboratorio.resultados_exames;

--*******CRIAR A ROLE analista_dados******----
CREATE ROLE analista_jr;

--Privilégios da Role
GRANT USAGE ON SCHEMA laboratorio TO analista_jr;
GRANT SELECT ON ALL TABLES IN SCHEMA laboratorio TO analista_jr;

--Criar o usuário Carlos e associá-lo à role analista_jr
CREATE USER carlos WITH PASSWORD '123456'
GRANT analista_jr TO carlos

--Logar como carlos e acessar a tabela pacientes

--******MASCARAMENTO DINÂMICO COM VIEW******--
-- O objetivo é permitir que um usuário veja os dados, mas não consiga identificar o paciente individualmente.
-- Nome: Exibe apenas a primeira e a última letra, com asteriscos no meio.
-- Endereço: Exibe apenas a Cidade/Estado (removendo rua e número).
-- Data de Nascimento: Exibe apenas o Ano (Generalização).

CREATE VIEW laboratorio.v_pacientes_mascarados AS
SELECT 
    cod_paciente,
    -- Mascara o nome: 'Joao Silva' vira 'J*********a'
    overlay(nome placing repeat('*', length(nome) - 2) from 2 for length(nome) - 2) AS nome_mascarado,
    
    -- Extrai apenas a cidade/estado do endereço (assumindo formato 'Rua, Numero, Cidade - UF')
    regexp_replace(endereco, '^.*, (.* - .*)$', '\1') AS localizacao_geral,
    
    sexo,
    cor,
    genero,
    
    -- Generaliza a data para apenas o ano
    EXTRACT(YEAR FROM data_nascimento) AS ano_nascimento
FROM laboratorio.pacientes;

SELECT * FROM laboratorio.v_pacientes_mascarados

--Atualizar os privilégios de analista_jr e consequentemente, de Carlos
REVOKE SELECT ON laboratorio.pacientes FROM analista_jr;
GRANT SELECT ON laboratorio.v_pacientes_mascarados TO analista_jr;


--******* Substituição (Tokenização) ****** --
-- O objetivo é substituir um dado real por um valor fictício fixo ("token") em uma tabela separada.
-- Exemplo: Resultado negativo de exame ou valores normais dentro do esperado vira "X0"
--			Resultado positivo de exame ou valores fora do normal esperado vira "Q1"
-- Ou seja, quem vê a tabela não sabe reconhecer o que é X0, nem Q1
-- Mas o analista pode ter um dicionário de tokens:
-- X0 -> Dentro da normalidade e Q1 -> Alteração detectada. 
-- Ele não sabe qual e o exame, apenas sabe o resultado.

CREATE TABLE laboratorio.de_para_tokens (
    token_id SERIAL PRIMARY KEY,
	token_value VARCHAR(50),
    resultado_real TEXT NOT NULL
);

-- Inserindo os mapeamentos dos tokens - dicionário de tokens
INSERT INTO laboratorio.de_para_tokens (token_value, resultado_real) VALUES 
('X0', 'Hemoglobina normal: 14g/dL'),
('X0', 'Negativo'),
('Q1', '95 mg/dL');

-- Criando uma View que faz a troca (Substituição Determinística)
CREATE VIEW laboratorio.v_resultados_tokenizados AS
SELECT 
    r.cod_resultado,
    r.cod_paciente,
    r.data_exame,
    t.token_value AS resultado_substituido
FROM laboratorio.resultados_exames r
JOIN laboratorio.de_para_tokens t ON r.resultado = t.resultado_real;

SELECT * FROM laboratorio.v_resultados_tokenizados

--Ajustando os privilégios
--Logar como Carlos e acessar a tabela laboratorio.resultados_exames
REVOKE SELECT ON laboratorio.resultados_exames FROM analista_jr
GRANT SELECT ON laboratorio.v_resultados_tokenizados TO analista_jr

--*******  Pseudonimização (HASH) ******** --
-- Diferente da tokenização comum (que usa uma tabela "De/Para" com valores aleatórios), 
-- 		o hashing é determinístico: o mesmo valor de entrada sempre resultará no mesmo "token" de saída.
-- O pgcrypto é uma extensão nativa do PostgreSQL que fornece funções criptográficas de alto nível, permitindo realizar hashing (como SHA256), 
--		encriptação de dados e geração de "salts" diretamente via comandos SQL.

CREATE EXTENSION IF NOT EXISTS pgcrypto;

-- Gerando um hash SHA256 para o nome do paciente
-- Definimos uma chave secreta (O SALT)
-- Exemplo: 'ChaveMestra123'
SELECT 
    encode(digest(nome || 'ChaveMestra123', 'sha256'), 'hex') AS nome_pseudonimizado,
    resultado
FROM laboratorio.pacientes p
JOIN laboratorio.resultados_exames r ON p.cod_paciente = r.cod_paciente;

-- Usando outro atributo como salt
SELECT 
    -- Usando o cod_paciente como salt (cada linha tem um hash único, mesmo para nomes iguais)
    encode(digest(nome || cod_paciente::text, 'sha256'), 'hex') AS id_paciente
FROM laboratorio.pacientes;
 
-- ******* Criptografia Reversível **** --
-- Na LGPD, isso é usado quando o dado precisa estar protegido no banco (caso alguém roube o arquivo do banco de dados), 
--		mas o sistema da clínica precisa "ler" o nome real do paciente para chamá-lo na recepção.
-- pgcrypto disponibiliza o algoritmo AES (Advanced Encryption Standard).

CREATE TABLE laboratorio.pacientes_seguros (
    cod_paciente SERIAL PRIMARY KEY,
    nome_cripto BYTEA,
    endereco_cripto BYTEA,
    sexo_cripto BYTEA,
    cor_cripto BYTEA,
    genero_cripto BYTEA,
    data_nascimento_cripto BYTEA
);

INSERT INTO laboratorio.pacientes_seguros (nome_cripto, endereco_cripto, sexo_cripto, cor_cripto, genero_cripto, data_nascimento_cripto)
VALUES (
    pgp_sym_encrypt('João Silva Sauro', 'chave_mestra_sala_aula'),
    pgp_sym_encrypt('Rua das Flores, 123, São Paulo - SP', 'chave_mestra_sala_aula'),
    pgp_sym_encrypt('M', 'chave_mestra_sala_aula'),
    pgp_sym_encrypt('Parda', 'chave_mestra_sala_aula'),
    pgp_sym_encrypt('Homem Cis', 'chave_mestra_sala_aula'),
    pgp_sym_encrypt('1985-04-12', 'chave_mestra_sala_aula')
),
(
    pgp_sym_encrypt('Maria Oliveira', 'chave_mestra_sala_aula'),
    pgp_sym_encrypt('Av. Paulista, 900, Apto 42, São Paulo - SP', 'chave_mestra_sala_aula'),
    pgp_sym_encrypt('F', 'chave_mestra_sala_aula'),
    pgp_sym_encrypt('Branca', 'chave_mestra_sala_aula'),
    pgp_sym_encrypt('Mulher Cis', 'chave_mestra_sala_aula'),
    pgp_sym_encrypt('1992-08-25', 'chave_mestra_sala_aula')
);

--Lendo os dados como estão armazenados no disco
SELECT * FROM laboratorio.pacientes_seguros;

SELECT encode(nome_cripto, 'hex') AS nome_incompreensivel 
FROM laboratorio.pacientes_seguros;

--Para descriptografar
SELECT pgp_sym_decrypt(nome_cripto, 'chave_mestra_sala_aula') AS nome_real
FROM laboratorio.pacientes_seguros;

-- **** Row-Level Security (RLS) ****** ----
-- Mecanismo de controle de acesso que permite definir políticas diretamente na tabela, 
--	determinando quais linhas cada usuário pode acessar ou manipular, com base em condições lógicas avaliadas pelo próprio banco.

--Criar uma tabela médicos
CREATE TABLE laboratorio.medicos (
    id SERIAL PRIMARY KEY,
    username TEXT UNIQUE, -- Deve ser igual ao nome da Role (dr_joao, dra_maria)
    nome TEXT,
    cidade_atuacao TEXT
);

-- Inserindo os dados dos médicos
INSERT INTO laboratorio.medicos (username, nome, cidade_atuacao) VALUES 
('dr_joao', 'Dr. João Silva', 'São Paulo'),
('dra_maria', 'Dra. Maria Terra', 'Curitiba');

--Criar o perfil médico e os usuários joão e maria
CREATE ROLE diretor_medico;
GRANT USAGE ON SCHEMA laboratorio TO diretor_medico;
GRANT SELECT ON laboratorio.pacientes TO diretor_medico;
GRANT SELECT ON laboratorio.medicos TO diretor_medico;
CREATE USER dr_joao WITH PASSWORD '123456';
GRANT diretor_medico TO dr_joao;
CREATE USER dra_maria WITH PASSWORD '123456';
GRANT diretor_medico TO dra_maria;


-- Para usar o RLS, primeiro precisa habilitá-lo na tabela
ALTER TABLE laboratorio.pacientes ENABLE ROW LEVEL SECURITY;

-- Depois, define-se políticas de acesso com base no usuário
-- Exemplo: os médicos só têm acesso aos pacientes da cidade em que residem

-- Política para o Diretor (Ver tudo)
CREATE POLICY politica_por_cidade_medico ON laboratorio.pacientes
    FOR SELECT
    USING (
        endereco ILIKE '%' || (
            SELECT cidade_atuacao 
            FROM laboratorio.medicos 
            WHERE username = current_user
        ) || '%'
    );


-- Testando
-- logar como dr_joao e fazer a consulta SELECT * FROM laboratorio.pacientes
-- logar como dra_maria e repetir a mesma consulta

--TESTAR A AUDITORIA --
-- Teste 1: Uma consulta simples (SELECT)
SELECT * FROM laboratorio.pacientes;

-- Teste 2: Uma tentativa de erro (para ver como o log registra falhas)
SELECT * FROM tabela_que_nao_existe;

-- Teste 3: Uma alteração (UPDATE)
UPDATE laboratorio.pacientes SET cor = 'Parda' WHERE cod_paciente = 1;

-- Analisar o arquivo de log após as consultas

