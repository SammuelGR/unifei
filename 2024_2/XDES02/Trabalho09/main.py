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
	def printDescricao(self) -> None:
		print(f'nome: {nome}, CPF: {cpf}, endereço: {endereco}, idade: {idade} - cadastrado com sucesso!')

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

	def printDescricao(self):
		print(f'✅ Professor, titulação: {self.titulacao},', end=' ')
		super().printDescricao()

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

	def printDescricao(self):
		print(f'✅ Aluno, curso: {self.curso},', end=' ')
		super().printDescricao()

if __name__ == "__main__":
	exemploProfessores = [
		("Hokama P", "91825688044", "Avenida de Cima", 30, "Doutor"), # ✅
		("Adler D", "15375480000", "Avenida do Lado", 29, "Doutor"), # ❌ idade invalida
		("Fabiano L", "21783873060", "Avenida de Baixo", 30, "Mestre"), # ❌ titulacao invalida
		("Claudino R", "91825688044", "Avenida Logo Ali", 30, "Doutor"), # ❌ cpf duplicado
		("Baldochi L", "19856646073", "Rua de Baixo", 35, "Doutor"), # ✅
	]

	exemploAlunos = [
		("Sammuel R", "02128543053", "Rua de Cima", 18, "SIN"), # ✅
		("Nathan A", "32789912068", "Rua do Lado", 18, "CCO"), # ✅
		("Pedro L", "50575832045", "Rua de Baixo", 15, "SIN"), # ❌ idade invalida
		("Renan S", "44640024045", "Rua do Outro Lado", 18, "ECO"), # ❌ curso invalido
		("Lucas G", "02128543053", "Rua Longe", 18, "CCO"), # ❌ cpf duplicado
	]

	cadastro = {}

	for nome, cpf, endereco, idade, titulacao in exemploProfessores:
		try:
			if titulacao.lower() != 'doutor':
				raise TitulacaoInvalida()
			if idade < 30:
				raise IdadeMenorQuePermitida(30)
			if cpf in cadastro:
				raise DocumentoDuplicado()
		except TitulacaoInvalida:
			print(f'❌ Titulação "{titulacao}" inválida para professor')
		except IdadeMenorQuePermitida as e:
			print(f'❌ A idade mínima é {e.args[0]} para professor')
		except DocumentoDuplicado:
			print(f'❌ CPF {cpf} já está em uso por outra pessoa')
		else:
			cadastro[cpf] = Professor(nome, cpf, endereco, idade, titulacao).printDescricao()

	print()

	for nome, cpf, endereco, idade, curso in exemploAlunos:
		try:
			if curso.lower() != 'cco' and curso.lower() != 'sin':
				raise CursoInvalido()
			if idade < 18:
				raise IdadeMenorQuePermitida(18)
			if cpf in cadastro:
				raise DocumentoDuplicado()
		except CursoInvalido:
			print(f'❌ Curso "{curso}" inválido para aluno')
		except IdadeMenorQuePermitida as e:
			print(f'❌ A idade mínima é {e.args[0]} para aluno')
		except DocumentoDuplicado:
			print(f'❌ CPF {cpf} já está em uso por outra pessoa')
		else:
			cadastro[cpf] = Aluno(nome, cpf, endereco, idade, curso).printDescricao()
