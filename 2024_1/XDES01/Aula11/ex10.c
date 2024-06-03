#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, i, idx = 0, *p = &idx;
	double *vector = NULL, average = 0, minDiff;

	scanf("%d", &N);

	vector = (double *)malloc(N * sizeof(double));

	for (i = 0; i < N; i++) {
		scanf("%lf", vector + i);
		average += *(vector + i);
	}

	average /= N;
	printf("%lf\n", average);

	minDiff = fabs(*(vector)-average);

	for (i = 1; i < N; i++) {
		if (fabs(*(vector + i) - average) < minDiff) {
			*p = i;
		}
	}

	printf("%d\n", *p);

	free(vector);

	return 0;
}
