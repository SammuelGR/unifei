from typing import List

def dimensaoMatriz(matrix: List[List[int]]):
    size = len(matrix[0])

    print(f'({size}, {size}) [', end='')

    for i in range(size - 1):
        print(matrix[i][i], end=' ')

    print(f'{matrix[size - 1][size - 1]}]')



dimensaoMatriz([[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]])