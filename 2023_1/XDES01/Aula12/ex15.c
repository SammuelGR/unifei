#include <stdio.h>
#include <stdlib.h>

void calcMinMax(int* vet, int n, int* min, int* max);

int main() {
	int* vet = NULL, n = 0, min = 0, max = 0, i = 0;

	scanf("%d", &n);

	vet = (int*)malloc(n * sizeof(int));

	if (!vet) exit(1);

	for (i = 0; i < n; i++) {
		scanf("%d", vet + i);
	}

	calcMinMax(vet, n, &min, &max);

	printf("%d %d\n", min, max);

	free(vet);

	return 0;
}

void calcMinMax(int* vet, int n, int* min, int* max) {
	int i = 0;

	for (i = 0; i < n; i++) {
		if (i == 0) {
			*min = *vet;
			*max = *vet;
		} else if (*(vet + i) > *max) {
			*max = *(vet + i);
		} else if (*(vet + i) < *min) {
			*min = *(vet + i);
		}
	}
}
