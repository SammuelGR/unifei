import numpy as np

def removeVertice(matriz, v):
    matrix = np.array(matriz)

    matrix[:, v] = matrix[v, :] = -1

    print(matrix)


removeVertice([[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]], 2)
# input: [[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]], 2
# output:
# [[ 0  1 -1  0]
#  [ 1  0 -1  1]
#  [-1 -1 -1 -1]
#  [ 0  1 -1  0]]
