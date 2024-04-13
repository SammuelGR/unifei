#include <math.h>
#include <stdio.h>

int main() {
	int n;

	scanf("%d", &n);

	if (n > 0) {
		printf("%lf\n", sqrt(n));
	} else {
		printf("%d\n", n * n);
	}

	return 0;
}
