from typing import Literal

class Veiculo:
	def __init__(self, marca: str, cor: str, motorLigado: bool):
		self.__marca = marca
		self.__cor = cor
		self.__motorLigado = motorLigado

	def ligaMotor(self) -> None:
		if self.__motorLigado == True:
			print('O motor já está ligado!')
		else:
			self.__motorLigado = True
			print('O motor acaba de ser ligado!')

	def desligaMotor(self) -> None:
		if self.__motorLigado == False:
			print('O motor já está desligado!')
		else:
			self.__motorLigado = False
			print('O motor acaba de ser desligado!')

	def mostraAtributos(self) -> None:
		print(f'da marca {self.__marca}, cor {self.__cor} e seu motor esta {"ligado" if self.__motorLigado else "desligado"}')

class Carro(Veiculo):
	def __init__(self, marca: str, cor: str, motorLigado: bool, portaMalasCheio):
		super().__init__(marca, cor, motorLigado)
		self.__portaMalasCheio = portaMalasCheio

	def mostraAtributos(self) -> None:
		print(f'Um carro com porta-malas {"cheio" if self.__portaMalasCheio else "vazio"}', end = ' ')
		super().mostraAtributos()

	def enchePortaMalas(self) -> None:
		if self.__portaMalasCheio == True:
			print('O porta-malas já está cheio!')
		else:
			self.__portaMalasCheio = True
			print('O porta-malas acaba de ser enchido!')

	def esvaziaPortaMalas(self) -> None:
		if self.__portaMalasCheio == False:
			print('O porta-malas já está vazio!')
		else:
			self.__portaMalasCheio = False
			print('O porta-malas acaba de ser esvaziado!')


class Motocicleta(Veiculo):
	def __init__(self, marca: str, cor: str, motorLigado: bool, estilo: Literal['trail', 'naked', 'custom']):
		super().__init__(marca, cor, motorLigado)
		self.__estilo = estilo

	def mostraAtributos(self) -> None:
		print(f'Uma moto de estilo {self.__estilo}', end = ' ')
		super().mostraAtributos()

lanceta = Carro('Mitsubishi', 'Cinza', False, False)
motoka = Motocicleta('Honda', 'Vermelha', False, 'naked')

motoka.ligaMotor()
motoka.mostraAtributos()
print()

lanceta.enchePortaMalas()
lanceta.ligaMotor()
lanceta.mostraAtributos()
