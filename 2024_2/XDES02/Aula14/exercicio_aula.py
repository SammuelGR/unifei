class UsernameDuplicado(Exception):
	pass

class IdadeMenorQuePermitida(Exception):
	pass

class IdadeInvalida(Exception):
	pass

class EmailInvalido(Exception):
	pass

class User:
	def __init__(self, username: str, email: str):
		self.__username = username
		self.__email = email

	def getUsername(self):
		return self.__username

	def getEmail(self):
		return self.__email

if __name__ == "__main__":
	listaExemplo = [
		("paulo", "paulo@gmail.com", 21),
		("maria", "maria@gmail.com", 19),
		("antonio", "antonio@gmail.com", 25),
		("pedro", "pedro@gmail.com", 15),
		("marisa", "marisa@", 23),
		("ana", "ana@gmail.com", -22),
		("maria", "maria2@gmail.com", 27)
	]

	cadastro = {}

	for username, email, idade in listaExemplo:
		try:
			if username in cadastro:
				raise UsernameDuplicado()
			if idade < 0:
				raise IdadeInvalida()
			if idade < 18:
				raise IdadeMenorQuePermitida()

			emailPartes = email.split('@')
			if len(emailPartes) != 2 or not emailPartes[0] or not emailPartes[1]:
				raise EmailInvalido()
		except UsernameDuplicado:
			print(f'Username "{username}" já está em uso')
		except IdadeInvalida:
			print(f'Idade inválida: {idade}')
		except IdadeMenorQuePermitida:
			print(f'Usuário "{username}" tem idade inferior à permitida')
		except EmailInvalido:
			print(f'"{email}" não é um endereço de email válido')
		else:
			cadastro[username] = User(username, email)
