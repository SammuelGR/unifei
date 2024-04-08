#include <stdio.h>
#include <math.h>

int main() {
	double a, b, c, p, res;

	scanf("%lf %lf %lf", &a, &b, &c);

	p = (a + b + c) / 2.0;

	res = sqrt(p * (p - a) * (p - b) * (p - c));

	printf("%.1lf\n", res);

	return 0;
}
