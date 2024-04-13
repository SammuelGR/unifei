#include <stdio.h>

int main() {
	int n;

	scanf("%d", &n);

	if ((n % 3 == 0 && n % 5 == 0) || (n % 3 != 0 && n % 5 != 0)) {
		printf("nao divisivel\n");
	} else {
		if (n % 3 == 0) {
			printf("divisivel por 3\n");
		} else {
			printf("divisivel por 5\n");
		}
	}

	return 0;
}
