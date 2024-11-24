from typing import List, TYPE_CHECKING


if TYPE_CHECKING:
	from artista import Artista
	from musica import Musica


class Album:
	def __init__(self, ano: int, titulo: str, artista: Artista) -> None:
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
