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

if __name__ == "__main__":
	totalFaturado = 0
	totalImposto = 0
	vendas = []
	vendapf = VendaPF(1000, date.today(), '123456789', 'Joao')
	vendapf.adicionaItem(100, 10, 10)
	vendapf.adicionaItem(100, 10, 20)
	vendapf.adicionaItem(100, 10, 30)
	vendas.append(vendapf)
	vendapj = VendaPJ(1001, date.today(), '987654321', 'Silva Ltda')
	vendapj.adicionaItem(200, 100, 10)
	vendapj.adicionaItem(201, 100, 20)
	vendas.append(vendapj)

	for venda in vendas:
		totalFaturado += venda.calculaTotalVendido()
		totalImposto += venda.calculaImposto()

	print('Total faturado: {}'.format(totalFaturado))
	print('Total pago em impostos: {}'.format(totalImposto))
