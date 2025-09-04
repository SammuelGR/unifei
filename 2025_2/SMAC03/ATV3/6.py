def removeArestaLista(adjList: dict, vi: int, vj: int):
    # check for directed graph
    isDirected = False
    i = 0
    for vertix in adjList.values():
        for edge in vertix:
            if i not in adjList[edge]:
                isDirected = True
                break
        i += 1

    adjList[vi].remove(vj)

    if vi != vj and isDirected is False:
        adjList[vj].remove(vi)

    print(adjList)

removeArestaLista({0: [1, 2], 1: [0, 2, 3], 2: [0, 1, 3], 3: [1, 2]}, 0, 2)

# input: {0: [1, 2], 1: [0, 2, 3], 2: [0, 1, 3], 3: [1, 2]}

# output: {0: [1], 1: [0, 2, 3], 2: [1, 3], 3: [1, 2]}
