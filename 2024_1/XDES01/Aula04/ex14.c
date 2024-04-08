#define ROOMS_QTY 80

#include <stdio.h>

int main() {
	float normalPrice, promotionalPrice;
	float promotionalProfit, normalProfit;

	scanf("%f", &normalPrice);

	promotionalPrice = normalPrice * 0.75;
	printf("%.2f\n", promotionalPrice);

	promotionalProfit = 0.8 * ROOMS_QTY * promotionalPrice;
	printf("%.2f\n", promotionalProfit);

	normalProfit = 0.5 * ROOMS_QTY * normalPrice;
	printf("%.2f\n", normalProfit);

	printf("%.2f\n", promotionalProfit - normalProfit);

	return 0;
}
