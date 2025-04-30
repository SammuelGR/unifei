import csv

def parse_percent(value):
	return float(value.strip('%'))

def parse_float(value):
	return float(value)

def carregar_dados_csv(caminho_arquivo):
	dados = []
	with open(caminho_arquivo, newline='', encoding='utf-8') as csvfile:
		leitor = csv.reader(csvfile)
		_ = next(leitor)

		for linha in leitor:
			nome = linha[0]
			roles = [r.strip() for r in linha[1].split(',')]
			pickrate = parse_percent(linha[2])
			winrate = parse_percent(linha[3])
			banrate = parse_percent(linha[4])
			kills = parse_float(linha[5])
			deaths = parse_float(linha[6])
			assists = parse_float(linha[7])
			pentakills = parse_float(linha[8])

			dados.append([nome, roles, pickrate, winrate, banrate, kills, deaths, assists, pentakills])
	return dados

def countingSortByDigit(list, d):
	sortedList = [None for _ in range(0, len(list))]
	auxList = [0 for _ in range(0, 10)]

	for a in list:
		index = 9 - (a[9] // 10**d) % 10
		auxList[index] += 1

	for i in range(1, 10):
		auxList[i] += auxList[i-1]

	for i in range(len(list) - 1, -1, -1):
		a = list[i]
		index = 9 - (a[9] // 10**d) % 10
		sortedList[auxList[index] - 1] = a
		auxList[index] -= 1

	return sortedList

def radixSort(champsList):
	for digit in range(0, 4):
		champsList = countingSortByDigit(champsList, digit)

	return champsList

if __name__ == "__main__":
	dados = carregar_dados_csv('champs.csv')

	for linha in dados:
		kda = int(round((linha[5] + linha[7]) / linha[6], 3)*1000)
		linha.append(kda)

	dados = radixSort(dados)

	for linha in dados:
		print(linha[0])
