Melhorar o escopo para consultas complexas
Criar nós departamento

```
CREATE (d1:DEPTO {nome: 'Tecnologia'});
CREATE (d2:DEPTO {nome: 'Produtos'});
CREATE (d3:DEPTO {nome: 'Design'});
```

Criar novos funcionários

```
CREATE (l:FUNC {nome: 'Lucas', cargo: 'UX Designer', salario: 6000});
CREATE (b:FUNC {nome: 'Beatriz', cargo: 'Dev Junior', salario: 4000});
```

Atualizar os funcionários que já existem
Atualizar dados da Maria

```
MATCH (f:FUNC {nome: 'Maria'})
SET f.cargo = 'Tech Lead', f.salario = 12000
```

Atualizar dados do Pedro

```
MATCH (f:FUNC {nome: 'Pedro'})
SET f.cargo = 'Dev Senior', f.salario = 8500
```

// Atualizar dados do Jose

```
MATCH (f:FUNC {nome: 'Jose'})
SET f.cargo = 'Gerente de TI', f.salario = 15000
```

// Atualizar dados da Camila

```
MATCH (f:FUNC {nome: 'Camila'})
SET f.cargo = 'Dev Pleno', f.salario = 6500
```

//Atualizar os nós de projetos
// Atualizar projetos individualmente

```
MATCH (p:PROJ {nome: 'P1'})
SET p.area = 'Mobile', p.orcamento = 50000

MATCH (p:PROJ {nome: 'P2'})
SET p.area = 'Web', p.orcamento = 120000;

MATCH (p:PROJ {nome: 'P3'})
SET p.area = 'AI', p.orcamento = 300000;

MATCH (p:PROJ {nome: 'P4'})
SET p.area = 'Infra', p.orcamento = 80000;
```

//CRIAR NÓS DE HABILIDADES/TECNOLOGIAS

```
CREATE (t1:TECH {nome: 'Python'});
CREATE (t2:TECH {nome: 'Neo4j'});
CREATE (t3:TECH {nome: 'React'});
CREATE (t4:TECH {nome: 'Figma'});
```

//ATUALIZAR RELACIONAMENTOS DOS NOVOS FUNCIONÁRIOS

```
MATCH (m:FUNC {nome: 'Maria'}), (b:FUNC {nome: 'Beatriz'})
CREATE (m)-[:GERENTE_DE]->(b);

MATCH (j:FUNC {nome: 'Jose'}), (l:FUNC {nome: 'Lucas'})
CREATE (j)-[:GERENTE_DE]->(l);

MATCH (b:FUNC {nome: 'Beatriz'}), (c:FUNC {nome: 'Camila'}) CREATE (b)-[:AMIGO_DE]->(c);
MATCH (l:FUNC {nome: 'Lucas'}), (m:FUNC {nome: 'Maria'}) CREATE (l)-[:AMIGO_DE]->(m);
```

//CRIAR OS RELACIONAMENTOS DE FUNCIONÁRIO E DEPARTAMENTOS

```
MATCH (f:FUNC), (d:DEPTO)
WHERE f.nome IN ['Maria', 'Pedro', 'Camila', 'Beatriz'] AND d.nome = 'Tecnologia'
CREATE (f)-[:PERTENCE_A]->(d);

MATCH (l:FUNC {nome: 'Lucas'}), (d:DEPTO {nome: 'Design'})
CREATE (l)-[:PERTENCE_A]->(d);

MATCH (j:FUNC {nome: 'Jose'}), (d:DEPTO {nome: 'Produtos'})
CREATE (j)-[:PERTENCE_A]->(d);
```

//CRIAR OS RELACIONAMENTOS DE ATUA para os novos funcionários

```
MATCH (b:FUNC {nome: 'Beatriz'}), (p2:PROJ {nome: 'P2'})
CREATE (b)-[:ATUA {horasSemanais: 40}]->(p2);

MATCH (l:FUNC {nome: 'Lucas'}), (p1:PROJ {nome: 'P1'})
CREATE (l)-[:ATUA {horasSemanais: 40}]->(p1);
```

//ATUALIZAR OS RELACIONAMENTOS ATUA PARA INCLUIR QUANTIDADE DE HORAS
// Atualizar horas da Maria no P3

```
MATCH (m:FUNC {nome: 'Maria'})-[r:ATUA]->(p:PROJ {nome: 'P3'})
SET r.horasSemanais = 40
```

// Atualizar horas da Camila no P3
MATCH (c:FUNC {nome: 'Camila'})-[r:ATUA]->(p:PROJ {nome: 'P3'})
SET r.horasSemanais = 30;

// Atualizar horas de Pedro no P1 e P4
MATCH (f:FUNC {nome: 'Pedro'})-[r1:ATUA]->(p1:PROJ {nome: 'P1'}), (f)-[r2:ATUA]->(p2:PROJ {nome: 'P4'})
SET r1.horasSemanais = 20,
r2.horasSemanais = 20

`fuckp2`

// Atualizar horas de Jose no P2 e P4
MATCH (f:FUNC {nome: 'Jose'})-[r1:ATUA]->(p1:PROJ {nome: 'P2'}), (f)-[r2:ATUA]->(p2:PROJ {nome: 'P4'})
SET r1.horasSemanais = 30,
r2.horasSemanais = 10

// RELACIONAMENTOS DE HABILIDADE (SABE_USAR)

```
MATCH (m:FUNC {nome: 'Maria'}), (t1:TECH {nome: 'Python'}), (t2:TECH {nome: 'Neo4j'})
CREATE (m)-[:SABE_USAR]->(t1), (m)-[:SABE_USAR]->(t2);

MATCH (c:FUNC {nome: 'Camila'}), (t2:TECH {nome: 'Neo4j'}), (t3:TECH {nome: 'React'})
CREATE (c)-[:SABE_USAR]->(t2), (c)-[:SABE_USAR]->(t3);

MATCH (l:FUNC {nome: 'Lucas'}), (t4:TECH {nome: 'Figma'})
CREATE (l)-[:SABE_USAR]->(t4);
```

//\***\*CONSULTAS\*\*\***//
//Ver o modelo inteiro
MATCH (n)-[r]->(m)
WHERE (n:FUNC OR n:PROJ OR n:DEPTO OR n:TECH)
AND (m:FUNC OR m:PROJ OR m:DEPTO OR m:TECH)
RETURN n, r, m

//Quem são os amigos dos amigos da Maria?
MATCH (m:FUNC {nome: 'Maria'})-[r:AMIGO_DE*2]-(f:FUNC) RETURN f

//Quais são os projetos que os amigos da Maria participam?
MATCH (m:FUNC {nome: 'Maria'})-[:AMIGO_DE]-(amigo:FUNC)-[:ATUA]->(p:PROJ)
RETURN DISTINCT p.nome AS Projeto, amigo.nome AS AmigoQueAtua

//Quais são os projetos que os amigos da Maria não participam?
MATCH (p:PROJ)
WHERE NOT EXISTS
{
MATCH (m:FUNC {nome: 'Maria'})-[:AMIGO_DE]-(amigo:FUNC)-[:ATUA]->(p)
}
RETURN p.nome AS ProjetoOndeAmigosNaoAtuam

//calcular a soma das horas trabalhadas por projeto
