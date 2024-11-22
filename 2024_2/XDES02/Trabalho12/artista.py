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
