#include <stdio.h>

int maxvet(int *v, int n);

int main() {
	int v[6] = { 2, 4, 6, 1, 3, 5 };

	printf("%d", maxvet(v, 6));

	return 0;
}

int maxvet(int *v, int n) {
	int i, highest = v[0];

	for (i = 1; i < n; i++) {
		if (v[i] > highest) {
			highest = v[i];
		}
	}

	return highest;
}
