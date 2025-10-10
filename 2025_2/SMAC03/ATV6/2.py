def DFS(adjList: dict, v: int):
	sequence = []

	vertexesIds = []
	for k in adjList.keys():
		vertexesIds.append(k)

	vStack = []
	vStack.append(v)

	while len(vertexesIds) > 0:
		while len(vStack) > 0:
			t = vStack.pop()

			if t not in sequence:
				sequence.append(t)

			viables = []
			for adj in adjList[t]:
				if adj not in sequence:
					viables.append(adj)

			if len(viables) > 0:
				vStack.append(viables[0])
			else:
				if len(vStack) > 0:
					vStack.pop()

		for k in vertexesIds:
			if k in sequence:
				vertexesIds.remove(k)

		if len(vertexesIds) > 0:
			vStack.append(vertexesIds.pop(0))

	print(sequence)


# DFS({0: [1, 3, 4], 1: [0, 2], 2: [1], 3: [0], 4: [0, 5], 5: [4]}, 0)

# input: {0: [1, 3, 4], 1: [0, 2], 2: [1], 3: [0], 4: [0, 5], 5: [4]}, 0

# output: [0, 1, 2, 3, 4, 5]

# DFS({0: [1, 2, 6], 1: [0, 3, 4], 2: [0, 6, 7], 3: [1, 4, 5], 4: [1, 3, 5], 5: [3, 4], 6: [0, 2, 7], 7: [2, 6]}, 0)

# [0, 1, 3, 4, 5, 2, 6, 7]

DFS({0: [1, 4, 7, 8], 1: [0, 2], 2: [1, 3, 4, 5], 3: [2, 5, 6], 4: [0, 2, 7, 9], 5: [2, 3, 6], 6: [3, 5], 7: [0, 4, 8, 9, 10], 8: [0, 7, 10], 9: [4, 7], 10: [7, 8]}, 0)

# [0, 1, 2, 3, 5, 6, 4, 7, 8, 10]

