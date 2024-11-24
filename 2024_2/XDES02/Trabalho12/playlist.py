from typing import List, TYPE_CHECKING

if TYPE_CHECKING:
	from musica import Musica

class Playlist:
	def __init__(self, nome: str) -> None:
		self.__nome = nome
		self.__musicas: List[Musica] = []

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
