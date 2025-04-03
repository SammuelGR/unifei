# at the i-th iteration, the first i elements are correctly sorted

def insertion_sort(list):
	for i in range(1, len(list)):
		j = i
		value = list[j]

		while j > 0 and list[j - 1] > value:
			list[j] = list[j - 1]
			j -= 1

		list[j] = value



numbers = [5, 99, 13, 18, 1, 30, 10]
insertion_sort(numbers)
print(numbers)
