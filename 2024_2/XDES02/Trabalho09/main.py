from abc import ABC, abstractmethod

class TitulacaoInvalida(Exception):
	pass

class IdadeMenorQuePermitida(Exception):
	pass

class CursoInvalido(Exception):
	pass

class DocumentoDuplicado(Exception):
	pass

class Pessoa(ABC):
	def __init__(self, nome: str, cpf: str, endereco: str, idade: int):
		self.__nome = nome
		self.__cpf = cpf
		self.__endereco = endereco
		self.__idade = idade

	@property
	def nome(self):
		return self.__nome

	@nome.setter
	def nome(self, value):
		self.nome = value

	@property
	def cpf(self):
		return self.__cpf

	@cpf.setter
	def cpf(self, value):
		self.cpf = value

	@property
	def endereco(self):
		return self.__endereco

	@endereco.setter
	def endereco(self, value):
		self.endereco = value

	@property
	def idade(self):
		return self.__idade

	@idade.setter
	def idade(self, value):
		self.idade = value

	@abstractmethod
	def printDescricao() -> None:
		pass

class Professor(Pessoa):
	def __init__(self, nome, cpf, endereco, idade, titulacao: str):
		super().__init__(nome, cpf, endereco, idade)
		self.__titulacao = titulacao

	@property
	def titulacao(self):
		return self.__titulacao

	@titulacao.setter
	def titulacao(self, value):
		self.titulacao = value

	def printDescricao():
		pass # TODO: implement

class Aluno(Pessoa):
	def __init__(self, nome, cpf, endereco, idade, curso: str):
		super().__init__(nome, cpf, endereco, idade)
		self.__curso = curso

	@property
	def curso(self):
		return self.__curso

	@curso.setter
	def curso(self, value):
		self.curso = value

	def printDescricao():
		pass # TODO: implement

if __name__ == "__main__":
	exemploAlunos = [
		("Aluno 1", "1111", "Rua de Cima", 18, "SIN"), # ✅
		("Aluno 2", "2222", "Rua de Cima", 18, "CCO"), # ✅
		("Aluno 3", "3333", "Rua de Cima", 15, "SIN"), # ❌ idade invalida
		("Aluno 4", "4444", "Rua de Cima", 18, "ECO"), # ❌ curso invalido
		("Aluno 5", "1111", "Rua de Cima", 18, "CCO"), # ❌ cpf duplicado
	]

	exemploProfessores = [
		("Professor 1", "5555", "Rua de Baixo", 30, "Doutor"), # ✅
		("Professor 2", "6666", "Rua de Baixo", 29, "Doutor"), # ❌ idade invalida
		("Professor 3", "7777", "Rua de Baixo", 30, "Espone"), # ❌ titulacao invalida
		("Professor 4", "7777", "Rua de Baixo", 30, "Doutor"), # ❌ cpf duplicado
	]


	cadastro = {}

	for nome, cpf, endereco, idade, titulacao in exemploProfessores:
		try:
			if idade < 30:
				raise IdadeMenorQuePermitida(30)
			if titulacao.lower() != 'doutor':
				raise TitulacaoInvalida()


		except:
			pass
		else:
			pass

	print("exemplo alunos: ", exemploAlunos, end='\n\n') # TODO: remove
	print("exemplo professores: ", exemploProfessores, end='\n\n') # TODO: remove
	print("todos: ", pessoas, end='\n\n') # TODO: remove


