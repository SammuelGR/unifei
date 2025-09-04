def calcDensidadeLista(adjList: dict):
    # check for directed graph
    isDirected = False
    i = 0
    for vertix in adjList.values():
        for edge in vertix:
            if i not in adjList[edge]:
                isDirected = True
                break
        i += 1

    verticesQty = len(adjList.keys())

    edgesQty = 0
    for vertex in adjList.values():
        edgesQty += len(vertex)

    if isDirected:
        edgesQty *= 2

    graphDensity = edgesQty / (verticesQty * (verticesQty - 1))

    print(f'{graphDensity:.3f}')

calcDensidadeLista({0: [1], 1: [0, 2, 3], 2: [1, 3], 3: [1, 2]})

# input: {0: [1], 1: [0, 2, 3], 2: [1, 3], 3: [1, 2]}

# output: 0.667
