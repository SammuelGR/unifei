#include <stdio.h>
#include <stdlib.h>

void imprimir_tabuleiro(int r0, int r1, int r2) {
	int i;

	for (i = 0; i < 3; i++) {
		if (r0 == i) {
			printf("R");
		} else {
			printf("_");
		}
	}
	printf("\n");

	for (i = 0; i < 3; i++) {
		if (r1 == i) {
			printf("R");
		} else {
			printf("_");
		}
	}
	printf("\n");

	for (i = 0; i < 3; i++) {
		if (r2 == i) {
			printf("R");
		} else {
			printf("_");
		}
	}
	printf("\n");

	return;
}

int main(void) {
	int r0, r1, r2;


	for (r0 = 0; r0 < 3; r0++) {
		for (r1 = 0; r1 < 3; r1++) {
			for (r2 = 0; r2 < 3; r2++) {
				// coluna
				if (r0 == r1 || r0 == r2 || r1 == r2) {
					continue;
				}

				// diagonal
				if (r0 == r1 - 1 || r0 == r1 + 1 ||
					r0 == r2 - 2 || r0 == r2 + 2 ||
					r1 == r2 - 1 || r1 == r2 + 1
					) {
					continue;
				}

				imprimir_tabuleiro(r0, r1, r2);
			}
		}
	}




	return 0;
}
