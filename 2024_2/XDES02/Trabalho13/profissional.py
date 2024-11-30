from typing import List, TYPE_CHECKING

import tkinter as tk
from tkinter import messagebox, ttk, simpledialog

if TYPE_CHECKING:
	from aluno import Aluno


class Profissional:
	def __init__(self, cpf: str, nome: str, email: str, valorPilates: float, valorTreinoFunc: float) -> None:
		self.__cpf = cpf
		self.__nome = nome
		self.__email = email
		self.__valorPilates = valorPilates
		self.__valorTreinoFunc = valorTreinoFunc
		self.__listaAlunos: List['Aluno'] = []

	@property
	def cpf(self):
		return self.__cpf

	@cpf.setter
	def cpf(self, value):
		self.__cpf = value

	@property
	def nome(self):
		return self.__nome

	@nome.setter
	def nome(self, value):
		self.__nome = value

	@property
	def email(self):
		return self.__email

	@email.setter
	def email(self, value):
		self.__email = value

	@property
	def valorPilates(self):
		return self.__valorPilates

	@valorPilates.setter
	def valorPilates(self, value):
		self.__valorPilates = value

	@property
	def valorTreinoFunc(self):
		return self.__valorTreinoFunc

	@valorTreinoFunc.setter
	def valorTreinoFunc(self, value):
		self.__valorTreinoFunc = value

	@property
	def listaAlunos(self):
		return self.__listaAlunos

	@listaAlunos.setter
	def listaAlunos(self, value):
		self.__listaAlunos = value

	def addAluno(self, aluno: 'Aluno'):
		self.listaAlunos.append(aluno)

class CtrlProfissional:
	def __init__(self) -> None:
		self.__listaDeProfissionais: List[Profissional] = []

	@property
	def listaDeProfissionais(self):
		return self.__listaDeProfissionais

	@listaDeProfissionais.setter
	def listaDeProfissionais(self, value):
		self.__listaDeProfissionais = value

	def cadastraProfissional(self):
		self.limiteCadastra = LimiteCadastraProfissional(self)

	def listaProfissionais(self):
		self.limiteLista = LimiteListaProfissionais(self)

		descricao = \
			'CPF -- Nome -- E-mail -- Valor pilates -- Valor treino funcional\n'

		for prof in self.listaDeProfissionais:
			descricao += (
				f'{prof.cpf} -- {prof.nome} -- {prof.email} -- ' \
				f'R$ {prof.valorPilates:.2f} -- R$ {prof.valorTreinoFunc:.2f}\n'
			)

		self.limiteLista.mostraJanela('Lista de profissionais', descricao)

	def enterHandler(self, event):
		cpf = self.limiteCadastra.inputCpf.get()
		nome = self.limiteCadastra.inputNome.get()
		email = self.limiteCadastra.inputEmail.get()
		valorPilates = float(self.limiteCadastra.inputValorPilates.get())
		valorTreinoFunc = float(self.limiteCadastra.inputValorTreinoFunc.get())

		profissional = Profissional(cpf, nome, email, valorPilates, \
								valorTreinoFunc)

		self.listaDeProfissionais.append(profissional)
		self.limiteCadastra.mostraJanela('Sucesso', \
									'Profissional cadastrado com sucesso')
		self.clearHandler(event)

	def faturamento(self):
		self.limiteFaturamento = LimiteFaturamento(self)

		buscaCpf = self.limiteFaturamento.mostraDialog('Consulta', 'CPF: ')

		profBusca = None

		for prof in self.listaDeProfissionais:
			if prof.cpf == buscaCpf:
				profBusca = prof
				break

		if profBusca != None:
			valorPilates = 0.0
			valorTreinoFunc = 0.0

			for aluno in profBusca.listaAlunos:
				if aluno.tipoAula == 'Pilates':
					valorPilates += aluno.valorMensalidade
				else:
					valorTreinoFunc += aluno.valorMensalidade

			descricao = (
				f'Valor Pilates: R$ {valorPilates:.2f}\n' \
				f'Valor Funcional: R$ {valorTreinoFunc:.2f}'
			)

			self.limiteFaturamento.mostraJanela('Faturamento', descricao)
		else:
			self.limiteFaturamento.mostraJanela('Não encontrado', \
									'Profissional não encontrado')

	def clearHandler(self, event):
		self.limiteCadastra.inputCpf.delete(0, \
								len(self.limiteCadastra.inputCpf.get()))
		self.limiteCadastra.inputNome.delete(0, \
								len(self.limiteCadastra.inputNome.get()))
		self.limiteCadastra.inputEmail.delete(0, \
								len(self.limiteCadastra.inputEmail.get()))
		self.limiteCadastra.inputValorPilates.delete(0, \
								len(self.limiteCadastra.inputValorPilates.get()))
		self.limiteCadastra.inputValorTreinoFunc.delete(0, \
								len(self.limiteCadastra.inputValorTreinoFunc.get()))

	def fechaHandler(self, event):
		self.limiteCadastra.destroy()

