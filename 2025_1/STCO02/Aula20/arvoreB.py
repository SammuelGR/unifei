from typing import List

class Node:
	def __init__(self):
		self.n = 0
		self.leaf: bool = True
		self.keys: List[int] = []
		self.children: List[Node] = []

def searchNode(tree: Node, value: int):
	if tree == None:
		return None

	i = 0
	while i < tree.n and value > tree.keys[i] and value != tree.keys[i]:
		i += 1

	if i < tree.n and value == tree.keys[i]:
		return tree.keys[i]
	if tree.leaf is True:
		return None

	return searchNode(tree.children[i], value)

tree = Node()
tree.keys = [100, 200]
tree.n = 2
tree.leaf = False
tree.children = [Node(), Node(), Node()]

tree.children[0].keys = [50, 75]
tree.children[0].n = 2
tree.children[0].leaf = True

tree.children[1].keys = [150, 175, 180]
tree.children[1].n = 3
tree.children[1].leaf = True

tree.children[2].keys = [250, 275]
tree.children[2].n = 2
tree.children[2].leaf = True

value = searchNode(tree, 175)
if value == None:
	print('Não encontrou 175')
else:
	print('Encontrou 175')

value = searchNode(tree, 150)
if value == None:
	print('Não encontrou 150')
else:
	print('Encontrou 150')

value = searchNode(tree, 900)
if value == None:
	print('Não encontrou 900')
else:
	print('Encontrou 900')

value = searchNode(tree, 100)
if value == None:
	print('Não encontrou 100')
else:
	print('Encontrou 100')

value = searchNode(tree, 18)
if value == None:
	print('Não encontrou 18')
else:
	print('Encontrou 18')