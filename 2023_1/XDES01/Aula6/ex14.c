#include <stdio.h>
#include <math.h>

int main() {
	int N = 0, i = 0;
	float sum = 0.0;

	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		sum += (i * 2.0) / (pow(2.0, i));
	}

	printf("%.2f\n", sum);

	return 0;
}
