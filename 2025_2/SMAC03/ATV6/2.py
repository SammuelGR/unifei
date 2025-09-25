# ☠☠☠☠☠☠☠☠☠☠☠☠☠☠☠

def DFS(adjList: dict, v: int):
	sequence = []

	vertexesIds = []
	for k in adjList.keys():
		vertexesIds.append(k)

	vStack = []
	vStack.append(v)

	while len(vertexesIds) > 0:
		while len(vStack) != 0:
			t = vStack.pop(0)

			if t not in sequence:
				sequence.append(t)

			viables = adjList[t]

			for k in viables:
				if k in sequence and k in viables:
					viables.remove(k)

			if len(viables) > 0:
				vStack.append(viables[0])
			else:
				if len(vStack) > 0:
					vStack.pop(0)

		for k in vertexesIds:
			if k in sequence:
				vertexesIds.remove(k)

		if len(vertexesIds) > 0:
			vStack = vertexesIds.pop(0)

	print(sequence)


DFS({0: [1, 3, 4], 1: [0, 2], 2: [1], 3: [0], 4: [0, 5], 5: [4]}, 0)

# input: {0: [1, 3, 4], 1: [0, 2], 2: [1], 3: [0], 4: [0, 5], 5: [4]}, 0

# output: [0, 1, 2, 3, 4, 5]

