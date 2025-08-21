from typing import List

def criaDicionario(matrix: List[List[int]]):
    size = len(matrix[0])
    dictionary = {}

    for i in range(size):
        dictionary[i] = []

    row_index = 0
    for row in matrix:
        for i in range(size):
            if row[i] != 0:
                for _ in range(row[i]):
                    dictionary[row_index].append(i)

        row_index += 1

    print(dictionary)

criaDicionario([[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]])
# {0: [1], 1: [0, 2, 3], 2: [1, 3], 3: [1, 2]}