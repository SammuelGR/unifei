import tkinter as tk

from profissional import CtrlProfissional
from aluno import CtrlAluno

class ControlePrincipal:
	def __init__(self) -> None:
		self.root = tk.Tk()

		self.ctrlProfissional = CtrlProfissional()
		self.ctrlAluno = CtrlAluno(self)

		self.limite = LimitePrincipal(self.root, self)

		self.root.title('Gestão de Estúdio')
		self.root.mainloop()

	def cadastraProfissional(self):
		self.ctrlProfissional.cadastraProfissional()

	def listaProfissionais(self):
		self.ctrlProfissional.listaProfissionais()

	def faturamento(self):
		self.ctrlProfissional.faturamento()

	def cadastraAluno(self):
		self.ctrlAluno.cadastraAluno()

	def consultaAluno(self):
		self.ctrlAluno.consultaAluno()

	def sair(self):
		self.root.destroy()

class LimitePrincipal:
	def __init__(self, root: tk.Tk, controle: ControlePrincipal) -> None:
		self.controle = controle

		self.root = root
		self.root.geometry('300x300')

		self.menubar = tk.Menu(self.root)
		self.profissionalMenu = tk.Menu(self.menubar)
		self.alunoMenu = tk.Menu(self.menubar)
		self.sairMenu = tk.Menu(self.menubar)

		self.profissionalMenu.add_command(label='Cadastra', \
									command=self.controle.cadastraProfissional)
		self.profissionalMenu.add_command(label='Lista', \
									command=self.controle.listaProfissionais)
		self.profissionalMenu.add_command(label='Faturamento', \
									command=self.controle.faturamento)
		self.menubar.add_cascade(label='Profissional', \
							menu=self.profissionalMenu)

		self.alunoMenu.add_command(label='Cadastra', \
							 command=self.controle.cadastraAluno)
		self.alunoMenu.add_command(label='Consulta', \
							 command=self.controle.consultaAluno)
		self.menubar.add_cascade(label='Aluno', menu=self.alunoMenu)

		self.sairMenu.add_command(label='Sair', command=self.controle.sair)
		self.menubar.add_cascade(label='Sair', menu=self.sairMenu)

		self.root.config(menu=self.menubar)


if __name__ == '__main__':
	c = ControlePrincipal()
