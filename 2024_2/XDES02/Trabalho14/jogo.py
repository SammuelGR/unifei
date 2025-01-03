import tkinter as tk
from tkinter import messagebox, ttk

from math import ceil
import os.path
import pickle
from typing import Literal, List

class Jogo:
	def __init__(self, \
			codigo: str, \
			titulo: str, \
			console: Literal['XBox, PlayStation', 'Switch', 'PC'], \
			genero: Literal['Ação', 'Aventura', 'Estratégia', 'RPG', 'Esporte', 'Simulação'], \
			preco: float) -> None:

		self.__codigo = codigo
		self.__titulo = titulo
		self.console = console
		self.genero = genero
		self.preco = preco
		self.__avaliacoes: List[int] = []
		self.__avaliacao: float = 0.0

	@property
	def codigo(self):
		return self.__codigo

	@codigo.setter
	def codigo(self, value):
		self.__codigo = value

	@property
	def titulo(self):
		return self.__titulo

	@titulo.setter
	def titulo(self, value):
		self.__titulo = value

	@property
	def console(self):
		return self.__console

	@console.setter
	def console(self, value):
		if not value in ['XBox, PlayStation', 'Switch', 'PC']:
			raise ValueError(f'Console inválido: {value}')
		else:
			self.__console = value

	@property
	def genero(self):
		return self.__genero

	@genero.setter
	def genero(self, value):
		if value not in ['Ação', 'Aventura', 'Estratégia', 'RPG', 'Esporte', 'Simulação']:
			raise ValueError(f'Gênero inválido: {value}')
		else:
			self.__genero = value

	@property
	def preco(self):
		return self.__preco

	@preco.setter
	def preco(self, value):
		if value > 0 and value <= 500:
			self.__preco = value
		else:
			raise ValueError(f'Preço inválido: {value}')

	@property
	def avaliacoes(self):
		return self.__avaliacoes

	@avaliacoes.setter
	def avaliacoes(self, value):
		self.__avaliacoes = value

	@property
	def avaliacao(self):
		return self.__avaliacao

	@avaliacao.setter
	def avaliacao(self, value):
		self.__avaliacao = value

	def addAvaliacao(self, novaNota: int):
		self.avaliacoes.append(novaNota)

		novaAvaliacao = 0.0
		for nota in self.avaliacoes:
			novaAvaliacao += nota

		novaAvaliacao /= len(self.avaliacoes)

		self.avaliacao = novaAvaliacao

	def getDescricao(self):
		return f'Código: {self.codigo}' \
				f'\nTítulo: {self.titulo}' \
				f'\nConsole: {self.console}' \
				f'\nGênero: {self.genero}' \
				f'\nPreço: R$ {self.preco:.2f}' \
				f'\nAvaliação: {self.avaliacao:.1f}'

class CtrlJogo:
	def __init__(self):
		if not os.path.isfile("jogo.pickle"):
			self.__listaDeJogos: List[Jogo] = []
		else:
			with open("jogo.pickle", "rb") as f:
				self.__listaDeJogos: List[Jogo] = pickle.load(f)

	@property
	def listaDeJogos(self):
		return self.__listaDeJogos

	@listaDeJogos.setter
	def listaDeJogos(self, value):
		self.__listaDeJogos = value

	def getJogo(self, codigo: str):
		result = next( \
			(jogo for jogo in self.listaDeJogos if jogo.codigo == codigo), None
		)

		if result == None:
			raise ValueError(f'Jogo com o código "{codigo}" não encontrado.')

		return result

	def cadastraJogo(self):
		self.limiteCadastra = LimiteCadastraJogo(self)

	def avaliaJogo(self):
		self.limiteAvalia = LimiteAvaliaJogo(self)

	def consultaJogos(self):
		self.limiteConsulta = LimiteConsultaJogos(self)

	def enterHandler(self, event):
		codigo = self.limiteCadastra.inputCodigo.get()
		titulo = self.limiteCadastra.inputTitulo.get()
		console = self.limiteCadastra.inputConsole.get()
		genero = self.limiteCadastra.inputGenero.get()
		preco = float(self.limiteCadastra.inputPreco.get())

		try:
			jogo = Jogo(codigo, titulo, console, genero, preco)
			self.listaDeJogos.append(jogo)
			self.limiteCadastra.mostraJanela('Sucesso', \
									'Jogo cadastrado com sucesso')
			self.clearHandler(event)
		except ValueError as error:
			self.limiteCadastra.mostraJanela('Erro', error)

	def clearHandler(self, event):
		self.limiteCadastra.inputCodigo.delete(0, \
			len(self.limiteCadastra.inputCodigo.get()))
		self.limiteCadastra.inputTitulo.delete(0, \
			len(self.limiteCadastra.inputTitulo.get()))
		self.limiteCadastra.inputConsole.delete(0, \
			len(self.limiteCadastra.inputConsole.get()))
		self.limiteCadastra.inputGenero.delete(0, \
			len(self.limiteCadastra.inputGenero.get()))
		self.limiteCadastra.inputPreco.delete(0, \
			len(self.limiteCadastra.inputPreco.get()))

	def enterNotaHandler(self, event):
		codigo = self.limiteAvalia.inputCodigo.get()
		nota = int(self.limiteAvalia.escolhaNota.get())

		try:
			jogo = self.getJogo(codigo)
			jogo.addAvaliacao(nota)

			self.limiteAvalia.mostraJanela('Sucesso', \
									'Avaliação enviada com sucesso')
			self.clearNotaHandler(event)
		except ValueError as error:
			self.limiteAvalia.mostraJanela('Erro', error)

	def clearNotaHandler(self, event):
		self.limiteAvalia.inputCodigo.delete(0, \
			self.limiteAvalia.inputCodigo.get())
		self.limiteAvalia.escolhaNota.set('')

	def fechaHandler(self, event):
		self.limiteCadastra.destroy()

	def exibeAvaliacoes(self, event):
		avaliacaoSel = int(self.limiteConsulta.comboAvaliacao.get())
		self.limiteConsulta.textJogos.config(state=tk.NORMAL)
		self.limiteConsulta.textJogos.delete('1.0', tk.END)

		for jogo in self.listaDeJogos:
			if ceil(jogo.avaliacao) == avaliacaoSel:
				self.limiteConsulta.textJogos.insert(tk.END, jogo.getDescricao() + '\n\n')

		self.limiteConsulta.textJogos.config(state=tk.DISABLED)

	def salvaJogos(self):
		if len(self.listaDeJogos) != 0:
			with open('jogo.pickle', 'wb') as f:
				pickle.dump(self.listaDeJogos, f)


