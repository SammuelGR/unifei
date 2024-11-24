import tkinter as tk
from tkinter import messagebox

from typing import List

from album import Album
from musica import Musica

class Artista:
	def __init__(self, nome: str) -> None:
		self.__nome = nome
		self.__albuns: List[Album] = []
		self.__musicas = List[Musica] = []

	@property
	def nome(self):
		return self.__nome

	@nome.setter
	def nome(self, value):
		self.nome = value

	@property
	def albuns(self):
		return self.__albuns

	@albuns.setter
	def albuns(self, value):
		self.albuns = value

	@property
	def musicas(self):
		return self.__musicas

	@musicas.setter
	def musicas(self, value):
		self.musicas = value

	def addAlbum(self, album: Album):
		self.albuns.append(album)

	def addMusica(self, musica: Musica):
		self.musicas.append(musica)

class CtrlArtista:
	def __init__(self) -> None:
		self.__listaArtistas: List[Artista] = []

	@property
	def listaArtistas(self):
		return self.__listaArtistas

	def insereArtista(self):
		self.limiteIns = LimiteInsereArtista(self)

	def mostraArtistas(self):
		text = 'Nome\n'

		for artista in self.listaArtistas:
			text += artista.nome

		self.limiteLista = LimiteMostraArtistas(text)

	def enterHandler(self, event):
		nome = self.limiteIns.inputNome.get()

		artista = Artista(nome)
		self.listaArtistas.append(artista)

		self.limiteIns.mostraJanela('Sucesso', 'Artista cadastrado com sucesso')
		self.clearHandler(event)

	def clearHandler(self, event):
		self.limiteIns.inputNome.delete(0, len(self.limiteIns.inputNome.get()))

	def fechaHandler(self, event):
		self.limiteIns.destroy()


class LimiteInsereArtista(tk.Toplevel):
	def __init__(self, controle: CtrlArtista):
		tk.Toplevel.__init__(self)
		self.geometry('250x100')
		self.title('Artista')
		self.controle = controle

		self.frameNome = tk.Frame(self)
		self.frameButton = tk.Frame(self)
		self.frameNome.pack()
		self.frameButton.pack()

		self.labelNome = tk.Label(self.frameNome, text='Nome: ')
		self.labelNome.pack(side='left')

		self.inputNome = tk.Entry(self.frameNome, width=20)
		self.inputNome.pack(side='left')

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

class LimiteMostraArtistas:
	def __init__(self, text: str) -> None:
		messagebox.showinfo('Lista de artistas', text)
