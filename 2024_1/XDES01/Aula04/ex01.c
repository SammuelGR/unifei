#include <stdio.h>

int main() {
	float amount, dollarQuote;

	scanf("%f %f", &amount, &dollarQuote);

	printf("%.2f\n", amount / dollarQuote);

	return 0;
}
