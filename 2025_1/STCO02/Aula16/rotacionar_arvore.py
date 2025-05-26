
class noh:
	def __init__(self, dado):
		self.dado = dado
		self.esq: noh | None = None
		self.dir: noh | None = None

def rotacionaEsquerda(x: noh):
	y = x.dir
	x.dir = y.esq
	y.esq = x

	return y

def rotacionaDireita(x: noh):
	y = x.esq
	x.esq = y.dir
	y.dir = x

	return y

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