#define SIZE 10

#include <stdio.h>

int main() {
	int numbers[SIZE], i, j, counter = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &numbers[i]);
	}

	for (i = 0; i < SIZE; i++) {
		counter = 0;
		for (j = i; j >= 0; j--) {
			if (i != j && numbers[i] == numbers[j]) counter++;
		}

		if (counter == 0) {
			printf("%d ", numbers[i]);
		}
	}

	return 0;
}