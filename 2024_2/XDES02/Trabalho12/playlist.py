from typing import List, TYPE_CHECKING

import tkinter as tk
from tkinter import ttk, messagebox, simpledialog

if TYPE_CHECKING:
	from musica import Musica
	from artista import Artista

class Playlist:
	def __init__(self, nome: str) -> None:
		self.__nome = nome
		self.__musicas: List['Musica'] = []

	@property
	def nome(self):
		return self.__nome

	@nome.setter
	def nome(self, value):
		self.nome = value

	@property
	def musicas(self):
		return self.__musicas

	@musicas.setter
	def musicas(self, value):
		self.musicas = value

class CtrlPlaylist:
	def __init__(self, controlePrincipal) -> None:
		self.controlePrincipal = controlePrincipal
		self.__listaPlaylists: List[Playlist] = []
		self.__listaArtistas: List['Artista'] = []
		self.__listaMusicas: List['Musica'] = []
		self.__listaMusicasAdicionadas: List['Musica'] = []

	@property
	def listaPlaylists(self):
		return self.__listaPlaylists

	@property
	def listaArtistas(self):
		return self.__listaArtistas

	@listaArtistas.setter
	def listaArtistas(self, value):
		self.__listaArtistas = value

	@property
	def listaMusicas(self):
		return self.__listaMusicas

	@property
	def listaMusicasAdicionadas(self):
		return self.__listaMusicasAdicionadas

	def inserePlaylist(self):
		self.listaArtistas = self.controlePrincipal.ctrlArtista.listaArtistas
		self.limiteIns = LimiteInserePlaylist(self, self.listaArtistas, self.listaMusicas)

	def insereMusica(self, event):
		musicaSel = self.limiteIns.listbox.get(tk.ACTIVE)
		self.listaMusicasAdicionadas.append(musicaSel)
		self.limiteIns.mostraJanela('Sucesso', 'Música adicionada')
		self.limiteIns.listbox.delete(tk.ACTIVE)

	def enterHandler(self, event):
		nome = self.limiteIns.inputNome.get()

		playlist = Playlist(nome)
		for musica in self.listaMusicasAdicionadas:
			playlist.musicas.append(musica)

		self.listaPlaylists.append(playlist)

		self.limiteIns.mostraJanela('Sucesso', 'Playlist criada')
		self.clearHandler(event)

	def clearHandler(self, event):
		self.limiteIns.inputNome.delete(0, len(self.limiteIns.inputNome.get()))
		self.limiteIns.escolhaCombo.set('')
		self.limiteIns.listbox.delete(0, tk.END)

	def fechaHandler(self, event):
		self.limiteIns.destroy()

class LimiteInserePlaylist(tk.Toplevel):
	def __init__(self, controle: CtrlPlaylist, listaArtistas: List['Artista'], listaMusicas: List['Musica']):
		tk.Toplevel.__init__(self)
		self.geometry('300x300')
		self.title('Playlist')
		self.controle = controle

		self.frameNome = tk.Frame(self)
		self.frameArtista = tk.Frame(self)
		self.frameMusicas = tk.Frame(self)
		self.frameButton = tk.Frame(self)
		self.frameNome.pack()
		self.frameArtista.pack()
		self.frameMusicas.pack()
		self.frameButton.pack()

		self.labelNome = tk.Label(self.frameNome, text='Nome: ')
		self.labelNome.pack(side='left')
		self.inputNome = tk.Entry(self.frameNome, width=20)
		self.inputNome.pack(side='left')

		self.labelArtista = tk.Label(self.frameArtista, text='Artista: ')
		self.labelArtista.pack(side='left')
		self.escolhaCombo = tk.StringVar()
		self.combobox = ttk.Combobox(self.frameArtista, width=15, textvariable=self.escolhaCombo)
		self.combobox.pack(side='left')
		self.combobox['values'] = [artista.nome for artista in listaArtistas]

		self.labelMusicas = tk.Label(self.frameMusicas, text='Escolha as músicas: ')
		self.labelMusicas.pack(side='left')
		self.listbox = tk.Listbox(self.frameMusicas)
		self.listbox.pack(side='left')
		for musica in listaMusicas:
			self.listbox.insert(tk.END, musica.titulo)

		self.atualizaMusicas(self.combobox.get(), listaArtistas)

		self.combobox.bind('<<ComboboxSelected>>', self.onArtistaSelecionado)

		self.buttonInsereMusica = tk.Button(self.frameButton, text='Adicionar música')
		self.buttonInsereMusica.pack(side='left')
		self.buttonInsereMusica.bind('<Button>', controle.insereMusica)

		self.buttonSubmit = tk.Button(self.frameButton, text='Criar playlist')
		self.buttonSubmit.pack(side='left')
		self.buttonSubmit.bind('<Button>', controle.enterHandler)

		self.buttonClear = tk.Button(self.frameButton, text='Limpar')
		self.buttonClear.pack(side='left')
		self.buttonClear.bind('<Button>', controle.clearHandler)

		self.buttonFecha = tk.Button(self.frameButton, text='Concluído')
		self.buttonFecha.pack(side='left')
		self.buttonFecha.bind('<Button>', self.controle.fechaHandler)

	def atualizaMusicas(self, nomeArtista: str, listaArtistas: List['Artista']):
		self.listbox.delete(0, tk.END)

		for artista in listaArtistas:
			if artista.nome == nomeArtista:
				for musica in artista.musicas:
					self.listbox.insert(tk.END, musica.titulo)
				return

	def onArtistaSelecionado(self, event):
		nomeArtista = self.escolhaCombo.get()
		self.atualizaMusicas(nomeArtista, self.controle.listaArtistas)

	def mostraJanela(self, titulo: str, msg: str):
		messagebox.showinfo(titulo, msg)
