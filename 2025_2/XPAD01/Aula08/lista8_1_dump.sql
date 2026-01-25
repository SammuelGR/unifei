--
-- PostgreSQL database dump
--

-- Dumped from database version 9.3.5
-- Dumped by pg_dump version 9.3.5
-- Started on 2015-05-13 16:41:44

SET statement_timeout = 0;
SET lock_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SET check_function_bodies = false;
SET client_min_messages = warning;

--
-- TOC entry 174 (class 3079 OID 11750)
-- Name: plpgsql; Type: EXTENSION; Schema: -; Owner: 
--

CREATE EXTENSION IF NOT EXISTS plpgsql WITH SCHEMA pg_catalog;


--
-- TOC entry 1963 (class 0 OID 0)
-- Dependencies: 174
-- Name: EXTENSION plpgsql; Type: COMMENT; Schema: -; Owner: 
--

COMMENT ON EXTENSION plpgsql IS 'PL/pgSQL procedural language';


SET search_path = public, pg_catalog;

SET default_tablespace = '';

SET default_with_oids = false;

--
-- TOC entry 173 (class 1259 OID 295655)
-- Name: alocacao; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE alocacao (
    codp integer NOT NULL,
    codf integer NOT NULL,
    horas double precision,
    CONSTRAINT alocacao_horas_check CHECK ((horas > (0)::double precision))
);


ALTER TABLE public.alocacao OWNER TO postgres;

--
-- TOC entry 170 (class 1259 OID 295635)
-- Name: departamento; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE departamento (
    codigo integer NOT NULL,
    nome character varying(100)
);


ALTER TABLE public.departamento OWNER TO postgres;

--
-- TOC entry 171 (class 1259 OID 295640)
-- Name: funcionario; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE funcionario (
    codigo integer NOT NULL,
    nome character varying(100) NOT NULL,
    salario double precision NOT NULL,
    dept integer NOT NULL
);


ALTER TABLE public.funcionario OWNER TO postgres;

--
-- TOC entry 172 (class 1259 OID 295650)
-- Name: projeto; Type: TABLE; Schema: public; Owner: postgres; Tablespace: 
--

CREATE TABLE projeto (
    codigo integer NOT NULL,
    nome character varying(150) NOT NULL
);


ALTER TABLE public.projeto OWNER TO postgres;

--
-- TOC entry 1955 (class 0 OID 295655)
-- Dependencies: 173
-- Data for Name: alocacao; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO alocacao VALUES (1, 2, 20);
INSERT INTO alocacao VALUES (1, 1, 10);
INSERT INTO alocacao VALUES (2, 3, 15);
INSERT INTO alocacao VALUES (2, 5, 5);
INSERT INTO alocacao VALUES (3, 4, 5);
INSERT INTO alocacao VALUES (3, 1, 2);
INSERT INTO alocacao VALUES (3, 2, 2);
INSERT INTO alocacao VALUES (3, 3, 5);
INSERT INTO alocacao VALUES (3, 5, 15);
INSERT INTO alocacao VALUES (3, 6, 15);
INSERT INTO alocacao VALUES (3, 7, 15);
INSERT INTO alocacao VALUES (3, 8, 15);
INSERT INTO alocacao VALUES (3, 9, 15);
INSERT INTO alocacao VALUES (3, 10, 15);
INSERT INTO alocacao VALUES (1, 3, 2);


--
-- TOC entry 1952 (class 0 OID 295635)
-- Dependencies: 170
-- Data for Name: departamento; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO departamento VALUES (1, 'DMC');
INSERT INTO departamento VALUES (2, 'IFQ');


--
-- TOC entry 1953 (class 0 OID 295640)
-- Dependencies: 171
-- Data for Name: funcionario; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO funcionario VALUES (1, 'Antonio', 5000, 1);
INSERT INTO funcionario VALUES (2, 'Joao', 21000, 1);
INSERT INTO funcionario VALUES (3, 'Lucia', 25600, 1);
INSERT INTO funcionario VALUES (4, 'Bia', 12500, 1);
INSERT INTO funcionario VALUES (5, 'Geraldo', 2500, 1);
INSERT INTO funcionario VALUES (6, 'Simone', 21000, 2);
INSERT INTO funcionario VALUES (7, 'Melina', 25000, 2);
INSERT INTO funcionario VALUES (8, 'Rafael', 19250, 2);
INSERT INTO funcionario VALUES (9, 'Luciano', 26800, 2);
INSERT INTO funcionario VALUES (10, 'Jorge', 5400, 2);


--
-- TOC entry 1954 (class 0 OID 295650)
-- Dependencies: 172
-- Data for Name: projeto; Type: TABLE DATA; Schema: public; Owner: postgres
--

INSERT INTO projeto VALUES (1, 'Qualidade de Dados Governamentais');
INSERT INTO projeto VALUES (2, 'Visualização de Dados Publicos');
INSERT INTO projeto VALUES (3, 'Mineração de Dados Geolocalizados');


--
-- TOC entry 1841 (class 2606 OID 295660)
-- Name: alocacao_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY alocacao
    ADD CONSTRAINT alocacao_pkey PRIMARY KEY (codp, codf);


--
-- TOC entry 1835 (class 2606 OID 295639)
-- Name: departamento_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY departamento
    ADD CONSTRAINT departamento_pkey PRIMARY KEY (codigo);


--
-- TOC entry 1837 (class 2606 OID 295644)
-- Name: funcionario_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY funcionario
    ADD CONSTRAINT funcionario_pkey PRIMARY KEY (codigo);


--
-- TOC entry 1839 (class 2606 OID 295654)
-- Name: projeto_pkey; Type: CONSTRAINT; Schema: public; Owner: postgres; Tablespace: 
--

ALTER TABLE ONLY projeto
    ADD CONSTRAINT projeto_pkey PRIMARY KEY (codigo);


--
-- TOC entry 1844 (class 2606 OID 295666)
-- Name: alocacao_codf_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY alocacao
    ADD CONSTRAINT alocacao_codf_fkey FOREIGN KEY (codf) REFERENCES funcionario(codigo);


--
-- TOC entry 1843 (class 2606 OID 295661)
-- Name: alocacao_codp_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY alocacao
    ADD CONSTRAINT alocacao_codp_fkey FOREIGN KEY (codp) REFERENCES projeto(codigo);


--
-- TOC entry 1842 (class 2606 OID 295645)
-- Name: funcionario_dept_fkey; Type: FK CONSTRAINT; Schema: public; Owner: postgres
--

ALTER TABLE ONLY funcionario
    ADD CONSTRAINT funcionario_dept_fkey FOREIGN KEY (dept) REFERENCES departamento(codigo);


--
-- TOC entry 1962 (class 0 OID 0)
-- Dependencies: 5
-- Name: public; Type: ACL; Schema: -; Owner: postgres
--

REVOKE ALL ON SCHEMA public FROM PUBLIC;
REVOKE ALL ON SCHEMA public FROM postgres;
GRANT ALL ON SCHEMA public TO postgres;
GRANT ALL ON SCHEMA public TO PUBLIC;


-- Completed on 2015-05-13 16:41:44

--
-- PostgreSQL database dump complete
--

