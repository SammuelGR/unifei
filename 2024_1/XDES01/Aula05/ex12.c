#include <stdio.h>

int main() {
	int a, b, c;

	scanf("%d %d %d", &a, &b, &c);

	if (a == b && a == c) {
		printf("equilatero\n");
	} else if ((a == b && a != c) || (a == c && a != b) || (a != b && b == c)) {
		printf("isosceles\n");
	} else {
		printf("escaleno\n");
	}

	return 0;
}
