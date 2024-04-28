#define SIZE 10

#include <stdio.h>

int main() {
	int numbers[10], highest, lowest, i;

	for (i = 0; i < SIZE; i++) {
		scanf("%d", &numbers[i]);

		if (i == 0) {
			highest = numbers[i];
			lowest = numbers[i];
		} else {
			if (numbers[i] > highest) {
				highest = numbers[i];
			}

			if (numbers[i] < lowest) {
				lowest = numbers[i];
			}
		}
	}

	printf("%d %d\n", highest, lowest);

	return 0;
}
