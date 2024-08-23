listSize = int(input("How many people? "))

tallest = {"name": "", "height": 0}
smallest = {"name": "", "height": 0}

for i in range(listSize):
	currentPerson = {"name": "", "height": ""}
	currentPerson["name"] = input(f"Person {i + 1} name: ")
	currentPerson["height"] = float(input(f"Person {i + 1} height: "))

	if currentPerson["height"] > tallest["height"] or i == 0:
		tallest = currentPerson

	if currentPerson["height"] < smallest["height"] or i == 0:
		smallest = currentPerson

print(f"Tallest person: {tallest['name']}, {str(tallest['height'])}")
print(f"Smallest person: {smallest['name']}, {str(smallest['height'])}")
