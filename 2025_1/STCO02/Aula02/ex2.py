import random

#Essa função recebe 2 números grandes e devolve o ultimo digito do
#   produtos desses dois números.

#Essa implementação está ineficiente e demora 40 segundos para executar
#   o programa. Uma implementação um pouco melhor pode fazer esse tempo
#   cair pela metade. Melhore essa função e explique.
# def ult_dig_prod(a, b):
#     r = a * b
#     return r % 10

def ult_dig_prod(a, b):
	return (a % 10 * b % 10) % 10

#Não altere o programa daqui para baixo
random.seed(10)
soma = 0
for i in range(0, 1000000, 1):
	soma = soma + ult_dig_prod(random.randint(0, 10**2000), random.randint(0, 10**2000))
print(soma)


