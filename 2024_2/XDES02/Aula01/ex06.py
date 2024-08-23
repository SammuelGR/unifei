inputStr = input("your text: ")

isEqual = True
size = len(inputStr)

for i in range(size):
	if inputStr[i] != inputStr[size - i - 1]:
		isEqual = False
		break

print("Is a palindrome!") if isEqual else print("Is not a palindrome!")
