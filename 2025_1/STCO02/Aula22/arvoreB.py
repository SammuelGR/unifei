t = 3

class node:
	def __init__(self):
		self.n = 0
		self.folha = True
		self.chaves = []
		self.filhos = []

def imprime_arvore(raiz, nivel=0):
	for i in range(nivel):
		print("  ", end="")
	print(raiz.chaves)
	for filho in raiz.filhos:
		imprime_arvore(filho, nivel + 1)

def busca(x, k):
	i = 0
	while i < x.n and k > x.chaves[i]:
		i += 1
	if i < x.n and k == x.chaves[i]:
		return x.chaves[i]
	elif x.folha:
		return None
	else:
		#se tiver no disco
		#le(x.filhos[i])
		return busca(x.filhos[i], k)

#sei que o filho indice_filho tem 2t - 1 chaves
def quebrar_filho(pai, indice_filho):
	z = node()
	y = pai.filhos[indice_filho]
	z.folha = y.folha

	pai.chaves.insert(indice_filho, y.chaves[t-1])
	z.chaves = y.chaves[t:] #precisa receber as ultimas chaves de y
	y.chaves = y.chaves[:t-1]
	pai.filhos.insert(indice_filho + 1, z)
	if not y.folha:
		z.filhos = y.filhos[t:]
		y.filhos = y.filhos[:t]
	pai.n = pai.n + 1
	y.n = t-1
	z.n = t-1
	#ESCREVER NO DISCO PAI O Z E O Y


def insere_nao_cheio(x, k):
	if x.folha:
		i = 0
		while i < x.n and x.chaves[i] < k:
			i += 1
		#k deve ser inserido na posicao i
		x.chaves.insert(i, k)
		x.n = x.n + 1
	else:
		i = 0
		while i < x.n and x.chaves[i] < k:
			i += 1
		#se tiver cheio, quebrar o filho i
		if x.filhos[i].n == 2 * t - 1:
			# tenta passar um elemento de i para o irmao
			res = redistribui_com_irmao(x, i) # TODO: criar funcao

			if res == False:
				# TODO: fazer a quebra de 2 para 3
				pass

			quebrar_filho(x, i)
			if x.chaves[i] < k:
				i += 1
		insere_nao_cheio(x.filhos[i], k)


def quebrar_raiz(raiz):
	s = node()
	s.folha = False
	s.n = 0
	s.filhos.append(raiz)
	quebrar_filho(s, 0)
	return s

def insere(raiz, k):
	if raiz.n == 2 * t - 1:
		raiz = quebrar_raiz(raiz)
	insere_nao_cheio(raiz, k)
	return raiz


arvore = node()
arvore.chaves = [100, 200]
arvore.n = 2
arvore.folha = False
arvore.filhos = [node(), node(), node()]

arvore.filhos[0].folha = True
arvore.filhos[0].n = 5
arvore.filhos[0].chaves = [1, 6, 18, 33, 42]

arvore.filhos[1].folha = True
arvore.filhos[1].n = 3
arvore.filhos[1].chaves = [150, 175, 180]

arvore.filhos[2].folha = True
arvore.filhos[2].n = 2
arvore.filhos[2].chaves = [250, 275]

imprime_arvore(arvore)

quebrar_filho(arvore, 0)

imprime_arvore(arvore)

insere_nao_cheio(arvore, 5)
imprime_arvore(arvore)
insere_nao_cheio(arvore, 4)
imprime_arvore(arvore)
insere_nao_cheio(arvore, 3)
imprime_arvore(arvore)
insere_nao_cheio(arvore, 2)
imprime_arvore(arvore)
insere_nao_cheio(arvore, 7)
imprime_arvore(arvore)
insere_nao_cheio(arvore, 8)
imprime_arvore(arvore)
insere_nao_cheio(arvore, 9)
imprime_arvore(arvore)
insere_nao_cheio(arvore, 10)
imprime_arvore(arvore)

arvore = quebrar_raiz(arvore)
imprime_arvore(arvore)


arvore = insere(arvore, 11)
arvore = insere(arvore, 12)
arvore = insere(arvore, 13)
arvore = insere(arvore, 14)
arvore = insere(arvore, 15)
arvore = insere(arvore, 16)
arvore = insere(arvore, 17)
arvore = insere(arvore, 19)
arvore = insere(arvore, 20)
imprime_arvore(arvore)
arvore = insere(arvore, 151)
imprime_arvore(arvore)
arvore = insere(arvore, 152)
imprime_arvore(arvore)
arvore = insere(arvore, 153)
imprime_arvore(arvore)
arvore = insere(arvore, 154)
imprime_arvore(arvore)
