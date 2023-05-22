#include <stdio.h>

int main() {
	int i = 0;
	float N = 0.0, sum = 0.0;

	scanf("%f", &N);

	for (i = 1; i <= N; i++) {
		if (i == 1) {
			sum += -1.0;
		}
		else if (i % 2 == 0) {
			sum += 1.0 / (float)i;
		}
		else {
			sum += -1.0 / (float)i;
		}
	}

	printf("%.2f\n", sum);

	return 0;
}
