def insereVerticeLista(adjList: dict):
    adjList[len(adjList.keys())] = []

    print(adjList)

insereVerticeLista({0: [1, 1, 2, 2, 3], 1: [0, 0, 3], 2: [0, 0, 3], 3: [0, 1, 2]})

# input: {0: [1, 1, 2, 2, 3], 1: [0, 0, 3], 2: [0, 0, 3], 3: [0, 1, 2]}

# output: {0: [1, 1, 2, 2, 3], 1: [0, 0, 3], 2: [0, 0, 3], 3: [0, 1, 2], 4: []}
