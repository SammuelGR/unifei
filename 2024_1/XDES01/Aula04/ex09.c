#include <stdio.h>

int main() {
	int days, months, years;
	int total;

	scanf("%d %d %d", &years, &months, &days);

	total = days + (months * 30) + (years * 365);

	printf("%d\n", total);

	return 0;
}
