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

	def put_quad(self, key, value):
		hi = HashItem(key, value)
		hv = self.hash2(key) % self.size
		pos = hv

		i = 1

		# TODO: breaks if table is full
		while self.slots[pos] != None:
			pos = (hv + (i * i)) % self.size
			# TODO: check if already exists

			i += 1

		self.slots[pos] = hi
		self.count += 1
		self.check_growth()

	def get_quad(self, key):
		hv = self.hash2(key) % self.size
		pos = hv

		i = 1

		while self.slots[pos] != None:
			if self.slots[pos].key == key:
				return self.slots[pos].value

			pos = (hv + (i * i)) % self.size
			i += 1

		return None

	def double_hash(self, key):
		num = self.hash2(key)

		return  5 - (num % 5) # 5 is prime > size

	def put_double_hash(self, key, value):
		hi = HashItem(key, value)
		hv = self.hash2(key) % self.size
		pos = hv

		i = 1

		# TODO: breaks if table is full
		while self.slots[pos] != None:
			pos = (hv + i * self.double_hash(key)) % self.size
			# TODO: check if already exists

			i += 1

		self.slots[pos] = hi
		self.count += 1
		self.check_growth()

	def get_double_hash(self, key):
		hv = self.hash2(key) % self.size
		pos = hv

		i = 1

		while self.slots[pos] != None:
			if self.slots[pos].key == key:
				return self.slots[pos].value

			pos = (hv + i * self.double_hash(key)) % self.size
			i += 1

		return None

	def __setitem__ (self, key, value):
		self.put_double_hash(key, value)

	def __getitem__ (self, key):
		return self.get_double_hash(key)

Table = HashTable(11)

Table.put('hokama', 'c1130')
print(Table.get('hokama'))

Table['ferreira'] = 2024001234
print(Table['ferreira'])

Table['ga'] = 1
Table['ad'] = 2

print(Table['ga'])
print(Table['ad'])

# sondagem linear
# hv = hv + 1

# sondagem quadratica
# hv = hv i^2 mod size

# double hashing
# hash2 = prime 9 (key % prime)
# prime < size
# hv = hv + i * hash2 (key) % size
