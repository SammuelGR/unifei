import tkinter as tk
from tkinter import messagebox, simpledialog
from typing import List

class Produto:
	def __init__(self, codigo: int, descricao: str, valorUnit: float) -> None:
		self.__codigo = codigo
		self.__descricao = descricao
		self.__valorUnit = valorUnit

	@property
	def codigo(self):
		return self.__codigo

	@codigo.setter
	def codigo(self, value):
		self.codigo = value

	@property
	def descricao(self):
		return self.__descricao

	@descricao.setter
	def descricao(self, value):
		self.descricao = value

	@property
	def valorUnit(self):
		return self.__valorUnit

	@valorUnit.setter
	def valorUnit(self, value):
		self.valorUnit = value


class LimiteInsereProdutos(tk.Toplevel):
	def __init__(self, controle):

		tk.Toplevel.__init__(self)
		self.geometry('250x100')
		self.title("Produto")
		self.controle = controle

		self.frameCodigo = tk.Frame(self)
		self.frameDescricao = tk.Frame(self)
		self.frameValorUnit = tk.Frame(self)
		self.frameButton = tk.Frame(self)
		self.frameCodigo.pack()
		self.frameDescricao.pack()
		self.frameValorUnit.pack()
		self.frameButton.pack()

		self.labelCodigo = tk.Label(self.frameCodigo,text="Código: ")
		self.labelDescricao = tk.Label(self.frameDescricao,text="Descrição: ")
		self.labelValorUnit = tk.Label(self.frameValorUnit,text="Valor unitário: ")
		self.labelCodigo.pack(side="left")
		self.labelDescricao.pack(side="left")
		self.labelValorUnit.pack(side="left")

		self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
		self.inputCodigo.pack(side="left")
		self.inputDescricao = tk.Entry(self.frameDescricao, width=20)
		self.inputDescricao.pack(side="left")
		self.inputValorUnit = tk.Entry(self.frameValorUnit, width=20)
		self.inputValorUnit.pack(side="left")

		self.buttonSubmit = tk.Button(self.frameButton ,text="Enter")
		self.buttonSubmit.pack(side="left")
		self.buttonSubmit.bind("<Button>", controle.enterHandler)

		self.buttonClear = tk.Button(self.frameButton ,text="Clear")
		self.buttonClear.pack(side="left")
		self.buttonClear.bind("<Button>", controle.clearHandler)

		self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")
		self.buttonFecha.pack(side="left")
		self.buttonFecha.bind("<Button>", controle.fechaHandler)

	def mostraJanela(self, titulo, msg):
		messagebox.showinfo(titulo, msg)

class LimiteConsultaProduto():
	def __init__(self, controle):
		self.controle = controle

	def mostraJanela(self, titulo, msg):
		messagebox.showinfo(titulo, msg)

	def mostraDialog(self, titulo, mensagem):
		return simpledialog.askstring(titulo, mensagem)


class CtrlProduto():
	def __init__(self):
		self.listaProdutos: List[Produto] = []

	def insereProdutos(self):
		self.limiteIns = LimiteInsereProdutos(self)

	def consultaProduto(self):
		self.limiteConsulta = LimiteConsultaProduto(self)

		searchCode = int(self.limiteConsulta.mostraDialog("Pesquisa", "Código: "))
		produtoBusca = None

		for produto in self.listaProdutos:
			if produto.codigo == searchCode:
				produtoBusca = produto
				break

		if produtoBusca != None:
			self.limiteConsulta.mostraJanela("Produto encontrado", \
						  f'Descrição: {produtoBusca.descricao} \nValor unit.: {produtoBusca.valorUnit}')
		else:
			self.limiteConsulta.mostraJanela("Não encontrado", "Código não cadastrado")

	def getListaProdutos(self):
		return self.listaProdutos

	def enterHandler(self, event):
		codigo = int(self.limiteIns.inputCodigo.get())
		descricao = self.limiteIns.inputDescricao.get()
		valorUnit = float(self.limiteIns.inputValorUnit.get())

		produto = Produto(codigo, descricao, valorUnit)

		self.listaProdutos.append(produto)
		self.limiteIns.mostraJanela('Sucesso', 'Produto cadastrado com sucesso')
		self.clearHandler(event)
		self.fechaHandler(event)

	def clearHandler(self, event):
		self.limiteIns.inputCodigo.delete(0, len(self.limiteIns.inputCodigo.get()))
		self.limiteIns.inputDescricao.delete(0, len(self.limiteIns.inputDescricao.get()))
		self.limiteIns.inputValorUnit.delete(0, len(self.limiteIns.inputValorUnit.get()))

	def fechaHandler(self, event):
		self.limiteIns.destroy()
