#define SIZE 10

#include <stdio.h>
#include <stdlib.h>

int main() {
	int *p = (int *)malloc(SIZE * sizeof(int)), *aux = NULL;
	int currentNumber;
	int i = 0, j, count = 1;

	do {
		scanf("%d", &currentNumber);

		if (currentNumber > 0) {
			if (i != 0 && i % SIZE == 0) {
				count++;

				aux = (int *)malloc(i * sizeof(int));
				for (j = 0; j < i; j++) {
					aux[j] = p[j];
				}

				free(p);

				p = (int *)malloc(count * SIZE * sizeof(int));
				for (j = 0; j < i; j++) {
					p[j] = aux[j];
				}

				free(aux);
			}
		}

		p[i] = currentNumber;
		i++;
	} while (currentNumber > 0);

	free(p);

	return 0;
}
