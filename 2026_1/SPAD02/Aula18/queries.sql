-- CLIENTE -- Dado complexo

CREATE TYPE endereco AS (
    rua     TEXT,
    numero  TEXT,
    bairro  TEXT,
    cidade  TEXT,
    CEP     TEXT
);

CREATE TABLE cliente (
    cpf     INT PRIMARY KEY,
    nome    TEXT,
    senha   TEXT,
    login   TEXT,
    endereco endereco,
    telefone TEXT[3]
);

INSERT INTO cliente VALUES (
    111,
    'Adagoberto',
    'senha_forte',
    'adago',
    ROW(
        'Rua Amarela', '10', 'Bairro Maneiro', 'São Paulo', '10000-001'
    ),
    '{"1111-1111", "2222-2222"}'
);

INSERT INTO cliente VALUES (
    222,
    'Bertolino',
    'senha_fraca',
    'berto',
    ROW(
        'Rua Branca', '20', 'Bairro Paia', 'São Paulo', '10000-200'
    ),
    '{"3333-3333", "4444-4444"}'
);

INSERT INTO cliente VALUES (
    333,
    'Crioscopio',
    'senha_diferente',
    'criosc',
    ROW(
        'Rua Cinza', '30', 'Bairro Distante', 'São Paulo', '10000-333'
    ),
    '{"6666-6666", "7777-7777"}'
);

SELECT * FROM cliente;

--- PAGAMENTO -- Herança

CREATE TABLE pagamento (
    id_pagamento    INT PRIMARY KEY,
    valor           NUMERIC,
    data            DATE
);

CREATE TABLE pgto_cartao_de_credito  (
    nro_cartao      TEXT,
    nome            TEXT,
    nro_seguranca    TEXT
) INHERITS(pagamento);

CREATE TABLE pgto_boleto_bancario  (
    cod_barras      TEXT,
    vencimento      DATE
) INHERITS(pagamento);

INSERT INTO pgto_cartao_de_credito VALUES (
    1, 200, '2026-06-02', '123 321 123', 'Adagoberto', '666'
);

INSERT INTO pgto_boleto_bancario VALUES (
    2, 150, '2026-06-02', '101010010101', '2026-06-20'
);

SELECT * FROM pagamento;
SELECT * FROM pgto_cartao_de_credito;
SELECT * FROM pgto_boleto_bancario;

-- POLIMORFISMO

CREATE FUNCTION fazpagamento(int, numeric, date, text, text, text)
RETURNS bool AS
$BODY$
	declare
		id_pagamento alias for $1;
		valor alias for $2;
		data alias for $3;
		nro_cartao alias for $4;
		nome alias for $5;
		nro_seguranca alias for $6;
	begin
		INSERT INTO pgto_cartao_de_credito VALUES (id_pagamento, valor, data, nro_cartao, nome, nro_seguranca);
		RAISE NOTICE 'Pagamento efetuado por cartão com sucesso!';
	RETURN true;
	end;
$BODY$
LANGUAGE 'plpgsql' VOLATILE;

CREATE FUNCTION fazpagamento(int, numeric, date, text, date)
RETURNS bool AS
$BODY$
	declare
		id_pagamento alias for $1;
		valor alias for $2;
		data alias for $3;
		cod_barras alias for $4;
		vencimento alias for $5;
	begin
		INSERT INTO pgto_boleto_bancario VALUES (id_pagamento, valor, data, cod_barras, vencimento);
		RAISE NOTICE 'Pagamento efetuado por boleto com sucesso!';
	RETURN true;
	end;
$BODY$
LANGUAGE 'plpgsql' VOLATILE;

SELECT fazpagamento(3, 67.52, '2020-11-03', '574963875', 'JOSE DA SILVA', '123'); -- CARTAO
SELECT fazpagamento(4, 98.64, '2020-11-03', '256.888.777.99', '2020-11-05'); -- BOLETO

SELECT * FROM pagamento;
SELECT * FROM pgto_boleto_bancario;
SELECT * FROM pgto_cartao_de_credito;