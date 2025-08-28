import numpy as np

def insereVertice(matriz):
    size = len(matriz[0])

    for row in matriz:
        row.append(0)

    matriz.append([0] * (size + 1))

    print(np.array(matriz))

insereVertice([[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]])
# input: [[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]]
#  output:
# [[0 1 0 0 0]
#  [1 0 1 1 0]
#  [0 1 0 1 0]
#  [0 1 1 0 0]
#  [0 0 0 0 0]]