#include <stdio.h>

int main() {
	double fullPrice, discountPrice;
	int discountPercentage;

	scanf("%lf %d", &fullPrice, &discountPercentage);

	discountPrice = discountPercentage * fullPrice / 100.0;

	printf("%.2lf %.2lf\n", fullPrice, discountPrice);

	return 0;
}
