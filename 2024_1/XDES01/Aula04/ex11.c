#include <math.h>
#include <stdio.h>

int main() {
	const double PI = acos(-1);
	double r, h;
	double volume;

	scanf("%lf %lf", &r, &h);

	volume = PI * r * r * h;

	printf("%.2lf\n", volume);

	return 0;
}
