sequence = []

def recursiveDfs(adjList: dict, v: int):
    if v not in sequence:
        sequence.append(v)

    for adj in adjList[v]:
        if adj not in sequence:
            recursiveDfs(adjList, adj)


def DFS(adjList: dict, v: int):
    recursiveDfs(adjList, v)

    print(sequence)


DFS({0: [1, 3, 4], 1: [0, 2], 2: [1], 3: [0], 4: [0, 5], 5: [4]}, 0)

# input: {0: [1, 3, 4], 1: [0, 2], 2: [1], 3: [0], 4: [0, 5], 5: [4]}, 0

# output: [0, 1, 2, 3, 4, 5]
