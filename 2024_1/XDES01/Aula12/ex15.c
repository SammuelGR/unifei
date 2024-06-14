#include <stdio.h>
#include <stdlib.h>

void getMinMax(int *v, int N, int *min, int *max);

int main() {
	int N, *v = NULL, i;
	int min, max;

	scanf("%d", &N);

	v = (int *)malloc(N * sizeof(int));

	for (i = 0; i < N; i++) {
		scanf("%d", (v + i));
	}

	getMinMax(v, N, &min, &max);

	printf("%d %d\n", min, max);

	free(v);

	return 0;
}

void getMinMax(int *v, int N, int *min, int *max) {
	int minValue = *v, maxValue = *v, i;

	for (i = 1; i < N; i++) {
		if (*(v + i) < minValue) {
			minValue = *(v + i);
		}

		if (*(v + i) > maxValue) {
			maxValue = *(v + i);
		}
	}

	*min = minValue;
	*max = maxValue;
}
