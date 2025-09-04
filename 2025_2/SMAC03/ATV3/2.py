def tipoGrafoLista(adjList: dict):
    # check for pseudo graph
    hasLoops = False
    i = 0
    for vertix in adjList.values():
        for edge in vertix:
            if edge == i:
                hasLoops = True
                break
        i += 1

    # check for directed graph
    isDirected = False
    i = 0
    for vertix in adjList.values():
        for edge in vertix:
            if i not in adjList[edge]:
                isDirected = True
                break
        i += 1

    # check for multi graph
    isMulti = False
    for vertix in adjList.values():
        edgesSize = len(vertix)

        for i in range(edgesSize):
            for j in range(edgesSize):
                if vertix[i] == vertix[j] and i != j:
                    isMulti = True
                    break

    if hasLoops:
        if isDirected:
            print(31)
        else:
            print(30)
        return

    if isMulti:
        if isDirected:
            print(21)
        else:
            print(20)
        return

    if isDirected:
        print(1)
    else:
        print(0)

tipoGrafoLista({0: [1], 1: [0, 2, 3], 2: [1, 3], 3: [1, 2]})

# input: {0: [1], 1: [0, 2, 3], 2: [1, 3], 3: [1, 2]}

# output: 0

# 0 - grafo simples ✅
# 1 - digrafo ✅
# 20 - multigrafo ✅
# 21 - multigrafo dirigido ✅
# 30 - pseudografo ✅
# 31 - pseudografo dirigido ✅