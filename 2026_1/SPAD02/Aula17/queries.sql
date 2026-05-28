CREATE TABLE cidades (
	idCidade	int,
	nome		text,
	populacao	float,
	altitude	int,
	primary key (idCidade)
);

CREATE TABLE capitais (
	estado		char(2)
) INHERITS (cidades);

INSERT INTO cidades VALUES (
	1, 'Campinas', 2000000.00, 1000
);

INSERT INTO capitais VALUES (
	2, 'São Paulo', 4000000.00, 700, 'SP'
);

SELECT * FROM cidades;
SELECT * FROM ONLY cidades;

SELECT * FROM capitais;
