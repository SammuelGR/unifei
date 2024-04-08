#define PROFIT_PER_CLASS 50
#define EXPENSES_PERCENTAGE 0.15

#include <stdio.h>

int main() {
	int classesQuantity;
	float totalProfit, totalExpenses;

	scanf("%d", &classesQuantity);

	totalProfit = classesQuantity * PROFIT_PER_CLASS;
	totalExpenses = totalProfit * EXPENSES_PERCENTAGE;


	printf("%.2f\n", totalProfit);
	printf("%.2f\n", totalExpenses);
	printf("%.2f\n", totalProfit - totalExpenses);

	return 0;
}
