names = []

length = int(input("How many names? "))

for i in range(length):
	names.append(input(f"Name {i + 1}: "))

print()
search = input("Type a name to search: ")

if search in names:
	print(f"{search} found!")
else:
	print(f"{search} is not in the list!")
