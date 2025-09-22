def BFS(adjList: dict, v: int):
    queue = [v]
    bfsList = []
    idsList = list(adjList.keys())

    while len(queue) > 0 or len(idsList) > 0:
        if len(queue) == 0 and len(idsList) > 0:
            queue.append(idsList.pop(0))

        currentVertex = queue[0]
        bfsList.append(currentVertex)

        if currentVertex in idsList:
            idsList.remove(currentVertex)

        for v in adjList[currentVertex]:
            if v not in bfsList and v not in queue:
                queue.append(v)

        queue.pop(0)

    print(bfsList)



# BFS({0: [1, 3, 4], 1: [0, 2], 2: [1], 3: [0], 4: [0, 5], 5: [4]}, 0)

# input1: {0: [1, 3, 4], 1: [0, 2], 2: [1], 3: [0], 4: [0, 5], 5: [4]}, 0

# output1: [0, 1, 3, 4, 2, 5]

BFS({0: [2, 4], 1: [2, 4], 2: [0, 1, 4], 3: [], 4: [0, 1, 2, 5, 6], 5: [4, 6], 6: [4, 5]}, 0)

# input2: BFS({0: [2, 4], 1: [2, 4], 2: [0, 1, 4], 3: [], 4: [0, 1, 2, 5, 6], 5: [4, 6], 6: [4, 5]}, 0)

# output2: [0, 2, 4, 1, 5, 6, 3]
