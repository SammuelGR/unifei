from typing import List

def dijkstra(adjMatrix: List[List[int]], vOrigin: int, vDest: int):
    size = len(adjMatrix)

    cost = [-1 for _ in range(size)]
    route = [vOrigin for _ in range(size)]

    cost[vOrigin] = 0

    openList = list(range(size))
    closedList = []

    # v = min(adjMatrix[vOrigin])

    def minCost(v: int):
        adjList = adjMatrix[v]
        print(adjList(-1))

    minCost(3)
    # while openList:


dijkstra([[0, 3, 8, 4, -1, 10],
          [ 3, 0, -1, 6, -1, -1],
          [ 8, -1, 0, -1, 7, -1],
          [ 4,  6, -1, 0,  1,  3],
          [-1, -1,  7,  1, 0, 1],
          [10, -1, -1,  3,  1, 0]],
          0, 5)
