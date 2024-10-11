from abc import ABC
from typing import List


class PontoFunc():
	def __init__(self, mes: int, ano: int, nroFaltas: int, nroAtrasos: int) -> None:
		self.__mes = mes
		self.__ano = ano
		self.__nroFaltas = nroFaltas
		self.__nroAtrasos = nroAtrasos

class Funcionario(ABC):
	def __init__(self, codigo: str, nome :str, cargo: str) -> None:
		self.__codigo = codigo
		self.__nome = nome
		self.__cargo = cargo
		self.__pontoMensalFunc: List[PontoFunc] = []

	@property
	def nome(self):
		return self.__nome

	@nome.getter
	def nome(self):
		return self.__nome

	@nome.setter
	def nome(self, valor):
		self.__nome = valor

	@property
	def codigo(self):
		return self.__codigo

	@codigo.getter
	def codigo(self):
		return self.__codigo

	@codigo.setter
	def getCodigo(self, valor):
		self.__codigo = valor

	@property
	def cargo(self):
		return self.__cargo

	@cargo.getter
	def cargo(self):
		return self.__cargo

	@cargo.setter
	def cargo(self, valor):
		self.__cargo = valor

	def getNome(self):
		return self.nome

	def getCodigo(self):
		return self.codigo

	def getPontoMensalFunc(self):
		return self.__pontoMensalFunc

	def adicionaPontoMes(mes, ano, faltas, atrasos):





if __name__ == "__main__":
	funcionarios = []
	prof = Professor(1, "Joao", "Doutor", 45.35, 32)
	prof.adicionaPonto(4, 2021, 0, 0)
	prof.lancaFaltas(4, 2021, 2)
	prof.lancaAtrasos(4, 2021, 3)
	funcionarios.append(prof)
	tec = TecAdmin(2, "Pedro", "Analista Contábil", 3600)
	tec.adicionaPonto(4, 2021, 0, 0)
	tec.lancaFaltas(4, 2021, 3)
	tec.lancaAtrasos(4, 2021, 4)
	funcionarios.append(tec)
	for func in funcionarios:
	func.imprimeFolha(4, 2021)
	print()
