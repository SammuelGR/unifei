#define SIZE 100

#include <stdio.h>
#include <string.h>

int main() {
	char F[SIZE], c;
	int i, idx = -1, size;

	scanf("%[^\n]", F);
	scanf(" %c %d", &c, &i);

	size = strlen(F);

	for (i = i; i < size; i++) {
		if (F[i] == c) {
			idx = i;
			i = size;
		}
	}

	printf("%d\n", idx);

	return 0;
}
