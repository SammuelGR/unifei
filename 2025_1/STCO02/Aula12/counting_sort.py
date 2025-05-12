import random

def countingSort(list, maxValue):
	result = [None for _ in range(0, len(list))]
	count = [0 for _ in range(0, maxValue + 1)]

	for a in list:
		count[a] += 1

	for i in range(1, maxValue + 1):
		count[i] += count[i-1]

	for a in list:
		result[count[a] - 1] = a
		count[a] -= 1

def stableCountingSort(list, k):
	B = [None for _ in range(0, len(list))]
	C = [0 for _ in range(0, k + 1)]

	for a in list:
		C[a] += 1

	for i in range(1, k + 1):
		C[i] += C[i-1]

	for i in range(len(list) - 1, -1, -1):
		a = list[i]

		B[C[a] - 1] = a
		C[a] -= 1

nums_list = [3, 3, 4, 2, 1, 8, 0, 1]
k = 10_000_000
n = 10_000_000
largeList = [random.randint(0, k) for _ in range(0, n)]

B = stableCountingSort(largeList, k)