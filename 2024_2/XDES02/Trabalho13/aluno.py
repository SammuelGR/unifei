import tkinter as tk
from tkinter import messagebox, simpledialog, ttk

from typing import List, Literal, TYPE_CHECKING

if TYPE_CHECKING:
	from profissional import Profissional

class Aluno:
	def __init__(self, cpf: str, nome: str, email: str, \
				tipoAula: Literal['Pilates', 'Treino Funcional'], \
				professor: 'Profissional', numeroAulasSemanais: int) -> None:

		self.__cpf = cpf
		self.__nome = nome
		self.__email = email
		self.__tipoAula = tipoAula
		self.__professor = professor
		self.__numeroAulasSemanais = numeroAulasSemanais
		self.__valorMensalidade: float = self.calculaMensalidade()

		professor.addAluno(self)

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
	def tipoAula(self):
		return self.__tipoAula

	@tipoAula.setter
	def tipoAula(self, value):
		self.__tipoAula = value

	@property
	def professor(self):
		return self.__professor

	@professor.setter
	def professor(self, value):
		self.__professor = value

	@property
	def numeroAulasSemanais(self):
		return self.__numeroAulasSemanais

	@numeroAulasSemanais.setter
	def numeroAulasSemanais(self, value):
		self.__numeroAulasSemanais = value

	@property
	def valorMensalidade(self):
		return self.__valorMensalidade

	@valorMensalidade.setter
	def valorMensalidade(self, value):
		self.__valorMensalidade = value

	def calculaMensalidade(self) -> float:
		custoProf = 0.0

		if self.tipoAula == 'Pilates':
			custoProf = self.professor.valorPilates
		else:
			custoProf = self.professor.valorTreinoFunc

		if self.numeroAulasSemanais == 3:
			custoProf *= 1.4
		elif self.numeroAulasSemanais == 4:
			custoProf *= 1.8

		return custoProf * 1.5

class CtrlAluno:
	def __init__(self, controlePrincipal) -> None:
		self.controlePrincipal = controlePrincipal
		self.__listaDeAlunos: List[Aluno] = []
		self.__listaDeProfissionais: List['Profissional'] = []

	@property
	def listaDeAlunos(self):
		return self.__listaDeAlunos

	@listaDeAlunos.setter
	def listaDeAlunos(self, value):
		self.__listaDeAlunos = value

	@property
	def listaDeProfissionais(self):
		return self.__listaDeProfissionais

	@listaDeProfissionais.setter
	def listaDeProfissionais(self, value):
		self.__listaDeProfissionais = value

	def consultaAluno(self):
		self.limiteConsulta = LimiteConsultaAlunos(self)

		buscaCpf = self.limiteConsulta.mostraDialog('Consulta', 'CPF: ')

		alunoBusca = None

		for aluno in self.listaDeAlunos:
			if aluno.cpf == buscaCpf:
				alunoBusca = aluno
				break

		if alunoBusca != None:
			descricao = (
				f'CPF: {alunoBusca.cpf}\n' \
				f'Nome: {alunoBusca.nome}\n' \
				f'E-mail: {alunoBusca.email}\n' \
				f'Tipo de aula: {alunoBusca.tipoAula}\n' \
				f'Professor: {alunoBusca.professor.nome}\n' \
				f'Número de aulas semanais: {alunoBusca.numeroAulasSemanais}\n'
				f'Mensalidade: {alunoBusca.valorMensalidade:.2f}'
			)

			self.limiteConsulta.mostraJanela('Aluno encontrado', descricao)
		else:
			self.limiteConsulta.mostraJanela('Não encontrado', \
									'Aluno não encontrado')

	def cadastraAluno(self):
		self.listaDeProfissionais = \
			self.controlePrincipal.ctrlProfissional.listaDeProfissionais
		self.limiteCadastra = LimiteCadastraAluno(self, self.listaDeProfissionais)

	def enterHandler(self, event):
		cpf = self.limiteCadastra.inputCpf.get()
		nome = self.limiteCadastra.inputNome.get()
		email = self.limiteCadastra.inputEmail.get()
		tipoAula = self.limiteCadastra.escolhaTipoAula.get()
		nomeProfessor = self.limiteCadastra.escolhaProfissional.get()
		numeroAulas = int(self.limiteCadastra.escolhaNumeroAulasSemanais.get())

		professor = next (prof for prof in self.__listaDeProfissionais \
					if prof.nome == nomeProfessor)

		aluno = Aluno(cpf, nome, email, tipoAula, professor, numeroAulas)

		self.listaDeAlunos.append(aluno)

		self.limiteCadastra.mostraJanela('Sucesso', 'Aluno cadastrado')
		self.clearHandler(event)

	def clearHandler(self, event):
		self.limiteCadastra.inputCpf.delete(0, len(self.limiteCadastra.inputCpf.get()))
		self.limiteCadastra.inputNome.delete(0, len(self.limiteCadastra.inputNome.get()))
		self.limiteCadastra.inputEmail.delete(0, len(self.limiteCadastra.inputEmail.get()))
		self.limiteCadastra.escolhaTipoAula.set('')
		self.limiteCadastra.escolhaProfissional.set('')
		self.limiteCadastra.escolhaNumeroAulasSemanais.set('')

	def fechaHandler(self, event):
		self.limiteCadastra.destroy()

