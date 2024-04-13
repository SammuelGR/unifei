#include <stdio.h>

int main() {
	int a, b;
	float average = 0;

	scanf("%d %d", &a, &b);

	if ((a >= 0 && a <= 10) && (b >= 0 && b <= 10)) {
		average = (a + b) / 2.0;

		printf("%f\n", average);
	} else {
		printf("notas incorretas\n");
	}

	return 0;
}
