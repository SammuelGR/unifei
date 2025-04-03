class HashItem:
	def __init__(self, key, value):
		self.key = key
		self.value = value

class HashTable:
	def __init__(self, size):
		self.size = size
		self.slots = [None for _ in range(size)]
		self.count = 0

	def hash2(self, text):
		multiplier = 1
		hash_value = 0

		for c in text:
			hash_value += multiplier * ord(c)
			multiplier += 1

		return hash_value

	def growth(self):
		new_table = HashTable(self.size * 2)

		for i in range(self.size):
			if self.slots[i] != None:
				new_table.put(self.slots[i].key, self.slots[i].value)

		self.size = self.size * 2
		self.slots = new_table.slots

	def check_growth(self):
		load_factor = self.count / self.size

		if load_factor >= 0.65:
			print('increasing table size')
			self.growth()

	def put(self, key, value):
		hi = HashItem(key, value)
		hv = self.hash2(key) % self.size

		# TODO: breaks if table is full
		while self.slots[hv] != None:
			hv = (hv + 1) % self.size
			# TODO: check if already exists

		self.slots[hv] = hi
		self.count += 1
		self.check_growth()

	def get(self, key):
		hv = self.hash2(key) % self.size

		while self.slots[hv] != None:
			if self.slots[hv].key == key:
				return self.slots[hv].value

			hv = (hv + 1) % self.size

		return None

Table = HashTable(11)

Table.put('hokama', 'c1130')
Table.put('a', 'aaaaa')
Table.put('b', 'bbbbb')
Table.put('ga1', 'ga1')
Table.put('ga2', 'ga2')
Table.put('ga3', 'ga3')
Table.put('ga4', 'ga4')
Table.put('ga5', 'ga5')
Table.put('ga6', 'ga6')
Table.put('ga7', 'ga7')
Table.put('ga8', 'ga8')
Table.put('ga9', 'ga9')
Table.put('ga10', 'ga10')
Table.put('ga11', 'ga11')
Table.put('ga12', 'ga12')
Table.put('ga13', 'ga13')
Table.put('ga14', 'ga14')
Table.put('ga15', 'ga15')
Table.put('ga16', 'ga16')
Table.put('ga17', 'ga17')

print(Table.get('hokama'))
print(Table.get('a'))
print(Table.get('b'))
print(Table.get('c'))
