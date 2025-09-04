def removeVerticeLista(adjList: dict, vi: int):
    adjList.pop(vi)

    for vertex in adjList:
        adjList[vertex] = [v for v in adjList[vertex] if v != vi]

    print(adjList)

removeVerticeLista({0: [1, 2], 1: [0, 2, 3], 2: [0, 1, 3], 3: [1, 2]}, 2)

# input: {0: [1, 2], 1: [0, 2, 3], 2: [0, 1, 3], 3: [1, 2]}, 2
# output: {0: [1], 1: [0, 3], 3: [1]}
