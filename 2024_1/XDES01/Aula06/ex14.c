#include <math.h>
#include <stdio.h>

int main() {
	int n, i;
	float sum = 0.0;

	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		sum += 2.0 * i / pow(2, i);
	}

	printf("%.2f\n", sum);

	return 0;
}
