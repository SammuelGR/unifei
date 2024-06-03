#include <stdio.h>
#include <stdlib.h>

int main() {
	int N, i, *vector = NULL, even = 0, odd = 0;

	scanf("%d", &N);

	vector = (int *)malloc(N * sizeof(int));

	for (i = 0; i < N; i++) {
		scanf("%d", vector + i);

		if (*(vector + i) % 2 == 0) {
			even++;
		} else {
			odd++;
		}
	}

	printf("%d\n%d\n", even, odd);

	free(vector);

	return 0;
}
