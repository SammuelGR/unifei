
class noh:
	def __init__(self, dado):
		self.dado = dado
		self.esq: noh | None = None
		self.dir: noh | None = None
		self.cor = True

def rotacionaEsquerda(x: noh):
	y = x.dir
	x.dir = y.esq
	y.esq = x
	y.cor = x.cor
	x.cor = True

	return y

def rotacionaDireita(x: noh):
	y = x.esq
	x.esq = y.dir
	y.dir = x
	y.cor = x.cor # sera que x eh sempre False?
	x.cor = True

	return y

def sobeVermelho(x: noh):
	x.cor = True
	x.esq.cor = False
	x.dir.cor = False

	return x

def ehVermelho(x: noh):
	if x == None:
		return False

	return x.cor

	# return False if x == None else x.cor

def ehNegro(x: noh):
	if x == None:
		return True

	return x.cor == False

# recebe uma arvore e devolve o endereco da nova arvore com o dado adicionado
def insere(raiz: noh, dado: noh):
	if raiz == None:
		return noh(dado)

	if dado < raiz.dado:
		raiz.esq = insere(raiz.esq, dado)

	elif dado > raiz.dado:
		raiz.dir = insere(raiz.dir, dado)

	else:
		return raiz

	# verificar se quebrou propriedades

	if ehVermelho(raiz.dir)and ehNegro(raiz.esq):
		raiz = rotacionaEsquerda(raiz)

	if ehVermelho(raiz.esq) and ehVermelho(raiz.esq.esq):
		raiz = rotacionaDireita(raiz)

	if ehVermelho(raiz.esq) and ehVermelho(raiz.dir):
		raiz = sobeVermelho(raiz)

	return raiz

def insere_arvore(raiz: noh, dado: noh):
	raiz = insere(raiz, dado)
	raiz.cor = False


def imprime(A: noh):
		if A == None:
			return

		print('(', end='')
		imprime(A.esq)
		print(' , ', end='')
		print(A.dado, end=' , ')
		imprime(A.dir)
		print(')', end='')

A = noh(5)
A.dir = noh(7)
imprime(A)
print()

A = rotacionaEsquerda(A)
imprime(A)
print()

A = rotacionaDireita(A)
imprime(A)
print()