from typing import List

def criaListaAdjacencias(adjMatrix: List[List[int]]):
    size = len(adjMatrix[0])
    adjList = {}

    for i in range(size):
        adjList[i] = []

    for i in range(size):
        for j in range(size):
            if adjMatrix[i][j] > 0:
                for _ in range(adjMatrix[i][j]):
                    adjList[i].append(j)

    print(adjList)

criaListaAdjacencias([[0, 1, 0, 0], [1, 0, 1, 1], [0, 0, 0, 0], [0, 1, 1, 0]])

# input: [[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]]

# output: {0: [1], 1: [0, 2, 3], 2: [1, 3], 3: [1, 2]}