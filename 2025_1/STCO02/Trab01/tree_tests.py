class Node:
	def __init__(self, content: int):
		self.content = content
		self.left_node: Node | None = None
		self.right_node: Node | None = None


def insert_tree(node: Node, value: int) -> Node:
	if node == None:
		return Node(value)

	if node.content > value:
		node.left_node = insert_tree(node.left_node, value)

	else:
		node.right_node = insert_tree(node.right_node, value)

	return node

def erd(node: Node):
	if (node != None):
		erd(node.left_node)
		print(node.content)
		erd(node.right_node)

numbers_list = [3, 8, 15, 2, 14, 3, 7, 9]

root = Node(numbers_list[0])

for item in numbers_list[1:]:
	insert_tree(root, item)

erd(root)
