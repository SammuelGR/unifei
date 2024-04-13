#include <stdio.h>

int main() {
	int a, b, smallest;

	scanf("%d %d", &a, &b);

	if (a < b) {
		smallest = a;
	} else {
		smallest = b;
	}

	printf("%d\n", smallest);

	return 0;
}
