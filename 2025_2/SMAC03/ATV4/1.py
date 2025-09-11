import numpy as np

def caminhoEuleriano(adjMatrix: np.ndarray):
    isConnected = True

    qtyOddDegree = 0
    qtyEvenDegree = 0

    for vertex in adjMatrix:
        vDegree = sum(vertex)

        # check if graph is connected
        if vDegree == 0:
            isConnected = False
            break

        # check if there is any vertex with odd degree
        if vDegree % 2 == 0:
            qtyEvenDegree += 1
        else:
            qtyOddDegree += 1

    # disconnected graph
    if isConnected == False:
        print(False)
        return

    # all vertex degree are even
    if qtyOddDegree == 0:
        print(True)
        return

    # has only 2 even vertices
    if qtyEvenDegree == 2 and qtyOddDegree == 0:
        print(True)
        return

    print(False)


# caminhoEuleriano([[0, 2, 2, 1], [2, 0, 0, 1], [2, 0, 0, 1], [1, 1, 1, 0]])

# caminhoEuleriano([[0, 2, 2, 0], [2, 0, 0, 0], [2, 0, 0, 0], [0, 0, 0, 0]])

# input: [[0, 2, 2, 1], [2, 0, 0, 1], [2, 0, 0, 1], [1, 1, 1, 0]]
# output: False

