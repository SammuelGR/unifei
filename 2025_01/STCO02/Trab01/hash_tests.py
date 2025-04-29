def get_recipes():
	recipes = {}
	item_uses = {}

	with open('craft.txt', 'r') as f:
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

					if item not in item_uses:
						item_uses[item] = []

					item_uses[item].append(current_recipe_key)

	return recipes, item_uses

if __name__ == "__main__":
	recipes, item_uses = get_recipes()

	while True:
		cmd_title, cmd_value = (input().split(' ', 1) + [None])[:2]

		if cmd_title == 'q':
			break
		if cmd_title == 'p':
			if cmd_value == 'r':
				for name in recipes.keys():
					print(name)
			elif cmd_value == 'i':
				for name in item_uses.keys():
					print(name)
		elif cmd_title == 'r':
			if cmd_value in recipes:
				print(cmd_value)

				for recipe in recipes[cmd_value]:
					print(recipe)
			else:
				print('Não encontrado')
		elif cmd_title == 'i':
			if cmd_value in item_uses:
				print(cmd_value)

				for item in item_uses[cmd_value]:
					print(item)
			else:
				print('Não encontrado')

		# r Jarra de conserva // repetir nome e imprimir receita
		# p r // imprimir todos os nomes de receitas
		# p i // imprimir todos os nomes de itens
		# i Essência nula // repetir e imprimir onde o item eh usado
		# q // quit
