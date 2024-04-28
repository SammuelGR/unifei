#define SIZE 10

#include <stdio.h>

int main(void) {
	float grades[SIZE], average = 0.0;
	int i;

	for (i = 0; i < SIZE; i++) {
		scanf("%f", &grades[i]);

		average += grades[i];
	}

	average /= SIZE;

	printf("%.2f\n", average);

	return 0;
}
