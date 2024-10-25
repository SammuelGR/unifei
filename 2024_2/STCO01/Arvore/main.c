#include <stdio.h>
#include <stdlib.h>

typedef struct cel cel;

struct cel {
	char dado;
	cel *esq;
	cel *dir;
};

cel *cria_celula(char dado) {
	cel *novo = (cel *)malloc(sizeof(cel));

	novo->dado = dado;
	novo->esq = NULL;
	novo->dir = NULL;

	return novo;
}

void imprime_inorder(cel *arvore) {
	if (arvore == NULL) return;

	imprime_inorder(arvore->esq);
	printf("%c", arvore->dado);
	imprime_inorder(arvore->dir);
}

void imprime_preorder(cel *arvore) {
	if (arvore == NULL) return;

	printf("%c", arvore->dado);
	imprime_preorder(arvore->esq);
	imprime_preorder(arvore->dir);
}

int calcula_altura(cel *arvore) {
	if (arvore == NULL) return 0;

	int altura_esq = calcula_altura(arvore->esq);
	int altura_dir = calcula_altura(arvore->dir);

	return altura_esq > altura_dir ? altura_esq + 1 : altura_dir + 1;
}

int main(void) {
	cel *arvore = cria_celula('C');
	arvore->esq = cria_celula('A');
	arvore->esq->dir = cria_celula('B');
	arvore->esq->dir->esq = cria_celula('W');
	arvore->esq->dir->esq->dir = cria_celula('X');
	arvore->dir = cria_celula('D');

	cel *arvoreDiagonal = cria_celula('A');
	arvoreDiagonal->dir = cria_celula('B');
	arvoreDiagonal->dir->dir = cria_celula('C');
	arvoreDiagonal->dir->dir->dir = cria_celula('D');

	printf("\nimprime_inorder(arvore): ");
	imprime_inorder(arvore);
	printf("\n");

	printf("\nimprime_preorder(arvore): ");
	imprime_preorder(arvore);
	printf("\n");

	printf("\ncalcula_altura(arvore): ");
	printf("%d", calcula_altura(arvore));
	printf("\n");

	printf("\ncalcula_altura(arvoreDiagonal): ");
	printf("%d", calcula_altura(arvoreDiagonal));
	printf("\n");

	free(arvore->esq->dir->esq);
	free(arvore->esq->dir);
	free(arvore->esq);
	free(arvore->dir);
	free(arvore);

	return 0;
}

// erd - inorder
// red - preorder
// edr - posorder
