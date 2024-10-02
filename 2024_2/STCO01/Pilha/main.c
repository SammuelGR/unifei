#include <stdio.h>
#include "pilha.h"

int main(void) {
	pilha P = criar_pilha();

	empilhar(P, 'a');
	empilhar(P, 'b');
	empilhar(P, 'c');

	printf("%c\n", desempilhar(P));
	printf("%c\n", desempilhar(P));

	empilhar(P, 'd');

	printf("%c\n", desempilhar(P));

	liberar_pilha(P);

	return 0;
}
