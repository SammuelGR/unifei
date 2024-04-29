#define SIZE 10

#include <stdio.h>

int main() {
	int odds[SIZE];
	int num, counter = 0, i;

	do {
		scanf("%d", &num);

		if (num % 2 != 0) {
			odds[counter] = num;
			counter++;
		}
	} while (counter < SIZE);

	for (i = 0; i < SIZE; i++) {
		printf("%d ", odds[i]);
	}

	printf("\n");

	return 0;
}
