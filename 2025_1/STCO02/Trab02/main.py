import csv

def getCreatures(fileName: str):
	creatures = []

	with open(fileName, newline='', encoding='utf-8') as csvFile:
		buffer = csv.reader(csvFile)
		_ = next(buffer) # ignore header

		for line in buffer:
			name = line[0]

			ratings = []
			for i in range(1, 7):
				ratings.append(float(line[i]))


			creatures.append((name, *ratings))
	return creatures

if __name__ == '__main__':
	fileName = input()
	usersQty = int(input())

	ratings = []
	for _ in range(0, usersQty):
		currentRatings = input().strip().split(' ')

		for i in range(0, 6):
			currentRatings[i] = int(currentRatings[i])

		ratings.append(currentRatings)

	creatures = getCreatures(fileName)

	for userRating in ratings[1:2]: # TODO: remove limit
		for i in range(0, len(creatures)):
			total = 0
			for j in range(0, 6):
				total += userRating[j] * creatures[i][j + 1]

			newCreature = (*creatures[i], total)
			creatures[i] = newCreature


	print(creatures)

