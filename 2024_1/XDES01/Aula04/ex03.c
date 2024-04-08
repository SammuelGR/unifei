#include <stdio.h>

int main() {
	double weight, medDrops;

	scanf("%lf", &weight);

	medDrops = weight / 2.0 * 5.0;

	printf("%.0lf\n", medDrops);

	return 0;
}
