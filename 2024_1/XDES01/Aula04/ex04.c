#include <stdio.h>

int main() {
	int distance, days;
	float priceA, priceB;

	scanf("%d %d", &distance, &days);

	priceA = 62.0 * days + 1.4 * distance;
	priceB = 80.0 * days + 1.2 * distance;

	printf("%.2f %.2f\n", priceA, priceB);

	return 0;
}
