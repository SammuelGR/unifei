import tkinter as tk

import jogo

class ControlePrincipal:
	def __init__(self):
		self.root = tk.Tk()

		self.ctrlJogo = jogo.CtrlJogo()

		self.limite = LimitePrincipal(self.root, self)

		self.root.title('Cadastro de Jogos')
		self.root.mainloop()

	def cadastraJogo(self):
		self.ctrlJogo.cadastraJogo()

	def avaliaJogo(self):
		self.ctrlJogo.avaliaJogo()

	def consultaJogos(self):
		self.ctrlJogo.consultaJogos()

	def salvaJogos(self):
		self.ctrlJogo.salvaJogos()

class LimitePrincipal:
	def __init__(self, root: tk.Tk, controle: ControlePrincipal):
		self.controle = controle
		self.root = root
		self.root.geometry('200x150')
		self.menubar = tk.Menu(self.root)
		self.jogoMenu = tk.Menu(self.menubar)
		self.salvaMenu = tk.Menu(self.menubar)

		self.jogoMenu.add_command(label='Cadastrar', command=self.controle.cadastraJogo)
		self.jogoMenu.add_command(label='Avaliar', command=self.controle.avaliaJogo)
		self.jogoMenu.add_command(label='Consultar', command=self.controle.consultaJogos)
		self.menubar.add_cascade(label='Jogo', menu=self.jogoMenu)

		self.salvaMenu.add_command(label='Salvar', command=self.controle.salvaJogos)
		self.menubar.add_cascade(label='Sair', menu=self.salvaMenu)

		self.root.config(menu=self.menubar)


if __name__ == '__main__':
	c = ControlePrincipal()
