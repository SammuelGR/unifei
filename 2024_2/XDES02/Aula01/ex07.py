numbers = []
average = 0

while True:
	currentNumber = int(input("Type a number: "))

	if currentNumber == 0:
		break

	numbers.append(currentNumber)
	average += currentNumber

average /= len(numbers)

print("The average is: " + str(average))
