from typing import List, TYPE_CHECKING

import tkinter as tk
from tkinter import messagebox, ttk, simpledialog

import musica as mus

if TYPE_CHECKING:
	from artista import Artista
	from musica import Musica


class Album:
	def __init__(self, ano: int, titulo: str, artista: 'Artista') -> None:
		self.__ano = ano
		self.__titulo = titulo
		self.__artista = artista
		self.__musicas: List[Musica] = []

	@property
	def ano(self):
		return self.__ano

	@ano.setter
	def ano(self, value):
		self.__ano = value

	@property
	def titulo(self):
		return self.__titulo

	@titulo.setter
	def titulo(self, value):
		self.__titulo = value

	@property
	def artista(self):
		return self.__artista

	@artista.setter
	def artista(self, value):
		self.__artista = value

	@property
	def musicas(self):
		return self.__musicas

	@musicas.setter
	def musicas(self, value):
		self.musicas = value

class LimiteInsereAlbum(tk.Toplevel):
	def __init__(self, controle: 'CtrlAlbum', listaArtistas: List['Artista']):
		tk.Toplevel.__init__(self)
		self.geometry('250x200')
		self.title('Album')
		self.controle = controle

		self.frameTitulo = tk.Frame(self)
		self.frameArtista = tk.Frame(self)
		self.frameAno = tk.Frame(self)
		self.frameFaixas = tk.Frame(self)
		self.frameButton = tk.Frame(self)
		self.frameTitulo.pack()
		self.frameArtista.pack()
		self.frameAno.pack()
		self.frameFaixas.pack()
		self.frameButton.pack()

		self.labelTitulo = tk.Label(self.frameTitulo, text='Título: ')
		self.labelTitulo.pack(side='left')
		self.inputTitulo = tk.Entry(self.frameTitulo, width=20)
		self.inputTitulo.pack(side='left')

		self.labelArtista = tk.Label(self.frameArtista, text='Artista: ')
		self.labelArtista.pack(side='left')
		self.escolhaCombo = tk.StringVar()
		self.combobox = ttk.Combobox(self.frameArtista, width=15, textvariable=self.escolhaCombo)
		self.combobox.pack(side='left')
		self.combobox['values'] = [artista.nome for artista in listaArtistas]

		self.labelAno = tk.Label(self.frameAno, text='Ano: ')
		self.labelAno.pack(side='left')
		self.inputAno = tk.Entry(self.frameAno, width=20)
		self.inputAno.pack(side='left')

		self.labelFaixas = tk.Label(self.frameFaixas, text='Faixas: ')
		self.labelFaixas.pack(side='left')
		self.inputFaixa = tk.Entry(self.frameFaixas, width=20)
		self.inputFaixa.pack(side='left')

		self.buttonInsereFaixa = tk.Button(self.frameFaixas, text='Insere faixa')
		self.buttonInsereFaixa.pack(side='top')
		self.buttonInsereFaixa.bind('<Button>', controle.insereFaixa)


		self.buttonSubmit = tk.Button(self.frameButton, text='Enter')
		self.buttonSubmit.pack(side='left')
		self.buttonSubmit.bind('<Button>', controle.enterHandler)

		self.buttonClear = tk.Button(self.frameButton, text='Clear')
		self.buttonClear.pack(side='left')
		self.buttonClear.bind('<Button>', controle.clearHandler)

		self.buttonFecha = tk.Button(self.frameButton, text='Concluído')
		self.buttonFecha.pack(side='left')
		self.buttonFecha.bind('<Button>', self.controle.fechaHandler)

	def mostraJanela(self, titulo: str, msg: str):
		messagebox.showinfo(titulo, msg)

class LimiteConsultaAlbum:
	def __init__(self, controle):
		self.controle = controle

	def mostraJanela(self, titulo, msg):
		messagebox.showinfo(titulo, msg)

	def mostraDialog(self, titulo, mensagem):
		return simpledialog.askstring(titulo, mensagem)


class CtrlAlbum:
	def __init__(self, controlePrincipal) -> None:
		self.controlePrincipal = controlePrincipal
		self.__listaAlbuns: List[Album] = []
		self.__listaArtistas: List['Artista'] = []
		self.listaFaixas: List['Musica'] = []

	@property
	def listaAlbuns(self):
		return self.__listaAlbuns

	@property
	def listaArtistas(self):
		return self.__listaArtistas

	@listaArtistas.setter
	def listaArtistas(self, value):
		self.__listaArtistas = value

	def consultaAlbum(self):
		self.limiteConsulta = LimiteConsultaAlbum(self)

		buscaTitulo = self.limiteConsulta.mostraDialog('Consulta', 'Título: ')
		albumBusca = None


		for album in self.listaAlbuns:
			if album.titulo == buscaTitulo:
				albumBusca = album
				break

		if albumBusca != None:
			descricao = 'Faixas:\n'

			for faixa in albumBusca.musicas:
				descricao += f'{faixa.nroFaixa} - {faixa.titulo}\n'

			self.limiteConsulta.mostraJanela('Álbum encontrado',  descricao)
		else:
			self.limiteConsulta.mostraJanela('Não encontrado', \
									'Álbum não encontrado')

	def insereAlbum(self):
		self.listaArtistas = self.controlePrincipal.ctrlArtista.listaArtistas
		self.limiteIns = LimiteInsereAlbum(self, self.listaArtistas)

	def insereFaixa(self, event):
		tituloFaixa = self.limiteIns.inputFaixa.get()
		nomeArtista = self.limiteIns.escolhaCombo.get()
		artista = self.controlePrincipal.ctrlArtista.getArtista(nomeArtista)
		faixa = mus.Musica(len(self.listaFaixas) + 1, tituloFaixa, artista)
		self.listaFaixas.append(faixa)
		self.limiteIns.mostraJanela('Sucesso', 'Faixa adicionada')
		self.limiteIns.inputFaixa.delete(0, len(self.limiteIns.inputFaixa.get()))

	def enterHandler(self, event):
		titulo = self.limiteIns.inputTitulo.get()
		nomeArtista = self.limiteIns.escolhaCombo.get()
		artista = self.controlePrincipal.ctrlArtista.getArtista(nomeArtista)
		ano = int(self.limiteIns.inputAno.get())
		album = Album(ano, titulo, artista)

		for faixa in self.listaFaixas:
			album.musicas.append(faixa)

		self.listaAlbuns.append(album)

		self.limiteIns.mostraJanela('Sucesso', 'Album cadastrado')
		self.listaFaixas = []
		self.fechaHandler(event)

	def clearHandler(self, event):
		self.limiteIns.inputTitulo.delete(0, len(self.limiteIns.inputTitulo.get()))
		self.limiteIns.escolhaCombo.set('')
		self.limiteIns.inputAno.delete(0, len(self.limiteIns.inputAno.get()))
		self.limiteIns.inputFaixa.delete(0, len(self.limiteIns.inputFaixa.get()))

	def fechaHandler(self, event):
		self.limiteIns.destroy()
