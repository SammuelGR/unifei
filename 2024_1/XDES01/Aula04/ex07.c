#include <stdio.h>

int main() {
	double initialPrice, distShareAmount, taxShareAmount;

	scanf("%lf", &initialPrice);

	distShareAmount = 0.28 * initialPrice;
	taxShareAmount = 0.45 * initialPrice;

	printf("%.2lf\n", initialPrice + distShareAmount + taxShareAmount);

	return 0;
}
