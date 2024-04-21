#include <stdio.h>

int main() {
	float n, sum = 0.0;
	int i;

	scanf("%f", &n);

	for (i = 1; i <= n; i++) {
		if (i & 1) {
			sum -= 1.0 / i;
		} else {
			sum += 1.0 / i;
		}
	}

	printf("%.2f\n", sum);

	return 0;
}
