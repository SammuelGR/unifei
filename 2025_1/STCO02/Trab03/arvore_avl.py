#Não mexa aqui.
import random
import time
MINIMO = 1
MAXIMO = 9_223_372_036_854_775_807
random.seed(42)  # Para garantir a reprodutibilidade dos testes

#SEU TRABALHO COMEÇA DAQUI PRA FRENTE
#VOCÊ PODE MODIFICAR A CLASSE NOH E CRIAR
#FUNÇÕES ADICIONAIS 

#Quando você estiver submetendo no RunCodes, mude para True
ESTOU_SUBMETENDO_NO_RUNCODES = True

class noh:
  def __init__(self, dado: int):
    self.dado = dado
    self.esq: noh | None = None
    self.dir: noh | None = None
    self.altura: int = 0

def getAltura(raiz: noh):
  if raiz == None:
    return -1
  return raiz.altura

def getFatorDeBalanceamento(raiz: noh):
  return getAltura(raiz.esq) - getAltura(raiz.dir)

def rotacionaEsq(raiz: noh) -> noh:
  novaRaiz = raiz.dir
  raiz.dir = novaRaiz.esq
  novaRaiz.esq = raiz

  raiz.altura = max(getAltura(raiz.esq), getAltura(raiz.dir)) + 1
  novaRaiz.altura = max(getAltura(novaRaiz.esq), getAltura(novaRaiz.dir)) + 1
  
  return novaRaiz

def rotacionaDir(raiz: noh) -> noh:
  novaRaiz = raiz.esq
  raiz.esq = novaRaiz.dir
  novaRaiz.dir = raiz

  raiz.altura = max(getAltura(raiz.esq), getAltura(raiz.dir)) + 1
  novaRaiz.altura = max(getAltura(novaRaiz.esq), getAltura(novaRaiz.dir)) + 1

  return novaRaiz

def insere(raiz: noh, dado: int):
  """
  recebe uma arvore e devolve o endereço da nova arvore com o dado adicionado
  """
  if raiz == None:
    return noh(dado)
  
  if dado < raiz.dado:
    raiz.esq = insere(raiz.esq, dado)

    if getFatorDeBalanceamento(raiz) == 2:
      if dado > raiz.esq.dado:
        raiz.esq = rotacionaEsq(raiz.esq)

      raiz = rotacionaDir(raiz)

  elif dado > raiz.dado:
    raiz.dir = insere(raiz.dir, dado)

    if getFatorDeBalanceamento(raiz) == -2:
      if dado < raiz.dir.dado:
        raiz.dir = rotacionaDir(raiz.dir)
      
      raiz = rotacionaEsq(raiz)
  
  else:
    return raiz

  raiz.altura = max(getAltura(raiz.esq), getAltura(raiz.dir)) + 1

  return raiz
  
def em_ordem(no: noh):
  """
  Imprime os dados da árvore em ordem crescente
  """
  if (no != None):
    em_ordem(no.esq)
    print(no.dado, end=" ")
    em_ordem(no.dir)


def encontra_mais_proximo(no: noh, x: int):
  """
  Encontra o valor mais próximo de x na árvore
  """
  raiz = no
  valorMaisProximo = raiz.dado

  while raiz != None:
    if x == raiz.dado:
      return x
    
    if abs(x - raiz.dado) < abs(x - valorMaisProximo):
      valorMaisProximo = raiz.dado
    elif abs(x - raiz.dado) == abs(x - valorMaisProximo) and raiz.dado < valorMaisProximo:
      valorMaisProximo = raiz.dado

    if x < raiz.dado:
      raiz = raiz.esq
    else:
      raiz = raiz.dir

  return valorMaisProximo
  
## A PARTIR DAQUI NÃO MUDE NADA.
## PARTES DESTE CÓDIGO ESTÃO PROPOSITALMENTE
## INEFICIENTES PARA DEIXAR O PROBLEMA MAIS DIFÍCIL.

##Não mexa aqui.
def inicializa_arvore(n):
  numeros = random.sample(range(MINIMO, MAXIMO), n)
  #Essa linha de baixo é só para deixar o problema
  #mais difícil. Deixe assim.
  numeros.sort()
  raiz = None
  for num in numeros:
    raiz = insere(raiz, num)
  return raiz

def insere_novos_numeros(arvore, n):
  numeros = random.sample(range(MINIMO, MAXIMO), n)
  for num in numeros:
    arvore = insere(arvore, num)
  return arvore


nivel = int(input("Digite o nivel do jogo 1-fácil, 2-normal, 3-difícil, 4-insano: "))
if nivel == 1:
  MAXIMO = 100
  n = 5
elif nivel == 2:
  MAXIMO = 1000
  n = 100
elif nivel == 3:
  n = 5
else:
  n = 50000

arvore = inicializa_arvore(n)
print("\nNúmeros inseridos no jogo:")
if not ESTOU_SUBMETENDO_NO_RUNCODES:
  em_ordem(arvore)
x = random.randint(MINIMO, MAXIMO)
print(f"\n\nQual o valor mais próximo de {x} digite -1 para sair:")

inicio = time.time()
chute = int(input(""))
print()
while chute >= 0:
  #Não é eficiente ficar encontrando o mais próximo
  #toda vez, mas está assim para deixar o problema mais difícil.
  #Deixe assim.
  mais_proximo = encontra_mais_proximo(arvore, x)
  if chute == mais_proximo:
    fim = time.time()
    tempo = fim - inicio
    print(f"Parabéns! Você acertou! O número mais próximo de {x} é {mais_proximo}.")
    if not ESTOU_SUBMETENDO_NO_RUNCODES:
      print(f"Você levou {tempo:.2f} segundos.")
    arvore = insere_novos_numeros(arvore, 3)
    
    if not ESTOU_SUBMETENDO_NO_RUNCODES:
      print("\n**************************")
      print("Números inseridos no jogo:")
      em_ordem(arvore)
    x = random.randint(MINIMO, MAXIMO)
    print(f"\n\nQual o valor mais próximo de {x}:")
    inicio = time.time()
    chute = int(input(""))
  else:
    chute = int(input(f"\nErrou! {chute} não é a resposta!\nTente novamente: "))

print("Saindo!")  
