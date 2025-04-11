import sys
import random

def partition(lista, esq, dir):
	r = random.randint(esq, dir)

	lista[r], lista[esq] = lista[esq], lista[r]

	j = esq
	pivot = lista[esq]

	for k in range(esq + 1, dir + 1):
		if lista[k] < pivot:
			j += 1
			lista[k], lista[j] = lista[j], lista[k]

	lista[esq] = lista[j]
	lista[j] = pivot

	return j

def quick_sort(lista, esq, dir):
	if esq < dir:
		p = partition(lista, esq, dir)
		quick_sort(lista, esq, p - 1)
		quick_sort(lista, p + 1, dir)


sys.setrecursionlimit(100000)

lista = list(range(0, 15000))

quick_sort(lista, 0, len(lista) - 1)
