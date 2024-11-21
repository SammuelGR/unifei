import tkinter as tk
from tkinter import messagebox
import produto as produto
import cupomFiscal as cupomFiscal

class LimitePrincipal():
	def __init__(self, root, controle):
		self.controle = controle
		self.root = root
		self.root.geometry('300x200')
		self.menubar = tk.Menu(self.root)
		self.produtoMenu = tk.Menu(self.menubar)
		self.cupomFiscalMenu = tk.Menu(self.menubar)

		self.produtoMenu.add_command(label="Cadastrar", \
					command=self.controle.insereProdutos)
		self.produtoMenu.add_command(label="Consultar", \
					command=self.controle.consultaProduto)
		self.menubar.add_cascade(label="Produto", \
					menu=self.produtoMenu)

		self.cupomFiscalMenu.add_command(label="Insere", \
					command=self.controle.insereCupomFiscal)
		self.cupomFiscalMenu.add_command(label="Mostra", \
					command=self.controle.mostraCupomFiscal)
		self.menubar.add_cascade(label="Cupom Fiscal", \
					menu=self.cupomFiscalMenu)

		self.root.config(menu=self.menubar)


class ControlePrincipal():
	def __init__(self):
		self.root = tk.Tk()

		self.ctrlProduto = produto.CtrlProduto()

		self.ctrlCupomFiscal = cupomFiscal.CtrlCupomFiscal(self)

		self.limite = LimitePrincipal(self.root, self)

		self.root.title("Cupom Fiscal")
		self.root.mainloop()

	def insereProdutos(self):
		self.ctrlProduto.insereProdutos()

	def consultaProduto(self):
		self.ctrlProduto.consultaProduto()

	def insereCupomFiscal(self):
		self.ctrlCupomFiscal.insereCupomFiscal()

	def mostraCupomFiscal(self):
		self.ctrlCupomFiscal.mostraCupomFiscal()

if __name__ == '__main__':
	c = ControlePrincipal()
