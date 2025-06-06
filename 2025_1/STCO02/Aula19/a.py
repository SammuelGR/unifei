import matplotlib.pyplot as plt

#FunÃ§Ã£o gerada pelo ChatGPT :)
def desenhar_arvore(raiz):
  #Desenha a Ã¡rvore binÃ¡ria usando matplotlib, com nÃ³s e texto maiores.
  fig, ax = plt.subplots(figsize=(16, 12))  # Tamanho grande
  ax.axis('off')

  def _desenhar(raiz, x, y, dx):
    if raiz is None:
      return
    # Desenhar o nÃ³ com texto e cÃ­rculo maiores
    ax.text(
      x, y, str(raiz.dado),
      ha='center', va='center',
      fontsize=16,  # Tamanho do texto
      bbox=dict(boxstyle="circle,pad=0.6", facecolor='lightblue', edgecolor='black', linewidth=1.5)
    )

    # Desenhar linha e chamada recursiva para o filho esquerdo
    if raiz.esq:
      nx, ny = x - dx, y - 1.5
      ax.plot([x, nx], [y, ny], 'k-', linewidth=1.5)
      _desenhar(raiz.esq, nx, ny, dx / 2)

    # Desenhar linha e chamada recursiva para o filho direito
    if raiz.dir:
      nx, ny = x + dx, y - 1.5
      ax.plot([x, nx], [y, ny], 'k-', linewidth=1.5)
      _desenhar(raiz.dir, nx, ny, dx / 2)

  _desenhar(raiz, x=0, y=0, dx=8)

  plt.show()

class node:
  def __init__(self, dado):
    self.dado = dado
    self.esq = None
    self.dir = None
    self.altura = 0

def altura(y):
  if y == None:
    return -1
  return y.altura

def rotacaoDireita(y):
  x = y.esq
  y.esq = x.dir
  x.dir = y

  y.altura = max(altura(y.esq), altura(y.dir)) + 1
  x.altura = max(altura(x.esq), altura(x.dir)) + 1

  return x


def rotacaoEsquerda(y):
  x = y.dir
  y.dir = x.esq
  x.esq = y

  y.altura = max(altura(y.esq), altura(y.dir)) + 1
  x.altura = max(altura(x.esq), altura(x.dir)) + 1

  return x

#FB = FATOR DE BALANCEAMENTO
def fb(y):
  return altura(y.esq) - altura(y.dir)

def insere(y, dado):
  if y == None:
    return node(dado)

  if dado < y.dado:
    y.esq = insere(y.esq, dado)
    #verificar se deslanceou para esquerda
    if fb(y) == 2:
      if dado > y.esq.dado:
        #inseriu na direita da esquerda
        y.esq = rotacaoEsquerda(y.esq)
      y = rotacaoDireita(y)
  elif dado > y.dado:
    y.dir = insere(y.dir, dado)
    if fb(y) == -2:
      #verificar se inseriu na esquerda da direita
      if dado < y.dir.dado:
        y.dir = rotacaoDireita(y.dir)
      y = rotacaoEsquerda(y)

  else:
    print("dado igual")
    #tratar esse caso
    return y

 #corrigir a altura de y
  y.altura = max(altura(y.dir), altura(y.esq)) + 1

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


T = None
valor = input()
while valor != '':
  T = insere(T, int(valor))
  desenhar_arvore(T)
  valor = input()
