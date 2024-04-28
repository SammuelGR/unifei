#define SIZE 10

#include <stdio.h>

int main(void) {
	int numbers[SIZE], i, j, aux;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &numbers[i]);
	}

	for (i = 1; i < SIZE; i++) {
		for (j = 0; j < SIZE - 1; j++) {
			if (numbers[i] < numbers[j]) {
				aux = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = aux;
			}
		}
	}

	printf("%d %d %d\n", numbers[0], numbers[1], numbers[2]);

	return 0;
}
