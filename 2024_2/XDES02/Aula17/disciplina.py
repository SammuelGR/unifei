import tkinter as tk
from tkinter import messagebox

class Disciplina:
	def __init__(self, codigo: str, nome: str):
		self.__codigo = codigo
		self.__nome = nome

	@property
	def codigo(self):
		return self.__codigo

	@property
	def nome(self):
		return self.__nome

class LimiteInsereDisciplinas(tk.Toplevel):
	def __init__(self, controle):
		tk.Toplevel.__init__(self)
		self.geometry('250x100')
		self.title('Disciplinas')
		self.controle = controle

		self.frameCodigo = tk.Frame(self)
		self.frameNome = tk.Frame(self)
		self.frameButton = tk.Frame(self)
		self.frameCodigo.pack()
		self.frameNome.pack()
		self.frameButton.pack()

		self.labelCodigo = tk.Label(self.frameCodigo, text='Código: ')
		self.labelNome = tk.Label(self.frameNome, text='Nome: ')
		self.labelCodigo.pack(side='left')
		self.labelNome.pack(side='left')

		self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
		self.inputCodigo.pack(side='left')
		self.inputNome = tk.Entry(self.frameNome, width=20)
		self.inputNome.pack(side='left')

		self.buttonSubmit = tk.Button(self.frameButton, text='Enter')
		self.buttonSubmit.pack(side='left')
		self.buttonSubmit.bind('<Button>', controle.enterHandler)

		self.buttonClear = tk.Button(self.frameButton, text="Clear")
		self.buttonClear.pack(side='left')
		self.buttonClear.bind('<Button>', controle.clearHandler)

		self.buttonFecha = tk.Button(self.frameButton, text="Concluído")
		self.buttonFecha.pack(side='left')
		self.buttonFecha.bind('<Button>', controle.fechaHandler)

	def mostraJanela(self, titulo, msg):
		messagebox.showinfo(titulo, msg)

class LimiteMostraDisciplinas:
	def __init__(self, str):
		messagebox.showinfo('Lista de disciplinas', str)

class CtrlDisciplina:
	def __init__(self):
		self.listaDisciplinas = []

	def insereDisciplinas(self):
		self.listaDisciplinas = LimiteInsereDisciplinas(self)

	def mostraDisciplinas(self):
		str = 'Codigo -- Nome\n'

		for disc in self.listaDisciplinas:
			str += disc.codigo + ' 00 ' + disc.nome + '\n'

		self.limiteLista = LimiteMostraDisciplinas(str)

	def enterHandler(self, event):
		codigo = self.limiteIns.inputCodigo.get()
		nome = self.limiteIns.inputNome.get()

		disciplina = Disciplina(codigo, nome)

		self.listaDisciplinas.append(disciplina)
		self.limiteIns.mostraJanela('Sucesso', 'Disciplina cadastrada com sucesso')
		self.clearHandler(event)

	def clearHandler(self, event):
		self.limiteIns.inputCodigo.delete(0, len(self.limiteIns.inputCodigo.get()))
		self.limiteIns.inputNome.delete(0, len(self.limiteIns.inputNome.get()))

	def fechaHandler(self, event):
		self.limiteIns.destroy()
