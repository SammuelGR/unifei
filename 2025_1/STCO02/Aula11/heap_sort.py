def selectionSort(lista):
	for i in range(len(lista)-1, 0, -1):
		maior = 0

		for j in range(1, i + 1):
			if lista[j] > lista[maior]:
				maior = j

		lista[i], lista[maior] = lista[maior], lista[i]

class MaxHeap:
	def __init__(self, lista):
		self.dados = lista
		self.tamanho = len(lista)
		self.constroi_heap()

	def constroi_heap(self):
		for i in range(self.tamanho // 2 - 1, -1, -1):
			self.desce_heap(i)

	def heap_sort(self):
		for i in range(self.tamanho - 1, 0, -1):
			self.dados[0], self.dados[i] = self.dados[i], self.dados[0]
			self.tamanho -= 1
			self.desce_heap(0)

	def sobe_heap(self, i):
		if i == 0:
			return

		pai = (i - 1) // 2

		if self.dados[i] > self.dados[pai]:
			self.dados[i], self.dados[pai] = self.dados[pai], self.dados[i]

			self.sobe_heap(pai)

	def inserir(self, valor):
		self.dados.append(valor)
		self.tamanho += 1
		self.sobe_heap(self.tamanho - 1)

	def desce_heap(self, i):
		esq = 2 * i + 1
		dir = 2 * i + 1
		maior = -1

		if esq <= self.tamanho - 1:
			maior = esq

		if dir <= self.tamanho - 1 and self.dados[dir] > self.dados[esq]:
			maior = dir

		if maior != -1 and self.dados[maior] > self.dados[i]:
			self.dados[i], self.dados[maior] = self.dados[maior], self.dados[i]
			self.desce_heap(maior)


	def remover(self):
		if self.tamanho == 0:
			return None

		maximo = self.dados[0]
		self.dados[0] = self.dados[self.tamanho - 1]
		self.dados.pop()
		self.tamanho -= 1

		if self.tamanho > 0:
			self.desce_heap(0)

		return maximo

L = [18, 1, 6, 33, 42, 31]
H = MaxHeap(L)
print(H.dados)

H.heap_sort()
print(H.dados)


# esq (i): 2 * i + 1
# dir (i): 2 * i + 2
# pai (i): floor((i - 1) / 2) || (i - 1) // 2