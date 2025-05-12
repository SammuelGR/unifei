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

	creatures = getCreatures(fileName)
	creaturesSize = len(creatures)

	ratings = []
	for _ in range(0, usersQty):
		currentRatings = input().strip().split(' ')

		for i in range(0, 6):
			currentRatings[i] = int(currentRatings[i])

		ratings.append(currentRatings)

	for userRating in ratings:
		for i in range(0, creaturesSize):
			total = 0
			for j in range(0, 6):
				total += userRating[j] * creatures[i][j + 1]

			prevPoints = creatures[i][8] if len(creatures[i]) >= 9 else 0
			creatures[i] = (*creatures[i][0:7], total, prevPoints)

		for i in range(0, creaturesSize - 1):
			for j in range(i + 1, creaturesSize):
				if creatures[i][7] < creatures[j][7]:
					creatures[i], creatures[j] = creatures[j], creatures[i]
				elif creatures[i][7] == creatures[j][7]:
					if creatures[i][0] > creatures[j][0]:
						creatures[i], creatures[j] = creatures[j], creatures[i]

		for i in range(0, creaturesSize):
			prevPoints = creatures[i][8]
			creatures[i] = (*creatures[i][0:8], prevPoints + (creaturesSize - i) - 1)

	for i in range(0, creaturesSize - 1):
		for j in range(i + 1, creaturesSize):
			if creatures[i][8] < creatures[j][8]:
				creatures[i], creatures[j] = creatures[j], creatures[i]

	for creature in creatures:
		print(f'{creature[0]} {creature[8]}')


# 0 ~ 10 initial rating
# max 46 users
# max 1000 creatures
# -20 ~ 20 single rating
# max ~ 1200 by user
