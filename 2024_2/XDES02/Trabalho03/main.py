from abc import ABC, abstractmethod
from typing import List

class EmpDomestica(ABC):
	def __init__(self, nome: str, telefone: str) -> None:
		self.__nome = nome
		self.__telefone = telefone

	@property
	def nome(self) -> str:
		return self.__nome

	@nome.setter
	def nome(self, texto: str):
		self.__nome = texto

	@property
	def telefone(self) -> str:
		return self.__telefone

	@telefone.setter
	def telefone(self, texto: str):
		self.__telefone = texto

	@abstractmethod
	def getSalario() -> float:
		pass

class Horista(EmpDomestica):
	def __init__(self, nome: str, telefone: str, horasTrabalhadas: int, valorPorHora: float) -> None:
		super().__init__(nome, telefone)
		self.__horasTrabalhadas = horasTrabalhadas
		self.__valorPorHora = valorPorHora

	@property
	def horasTrabalhadas(self) -> int:
		return self.__horasTrabalhadas

	@horasTrabalhadas.setter
	def horasTrabalhadas(self, valor: int):
		self.__horasTrabalhadas = valor

	@property
	def valorPorHora(self) -> float:
		return self.__valorPorHora

	@valorPorHora.setter
	def valorPorHora(self, valor: float):
		self.__valorPorHora = valor

	def getSalario(self) -> float:
		return self.horasTrabalhadas * self.valorPorHora

class Diarista(EmpDomestica):
	def __init__(self, nome: str, telefone: str, diasTrabalhados: int, valorPorDia: float) -> None:
		super().__init__(nome, telefone)
		self.__diasTrabalhados = diasTrabalhados
		self.__valorPorDia = valorPorDia

	@property
	def diasTrabalhados(self):
		return self.__diasTrabalhados

	@diasTrabalhados.setter
	def diasTrabalhados(self, valor: int):
		self.__diasTrabalhados = valor

	@property
	def valorPorDia(self):
		return self.__valorPorDia

	@valorPorDia.setter
	def valorPorDia(self, valor: float):
		self.__valorPorDia = valor

	def getSalario(self) -> float:
		return self.diasTrabalhados * self.valorPorDia

class Mensalista(EmpDomestica):
	def __init__(self, nome: str, telefone: str, valorMensal: float) -> None:
		super().__init__(nome, telefone)
		self.__valorMensal = valorMensal

	@property
	def valorMensal(self):
		return self.__valorMensal

	@valorMensal.setter
	def valorMensal(self, valor):
		self.__valorMensal = valor

	def getSalario(self) -> float:
		return self.valorMensal

if __name__ == '__main__':
	empregadas: List[EmpDomestica] = []

	empHorista = Horista('Creuza', '35999999999', 160, 12)
	empDiarista = Diarista('Vandirleia', '35988888888', 20, 65)
	empMensalista = Mensalista('Dra Deolane', '31977777777', 1200)

	empregadas.extend([empHorista, empDiarista, empMensalista])

	empMenorPreco = empregadas[0]

	for emp in empregadas:
		salarioAtual = emp.getSalario()

		print(f'{emp.nome}, salário mensal de R$ {salarioAtual:.2f}')

		if salarioAtual < empMenorPreco.getSalario():
			empMenorPreco = emp

	print()
	print(f'A opção mais barata será a empregada {empMenorPreco.nome}, telefone {empMenorPreco.telefone}, pelo valor de {empMenorPreco.getSalario()}')
