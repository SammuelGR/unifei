from abc import ABC, abstractmethod

class Pessoa(ABC):
	def __init__(self, nome, endereco, idade):
		self.__nome = nome
		self.__endereco = endereco
		self.__idade = idade
		self.__listaDisc = []

	@property
	def nome(self):
		return self.__nome

	@property
	def endereco(self):
		return self.__endereco

	@property
	def idade(self):
		return self.__idade

	@property
	def listaDisc(self):
		return self.__listaDisc

	def insereDisc(self, disc):
		self.__listaDisc.append(disc)

	@abstractmethod
	def printDescricao(self):
		pass

class Professor(Pessoa):
	def __init__(self, nome, endereco, idade, titulacao):
		super().__init__(nome, endereco, idade)
		self.__titulacao = titulacao

	@property
	def titulacao(self):
		return self.__titulacao

	def printDescricao(self):
		print('Nome: {}'.format(self.nome))
		print('Endereço: {}'.format(self.endereco))
		print('Idade: {}'.format(self.idade))
		print('Titulação: {}'.format(self.titulacao))
		print('Disciplinas ministradas:')

		for disc in self.listaDisc:
			print(f'Nome: {disc.nomeDisc} - Carga Horaria: {disc.cargaHoraria}')

class Aluno(Pessoa):
	def __init__(self, nome, endereco, idade, curso):
		super().__init__(nome, endereco, idade)
		self.__curso = curso

	@property
	def curso(self):
		return self.__curso

	def printDescricao(self):
		print(f'Nome: {self.nome}')
		print(f'Endereço: {self.endereco}')
		print(f'Idade: {self.idade}')
		print(f'Curso: {self.curso}')
		print('Disciplinas cursadas:')

		for disc in self.listaDisc:
			print(f'Nome: {disc.nomeDisc} - Carga Horaria: {disc.cargaHoraria}')

class Disciplina:
	def __init__(self, nomeDisc, cargaHoraria):
		self.__nomeDisc = nomeDisc
		self.__cargaHoraria = cargaHoraria

	@property
	def nomeDisc(self):
		return self.__nomeDisc

	@property
	def cargaHoraria(self):
		return self.__cargaHoraria

if __name__ == "__main__":
	disc1 = Disciplina("Programacao 00", 64)
	disc2 = Disciplina("Estrutura de Dados 00", 64)
	disc3 = Disciplina("Banco de Dados 00", 64)

	prof = Professor('Joao','Av. BPS, 1303', 44, 'doutorado')
	prof.insereDisc(disc1)
	prof.insereDisc(disc2)
	prof.printDescricao()

	print()

	aluno = Aluno('Pedro','Av. Cesario Alvim, 205', 20, 'SIN')
	aluno.insereDisc(disc1)
	aluno.insereDisc(disc2)
	aluno.insereDisc(disc3)
	aluno.printDescricao()
