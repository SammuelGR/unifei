def merge(listaA, listaB):
	lista = []
	i = 0
	j = 0

	while i < len(listaA) and j < len(listaB):
		if listaA[i] < listaB[j]:
			lista.append(listaA[i])
			i += 1
		else:
			lista.append(listaB[j])
			j += 1
	while i < len(listaA):
		lista.append(listaA[i])
		i += 1

	while j < len(listaB):
		lista.append(listaB[j])
		j += 1

	return lista

def mergesort(lista):
	if len(lista) <= 1:
		return lista

	meio = len(lista) // 2
	listaA = mergesort(lista[:meio])
	listaB = mergesort(lista[meio:])

	return merge(listaA, listaB)

lista = [18, 1, 33, 42, 16, 46, 2, 13]
lista = mergesort(lista)
print(lista)
