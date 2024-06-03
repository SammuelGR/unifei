#define SIZE 10

#include <stdio.h>

int main() {
	int vector[SIZE], i, *p = NULL, aux;
	int highestVal, secHighestVal, secHIdx = 0;
	int lowestVal, secLowestVal, secLIdx = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &vector[i]);
	}

	p = vector;
	highestVal = *p;
	lowestVal = *p;

	for (i = 0; i < SIZE; i++) {
		if (*(p + i) > highestVal) {
			highestVal = *(p + i);
		}

		if (*(p + i) < lowestVal) {
			lowestVal = *(p + i);
		}
	}

	i = 0;
	while (*(p + i) == highestVal) i++;
	secHighestVal = *(p + i);
	secHIdx = i;

	i = 0;
	while (*(p + i) == lowestVal) i++;
	secLowestVal = *(p + i);
	secLIdx = i;

	for (i = 0; i < SIZE; i++) {
		if (*(p + i) > secHighestVal && *(p + i) != highestVal) {
			secHighestVal = *(p + i);
			secHIdx = i;
		}

		if (*(p + i) < secLowestVal && *(p + i) != lowestVal) {
			secLowestVal = *(p + i);
			secLIdx = i;
		}
	}

	aux = *(p + secHIdx);
	*(p + secHIdx) = *(p + secLIdx);
	*(p + secLIdx) = aux;

	for (i = 0; i < SIZE; i++) {
		printf("%d\n", *(p + i));
	}

	return 0;
}
