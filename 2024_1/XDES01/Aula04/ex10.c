#include <stdio.h>

int main() {
	int days, months, years;
	int total;

	scanf("%d", &total);

	years = total / 365;
	total -= years * 365;

	months = total / 30;
	total -= months * 30;

	days = total;

	printf("%d %d %d\n", years, months, days);

	return 0;
}
