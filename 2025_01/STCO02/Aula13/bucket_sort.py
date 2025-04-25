import random

def insertionSort(list):
	for i in range(1, len(list)):
		j = i
		value = list[j]

		while j > 0 and list[j - 1] > value:
			list[j] = list[j - 1]
			j -= 1

		list[j] = value

def bucketSort(A):
	n = len(A)
	buckets = [[] for _ in range(n)]

	for a in A:
		index = int(a * n)
		buckets[index].append(a)

	for b in buckets:
		insertionSort(b)

	R = []
	for b in buckets:
		if b != []:
			current = b.pop()
			R.append(current)

	return R

A = [random.random() for _ in range(1_000_000)]

bucketSort(A)
