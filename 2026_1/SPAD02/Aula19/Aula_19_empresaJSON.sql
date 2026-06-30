CREATE SCHEMA IF NOT EXISTS empresaJSON;

CREATE TABLE empresaJSON.funcionario (
    cpf varchar(11) PRIMARY KEY,
    nome varchar(30) NOT NULL,
    dados jsonb -- Aqui entrará o restante da estrutura
);

INSERT INTO empresaJSON.funcionario (cpf, nome, dados)
SELECT
    cpf,
    nome,
    jsonb_build_object(
        'endereco', endereco,
        'telefone', to_jsonb(telefone),
        'cargo', to_jsonb(cargo),
        'dependentes', to_jsonb(dependentes),
        'historico_salarial', to_jsonb(historico_salarial)
    )
FROM empresaBDOR.funcionario_obj;

SELECT * FROM empresaJSON.funcionario

--******Operadores de Extração - Acesso aos dados******--
-- ->retorna json
-- ->>retorna string
-- #>> recebe o caminho json
SELECT dados->'cargo' FROM empresaJSON.funcionario
SELECT dados->>'cargo' FROM empresaJSON.funcionario
SELECT dados#>>'{cargo,salariobase}' as salarioBase FROM empresaJSON.funcionario

--Selecionar funcionários que sejam do cargo 'Desenvolvedor Junior'
SELECT nome FROM empresaJSON.funcionario WHERE dados #>> '{cargo, nome}' = 'Desenvolvedor Junior';

--******Operadores de Contenção e Existência***--
--@> (Contém): Verifica se o JSON à esquerda contém a estrutura à direita.
SELECT nome FROM empresaJSON.funcionario WHERE dados @> '{"telefone": ["999998888"]}'

-- ? (Existe): Verifica se uma string existe como chave de objeto ou elemento de array.
SELECT nome FROM empresaJSON.funcionario WHERE dados ? 'dependentes'

--Remover a chave dependentes de Pedro Santos, pois ele não possui dependentes
--Operador - (Subtração): Quando aplicado a um JSONB à esquerda e um text à direita, ele remove a chave correspondente.
--Se a chave não existir, o JSON original é retornado sem erros.
UPDATE empresaJSON.funcionario SET dados = dados - 'dependentes' WHERE nome = 'Pedro Santos';


--******Operadores de Caminho (JSONPath - v12+)******--
--Introduzidos para alinhar o PostgreSQL ao padrão SQL:2016, permitem consultas complexas similares ao XPath.
-- operador @? verifica se o caminho especificado retorna algum item.
-- operador @@ avalia o resultado de um predicado booleano definido no final do path.
-- ? (@.valor < 500): O ponto de interrogação inicia um filtro de item.
SELECT * FROM empresaJSON.funcionario WHERE dados @? '$.historico_salarial[*] ? (@.valor < 500)';
SELECT * FROM empresajson.funcionario where dados @? '$.cargo.nome[*] ? (@ == "Desenvolvedor Junior")';
SELECT * FROM empresajson.funcionario where dados @? '$.dependentes.nome ? (@ == "Ana Silva")';


--Funcionários que tenham tido o último ajuste salarial em 2026
--Acesso ao Último Elemento (->-1): O PostgreSQL permite o uso de índices negativos em operadores JSONB.
--O índice -1 é um atalho para acessar o último elemento do array, independente do seu tamanho.
SELECT
    nome,
    dados->'historico_salarial'->-1->>'data' AS data_ultimo_ajuste
FROM empresaJSON.funcionario
WHERE EXTRACT(YEAR FROM (dados->'historico_salarial'->-1->>'data')::timestamp) = 2026;


--Incluir uma atualização salarial para o funcionário Pedro Santos para o ano de 2025, mantendo o array ordenado
--jsonb_set: Esta função é a forma padrão de atualizar uma chave específica dentro de um objeto JSONB sem sobrescrever todo o campo dados.
--jsonb_array_elements + UNION ALL: Como o JSONB é um formato binário, expandimos o array atual em linhas e adicionamos o novo objeto de 2025 à coleção temporária.
--jsonb_agg é uma função de agregação no PostgreSQL que transforma um conjunto de valores (linhas) em um único array JSONB.

SELECT * FROM empresaJSON.funcionario WHERE nome = 'Pedro Santos';

UPDATE empresaJSON.funcionario
SET dados = jsonb_set(
    dados,
    '{historico_salarial}',
    (
        SELECT jsonb_agg(elem ORDER BY (elem->>'data')::date)
        FROM (
            SELECT jsonb_array_elements(dados->'historico_salarial') AS elem
            UNION ALL
            SELECT '{"data": "2025-01-01", "valor": 400.00}'::jsonb
        ) sub
    )
)
WHERE nome = 'Pedro Santos';

--***********ÍNDICE GIN**************--
CREATE INDEX idx_dados_json ON empresaJSON.funcionario  USING GIN (dados);