class LimiteCadastraProfissional(tk.Toplevel):
	def __init__(self, controle: CtrlProfissional):
		tk.Toplevel.__init__(self)
		self.geometry('300x150')
		self.title('Profissional')
		self.controle = controle

		self.frameCpf = tk.Frame(self)
		self.frameNome = tk.Frame(self)
		self.frameEmail = tk.Frame(self)
		self.frameValorPilates = tk.Frame(self)
		self.frameValorTreinoFunc = tk.Frame(self)
		self.frameButton = tk.Frame(self)
		self.frameCpf.pack()
		self.frameNome.pack()
		self.frameEmail.pack()
		self.frameValorPilates.pack()
		self.frameValorTreinoFunc.pack()
		self.frameButton.pack()

		self.labelCpf = tk.Label(self.frameCpf, text='CPF: ')
		self.labelCpf.pack(side='left')
		self.inputCpf = tk.Entry(self.frameCpf, width=20)
		self.inputCpf.pack(side='left')

		self.labelNome = tk.Label(self.frameNome, text='Nome: ')
		self.labelNome.pack(side='left')
		self.inputNome = tk.Entry(self.frameNome, width=20)
		self.inputNome.pack(side='left')

		self.labelEmail = tk.Label(self.frameEmail, text='E-mail: ')
		self.labelEmail.pack(side='left')
		self.inputEmail = tk.Entry(self.frameEmail, width=20)
		self.inputEmail.pack(side='left')

		self.labelValorPilates = tk.Label(self.frameValorPilates, \
									text='Valor aula de pilates: ')
		self.labelValorPilates.pack(side='left')
		self.inputValorPilates = tk.Entry(self.frameValorPilates, width=20)
		self.inputValorPilates.pack(side='left')

		self.labelValorTreinoFunc = tk.Label(self.frameValorTreinoFunc, \
										text='Valor aula treino funcional: ')
		self.labelValorTreinoFunc.pack(side='left')
		self.inputValorTreinoFunc = tk.Entry(self.frameValorTreinoFunc, width=20)
		self.inputValorTreinoFunc.pack(side='left')

		self.buttonSubmit = tk.Button(self.frameButton, text='Salvar')
		self.buttonSubmit.pack(side='left')
		self.buttonSubmit.bind('<Button>', controle.enterHandler)

		self.buttonClear = tk.Button(self.frameButton, text='Limpar')
		self.buttonClear.pack(side='left')
		self.buttonClear.bind('<Button>', controle.clearHandler)

		self.buttonFecha = tk.Button(self.frameButton, text='Fechar')
		self.buttonFecha.pack(side='left')
		self.buttonFecha.bind('<Button>', self.controle.fechaHandler)

	def mostraJanela(self, titulo: str, msg: str):
		messagebox.showinfo(titulo, msg)

class LimiteListaProfissionais(tk.Toplevel):
	def __init__(self, controle) -> None:
		self.controle = controle

	def mostraJanela(self, titulo: str, msg: str):
		messagebox.showinfo(titulo, msg)

class LimiteFaturamento(tk.Toplevel):
	def __init__(self, controle: CtrlProfissional) -> None:
		self.controle = controle

	def mostraJanela(self, titulo, msg):
		messagebox.showinfo(titulo, msg)

	def mostraDialog(self, titulo, msg):
		return simpledialog.askstring(titulo, msg)
