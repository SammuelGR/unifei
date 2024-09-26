from abc import ABC, abstractmethod

class Professor(ABC):
	def __init__(self, nome, matricula, cargaHoraria):
		self.__nome = nome
		self.__matricula = matricula
		self.__cargaHoraria = cargaHoraria

	@property
	def nome(self):
		return self.__nome
	@property
	def matricula(self):
		return self.__matricula
	@property
	def cargaHoraria(self):
		return self.__cargaHoraria

	@abstractmethod
	def calculaSalario(self):
		pass

	def calculaValorImposto(self, salarioBruto):
		if salarioBruto <= 1903.98:
			return 0

		if salarioBruto <= 2826.65:
			return salarioBruto * 0.075

		if salarioBruto <= 3751.05:
			return salarioBruto * 0.15

		if salarioBruto <= 4664.68 :
			return salarioBruto * 0.225

		return salarioBruto * 0.275

class ProfDE(Professor):
	def __init__(self, nome, matricula, cargaHoraria, salarioBruto):
		super().__init__(nome, matricula, cargaHoraria)
		self.__salarioBruto = salarioBruto

	@property
	def salarioBruto(self):
		return self.__salarioBruto

	@salarioBruto.setter
	def salarioBruto(self, salarioBruto):
		self.__salarioBruto = salarioBruto

	def calculaSalario(self):
		contribuicaoPrevid = self.salarioBruto * 0.11
		imposto = self.calculaValorImposto(self.salarioBruto)

		salarioLiq = self.salarioBruto - (imposto + contribuicaoPrevid)

		return salarioLiq

class ProfHorista(Professor):
	def __init__(self, nome, matricula, cargaHoraria, salarioHora):
		super().__init__(nome, matricula, cargaHoraria)
		self.__salarioHora = salarioHora

	@property
	def salarioHora(self):
		return self.__salarioHora

	@salarioHora.setter
	def salarioHora(self, salarioHora):
		self.__salarioHora = salarioHora

	def calculaSalario(self):
		salarioBruto = self.__salarioHora * self.cargaHoraria
		imposto = self.calculaValorImposto(salarioBruto)

		salarioLiq = salarioBruto - imposto

		return salarioLiq

if __name__ == "__main__":
	prof1 = ProfDE('Joao', 12345, 40, 5000)
	prof2 = ProfHorista('Paulo', 54321, 30, 75)
	prof3 = ProfHorista('Ana', 56789, 38, 95)

	prof1.salarioBruto = 6000
	prof2.salarioHora = 85


	profs = [prof1, prof2, prof3]
	for prof in profs:
		print ('Nome: {} - Salário: {}'.format(prof.nome, prof.calculaSalario()))
