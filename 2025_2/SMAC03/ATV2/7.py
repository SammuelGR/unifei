def removeAresta(matriz, vi, vj):
    matriz[vi][vj] = matriz[vj][vi] = 0

    print(matriz)

removeAresta([[0, 1,0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]], 1, 0)
# input: [[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]], 1, 0
# output: [[0, 0, 0, 0], [0, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]]