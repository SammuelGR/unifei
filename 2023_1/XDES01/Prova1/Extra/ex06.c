#include <stdio.h>
#include <math.h>

int main() {
	int N = 0, P = 0, i = 0;
	int nFat = 1, pFat = 1, npFat = 1, result = 0;

	do {
		scanf("%d %d", &N, &P);

		if (N > 0 && P > 0) {
			for (i = 0; i < N; i++) {
				nFat *= N - i;
			}

			for (i = 0; i < P; i++) {
				pFat *= P - i;
			}

			for (i = 0; i < (N - P); i++) {
				npFat *= (N - P) - i;
			}

			result = nFat / (pFat * npFat);
		}

	} while (N <= 0 || P <= 0);

	printf("%d\n", result);

	return 0;
}
