#include <stdio.h>

int main() {
	int a, b, c, d, smallest;

	scanf("%d %d %d %d", &a, &b, &c, &d);

	smallest = a;

	if (b < smallest) {
		smallest = b;
	} if (c < smallest) {
		smallest = c;
	} if (d < smallest) {
		smallest = d;
	}

	printf("%d\n", smallest);

	return 0;
}
