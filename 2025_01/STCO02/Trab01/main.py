from typing import Optional, Tuple

class Node:
	def __init__(self, key: Optional[str] = None):
		self.key: Optional[str] = key
		self.leftNode: Optional[Node] = None
		self.rightNode: Optional[Node] = None

	def insert(self, key: str):
		if not self.key:
			self.key = key
			return

		if key < self.key:
			if self.leftNode:
				self.leftNode.insert(key)
				return

			self.leftNode = Node(key)
			return

		if self.rightNode:
			self.rightNode.insert(key)
			return

		self.rightNode = Node(key)
	
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
	
	def put(self, key: str):
		hashValue = self.getHash(key)

		self.slots[hashValue].insert(key)

	def listAll(self):
		for slot in self.slots:
			if slot.key is not None:
				print(slot.preorder())


table = HashTable()
table.put('Máquina de maionese')
table.put('Elixir da vida')
table.put('Sementes Silvestres (Ver)')
table.put('Piso Rústico de Tábuas')

table.listAll()
