def insereArestaLista(adjList: dict, vi: int, vj: int):
    # check for directed graph
    isDirected = False
    i = 0
    for vertex in adjList.values():
        for edge in vertex:
            if i not in adjList[edge]:
                isDirected = True
                break
        i += 1

    iList = adjList[vi]
    iList.append(vj)
    iList.sort()
    adjList[vi] = iList

    if vi != vj and isDirected is False:
        jList = adjList[vj]
        jList.append(vi)
        jList.sort()
        adjList[vj] = jList

    print(adjList)

insereArestaLista({0: [], 1: [0, 2], 2: [3], 3: [1]}, 0, 3)

# input: {0: [1], 1: [0, 2, 3], 2: [1, 3], 3: [1, 2], 0, 2

# output: {0: [1, 2], 1: [0, 2, 3], 2: [0, 1, 3], 3: [1, 2]}
