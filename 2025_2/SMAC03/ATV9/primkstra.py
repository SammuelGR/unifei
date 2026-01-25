from typing import List
from math import inf

def prim(adjMatrix: List[List[int]]):
	V = list(range(len(adjMatrix)))
	S = [V.pop(0)]
	N = V.copy()
	T = []

	peso = 0

	def getMinEdge() -> tuple:
		min = inf
		minV = 0
		minU = 0

		for v in S:
			for u in N:
				if adjMatrix[v][u] < min and adjMatrix[v][u] > 0:
					min = adjMatrix[v][u]
					minV = v
					minU = u

		return ((minV, minU), min)

	while len(T) < len(V):
		minEdge, novoPeso = getMinEdge()

		peso += novoPeso

		S.append(minEdge[1]) # u
		N.remove(minEdge[1]) # u

		T.append(minEdge) # vu

	print(T, peso)


prim([  [0, 4, 0, 0, 0, 0, 0, 8, 0],
		[4, 0, 8, 0, 0, 0, 0, 11, 0],
		[0, 8, 0, 7, 0, 4, 0, 0, 2],
		[0, 0, 7, 0, 9, 14, 0, 0, 0],
		[0, 0, 0, 9, 0, 10, 0, 0, 0],
		[0, 0, 4, 14, 10, 0, 2, 0, 0],
		[0, 0, 0, 0, 0, 2, 0, 1, 6],
		[8, 11, 0, 0, 0, 0, 1, 0, 7],
		[0, 0, 2, 0, 0, 0, 6, 7, 0]
	])

# [(0, 1), (0, 7), (7, 6), (6, 5), (5, 2), (2, 8), (2, 3)] 28