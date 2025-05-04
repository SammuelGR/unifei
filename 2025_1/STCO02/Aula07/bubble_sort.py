# at the i-th iteration, the last i elements are correctly sorted

def bubble_sort(list):
	k = len(list) - 1

	for i in range(k, 0 , -1):
		has_changed = False

		for j in range(0, i):
			if list[j] > list[j + 1]:
				list[j], list[j + 1] = list[j + 1], list[j]
				has_changed = True

		if has_changed == False:
			return

numbers = [5, 99, 13, 18, 1, 30]
bubble_sort(numbers)
print(numbers)
