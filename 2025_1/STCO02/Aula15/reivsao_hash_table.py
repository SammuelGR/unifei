crypticChars = {
	'4': 'a',
	'@': 'a',
	'3': 'e',
	'1': 'i',
	'!': 'i',
	'0': 'o',
	'5': 's',
	'$': 's',
	'#': 'h',
	'<': 'k',
	'x': 'k',
}

class HashTable:
	def __init__(self, size):
		self.size = size
		self.slots = [[] for _ in range(size)]

	def hash(self, s):
		mult = 0
		hash_value = 0
		for c in s[:3]:
			c = c.lower()

			if c in crypticChars:
				c = crypticChars[c]

			hash_value += (123**mult) * ord(c)
			mult += 1
		return hash_value

	def put(self, key):
		hv = self.hash(key) % self.size
		#supor que todo put é diferente
		self.slots[hv].append((key))

    # lista de valores com as 3 primeiras letras similares
	def get(self, key):
		hv = self.hash(key) % self.size

		results = []

		for k in self.slots[hv]:
			frankstein = key[:3].lower()
			frankstein2 = k[:3].lower()


			for i in range(3):
				f1 = frankstein[i].lower()
				f2 = frankstein2[i].lower()

				if f1 in crypticChars:
					frankstein = frankstein[0:i] + crypticChars[f1] + frankstein[i+1:3]


				if f2 in crypticChars:
					frankstein2 = frankstein2[0:i] + crypticChars[f2] + frankstein2[i+1:3]

			if frankstein == frankstein2:
				results.append(k)

		if len(results) > 0:
			return results
		return None

Table = HashTable(997)

nomes_invocadores = []
with open("invocadores.txt", "r", encoding="utf-8") as arquivo:
    for linha in arquivo:
        nome = linha.strip()  # Remove espaços em branco e quebras de linha
        if nome:  # Garante que não adiciona linhas vazias
            Table.put(nome)

nome_busca = input()

while nome_busca != "-1":
		resultado = Table.get(nome_busca)

		if resultado is None:
			print("Nome não encontrado.")
		else:
			for nome in resultado:
				print(f"Nome encontrado: {nome}")
		nome_busca = input()

"""
'a': ['4', '@'],
'e': ['3'],
'i': ['1', '!'],
'o': ['0'],
's': ['5', '$'],
'h': ['#'],
'k': ['<', 'x'],
"""
