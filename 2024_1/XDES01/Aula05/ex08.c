#include <stdio.h>

int main() {
	int n;

	scanf("%d", &n);

	if (n % 11 == 0) {
		printf("sim\n");
	} else {
		printf("nao\n");
	}

	return 0;
}
