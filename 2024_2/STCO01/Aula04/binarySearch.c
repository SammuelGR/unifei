#define ARRAY_SIZE 8

#include <stdio.h>

int find(int V[], int size, int searchNumber);

int binarySearch(int *V, int from, int to, int searchNumber);

int main(void) {
	int V[ARRAY_SIZE] = { 50, 52, 56, 60, 61, 67, 70, 91 };

	printf("Find 52: %d\n", find(V, ARRAY_SIZE, 52));
	printf("Find 61: %d\n", find(V, ARRAY_SIZE, 61));
	printf("Find 73: %d\n", find(V, ARRAY_SIZE, 73));


	printf("Binary 52: %d\n", binarySearch(V, 0, ARRAY_SIZE - 1, 52));
	printf("Binary 61: %d\n", binarySearch(V, 0, ARRAY_SIZE - 1, 61));
	printf("Binary 73: %d\n", binarySearch(V, 0, ARRAY_SIZE - 1, 73));

	return 0;
}

int find(int V[], int size, int searchNumber) {
	int i;

	for (i = 0; i < size; i++) {
		if (V[i] == searchNumber) return 1;
		if (V[i] > searchNumber) return 0;
	}

	return 0;
}

int binarySearch(int *V, int fromIdx, int toIdx, int searchNumber) {
	if (toIdx < fromIdx) return 0; // empty array

	int middleIdx = (toIdx + fromIdx) / 2;

	if (V[middleIdx] == searchNumber) return 1;
	if (V[middleIdx] > searchNumber) return binarySearch(V, fromIdx, middleIdx - 1, searchNumber);

	return binarySearch(V, middleIdx + 1, toIdx, searchNumber);
}
