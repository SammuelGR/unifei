def verificaAdjacenciaLista(adjList, vi, vj):
    print(vi in adjList[vj] or vj in adjList[vi])

verificaAdjacenciaLista({0: [1], 1: [0, 2, 3], 2: [1, 3], 3: [1, 2]}, 0, 3)

# input: {0: [1], 1: [0, 2, 3], 2: [1, 3], 3: [1, 2]}, 0, 3
# output: False
