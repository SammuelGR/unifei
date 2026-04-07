-- Questão 1

CREATE TABLE sensor_data (
    id SERIAL PRIMARY KEY,
    timestamp TIMESTAMP DEFAULT NOW(),
    leitura NUMERIC,
    status TEXT
);

INSERT INTO sensor_data (leitura, status)
SELECT
    ROUND((random() * 80 - 30)::numeric, 2), -- [-30, 50]
    md5(random()::text)
FROM generate_series(1, 10000);

SELECT * FROM sensor_data

-- Questão 2
-- a)
SHOW data_directory;

-- c)
SELECT *, ctid FROM sensor_data ORDER BY ctid DESC

-- Questão 3
DELETE FROM sensor_data WHERE id % 2 = 0

SELECT *, ctid FROM sensor_data ORDER BY ctid DESC

-- qtd blocos
SELECT COUNT(DISTINCT split_part(ctid::text, ',', 1)) FROM sensor_data

-- Questão 6
VACUUM FULL sensor_data
