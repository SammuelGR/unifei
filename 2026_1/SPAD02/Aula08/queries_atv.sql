-- Questão 1: Fazer o restore do banco de dados cep no servidor de banco de dados.

-- Questão 2: Analisar os índices existentes na tabela log_logradouro.
SELECT * FROM pg_indexes WHERE tablename = 'log_logradouro'

-- Questão 3– Índice Primário: Para todas os comandos que envolvam consultas, utilize o
-- comando EXPLAIN ANALYZE e avalie a quantidade de registros recuperada, o tempo para
-- executar o comando e método de acesso.

-- a) Recuperar todos os registros da tabela log_logradouro;
SELECT * FROM cep.log_logradouro
-- Total rows: 909585
-- Query complete 00:00:00.693

EXPLAIN ANALYZE SELECT * FROM cep.log_logradouro
-- Seq Scan, rows=909585, "Planning Time: 0.060 ms", "Execution Time: 69.320 ms"

-- b) Quais são os índices existentes na tabela log_logradouro?
SELECT * FROM pg_indexes WHERE tablename = 'log_logradouro'
-- "log_logradouro_pkey", "CREATE UNIQUE INDEX log_logradouro_pkey ON cep.log_logradouro USING btree (log_nu_sequencial)"

-- c) Recuperar todos os registros da tabela log_logradouro onde log_nu_sequencial
-- < 10

EXPLAIN ANALYZE SELECT * FROM cep.log_logradouro WHERE log_nu_sequencial < 10
-- Index Scan, rows=7, "Planning Time: 0.255 ms", "Execution Time: 0.047 ms"

-- d) Recuperar todos os registros da tabela log_logradouro onde log_nu_sequencial
-- >10
EXPLAIN ANALYZE SELECT * FROM cep.log_logradouro WHERE log_nu_sequencial > 10
-- Seq Scan, rows=909577, "Planning Time: 0.405 ms", "Execution Time: 93.695 ms"

-- e) Recuperar o registro de log_nu_sequencial = 15 da tabela log_logradouro
EXPLAIN ANALYZE SELECT * FROM cep.log_logradouro WHERE log_nu_sequencial = 15
-- Index Scan, rows=1, "Planning Time: 0.266 ms", "Execution Time: 0.057 ms"

-- f) Deletar o registro de log_nu_sequencial = 15 da tabela log_logradouro
EXPLAIN ANALYZE DELETE FROM cep.log_logradouro WHERE log_nu_sequencial = 15
-- Index Scan, rows=1, "Planning Time: 2.511 ms", "Execution Time: 4.220 ms"

-- g) Recuperar o registro de log_nu_sequencial = 15 da tabela log_logradouro
EXPLAIN ANALYZE SELECT * FROM cep.log_logradouro WHERE log_nu_sequencial = 15
-- Index Scan, rows=1 🤔, "Planning Time: 0.202 ms", "Execution Time: 0.038 ms"

-- Questão 4 – Índice Secundário
-- a) Recuperar todos os registros da tabela log_logradouro onde ufe_sg = 'AC' e
-- log_tipo_logradouro = 'Avenida';
EXPLAIN ANALYZE SELECT * FROM cep.log_logradouro
    WHERE ufe_sg = 'AC' AND log_tipo_logradouro = 'Avenida'
-- Parallel Seq Scan, rows=79, "Workers Planned: 2, Workers Launched: 2,
-- Gather rows=189, "Planning Time: 0.103 ms", "Execution Time: 62.925 ms"

-- b) Crie um índice (btree) na coluna ufe_sg da tabela log_logradouro
CREATE INDEX idx_ufe_sg ON cep.log_logradouro(ufe_sg)

-- c) Refaça a questão a.
-- "Bitmap Heap Scan on log_logradouro  (cost=35.21..7544.64 rows=189 width=147) (actual time=1.646..2.887 rows=139 loops=1)"
-- "  Recheck Cond: ((ufe_sg)::text = 'AC'::text)"
-- "  Filter: ((log_tipo_logradouro)::text = 'Avenida'::text)"
-- "  Rows Removed by Filter: 3126"
-- "  Heap Blocks: exact=74"
-- "  ->  Bitmap Index Scan on idx_ufe_sg  (cost=0.00..35.16 rows=3032 width=0) (actual time=1.595..1.595 rows=3265 loops=1)"
-- "        Index Cond: ((ufe_sg)::text = 'AC'::text)"
-- "Planning Time: 0.915 ms"
-- "Execution Time: 2.991 ms"

-- d) Crie um índice (btree) na coluna log_tipo_logradouro da tabela log_logradouro
CREATE INDEX idx_tipo_logradouro ON cep.log_logradouro(log_tipo_logradouro)

-- e) Refaça a questão a.
-- "Bitmap Heap Scan on log_logradouro  (cost=656.48..1348.00 rows=189 width=147) (actual time=3.547..3.759 rows=139 loops=1)"
-- "  Recheck Cond: (((ufe_sg)::text = 'AC'::text) AND ((log_tipo_logradouro)::text = 'Avenida'::text))"
-- "  Heap Blocks: exact=29"
-- "  ->  BitmapAnd  (cost=656.48..656.48 rows=189 width=0) (actual time=3.528..3.528 rows=0 loops=1)"
-- "        ->  Bitmap Index Scan on idx_ufe_sg  (cost=0.00..35.16 rows=3032 width=0) (actual time=0.140..0.140 rows=3265 loops=1)"
-- "              Index Cond: ((ufe_sg)::text = 'AC'::text)"
-- "        ->  Bitmap Index Scan on idx_tipo_logradouro  (cost=0.00..620.97 rows=56606 width=0) (actual time=3.372..3.372 rows=56624 loops=1)"
-- "              Index Cond: ((log_tipo_logradouro)::text = 'Avenida'::text)"
-- "Planning Time: 0.378 ms"
-- "Execution Time: 3.818 ms"

-- Questão 5 – Índice Composto
-- a) Apague os índices criados na letra b e na letra d da questão 4.
DROP INDEX cep.idx_ufe_sg
DROP INDEX cep.idx_tipo_logradouro

-- b) Crie um índice composto utilizando os atributos ufe_sg e log_tipo_logradouro
CREATE INDEX idx_ufe_sg_and_tipo_logradouro
    ON cep.log_logradouro(log_tipo_logradouro, ufe_sg)

-- c) Refaça a questão 4a
-- "Index Scan using idx_ufe_sg_and_tipo_logradouro on log_logradouro  (cost=0.42..648.99 rows=189 width=147) (actual time=0.105..0.353 rows=139 loops=1)"
-- "  Index Cond: (((log_tipo_logradouro)::text = 'Avenida'::text) AND ((ufe_sg)::text = 'AC'::text))"
-- "Planning Time: 1.226 ms"
-- "Execution Time: 0.398 ms"
