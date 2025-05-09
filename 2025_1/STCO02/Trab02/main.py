import csv

def getCreatures(fileName: str):
	creatures = {}

	with open(fileName, newline='', encoding='utf-8') as csvfile:
		buffer = csv.reader(csvfile)
		_ = next(buffer) # ignore header

		for line in buffer:
			name = line[0]

			ratings = []
			for i in range(1, 7):
				ratings.append(float(line[i]))

			creatures[name] = ratings
	return creatures

if __name__ == '__main__':
	fileName = input()
	usersQty = int(input())
	ratings = []

	creatures = getCreatures(fileName)

	for _ in range(0, usersQty):
		currentRatings = input().strip().split(' ')

		for i in range(0, 6):
			currentRatings[i] = int(currentRatings[i])
		
		ratings.append(currentRatings)

	print(creatures)
