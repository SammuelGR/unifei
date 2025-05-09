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
			
			ratings.append(0) # sum of ratings
			ratings.append(0) # sum of points

			creatures[name] = ratings
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

	for userRating in ratings:
		for creature, cRatings in creatures.items():
			total = 0
			
			for i in range(0, 6):
				total += cRatings[i] * userRating[i]
			
			creatures[creature][6] = total

		

		for creature, cRatings in creatures.items():
			pass