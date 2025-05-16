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


def sortByName(creatures):
	maxLen = 0

	for i in range(len(creatures)):
		nameLen = len(creatures[i][0])
		if nameLen > maxLen:
			maxLen = nameLen

	for pos in range(maxLen - 1, -1, -1):
		buckets = [[] for _ in range(256)] 

		for i in range(len(creatures)):
			name = creatures[i][0]
			code = ord(name[pos]) if pos < len(name) else 0
			buckets[code].append(creatures[i])

		idx = 0
		for b in buckets:
			for c in b:
				creatures[idx] = c
				idx += 1

	return creatures

def parsePoints(points: float):
	return int(points * 1000)

def sortByUserRating(creatures, creaturesSize, scoreIdx):
	minScore = maxScore = parsePoints(creatures[0][scoreIdx])
	for i in range(1, creaturesSize):
		currScore = parsePoints(creatures[i][scoreIdx])
		if currScore < minScore:
			minScore = currScore
		if currScore > maxScore:
			maxScore = currScore

	rangeSize = maxScore - minScore + 1
	C = [0 for _ in range(rangeSize)]

	for i in range(creaturesSize):
		idx = maxScore - parsePoints(creatures[i][scoreIdx])
		C[idx] += 1

	for i in range(1, rangeSize):
		C[i] += C[i - 1]

	sortedCreatures = [None for _ in range(creaturesSize)]

	for i in range(creaturesSize - 1, -1, -1):
		idx = maxScore - parsePoints(creatures[i][scoreIdx])
		sortedCreatures[C[idx] - 1] = creatures[i]
		C[idx] -= 1

	return sortedCreatures


if __name__ == '__main__':
	fileName = input()
	usersQty = int(input())

	creatures = sortByName(getCreatures(fileName))
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

		creatures = sortByUserRating(creatures, creaturesSize, 7)

		for i in range(0, creaturesSize):
			prevPoints = creatures[i][8]
			creatures[i] = (*creatures[i][0:8], prevPoints + (creaturesSize - i) - 1)

	creatures = sortByUserRating(creatures, creaturesSize, 8)

	for creature in creatures:
		print(f'{creature[0]} {creature[8]}')


# 0 ~ 10 initial rating
# max 46 users
# max 1000 creatures
# -20 ~ 20 single rating
# max ~ 1200 by user
