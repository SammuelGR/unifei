from __future__ import annotations
from abc import ABC
from datetime import date
from typing import List, Literal

class Transacao(ABC):
	def __init__(self, valor: float, data: date) -> None:
		self.__valor = valor
		self.__data = data

	@property
	def valor(self):
		return self.__valor

	@valor.setter
	def valor(self, value):
		self.__valor = value

	@property
	def data(self):
		return self.__data

	@data.setter
	def data(self, value):
		self.__data = value

	def getValor(self):
		return self.valor

	def getData(self):
		return self.data

class Saque(Transacao):
	def __init__(self, valor: float, data: date, senha: str) -> None:
		super().__init__(valor, data)
		self.__senha = senha

	@property
	def senha(self):
		return self.__senha

	@senha.setter
	def senha(self, value):
		self.__senha = value

	def getSenha(self):
		return self.senha

class Deposito(Transacao):
	def __init__(self, valor: float, data: date, nomeDepositante: str) -> None:
		super().__init__(valor, data)
		self.__nomeDepositante = nomeDepositante

	@property
	def nomeDepositante(self):
		return self.__nomeDepositante

	@nomeDepositante.setter
	def nomeDepositante(self, value):
		self.__nomeDepositante = value

	def getNomeDepositante(self):
		return self.nomeDepositante

class Transferencia(Transacao):
	def __init__(self, valor: float, data: date, senha: str, tipoTransf: Literal['C', 'D' ]) -> None:
		super().__init__(valor, data)
		self.__senha = senha
		self.__tipoTransf = tipoTransf

	@property
	def senha(self):
		return self.__senha

	@senha.setter
	def senha(self, value):
		self.__senha = value

	@property
	def tipoTransf(self):
		return self.__tipoTransf

	@tipoTransf.setter
	def tipoTransf(self, value):
		self.__tipoTransf = value

	def getSenha(self):
		return self.senha

	def getTipoTransf(self):
		return self.tipoTransf

class Conta:
	def __init__(self, nroConta: str, nome: str, limite:float, senha: str) -> None:
		self.__nroConta = nroConta
		self.__nome = nome
		self.__limite = limite
		self.__senha = senha
		self.__transacoes: List[Transacao] = []

	@property
	def nroConta(self):
		return self.__nroConta

	@nroConta.setter
	def nroConta(self, value):
		self.__nroConta = value

	@property
	def nome(self):
		return self.__nome

	@nome.setter
	def nome(self, value):
		self.__nome = value

	@property
	def limite(self):
		return self.__limite

	@limite.setter
	def limite(self, value):
		self.__limite = value

	@property
	def senha(self):
		return self.__senha

	@senha.setter
	def senha(self, value):
		self.__senha = value

	@property
	def transacoes(self):
		return self.__transacoes

	@transacoes.setter
	def transacoes(self, value):
		self.__transacoes = value

	def getNroConta(self):
		return self.nroConta

	def getNome(self):
		return self.nome

	def getLimite(self):
		return self.limite

	def getSenha(self):
		return self.senha

	def getTransacoes(self):
		return self.transacoes

	def adicionaDeposito(self, valor: float, data: date, nomeDepositante: str):
		deposito = Deposito(valor, data, nomeDepositante)
		self.transacoes.append(deposito)

	def adicionaSaque(self, valor: float, data: date, senha: str) -> bool:
		if self.calculaSaldo() < valor or senha != self.senha:
			return False

		saque = Saque(-valor, data, senha)
		self.transacoes.append(saque)
		return True


	def adicionaTransf(self, valor: float, data: date, senha: str, contaFavorecido: Conta) -> bool:
		if self.calculaSaldo() < valor or senha != self.senha:
			return False

		debito = Transferencia(-valor, data, senha, 'D')
		self.transacoes.append(debito)

		credito = Transferencia(valor, data, senha, 'C')
		contaFavorecido.transacoes.append(credito)

	def calculaSaldo(self):
		saldo = self.getLimite()

		for txn in self.transacoes:
			saldo += txn.getValor()

		return saldo

if __name__ == "__main__":
	c1 = Conta(1234, 'Jose da Silva', 1000, 'senha1')
	c1.adicionaDeposito(5000, date.today(), 'Antonio Maia')

	if c1.adicionaSaque(2000, date.today(), 'senha1') == False:
		print('Não foi possível realizar o saque no valor de 2000')

	if c1.adicionaSaque(1000, date.today(), 'senha-errada') == False: # deve falhar
		print('Não foi possível realizar o saque no valor de 1000')

	c2 = Conta(4321, 'Joao Souza', 1000, 'senha2')
	c2.adicionaDeposito(3000, date.today(), 'Maria da Cruz')

	if c2.adicionaSaque(1500, date.today(), 'senha2') == False:
		print('Não foi possível realizar o saque no valor de 1500')

	if c2.adicionaTransf(5000, date.today(), 'senha2', c1) == False: # deve falhar
		print('Não foi possível realizar a transf no valor de 5000')

	if c2.adicionaTransf(800, date.today(), 'senha2', c1) == False:
		print('Não foi possível realizar a transf no valor de 800')

	print('--------')
	print('Saldo de c1: {}'.format(c1.calculaSaldo())) # deve imprimir 4800
	print('Saldo de c2: {}'.format(c2.calculaSaldo())) # deve imprimir 1700
