#include <stdio.h>

int main() {
	float price, finalPrice = 0;
	int state;

	scanf("%f %d", &price, &state);

	switch (state)
	{
	case 1:
		finalPrice = price * 1.12;
		break;
	case 2:
		finalPrice = price * 1.07;
		break;
	case 3:
		finalPrice = price * 1.15;
		break;
	case 4:
		finalPrice = price * 1.08;
		break;
	default:
		break;
	}

	printf("%.2f\n", finalPrice);

	return 0;
}
