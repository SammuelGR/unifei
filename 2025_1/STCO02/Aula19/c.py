import random
import sys

class node:
  def __init__(self, dado):
    self.dado = dado
    self.esq = None
    self.dir = None

def insere(y, dado):
  if y == None:
    return node(dado)

  if dado < y.dado:
    y.esq = insere(y.esq, dado)
  elif dado > y.dado:
    y.dir = insere(y.dir, dado)
  else:
    #print("dado igual")
    #tratar esse caso
    return y

  return y

def busca(T, dado):
  if T is None:
    return None
  if dado < T.dado:
    return busca(T.esq, dado)
  elif dado > T.dado:
    return busca(T.dir, dado)
  else:
    return T

sys.setrecursionlimit(100000)

T = None
operacoes = int(sys.argv[1])
for i in range(operacoes):
  T = insere(T, i)

for i in range(operacoes):
  resultado = busca(T, i)

# 10k - 14.91s
# 40k - 82.34s [SEGMENTATION FAULT]
