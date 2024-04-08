#include <stdio.h>
#include <math.h>

int main() {
	int num;
	double sum;

	scanf("%d", &num);

	sum = pow((double)num, 1.0 / 3.0) + pow((double)num, 1.0 / 4.0);

	printf("%.2lf\n", sum);

	return 0;
}
