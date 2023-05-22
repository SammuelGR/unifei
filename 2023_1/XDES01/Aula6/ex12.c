#include <stdio.h>

int main() {
	int N = 0, i = 0, sum = 0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		if (i % 2 == 0) {
			sum += -i;
		}
		else {
			sum += i;
		}
	}

	printf("%d\n", sum);

	return 0;
}
