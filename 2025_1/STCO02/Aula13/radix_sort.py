import random

def countingSortByDigit(list, d):
	B = [None for _ in range(0, len(list))]
	C = [0 for _ in range(0, 10)]

	for a in list:
		index = (a // 10**d) % 10
		C[index] += 1

	for i in range(1, 10):
		C[i] += C[i-1]

	for i in range(len(list) - 1, -1, -1):
		a = list[i]
		index = (a // 10**d) % 10
		B[C[index] - 1] = a
		C[index] -= 1

	return B

def radixSort(A, D):
	for d in range(0, D):
		A = countingSortByDigit(A, d)

	return A


A = [random.randint(0, 99999) for _ in range(1_000_000)]
A = radixSort(A, 8)

