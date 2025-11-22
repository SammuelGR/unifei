CREATE TABLE cliente (
cliente_id SERIAL PRIMARY KEY,
nome VARCHAR(100) NOT NULL
)

CREATE TABLE conta (
conta_id SERIAL PRIMARY KEY,
cliente_id INT NOT NULL,
saldo DECIMAL(10, 2) NOT NULL CHECK (saldo >= 0),
FOREIGN KEY (cliente_id) REFERENCES cliente(cliente_id)
)

-- ----------------

INSERT INTO cliente (nome) VALUES ('joao'), ('maria')

INSERT INTO conta (cliente_id, saldo) VALUES
(1, 1000.00), -- conta do joao
(2, 500.00); -- conta da maria

BEGIN;
UPDATE conta SET saldo = saldo + 100
WHERE conta_id = 2;
UPDATE conta SET saldo = saldo - 100
WHERE conta_id = 1
-- SELECT * FROM conta
COMMIT

BEGIN
UPDATE cliente SET nome = ‘Maria Jose’
WHERE cliente_id = 2;
-- SELECT * FROM cliente

BEGIN
UPDATE cliente SET nome = ‘Maria Jose’
WHERE cliente_id = 2;
/* UPDATE cliente SET nome = 'Maria Lucia'
WHERE cliente_id = 2 */
COMMIT
