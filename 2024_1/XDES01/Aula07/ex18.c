#define SIZE 10

#include <math.h>
#include <stdio.h>

int main() {
	float v[SIZE], average = 0.0, sum = 0.0, deviation = 0.0;
	int i;

	for (i = 0; i < SIZE; i++) {
		scanf("%f", &v[i]);
		average += v[i];
	}

	average /= SIZE;

	for (i = 0; i < SIZE; i++) {
		sum += pow((v[i] - average), 2.0);
	}

	deviation = sqrt((1.0 / (SIZE - 1.0)) * sum);

	printf("%.1f\n", deviation);

	return 0;
}
