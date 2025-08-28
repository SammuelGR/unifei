from typing import List

def verificaAdjacencia(matriz: List[List[int]], vi: int, vj: int) -> None:
    print(matriz[vi][vj] == 1)

verificaAdjacencia([[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]], 0, 3)
#verificaAdjacencia(matriz, vi, vj)
# [[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]], 0, 3
# False