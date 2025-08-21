from typing import List

def valorCelula(matrix: List[List[int]], row: int, column: int):
    size = len(matrix[0])

    if row > size or column > size:
        print('Erro')
        return

    print(f'Celula[{row}][{column}] = {matrix[row][column]}')

valorCelula([[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]], 2, 3)