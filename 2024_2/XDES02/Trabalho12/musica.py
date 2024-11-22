class Musica:
	def __init__(self, nroFaixa: int, titulo: str) -> None:
		self.__nroFaixa = nroFaixa
		self.__titulo = titulo

	@property
	def nroFaixa(self):
		return self.__nroFaixa

	@nroFaixa.setter
	def nroFaixa(self, value):
		self.nroFaixa = value

	@property
	def titulo(self):
		return self.__titulo

	@titulo.setter
	def titulo(self, value):
		self.titulo = value
