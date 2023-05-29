#include <stdio.h>

#define SIZE 12

int main() {
	int numbers[SIZE] = { 0 }, i = 0, oddCounter = 0, evenCounter = 0;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &numbers[i]);

		if (numbers[i] % 2 == 0) {
			evenCounter++;
		}
		else {
			oddCounter++;
		}
	}

	printf("%d %d\n", evenCounter, oddCounter);

	return 0;
}
