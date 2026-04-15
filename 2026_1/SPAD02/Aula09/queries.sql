-- Essa prática deve ser executada no SGBD PostgreSQL, banco cep

-- Questão 1 – Comandos Diversos: Para todas os comandos que envolvam consultas,
-- utilize o comando EXPLAIN ANALYZE e avalie a quantidade de registros recuperada, o
-- tempo para executar o comando e método de acesso.
-- a) Recuperar os 20 primeiros registros da tabela log_logradouro onde ufe_sg = 'AC'
-- e log_tipo_logradouro = 'Avenida';

EXPLAIN ANALYZE SELECT * FROM cep.log_logradouro
    WHERE ufe_sg = 'AC' AND log_tipo_logradouro = 'Avenida'
    LIMIT 20

"Limit  (cost=0.42..69.06 rows=20 width=147) (actual time=0.049..0.065 rows=20 loops=1)"
"  ->  Index Scan using idx_ufe_sg_and_tipo_logradouro on log_logradouro  (cost=0.42..648.99 rows=189 width=147) (actual time=0.048..0.061 rows=20 loops=1)"
"        Index Cond: (((log_tipo_logradouro)::text = 'Avenida'::text) AND ((ufe_sg)::text = 'AC'::text))"
"Planning Time: 0.186 ms"
"Execution Time: 0.088 ms"

-- b) Refaça a questão a ordenando os resultados pelo atributo cep.

EXPLAIN ANALYZE SELECT * FROM cep.log_logradouro
    WHERE ufe_sg = 'AC' AND log_tipo_logradouro = 'Avenida'
    ORDER BY cep

"Sort  (cost=656.14..656.61 rows=189 width=147) (actual time=0.320..0.338 rows=139 loops=1)"
"  Sort Key: cep"
"  Sort Method: quicksort  Memory: 48kB"
"  ->  Index Scan using idx_ufe_sg_and_tipo_logradouro on log_logradouro  (cost=0.42..648.99 rows=189 width=147) (actual time=0.061..0.209 rows=139 loops=1)"
"        Index Cond: (((log_tipo_logradouro)::text = 'Avenida'::text) AND ((ufe_sg)::text = 'AC'::text))"
"Planning Time: 0.568 ms"
"Execution Time: 0.404 ms"

-- c) Avalie a consulta:
SELECT bai_nu_sequencial_ini, COUNT(bai_nu_sequencial_ini)
    FROM cep.log_logradouro
    WHERE ufe_sg = 'AC' and log_tipo_logradouro = 'Avenida'
    GROUP BY bai_nu_sequencial_ini;

EXPLAIN ANALYZE SELECT bai_nu_sequencial_ini, COUNT(bai_nu_sequencial_ini)
    FROM cep.log_logradouro
    WHERE ufe_sg = 'AC' and log_tipo_logradouro = 'Avenida'
    GROUP BY bai_nu_sequencial_ini;

"HashAggregate  (cost=649.94..651.82 rows=188 width=12) (actual time=0.144..0.154 rows=59 loops=1)"
"  Group Key: bai_nu_sequencial_ini"
"  Batches: 1  Memory Usage: 40kB"
"  ->  Index Scan using idx_ufe_sg_and_tipo_logradouro on log_logradouro  (cost=0.42..648.99 rows=189 width=4) (actual time=0.044..0.092 rows=139 loops=1)"
"        Index Cond: (((log_tipo_logradouro)::text = 'Avenida'::text) AND ((ufe_sg)::text = 'AC'::text))"
"Planning Time: 0.127 ms"
"Execution Time: 0.191 ms"

-- d) Avalie a consulta:
SELECT * FROM cep.log_bairro WHERE bai_nu_sequencial IN
    (SELECT bai_nu_sequencial
    FROM cep.log_faixa_bairro
    WHERE fcb_rad_ini = '69918')

EXPLAIN ANALYZE SELECT * FROM cep.log_bairro WHERE bai_nu_sequencial IN
    (SELECT bai_nu_sequencial
    FROM cep.log_faixa_bairro
    WHERE fcb_rad_ini = '69918')

"Nested Loop  (cost=1832.10..1906.67 rows=9 width=38) (actual time=14.110..14.171 rows=21 loops=1)"
"  ->  HashAggregate  (cost=1831.81..1831.90 rows=9 width=4) (actual time=14.084..14.090 rows=21 loops=1)"
"        Group Key: log_faixa_bairro.bai_nu_sequencial"
"        Batches: 1  Memory Usage: 24kB"
"        ->  Seq Scan on log_faixa_bairro  (cost=0.00..1831.79 rows=9 width=4) (actual time=0.021..14.059 rows=21 loops=1)"
"              Filter: ((fcb_rad_ini)::text = '69918'::text)"
"              Rows Removed by Filter: 92202"
"  ->  Index Scan using log_bairro_pkey on log_bairro  (cost=0.29..8.31 rows=1 width=38) (actual time=0.003..0.003 rows=1 loops=21)"
"        Index Cond: (bai_nu_sequencial = log_faixa_bairro.bai_nu_sequencial)"
"Planning Time: 0.781 ms"
"Execution Time: 14.240 ms"