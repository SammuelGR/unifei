#include <stdio.h>

int main() {
	int n;

	scanf("%d", &n);

	if (n & 1) {
		printf("impar\n");
	} else {
		printf("par\n");
	}

	return 0;
}
