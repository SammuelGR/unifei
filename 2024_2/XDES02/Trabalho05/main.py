from abc import ABC
from typing import List


class PontoFunc():
	def __init__(self, mes: int, ano: int, nroFaltas: int, nroAtrasos: int) -> None:
		self.__mes = mes
		self.__ano = ano
		self.__nroFaltas = nroFaltas
		self.__nroAtrasos = nroAtrasos

	@property
	def mes(self):
		return self.__mes

	@mes.getter
	def mes(self):
		return self.__mes

	@mes.setter
	def mes(self, value):
		self.__mes = value

	@property
	def ano(self):
		return self.__ano

	@mes.getter
	def ano(self):
		return self.__ano

	@ano.setter
	def ano(self, value):
		self.__ano = value

	@property
	def nroFaltas(self):
		return self.__nroFaltas

	@nroFaltas.getter
	def nroFaltas(self):
		return self.__nroFaltas

	@nroFaltas.setter
	def nroFaltas(self, value):
		self.__nroFaltas = value

	@property
	def nroAtrasos(self):
		return self.__nroAtrasos

	@nroAtrasos.getter
	def nroAtrasos(self):
		return self.__nroAtrasos

	@nroAtrasos.setter
	def nroAtrasos(self, value):
		self.__nroAtrasos = value

	def getmes(self):
		return self.__mes

	def getAno(self):
		return self.__ano

	def getNroFaltas(self):
		return self.nroFaltas

	def getNroAtrasos(self):
		return self.nroAtrasos

	def lancaFaltas(self, nroFaltas):
		pass

	def lancaAtrasos(self, nroAtrasos):
		pass

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

	def getCodigo(self):
		return self.codigo

	def getNome(self):
		return self.nome

	def getPontoMensalFunc(self):
		return self.__pontoMensalFunc

	def adicionaPonto(self, mes, ano, faltas, atrasos):
		self.__pontoMensalFunc.append(PontoFunc(mes, ano, faltas, atrasos))

	def lancaAtrasos(self, mes, ano, atrasos):
		pass

	def lancaFaltas(self, nroFaltas, ano, mes):
		pass

	def imprimeFolha(self, mes, ano):
		print(f"Código: {self.codigo}")
		print(f"Nome: {self.nome}")
		print(f"Salário líquido: ") # TODO: calc sallary
		print(f"Bônus: ") # TODO: calc bonus

class Professor(Funcionario):
	def __init__(self, codigo: str, nome: str, cargo: str, salarioHora: float, nroAulas: int) -> None:
		super().__init__(codigo, nome, cargo)
		self.__salarioHora = salarioHora
		self.__nroAulas = nroAulas

	@property
	def salarioHora(self):
		return self.__salarioHora

	@salarioHora.getter
	def salarioHora(self):
		return self.__salarioHora

	@salarioHora.setter
	def salarioHora(self, value):
		self.__salarioHora = value

	@property
	def nroAulas(self):
		return self.__nroAulas

	@nroAulas.getter
	def nroAulas(self):
		return self.__nroAulas

	@nroAulas.setter
	def nroAulas(self, value):
		self.__nroAulas = value

	def getTitulacao(self):
		return self.cargo

	def getSalarioHora(self):
		return self.salarioHora * self.nroAulas -  (self.salarioHora * self.nroFaltas)

	def getNroAulas(self):
		pass

	def calculaSalario(self, mes, ano):
		pass

	def calculaBonus(self, mes, ano):
		pass

class TecAdmin(Funcionario):
	def __init__(self, codigo: str, nome: str, cargo: str, salarioMensal: float) -> None:
		super().__init__(codigo, nome, cargo)
		self.__salarioMensal = salarioMensal

	@property
	def salarioMensal(self):
		return self.__salarioMensal

	@salarioMensal.getter
	def salarioMensal(self):
		return self.__salarioMensal

	@salarioMensal.setter
	def salarioMensal(self, value):
		self.__salarioMensal = value

	def getFuncao(self):
		return self.cargo

	def getSalarioMensal(self):
		return self.__salarioMensal

	def calculaBonus(self):
		pass

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
