#include <stdio.h>
#include <math.h>

int main() {
	int N = 0, i = 0, count = 0;
	float sum = 0.0, currentValue = 0.0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		currentValue = (((2.0 * i) - 1.0) / i);

		if (count == 0 || count == 1) {
			count++;
			sum += currentValue;
		}
		else if (count == 2) {
			count++;
			sum += -currentValue;
		}
		else {
			count = 0;
			sum += -currentValue;
		}
	}

	printf("%.2f\n", sum);

	return 0;
}