class LimiteCadastraAluno(tk.Toplevel):
	def __init__(self, controle: CtrlAluno, listaProfissionais: List['Profissional']):
		tk.Toplevel.__init__(self)
		self.geometry('300x300')
		self.title('Aluno')
		self.controle = controle

		self.frameCpf = tk.Frame(self)
		self.frameNome = tk.Frame(self)
		self.frameEmail = tk.Frame(self)
		self.frameTipoAula = tk.Frame(self)
		self.frameProfissional = tk.Frame(self)
		self.frameNumeroAulasSemanais = tk.Frame(self)
		self.frameButton = tk.Frame(self)
		self.frameCpf.pack()
		self.frameNome.pack()
		self.frameEmail.pack()
		self.frameTipoAula.pack()
		self.frameProfissional.pack()
		self.frameNumeroAulasSemanais.pack()
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

		self.labelTipoAula = tk.Label(self.frameTipoAula, text='Tipo de aula: ')
		self.labelTipoAula.pack(side='left')
		self.escolhaTipoAula = tk.StringVar()
		self.comboTipoAula = ttk.Combobox(self.frameTipoAula, width=20, \
									textvariable=self.escolhaTipoAula)
		self.comboTipoAula.pack(side='left')
		self.comboTipoAula['values'] = ['Pilates', 'Treino Funcional']

		self.labelProfissional = tk.Label(self.frameProfissional, \
									text='Nome do professor: ')
		self.labelProfissional.pack(side='left')
		self.escolhaProfissional = tk.StringVar()
		self.comboProfissional = ttk.Combobox(self.frameProfissional, width=20, \
									textvariable=self.escolhaProfissional)
		self.comboProfissional.pack(side='left')
		self.comboProfissional['values'] = [prof.nome for prof in listaProfissionais]

		self.labelNumeroAulasSemanais = tk.Label(self.frameNumeroAulasSemanais, \
											text='Número de aulas semanais: ')
		self.labelNumeroAulasSemanais.pack(side='left')
		self.escolhaNumeroAulasSemanais = tk.StringVar()
		self.comboNumeroAulasSemanais = ttk.Combobox(self.frameNumeroAulasSemanais, \
							width=20, textvariable=self.escolhaNumeroAulasSemanais)
		self.comboNumeroAulasSemanais.pack(side='left')
		self.comboNumeroAulasSemanais['values'] = ['2', '3', '4']

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

class LimiteConsultaAlunos:
	def __init__(self, controle: CtrlAluno) -> None:
		self.controle = controle

	def mostraJanela(self, titulo, msg):
		messagebox.showinfo(titulo, msg)

	def mostraDialog(self, titulo, msg):
		return simpledialog.askstring(titulo, msg)
