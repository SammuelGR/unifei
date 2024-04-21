#include <stdio.h>

int main() {
	int n, counter = 0;
	float average = 0.0;

	do {
		scanf("%d", &n);

		if (n >= 0) {
			average += n;
			counter++;
		}

	} while (n >= 0);

	average /= counter;
	printf("%.1f\n", average);

	return 0;
}
