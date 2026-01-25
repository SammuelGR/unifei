from math import inf
from typing import List

def dijkstra(adjMatrix: List[List[int]], vOrigin: int, vDest: int):
	size = len(adjMatrix)

	costs = [inf for _ in range(size)]
	routes = [vOrigin for _ in range(size)]

	openList = list(range(size))
	closedList = []

	costs[vOrigin] = 0

	while len(openList) > 0:
		v = openList[0]
		minCost = costs[openList[0]]

		for x in openList:
			if costs[x] < minCost:
				minCost = costs[x]
				v = x
		
		openList.remove(v)
		closedList.append(v)

		vRow = adjMatrix[v]
		for u in range(size):
			weight = vRow[u]
			if u in closedList or weight <= 0:
				continue

			if costs[u] > costs[v] + weight:
				costs[u] = costs[v] + weight
				routes[u] = v

	path = []
	x = vDest
	while x != vOrigin:
		path.append(x)
		x = routes[x]
	path.append(vOrigin)
	path.reverse()

	print(path, costs[vDest])

dijkstra([[0, 3, 8, 4, -1, 10],
		  [ 3, 0, -1, 6, -1, -1],
		  [ 8, -1, 0, -1, 7, -1],
		  [ 4,  6, -1, 0,  1,  3],
		  [-1, -1,  7,  1, 0, 1],
		  [10, -1, -1,  3,  1, 0]],
		  0, 5)
# input:
# [[0, 3, 8, 4, -1, 10], [ 3, 0, -1, 6, -1, -1], [ 8, -1, 0, -1, 7, -1], [ 4,  6, -1, 0,  1,  3], [-1, -1,  7,  1, 0, 1], [10, -1, -1,  3,  1, 0]], 0, 5

# output:
# [0, 3, 4, 5] 6
