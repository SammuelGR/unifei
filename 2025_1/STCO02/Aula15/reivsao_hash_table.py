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

		searchStr = key[:3].lower()
		results = []

		for k in self.slots[hv]:
			slot = k[:3].lower()

			for i in range(3):
				searchChar = searchStr[i].lower()
				slotChar = slot[i].lower()

				if searchChar in crypticChars:
					searchStr = searchStr[0:i] + crypticChars[searchChar] + searchStr[i+1:3]

				if slotChar in crypticChars:
					slot = slot[0:i] + crypticChars[slotChar] + slot[i+1:3]

			if searchStr == slot:
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
