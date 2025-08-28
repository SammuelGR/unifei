''''
Função: tipoGrafo(matriz)

Descrição: Retorna o tipo do grafo representado por uma dada matriz de adjacências.

Entrada: matriz de adjacências

Saída: Tipo do grafo (Integer) sendo:
0 - grafo simples; ✅
1 - digrafo;
20 - multigrafo; ✅
21 - multigrafo dirigido; ✅
30 - pseudografo; ✅
31 - pseudografo dirigido. ✅
'''

from typing import List
import numpy as np

def tipoGrafo(matriz: List[List[int]]):
    size = len(matriz[0])

    isSymmetrical = True

    for i in range(size):
        for j in range(size):
            if matriz[i][j] != matriz[j][i]:
                isSymmetrical = False
                break

    isMultigraph = np.max(matriz) > 1

    isPseudograph = np.max(np.diag(matriz)) > 0

    if isSymmetrical and not isMultigraph and not isPseudograph:
        print(0)
        return

    if isPseudograph:
        if isSymmetrical:
            print(30)
        else:
            print(31)
        return

    if isMultigraph:
        if isSymmetrical:
            print(20)
        else:
            print(21)
        return

    print(1)




tipoGrafo([[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]])
# input: [[0, 1, 0, 0], [1, 0, 1, 1], [0, 1, 0, 1], [0, 1, 1, 0]]
# output: 0