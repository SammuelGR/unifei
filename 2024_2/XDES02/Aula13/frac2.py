def mdc(m, n):
	while m%n != 0:
		oldm = m
		oldn = n
		m = oldn
		n = oldm%oldn
	return n

def mesmaFracao(f1, f2):
	return (f1.num == f2.num) and (f1.den == f2.den)


class Fracao():
	def __init__(self, num, den):
		self.__num = num
		self.__den = den

	def __str__(self):
		return str(self.__num) + "/" + str(self.__den)

	@property
	def num(self):
		return self.__num

	@property
	def den(self):
		return self.__den

	def simplifica(self):
		divComum = mdc(self.__num, self.__den)
		self.__num = self.__num // divComum
		self.__den = self.__den // divComum

	def __add__(self,outraFrac):
		novoNum = self.__num * outraFrac.den + self.__den * outraFrac.num
		novoDen = self.__den * outraFrac.den
		divComum = mdc(novoNum, novoDen)
		return Fracao(novoNum//divComum, novoDen//divComum)

class FracaoMista(Fracao):
	def __init__(self, num, den, inteira):
		super().__init__(num, den)
		self.__inteira = inteira

	def __str__(self):
		return str(self.__inteira) + " " + str(self.num) + "/" + str(self.den)

	@property
	def inteira(self):
		return self.__inteira

	def __add__(self, outraFrac):
		parcial = super().__add__(outraFrac)
		intParc = 0

		if parcial.num > parcial.den:
			intParc = parcial.den % parcial.num

		return FracaoMista(parcial.num, parcial.den, intParc)

if __name__ == "__main__":
	frac1 = Fracao (1, 4)
	frac2 = Fracao(1, 6)
	frac3 = frac1 + frac2
	print(frac3)
	print()
	frac1 = Fracao (3, 4)
	frac2 = Fracao(5, 6)
	frac3 = frac1 + frac2
	print(frac3)
	print()

	fracMist1 = FracaoMista(7, 6, 0)
	fracMist2 = FracaoMista(13, 7, 0)
	fracMist3 = fracMist1 + fracMist2
	#  7/6 + 13/7 = 3 1/42
	print(fracMist3)

	fracMist4 = FracaoMista(1, 3, 0)
	fracMist5 = FracaoMista(2, 3, 0)
	fracMist6 = fracMist4 + fracMist5
	#  1/3 + 2/3 = 1
	print(fracMist6)

	fracMist7 = FracaoMista(1, 2, 3)
	fracMist8 = FracaoMista(2, 3, 4)
	fracMist9 = fracMist7 + fracMist8
	#  3 1/2 + 4 2/3 = 8 1/6
	print(fracMist9)
