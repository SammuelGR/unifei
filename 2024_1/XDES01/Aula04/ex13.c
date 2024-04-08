#include <math.h>
#include <stdio.h>

int main() {
	const double PI = acos(-1.0);
	double r, volume;

	scanf("%lf", &r);

	volume = 4.0 * PI * pow(r, 3.0) / 3.0;

	printf("%lf\n", volume);

	return 0;
}
