## Neo4j - Cypher CRUD

Create users

```
CREATE(M:Func {nome: "Camila"})
CREATE(M:Func {nome: "Jose"})
CREATE(M:Func {nome: "Maria"})
CREATE(M:Func {nome: "Pedro"})
```

---

Delete user

```
MATCH (m:FUNC {nome: 'Maria'}) DELETE (m)
```

```
MATCH (x:FUNC) DETACH DELETE x
```

```
MATCH (f:FUNC) WHERE elementId(f) = '...' DELETE f
```

---

Create `AMIGO_DE` relationship

```
MATCH (p:FUNC {nome: 'Pedro'}),
  (m:FUNC {nome: 'Camila'})
CREATE (p)-[:AMIGO_DE]->(m)
```

```
MATCH (j:FUNC {nome: "Jose"}), (p:FUNC {nome: "Pedro"})
CREATE (j)-[:AMIGO_DE]->(p)
```

```
MATCH (j:FUNC {nome: "Jose"}), (c:FUNC {nome: "Camila"})
CREATE (j)-[:AMIGO_DE]->(c)
```

```
MATCH (m:FUNC {nome: "Maria"}), (c:FUNC {nome: "Camila"})
CREATE (c)-[:AMIGO_DE]->(m)
```

---

Create `GERENTE_DE` relationship

```
MATCH (m:FUNC {nome: 'Maria'}), (c:FUNC {nome: 'Camila'})
CREATE (m)-[:GERENTE_DE]->(c)
```

```
MATCH (m:FUNC {nome: 'Maria'}), (p:FUNC {nome: 'Pedro'})
CREATE (m)-[:GERENTE_DE]->(p)
```

```
MATCH (m:FUNC {nome: 'Maria'}), (j:FUNC {nome: 'Jose'})
CREATE (j)-[:GERENTE_DE]->(m)
```

---

Show nodes and relationships

```
MATCH p=()-[:AMIGO_DE|GERENTE_DE]->() RETURN p
```

---

Create `PROJ` nodes and relationships with `FUNC`

```
CREATE (:PROJ {nome: 'P1'});
CREATE (:PROJ {nome: 'P2'});
CREATE (:PROJ {nome: 'P3'});
CREATE (:PROJ {nome: 'P4'});
```

```
MATCH (c:FUNC {nome: 'Camila'}), (p:PROJ {nome: 'P3'})
CREATE (c)-[:ATUA]->(p)

MATCH (m:FUNC {nome: 'Maria'}), (p:PROJ {nome: 'P3'})
CREATE (m)-[:ATUA]->(p);

MATCH (j:FUNC {nome: 'Jose'}), (p:PROJ {nome: 'P2'})
CREATE (j)-[:ATUA]->(p);

MATCH (j:FUNC {nome: 'Jose'}), (p:PROJ {nome: 'P4'})
CREATE (j)-[:ATUA]->(p);

MATCH (f:FUNC {nome: 'Pedro'}), (p:PROJ {nome: 'P1'})
CREATE (f)-[:ATUA]->(p);

MATCH (f:FUNC {nome: 'Pedro'}), (p:PROJ {nome: 'P4'})
CREATE (f)-[:ATUA]->(p);
```

---

Show nodes and results

```
MATCH p=()-[:AMIGO_DE|GERENTE_DE|ATUA]->() RETURN p
```

---

Update node

```
MATCH (p:PROJ {nome: "P2"})
SET p.nome = "Projeto Neo4J"
RETURN p
```

```
MATCH (p:PROJ {nome: "Projeto Neo4J"})
SET p.inicio = date("2024-01-01")
RETURN p
```

```
MATCH (p:PROJ {nome: "Projeto Neo4J"})
REMOVE p.inicio
RETURN p
```

---

Amigos de `Jose`:

```
MATCH (:FUNC {nome: 'Jose'})-[:AMIGO_DE]->(amigos)
RETURN amigos
```

```
MATCH (j:FUNC {nome: 'Jose'})-[r:AMIGO_DE]->(amigos)
RETURN j, r, amigos
```

De quem `Maria` é gerente?

```
MATCH (m:FUNC {nome: 'Maria'})-[r:GERENTE_DE]->(funcionarios)
RETURN m, r, funcionarios
```

De quem Maria é gerente e amiga?

```
MATCH (m:FUNC {nome: 'Maria'})-[r:GERENTE_DE|AMIGO_DE]->(funcionarios)
RETURN m, r, funcionarios
```

Em quais projetos o Pedro atuou?

```
MATCH (f:FUNC {nome: 'Pedro'})-[r:ATUA]->(p:PROJ)
RETURN f, r, p
```

Quem atuou no projeto P3?

```
MATCH (f:FUNC)-[r:ATUA]->(p:PROJ {nome: 'P3'})
RETURN f, r, p
```

-roteiro-

```
MATCH (inicio:FUNC {nome: 'Beatriz'}), (fim:FUNC {nome: 'Pedro'}),
p = shortestPath((inicio)-[:AMIGO_DE*]-(fim))
RETURN p
```
