#include <stdio.h>

int maxvet(int* vet, int n);

int main() {
	int v[6] = { 2, 4, 6, 1, 3, 5 }, size = 6;

	printf("%d\n", maxvet(v, size));

	return 0;
}

int maxvet(int* vet, int n) {
	int i = 0, maxValue = 0;

	for (i = 0; i < n; i++) {
		if (i == 0 || *(vet + i) > maxValue) {
			maxValue = *(vet + i);
		}
	}

	return maxValue;
}
