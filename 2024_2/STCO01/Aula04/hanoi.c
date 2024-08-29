#include <stdio.h>

void hanoi(int n, int ini, int dest, int aux);

int main(void) {

	hanoi(4, 1, 3, 2);

	return 0;
}

// Func para imprimir os movimentos para levar n discos
// de ini ate dest, usando aux para ajudar.
void hanoi(int n, int ini, int dest, int aux) {
	if (n == 1) {
		printf("Mova disco %d, de torre %d para torre %d\n", n, ini, dest);

		return;
	}

	// mover os n-1 de ini ate aux, posso usar dest como auxuliar
	hanoi(n - 1, ini, aux, dest);
	// mover disco grande de ini ate dest
	printf("Mova disco %d, de torre %d para torre %d\n", n, ini, dest);
	// mover os n-1 discos de aux ate dest, posso usar ini como auxiliar
	hanoi(n - 1, aux, dest, ini);

	return;
}
