#define SIZE 10

#include <stdio.h>

int main(void) {
	int numbers[SIZE], i, counter = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &numbers[i]);

		if ((numbers[i] & 1) != 1) counter++;
	}

	printf("%d\n", counter);

	return 0;
}
