from abc import ABC, abstractmethod
from typing import List
from datetime import date

class ItemVenda:
	def __init__(self, pCodProd: int, pQuant: int, pPrecoUnit: float):
		self.__codProd = pCodProd
		self.__quant = pQuant
		self.__precoUnit = pPrecoUnit

	@property
	def codProd(self):
		return self.__codProd

	def getCodProd(self):
		return self.codProd

	@property
	def quant(self):
		return self.__quant

	def getQuant(self):
		return self.quant

	@property
	def precoUnit(self):
		return self.__precoUnit

	def getPrecoUnit(self):
		return self.precoUnit

class Venda(ABC):
	def __init__(self, pNroNF: int, pDtEmissao: date):
		self.__nroNF = pNroNF
		self.__dtEmissao = pDtEmissao
		self.__itens: List[ItemVenda] = []

	@property
	def nroNF(self):
		return self.__nroNF

	def getNroNF(self):
		return self.nroNF

	@property
	def dtEmissao(self):
		return self.__dtEmissao

	def getDtEmissao(self):
		return self.dtEmissao

	@property
	def itens(self):
		return self.__itens

	def getItens(self):
		return self.itens

	def adicionaItem(self, pCodProd: int, pQuant: int, pPrecoUnit: float) -> None:
		novoItem = ItemVenda(pCodProd, pQuant, pPrecoUnit)
		self.itens.append(novoItem)
		return

	def calculaTotalVendido(self) -> float:
		total = 0

		for item in self.itens:
			total += item.getQuant() * item.getPrecoUnit()

		return total

	@abstractmethod
	def geraNF(self) -> str:
		pass

	@abstractmethod
	def calculaImposto(self) -> float:
		pass

class VendaPF(Venda):
	def __init__(self, pNroNF: int, pDtEmissao: date, pCpf: str, pNome: str):
		super().__init__(pNroNF, pDtEmissao)
		self.__cpf = pCpf
		self.__nome = pNome

	@property
	def cpf(self):
		return self.__cpf

	@property
	def nome(self):
		return self.__nome

	def getCpf(self):
		return self.cpf

	def getNome(self):
		return self.nome

	def geraNF(self) -> str:
		pass # ¯\_(ツ)_/¯

	def calculaImposto(self) -> float:
		total = 0
		for item in self.getItens():
			total += item.getQuant() * item.getPrecoUnit()

		return total * 0.09


class VendaPJ(Venda):
	def __init__(self, pNroNF: int, pDtEmissao: date, pCnpj: str, pNomeFantasia: str):
		super().__init__(pNroNF, pDtEmissao)
		self.__cnpj = pCnpj
		self.__nomeFantasia = pNomeFantasia

	@property
	def cnpj(self):
		return self.__cnpj

	@property
	def nomeFantasia(self):
		return self.__nomeFantasia

	def getCnpj(self):
		return self.cnpj

	def getNomeFantasia(self):
		return self.nomeFantasia

	def geraNF(self) -> str:
		pass # ¯\_(ツ)_/¯

	def calculaImposto(self) -> float:
		total = 0

		for item in self.getItens():
			total += item.getPrecoUnit() * item.getQuant()

		return total * 0.06

if __name__ == "__main__":
	totalFaturado = 0
	totalImposto = 0
	vendas = []

	vendapf = VendaPF(1000, date.today(), '123456789', 'Joao')
	vendapf.adicionaItem(100, 10, 10) # 100
	vendapf.adicionaItem(100, 10, 20) # 200
	vendapf.adicionaItem(100, 10, 30) # 300
	vendas.append(vendapf) # 600 - 54

	vendapj = VendaPJ(1001, date.today(), '987654321', 'Silva Ltda')
	vendapj.adicionaItem(200, 100, 10) # 1000
	vendapj.adicionaItem(201, 100, 20) # 2000
	vendas.append(vendapj) # 3000 - 180

	for venda in vendas:
		totalFaturado += venda.calculaTotalVendido() # 3600
		totalImposto += venda.calculaImposto() # 234

	print('Total faturado: {}'.format(totalFaturado))
	print('Total pago em impostos: {}'.format(totalImposto))
