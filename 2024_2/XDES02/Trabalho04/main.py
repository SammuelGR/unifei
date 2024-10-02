from abc import ABC, abstractmethod
from typing import List

class Terreno(ABC):
	def __init__(self, localizacao: str, preco: float) -> None:
		self.__localizacao = localizacao
		self.__preco = preco

	@property
	def localizacao(self):
		return self.__localizacao

	@localizacao.setter
	def localizacao(self, valor):
		self.__localizacao = valor

	@property
	def preco(self):
		return self.__preco

	@preco.setter
	def preco(self, valor):
		self.__preco = valor

	@abstractmethod
	def calcula_peso():
		pass

class TerrenoCircular(Terreno):
	def __init__(self, localizacao: str, preco: float, raio: float) -> None:
		super().__init__(localizacao, preco)
		self.__raio = raio

	@property
	def raio(self):
		return self.__raio

	@raio.setter
	def raio(self, valor):
		self.__raio = valor

	def calcula_peso(self):
		pi = 3.14
		area = pi * (self.raio * self.raio)

		return self.preco / area

class TerrenoRetangular(Terreno):
	def __init__(self, localizacao: str, preco: float, ladoMenor: float, ladoMaior: float) -> None:
		super().__init__(localizacao, preco)
		self.__ladoMenor = ladoMenor
		self.__ladoMaior = ladoMaior

	@property
	def ladoMenor(self):
		return self.__ladoMenor

	@ladoMenor.setter
	def ladoMenor(self, valor):
		self.ladoMenor = valor

	@property
	def ladoMaior(self):
		return self.__ladoMaior

	@ladoMaior.setter
	def ladoMaior(self, valor):
		self.ladoMaior = valor

	def calcula_peso(self):
		area = self.ladoMenor * self.ladoMaior

		return self.preco / area

if __name__ == '__main__':
	terrenos: List[Terreno] = []

	tCircular1 = TerrenoCircular('Sao Thome Das Letras', 70000, 15)
	tRetangular = TerrenoRetangular('Machu Picchu', 75000, 20, 35)
	tCircular2 = TerrenoCircular('Varginha', 110000, 20)

	terrenos.extend([tCircular1, tRetangular, tCircular2])

	melhorCusto = terrenos[0]

	for ter in terrenos:
		pesoAtual = ter.calcula_peso()

		print(f'Localizado em {ter.localizacao}, custando R$ {ter.preco:.2f} e peso de {pesoAtual:.3f}')

		if pesoAtual < melhorCusto.calcula_peso():
			melhorCusto = ter

	print()
	print(f'O terreno de melhor custo benefício está localizado em {melhorCusto.localizacao}, no valor de {melhorCusto.preco:.2f} e peso {melhorCusto.calcula_peso():.3f}')
