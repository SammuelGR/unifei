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
				print(str(slot.preorder()).replace("'", ''))
			else:
				print('None')

	def __setitem__ (self, key, values):
		self.put(key, values)

	def __getitem__ (self, key):
		return self.get(key)

def getRecipes():
	recipes = HashTable()
	item_uses = HashTable()

	with open('craft.txt', 'r', encoding='utf-8') as f:
		is_key = True
		current_recipe_key = ''

		for line in f:
			text = line.strip()

			if text == '':
				is_key = True
			else:
				if is_key is True:
					current_recipe_key = text
					is_key = False
					recipes[current_recipe_key] = []
				else:
					buffer = text.split(' ')
					item = ''
					quantity = int(buffer[-1])

					for c in buffer[:-1]:
						item += c + ' '

					item = item.strip()

					recipes[current_recipe_key].append((item, quantity))

					isAlreadyUsing = item_uses.get(item)

					if isAlreadyUsing is None:
						item_uses[item] = []

					item_uses[item].append(current_recipe_key)

	return recipes, item_uses


if __name__ == "__main__":
	recipes, item_uses = getRecipes()

	while True:
		cmd_title, cmd_value = (input().split(' ', 1) + [None])[:2]

		if cmd_title == 'q':
			break
		if cmd_title == 'p':
			if cmd_value == 'r':
				recipes.listAll()
			elif cmd_value == 'i':
				item_uses.listAll()
		elif cmd_title == 'r':
			print(cmd_value)

			item_recipes = recipes.get(cmd_value)

			if item_recipes is not None:
				for recipe in item_recipes:
					print(recipe[0], recipe[1])
			else:
				print('Não encontrado')
		elif cmd_title == 'i':
			print(cmd_value)

			hasUse = item_uses.get(cmd_value)

			if hasUse is not None:
				for item in item_uses[cmd_value]:
					print(item)
			else:
				print('Não encontrado')
