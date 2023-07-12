#include <stdio.h>

double avgvet(int* vet, int n);

int main() {
	int v[6] = { 2, 4, 6, 1, 3, 5 };

	printf("%lf", avgvet(v, 6));

	return 0;
}

double avgvet(int* vet, int n) {
	double average = 0;
	int i = n;

	while (i--) {
		average += *(vet + i);
	}

	average /= n;

	return average;
}
