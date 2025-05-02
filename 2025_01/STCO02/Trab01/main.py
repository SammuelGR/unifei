from typing import List, Optional, Tuple

class Node:
	def __init__(self, key: Optional[str] = None, values: Optional[List[Tuple[str]]] = None):
		self.key: Optional[str] = key
		self.values: Optional[List[Tuple[str]]] = values
		self.leftNode: Optional[Node] = None
		self.rightNode: Optional[Node] = None
	
	def find(self, key: str):
		if self.key is None:
			return None

		if key == self.key:
			return self.values
		
		if key < self.key:
			if self.leftNode is None:
				return None
			return self.leftNode.find(key)
		
		if self.rightNode is None:
			return None
		
		return self.rightNode.find(key)

	def insert(self, key: str, values: List[Tuple[str]]):
		if not self.key:
			self.key = key
			self.values = values
			return

		if key < self.key:
			if self.leftNode:
				self.leftNode.insert(key, values)
				return

			self.leftNode = Node(key, values)
			return

		if self.rightNode:
			self.rightNode.insert(key, values)
			return

		self.rightNode = Node(key, values)
	
	def preorder(self):
		return (self.key, \
			self.leftNode.preorder() if self.leftNode is not None else None, \
			self.rightNode.preorder() if self.rightNode is not None else None)

class HashTable:
	def __init__(self):
		self.size = 29
		self.slots = [Node() for _ in range(self.size)]

	def getHash(self, text: str):
		mult = 1
		hashValue = 0

		for c in text:
			hashValue += mult * ord(c)
			mult += 1

		return hashValue % self.size
	
	def put(self, key: str, values: List[Tuple[str]]):
		hashValue = self.getHash(key)

		self.slots[hashValue].insert(key, values)
	
	def get(self, key: str):
		hashValue = self.getHash(key)

		return self.slots[hashValue].find(key)
		
	def listAll(self):
		for slot in self.slots:
			if slot.key is not None:
				print(slot.preorder())

	def __setitem__ (self, key, values):
		self.put(key, values)

	def __getitem__ (self, key):
		return self.get(key)


table = HashTable()
table['Máquina de maionese'] = [('Madeira', '15'), ('Pedra', '15'), ('Cristal de terra', '1'), ('Barra de cobre', '1')]
table['Elixir da vida'] = [('Cogumelo vermelho', '1'), ('Cogumelo roxo', '1'), ('Morel', '1'), ('Cantarelo', '1')]
table['Sementes Silvestres (Ver)'] = [('Café de jardim', '1')]
table['Piso Rústico de Tábuas'] = [('Madeira', '1')]
table['Jarra de conserva'] = [('Madeira', '50'), ('Pedra', '40'), ('Carvão', '8')]

# table.listAll()

print(table['Máquina de maionese'])
print(table['Elixir da vida'])
print(table['Sementes Silvestres (Ver)'])
print(table['Piso Rústico de Tábuas'])
print(table['Jarra de conserva'])
print(table['AAAAAAAAAAAAAA'])

