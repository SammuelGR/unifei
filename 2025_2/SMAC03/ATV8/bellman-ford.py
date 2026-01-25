from math import inf
from typing import List

def bellmanFord(adjMatrix: List[List[int]], vOrigin: int, vDest: int):
	size = len(adjMatrix)

	costs = [inf for _ in range(size)]
	routes = [vOrigin for _ in range(size)]

	costs[vOrigin] = 0

	for _ in range(size - 1):
		for v in range(size):
			for u in range(size):
				weight = adjMatrix[v][u]

				if weight <= 0:
					continue

				if costs[u] > costs[v] + weight:
					costs[u] = costs[v] + weight
					routes[u] = v

	# check for negative loops
	for v in range(size):
		for u in range(size):
			weight = adjMatrix[v][u]

			if weight <= 0:
				continue

			if costs[u] > costs[v] + weight:
				return False

	path = []
	x = vDest
	while x != vOrigin:
		path.append(x)
		x = routes[x]
	path.append(vOrigin)
	path.reverse()
	
	print(path, costs[vDest])

bellmanFord([[0, 3, 8, 4, -1, 10],
		  [ 3, 0, -1, 6, -1, -1],
		  [ 8, -1, 0, -1, 7, -1],
		  [ 4,  6, -1, 0,  1,  3],
		  [-1, -1,  7,  1, 0, 1],
		  [10, -1, -1,  3,  1, 0]],
		  0, 5)
