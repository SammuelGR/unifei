# at the i-th iteration, the first i elements are correctly sorted

def cagada_sort(list):
	for i in range(len(list)):
		for j in range(i + 1, len(list)):
			if list[i] > list[j]:
				list[i], list[j] = list[j], list[i]

def selection_sort(list):
	for i in range(len(list)):
		lowest_idx = i

		for j in range(i + 1, len(list)):
			if list[j] < list[lowest_idx]:
				lowest_idx = j

		list[i], list[lowest_idx] = list[lowest_idx], list[i]

numbers = [5, 99, 13, 18, 1, 30, 10, 77]
selection_sort(numbers)
print(numbers)
