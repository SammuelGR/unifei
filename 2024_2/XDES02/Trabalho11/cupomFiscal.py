import tkinter as tk
from tkinter import messagebox, ttk
from typing import List
import produto as produto

class CupomFiscal:
	def __init__(self, nroCupom: int) -> None:
		self.__nroCupom = nroCupom
		self.__itensCupom: List[produto.Produto] = []

	@property
	def nroCupom(self):
		return self.__nroCupom

	@nroCupom.setter
	def nroCupom(self, value):
		self.nroCupom = value

	@property
	def itensCupom(self):
		return self.__itensCupom

	@itensCupom.setter
	def itensCupom(self, value):
		self.itensCupom = value


class LimiteInsereCupomFiscal(tk.Toplevel):
	def __init__(self, controle, listaProdutos: List[produto.Produto]):

		tk.Toplevel.__init__(self)
		self.geometry('250x100')
		self.title("Cupom fiscal")
		self.controle = controle

		self.frameNro = tk.Frame(self)
		self.frameProduto = tk.Frame(self)
		self.frameButton = tk.Frame(self)
		self.frameNro.pack()
		self.frameProduto.pack()
		self.frameButton.pack()

		self.labelNroCupom = tk.Label(self.frameNro,text="Número do cupom: ")
		self.labelNroCupom.pack(side="left")

		self.inputNroCupom = tk.Entry(self.frameNro, width=20)
		self.inputNroCupom.pack(side="left")

		self.labelProduto = tk.Label(self.frameProduto,text="Produto(s): ")
		self.labelProduto.pack(side="left")

		self.escolhaCombo = tk.StringVar()
		self.combobox = ttk.Combobox(self.frameProduto, width = 15 , textvariable = self.escolhaCombo)
		self.combobox.pack(side="left")
		self.combobox['values'] = listaProdutos

		self.buttonSubmit = tk.Button(self.frameButton ,text="Fechar cupom")
		self.buttonSubmit.pack(side="left")
		self.buttonSubmit.bind("<Button>", controle.enterHandler)

		self.buttonFecha = tk.Button(self.frameButton ,text="Concluído")
		self.buttonFecha.pack(side="left")
		self.buttonFecha.bind("<Button>", controle.fechaHandler)

	def mostraJanela(self, titulo, msg):
		messagebox.showinfo(titulo, msg)

class LimiteMostraCupomFiscal():
	def __init__(self, str):
		messagebox.showinfo('Lista de cupons', str)


class CtrlCupomFiscal():
	def __init__(self, controlePrincipal):
		self.listaCupomFiscal: List[CupomFiscal] = []
		self.ctrlPrincipal = controlePrincipal

	def insereCupomFiscal(self):
		listaProdutos =  []
		for produto in self.ctrlPrincipal.ctrlProduto.getListaProdutos():
			listaProdutos.append(produto.descricao)

		self.limiteIns = LimiteInsereCupomFiscal(self, listaProdutos)

	# TODO: completar
	def mostraCupomFiscal(self):
		output = 'Código\n'

		for cupom in self.listaCupomFiscal:
			output += cupom.nroCupom + '\n'
		self.limiteLista = LimiteMostraCupomFiscal(output)

	def enterHandler(self, event):
		nroCupom = int(self.limiteIns.inputNroCupom.get())

		cupom = CupomFiscal(nroCupom)

		self.listaCupomFiscal.append(cupom)
		self.limiteIns.mostraJanela('Sucesso', 'Cupom fiscal cadastrado com sucesso')
		self.clearHandler(event)

	def fechaHandler(self, event):
		self.limiteIns.destroy()
