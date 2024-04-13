#include <math.h>
#include <stdio.h>

int main() {
	float a, b, c;
	float delta, x1, x2, aux;

	scanf("%f %f %f", &a, &b, &c);

	delta = (b * b) - 4 * a * c;

	if (delta < 0) {
		printf("sem raizes reais\n");
	} else if (delta == 0) {
		x1 = (-b + sqrt(delta)) / (2.0 * a);

		printf("%f\n", x1);
	} else {
		x1 = (-b + sqrt(delta)) / (2.0 * a);
		x2 = (-b - sqrt(delta)) / (2.0 * a);

		if (x1 > x2) {
			aux = x1;
			x1 = x2;
			x2 = aux;
		}

		printf("%f %f\n", x1, x2);
	}

	return 0;
}
