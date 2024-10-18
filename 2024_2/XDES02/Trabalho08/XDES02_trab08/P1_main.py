from abc import ABC
from datetime import date, datetime
from typing import Literal, List

class Paciente:
	def __init__(self, nome: str, tipo: Literal['Particular', 'Convênio']):
		self.__nome = nome
		self.__tipo = tipo

	@property
	def nome(self):
		return self.__nome

	@property
	def tipo(self):
		return self.__tipo

	def getNome(self):
		return self.nome

	def getTipo(self) -> Literal['Particular', 'Convênio']:
		return self.tipo

class TipoCirurgia:
	def __init__(self, descricao: str, valorCirurgiao: float, valorAnest: float, valorInstrum: float):
		self.__descricao = descricao
		self.__valorCirurgiao = valorCirurgiao
		self.__valorAnest = valorAnest
		self.__valorInstrum = valorInstrum

	@property
	def descricao(self):
		return self.__descricao

	@property
	def valorCirurgiao(self):
		return self.__valorCirurgiao

	@property
	def valorAnest(self):
		return self.__valorAnest

	@property
	def valorInstrum(self):
		return self.__valorInstrum

	def getDescricao(self):
		return self.descricao

	def getValorCirurgiao(self):
		return self.valorCirurgiao

	def getValorAnest(self):
		return self.valorAnest

	def getValorInstrum(self):
		return self.valorInstrum

class ProfSaude(ABC):
	def __init__(self, nome: str, cpf: str):
		self.__nome = nome
		self.__cpf = cpf

	@property
	def nome(self):
		return self.__nome

	@property
	def cpf(self):
		return self.__cpf

	def getNome(self):
		return self.nome

	def getCpf(self):
		return self.cpf

class Medico(ProfSaude):
	def __init__(self, nome, cpf, crm: str, especialidade: Literal['Cirurgião', 'Anestesista']):
		super().__init__(nome, cpf)
		self.__cmr = crm
		self.__especialidade = especialidade

	@property
	def crm(self):
		return self.__cmr

	@property
	def especialidade(self):
		return self.__especialidade

	def getCrm(self):
		return self.crm

	def getEspecialidade(self):
		return self.especialidade

class Instrumentador(ProfSaude):
	def __init__(self, nome, cpf, coren: str):
		super().__init__(nome, cpf)
		self.__coren = coren

	@property
	def coren(self):
		self.__coren

	def getCoren(self):
		return self.coren

class Cirurgia:
	def __init__(self, data: date, paciente: Paciente, tipoCirurgia: TipoCirurgia):
		self.__data = data
		self.__paciente = paciente
		self.__tipoCirurgia = tipoCirurgia
		self.__equipe: List[ProfSaude] = []

	@property
	def data(self):
		return self.__data

	@property
	def paciente(self):
		return self.__paciente

	@property
	def tipoCirurgia(self):
		return self.__tipoCirurgia

	@property
	def equipe(self):
		return self.__equipe

	def getData(self):
		return self.data

	def getPaciente(self):
		return self.paciente

	def getTipoCirurgia(self):
		return self.tipoCirurgia

	def getEquipe(self):
		return self.equipe

	def adicionaProf(self, prof: ProfSaude) -> None:
		self.equipe.append(prof)

	def equipeValida(self):
		cirurg = instr = anest = 0

		for prof in self.equipe:
			if isinstance(prof, Medico) and prof.getEspecialidade() == 'Cirurgião':
				cirurg += 1
			elif isinstance(prof, Medico) and prof.getEspecialidade() == 'Anestesista':
				anest += 1
			else:
				instr += 1

		if cirurg >= 1 and instr >= 1 and anest >= 1:
			return True
		return False

	def calculaCustoCir(self) -> float:
		if not self.equipeValida():
			return 0

		valorTotal = 0

		tipoCirur = self.getTipoCirurgia()

		valorTotal += tipoCirur.getValorAnest() + tipoCirur.getValorCirurgiao() + tipoCirur.getValorInstrum()

		if self.paciente.getTipo() == 'Particular':
			return valorTotal

		return valorTotal * 0.8

if __name__ == "__main__":
	tipo1 = TipoCirurgia('Oncológica', 8000, 2000, 1000)
	tipo2 = TipoCirurgia('Cardíaca', 9000, 2000, 1200)
	tipo3 = TipoCirurgia('Ortopédica', 7000, 2000, 900)
	pac1 = Paciente('Luiz Silva', 'Particular')
	pac2 = Paciente('José Cruz', 'Convênio')
	pac3 = Paciente('Márcia Reis', 'Particular')
	medCir1 = Medico('Luis Lima', '1234', 'crm1234', 'Cirurgião')
	medCir2 = Medico('Marcos Lopes', '9876', 'crm9876', 'Cirurgião')
	medAnest1 = Medico('Marisa Lins', '4321', 'crm4321', 'Anestesista')
	inst1 = Instrumentador('Ana Souza', '4567', 'coren4567')
	inst2 = Instrumentador('Joel Santos', '7890', 'coren7890')
	cirurgia1 = Cirurgia(datetime(2023, 10, 30), pac1, tipo1)
	cirurgia1.adicionaProf(medCir1)
	cirurgia1.adicionaProf(inst1)
	custo1 = cirurgia1.calculaCustoCir()
	if custo1 == 0:
		print('Equipe não está completa.')
	else:
		print('O valor da cirurgia do paciente {} é {}'.format(pac1.nome, custo1))
	#Saída esperada: 'Equipe não está completa'
	print()

	cirurgia2 = Cirurgia(datetime(2023, 11, 10), pac2, tipo1)
	cirurgia2.adicionaProf(medCir1)
	cirurgia2.adicionaProf(medAnest1)
	cirurgia2.adicionaProf(inst1)
	custo2 = cirurgia2.calculaCustoCir()
	if custo2 == 0:
		print('Equipe não está completa.')
	else:
		print('O valor da cirurgia do paciente {} é {}'.format(pac2.nome, custo2))
	#Saída esperada: 'O valor da cirurgia do paciente José Cruz é 8800.0'
	print()

	cirurgia3 = Cirurgia(datetime(2023, 11, 20), pac3, tipo2)
	cirurgia3.adicionaProf(medCir1)
	cirurgia3.adicionaProf(medAnest1)
	cirurgia3.adicionaProf(inst2)
	custo3 = cirurgia3.calculaCustoCir()
	if custo3 == 0:
		print('Equipe não está completa.')
	else:
		print('O valor da cirurgia da paciente {} é {}'.format(pac3.nome, custo3))
	#Saída esperada: 'O valor da cirurgia da paciente Márcia Reis é 12200'