class LimiteCadastraJogo(tk.Toplevel):
	def __init__(self, controle: CtrlJogo):
		tk.Toplevel.__init__(self)
		self.geometry('250x150')
		self.title('Jogo')
		self.controle = controle

		self.frameCodigo = tk.Frame(self)
		self.frameTitulo = tk.Frame(self)
		self.frameConsole = tk.Frame(self)
		self.frameGenero = tk.Frame(self)
		self.framePreco = tk.Frame(self)
		self.frameButton = tk.Frame(self)
		self.frameCodigo.pack()
		self.frameTitulo.pack()
		self.frameConsole.pack()
		self.frameGenero.pack()
		self.framePreco.pack()
		self.frameButton.pack()

		self.labelCodigo = tk.Label(self.frameCodigo, text='Código: ')
		self.labelCodigo.pack(side='left')
		self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
		self.inputCodigo.pack(side='left')

		self.labelTitulo = tk.Label(self.frameTitulo, text='Título: ')
		self.labelTitulo.pack(side='left')
		self.inputTitulo = tk.Entry(self.frameTitulo, width=20)
		self.inputTitulo.pack(side='left')

		self.labelConsole = tk.Label(self.frameConsole, text='Console: ')
		self.labelConsole.pack(side='left')
		self.inputConsole = tk.Entry(self.frameConsole, width=20)
		self.inputConsole.pack(side='left')

		self.labelGenero = tk.Label(self.frameGenero, text='Gênero: ')
		self.labelGenero.pack(side='left')
		self.inputGenero = tk.Entry(self.frameGenero, width=20)
		self.inputGenero.pack(side='left')

		self.labelPreco = tk.Label(self.framePreco, text='Preço: ')
		self.labelPreco.pack(side='left')
		self.inputPreco = tk.Entry(self.framePreco, width=20)
		self.inputPreco.pack(side='left')

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

class LimiteAvaliaJogo(tk.Toplevel):
	def __init__(self, controle: CtrlJogo):
		tk.Toplevel.__init__(self)
		self.geometry('200x150')
		self.title('Avaliar Jogo')
		self.controle = controle

		self.frameCodigo = tk.Frame(self)
		self.frameNota = tk.Frame(self)
		self.frameButton = tk.Frame(self)
		self.frameCodigo.pack()
		self.frameNota.pack()
		self.frameButton.pack()

		self.labelCodigo = tk.Label(self.frameCodigo, text='Código: ')
		self.labelCodigo.pack(side='left')
		self.inputCodigo = tk.Entry(self.frameCodigo, width=20)
		self.inputCodigo.pack(side='left')

		self.labelNota = tk.Label(self.frameNota, text='Nota: ')
		self.labelNota.pack(side='left')
		self.escolhaNota = tk.StringVar()
		self.comboboxNota = ttk.Combobox( \
								self.frameNota, \
								width=15, \
								values=[1, 2, 3, 4, 5], \
								textvariable=self.escolhaNota \
							)
		self.comboboxNota.pack(side='left')

		self.buttonSubmit = tk.Button(self.frameButton, text='Salvar')
		self.buttonSubmit.pack(side='left')
		self.buttonSubmit.bind('<Button>', controle.enterNotaHandler)

		self.buttonClear = tk.Button(self.frameButton, text='Limpar')
		self.buttonClear.pack(side='left')
		self.buttonClear.bind('<Button>', controle.clearNotaHandler)

	def mostraJanela(self, titulo: str, msg: str):
		messagebox.showinfo(titulo, msg)

class LimiteConsultaJogos(tk.Toplevel):
	def __init__(self, controle: CtrlJogo):
		tk.Toplevel.__init__(self)

		self.geometry('400x250')
		self.title('Consultar Jogos')
		self.controle = controle

		self.frameCombo = tk.Frame(self)
		self.frameCombo.pack()

		self.labelAvaliacao = tk.Label(self.frameCombo, text='Avaliação: ')
		self.labelAvaliacao.pack(side='left')
		self.escolhaAvaliacao = tk.StringVar()
		self.comboAvaliacao = ttk.Combobox( \
									self.frameCombo, \
									width=15, \
									values=[1, 2, 3, 4, 5], \
									textvariable=self.escolhaAvaliacao \
								)
		self.comboAvaliacao.bind('<<ComboboxSelected>>', \
									self.controle.exibeAvaliacoes)
		self.comboAvaliacao.pack()

		self.frameJogos = tk.Frame(self)
		self.frameJogos.pack()
		self.textJogos = tk.Text(self.frameJogos, height=20, width=40)
		self.textJogos.pack()
		self.textJogos.config(state=tk.DISABLED)
