#include <stdio.h>
#include <math.h>

int main() {
	int N = 0, i = 0;
	float catalanResult = 0.0, currentResult = 0.0;

	do {
		scanf("%d", &N);

		if (N > 0) {
			for (i = 0; i < N; i++) {
				currentResult = 1.0 / pow((1.0 + (2.0 * (float)i)), 2);

				if (i % 2 == 0) {
					catalanResult += currentResult;
				}
				else {
					catalanResult -= currentResult;
				}
			}
		}
	} while (N <= 0);

	printf("%.4f\n", catalanResult);

	return 0;
}
