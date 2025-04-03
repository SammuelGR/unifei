class HashTable:
	def __init__(self, size):
		self.size = size
		self.slots = [[] for _ in range(size)]

	def hash(self, text):
		multiplier = 1
		hash_value = 0

		for c in text:
			hash_value += multiplier * ord(c)
			multiplier += 1

		return hash_value

	def put(self, key, value):
		hv = self.hash(key) % self.size
		# suppose every put is different

		self.slots[hv].append((key, value))

	def get(self, key):
		hv = self.hash(key) % self.size

		for (k, v) in self.slots[hv]:
			if key == k:
				return v

		return None

	def __setitem__ (self, key, value):
		self.put(key, value)

	def __getitem__ (self, key):
		return self.get(key)


Table = HashTable(11)

Table.put('hokama', 'c1130')
print(Table.get('hokama'))

Table['ferreira'] = 2024001234
print(Table['ferreira'])

Table['ga'] = 1
Table['ad'] = 2

print(Table['ga'])
print(Table['ad'])
