from abc import ABC, abstractmethod
from typing import List
from datetime import date

class Transacao():
	def __init__(self, data: date, valor: float, descricao: str) -> None:
		self.__data = data
		self.__valor = valor
		self.__descricao = descricao

	@property
	def data(self):
		return self.__data

	@property
	def valor(self):
		return self.__valor

	@property
	def descricao(self):
		return self.__descricao

class Conta(ABC):
	def __init__(self, numeroConta: int, nomeCliente: str, saldo: float) -> None:
		self.__numeroConta = numeroConta
		self.__nomeCliente = nomeCliente
		self.__saldo = saldo
		self.__transacoes: List[Transacao] = []

	@property
	def numeroConta(self):
		return self.__numeroConta

	@property
	def nomeCliente(self):
		return self.__nomeCliente

	@property
	def saldo(self):
		return self.__saldo

	@saldo.setter
	def saldo(self, valor: float):
		self.__saldo = valor

	@property
	def transacoes(self):
		return self.__transacoes

	def deposito(self, valor: float, descricao: str) -> None:
		self.__transacoes.append(Transacao(date.today(), valor, descricao))
		self.__saldo += valor

	def saque(self, valor: float, descricao: str) -> bool:
		if valor > 0:
			return False

		if self.__saldo + valor < 0:
			return False

		self.__transacoes.append(Transacao(date.today(), valor, descricao))
		self.__saldo += valor

		return True

	@abstractmethod
	def impExtrato():
		pass

class ContaLimite(Conta):
	def __init__(self, numeroConta: int, nomeCliente: str, saldo: float, limite: float) -> None:
		super().__init__(numeroConta, nomeCliente, saldo)
		self.__limite = limite

	@property
	def limite(self):
		return self.__limite

	def saque(self, valor: float, descricao: str) -> bool:
		if valor > 0:
			return False

		if self.saldo  + self.__limite + valor < 0:
			return False

		self.transacoes.append(Transacao(date.today(), valor, descricao))
		self.saldo += valor

		return True

	def impExtrato(self) -> None:
		print(f'Nro conta: {self.numeroConta}')
		print(f'Nome: {self.nomeCliente}')
		print(f'Saldo: {self.saldo}')
		print(f'Saldo + Limite: {self.saldo + self.__limite}')

class ContaPoupanca(Conta):
	def __init__(self, numeroConta: int, nomeCliente: str, saldo: float, diaAniversario: int) -> None:
		super().__init__(numeroConta, nomeCliente, saldo)
		self.__diaAniversario = diaAniversario

	@property
	def diaAniversario(self):
		return self.__diaAniversario

	def impExtrato(self) -> None:
		print(f'Nro conta: {self.numeroConta}')
		print(f'Nome: {self.nomeCliente}')
		print(f'Saldo: {self.saldo}')
		print(f'Dia aniversario: {self.__diaAniversario}')

class ContaCorrente(Conta):
	def __init__(self, numeroConta: int, nomeCliente: str, saldo: floa, mensalidade: float) -> None:
		super().__init__(numeroConta, nomeCliente, saldo)
		self.__mensalidade = mensalidade

	@property
	def mensalidade(self):
		return self.__mensalidade

if __name__ == '__main__':
	contas: List[Conta] = []

	cl = ContaLimite(1111, 'Ana Souza', 0, 1000)
	cl.deposito(1500, 'Crédito salário')

	if cl.saque(-1200, 'Pgto boleto'):
		print(f'Saque de R$ 1200,00 na conta {cl.numeroConta}')
	else:
		print(f'Falha ao realizar saque de R$ 1200,00 na conta {cl.numeroConta}')

	if cl.saque(-500, 'PIX'):
		print(f'Saque de R$ 500,00 na conta {cl.numeroConta}')
	else:
		print(f'Falha ao realizar saque de R$ 500,00 na conta {cl.numeroConta}')

	contas.append(cl)

	cp = ContaPoupanca(2222, 'Elinho Moska', 0, 10)
	cp.deposito(3000, 'Tigrinho')

	if cp.saque(-50000, 'Multa do careca'):
		print(f'Saque de R$ 50000,00 na conta {cp.numeroConta}')
	else:
		print(f'Falha ao realizar saque de R$ 50000,00 na conta {cp.numeroConta}')

	if cp.saque(-2000, 'Investimento'):
		print(f'Saque de R$ 2000,00 na conta {cp.numeroConta}')
	else:
		print(f'Falha ao realizar saque de R$ 2000,00 na conta {cp.numeroConta}')

	contas.append(cp)

	print()

	for conta in contas:
		conta.impExtrato()
		print()

