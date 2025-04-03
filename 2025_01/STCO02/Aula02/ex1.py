#Com essa função abaixo o programa demora quase 1 minuto para rodar.
#   Com uma implementação eficiente dessa função o programa passa a
#   usar menos de 1 segundo. Melhore essa função e explique.

#Essa função recebe uma lista com números de fibonacci e calcula o
#   proximo acrescentando na lista original. A função pode modificar
#   a lista que recebe na origem.
# def aumenta_fib(lista):
#     next = lista[-1] + lista[-2]
#     lista = lista + [next]
#     return lista

def aumenta_fib(lista):
	next = lista[-1] + lista[-2]
	lista.append(next)

	return lista

#Não mexa daqui para baixo
l = [0, 1]
for i in range(2, 100000, 1):
	l = aumenta_fib(l)

#imprime os 5 ultimos digitos do ultimo elemento da lista
print(l[99999]%100000)
