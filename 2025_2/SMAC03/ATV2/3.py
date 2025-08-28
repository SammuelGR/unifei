import numpy as np

def calcDensidade(matriz):
    isSymmetrical = True
    size = len(matriz[0])

    for i in range(size):
        for j in range(size):
            if matriz[i][j] != matriz[j][i]:
                isSymmetrical = False
                break

    isSimpleGraph = not isSymmetrical

    edges = 0
    if isSimpleGraph:
        edges = 2 * np.sum(np.tril(matriz))
    else:
        edges = np.sum(matriz)

    deg = edges /( size * (size - 1))

    print(f'{deg:.3f}')

    # for i in matriz:
    #     print(i)

calcDensidade([[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]])
# input: [[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]]
# output: 0.667