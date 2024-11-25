from __future__ import annotations
import tkinter as tk

from artista import CtrlArtista
from album import CtrlAlbum
from playlist import CtrlPlaylist

class ControlePrincipal():
	def __init__(self):
		self.root = tk.Tk()

		self.ctrlArtista = CtrlArtista()
		self.ctrlAlbum = CtrlAlbum(self)
		self.ctrlPlaylist = CtrlPlaylist(self)

		self.limite = LimitePrincipal(self.root, self)

		self.root.title('Player de música MVC')
		self.root.mainloop()

	def insereArtista(self):
		self.ctrlArtista.insereArtista()

	def consultaArtista(self):
		self.ctrlArtista.mostraArtista()

	def insereAlbum(self):
		self.ctrlAlbum.insereAlbum()

	def consultaAlbum(self):
		self.ctrlAlbum.consultaAlbum()

	def inserePlaylist(self):
		self.ctrlPlaylist.inserePlaylist()

	def consultaPlaylist(self):
		print(self.ctrlPlaylist.listaPlaylists)
		# TODO: remove

	def sair(self):
		self.root.destroy()

class LimitePrincipal():
	def __init__(self, root: tk.Tk, controle: ControlePrincipal):
		self.controle = controle

		self.root = root
		self.root.geometry('300x300')

		self.menubar = tk.Menu(self.root)
		self.artistaMenu = tk.Menu(self.menubar)
		self.albumMenu = tk.Menu(self.menubar)
		self.playlistMenu = tk.Menu(self.menubar)
		self.sairMenu = tk.Menu(self.menubar)

		self.artistaMenu.add_command(label='Cadastrar', \
							   command=self.controle.insereArtista)
		self.artistaMenu.add_command(label='Consultar', \
							   command=self.controle.consultaArtista)
		self.menubar.add_cascade(label='Artista', \
						   menu=self.artistaMenu)

		self.albumMenu.add_command(label='Cadastrar', \
							 command=self.controle.insereAlbum)
		self.albumMenu.add_command(label='Consultar', \
							 command=self.controle.consultaAlbum)
		self.menubar.add_cascade(label='Album', menu=self.albumMenu)

		self.playlistMenu.add_command(label='Cadastrar', \
								command=self.controle.inserePlaylist)
		self.playlistMenu.add_command(label='Consultar', \
								command=self.controle.consultaPlaylist)
		self.menubar.add_cascade(label='Playlist', menu=self.playlistMenu)

		self.sairMenu.add_command(label='Sair', command=self.controle.sair)
		self.menubar.add_cascade(label='Sair', menu=self.sairMenu)

		self.root.config(menu=self.menubar)

if __name__ == '__main__':
	c = ControlePrincipal()
