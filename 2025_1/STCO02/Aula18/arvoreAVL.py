class Node:
	def __init__(self, data: int):
		self.data = data
		self.left: Node | None = None
		self.right: Node | None = None
		self.height: int = 0

def getHeight(node: Node):
	if node == None:
		return -1

	return node.height

def rotateRight(y: Node):
	x = y.left
	y.left = x.right
	x.right = y

	y.height = max(getHeight(y.left), getHeight(y.right)) + 1
	x.height = max(getHeight(x.left), getHeight(x.right)) + 1

	return x

def rotateLeft(y: Node):
	x = y.right
	y.right = x.left
	x.left = y

	y.height = max(getHeight(y.left), getHeight(y.right)) + 1
	x.height = max(getHeight(x.left), getHeight(x.right)) + 1

	return x

def getBalanceFactor(node: Node):
	return getHeight(node.left) - getHeight(node.right)

def insertNode(node: Node, data: int):
	if node == None:
		return Node(data)

	if data < node.data:
		node.left = insertNode(node.left, data)

		# check if balance is compromised to the left
		if getBalanceFactor(node) == 2:
			if data > node.left.data: # inserted on the right of the left
				node.left = rotateLeft(node.left)

			node = rotateRight(node)

	elif data > node.data:
		node.right = insertNode(node.right, data)

		if getBalanceFactor(node) == -2:
			if data < node.right.data: # inserted on the left of the right
				node.right = rotateRight(node.right)

			node = rotateLeft(node)
	else:
		print('duplicated data')
		return node

	node.height = max(getHeight(node.left), getHeight(node.right)) + 1

	return node