#include <stdio.h>
#include <stdlib.h>

typedef struct cel cel;

struct cel {
	int dado;
	cel *esq;
	cel *dir;
};

cel *cria_celula(int dado) {
	cel *novo = (cel *)malloc(sizeof(cel));

	novo->dado = dado;
	novo->esq = NULL;
	novo->dir = NULL;

	return novo;
}

// insere valor na arvore e devolve o endereco da nova arvore com o valor
cel *insere_arvore(cel *arvore, int valor) {
	if (arvore == NULL) {
		return cria_celula(valor);
	}

	if (arvore->dado > valor) {
		arvore->esq = insere_arvore(arvore->esq, valor);
	}
	else {
		arvore->dir = insere_arvore(arvore->dir, valor);
	}

	return arvore;
}



// erd - inorder
void imprime_inorder(cel *arvore) {
	if (arvore == NULL) return;

	imprime_inorder(arvore->esq);
	printf("%d ", arvore->dado);
	imprime_inorder(arvore->dir);
}

// red - preorder
void imprime_preorder(cel *arvore) {
	if (arvore == NULL) return;

	printf("%d ", arvore->dado);
	imprime_preorder(arvore->esq);
	imprime_preorder(arvore->dir);
}

// edr - posorder
void imprime_posorder(cel *arvore) {
	if (arvore == NULL) return;

	imprime_posorder(arvore->esq);
	printf("%d ", arvore->dado);
	imprime_posorder(arvore->dir);
}

int calcula_altura(cel *arvore) {
	if (arvore == NULL) return 0;

	int altura_esq = calcula_altura(arvore->esq);
	int altura_dir = calcula_altura(arvore->dir);

	return altura_esq > altura_dir ? altura_esq + 1 : altura_dir + 1;
}

// devolve o endereco da celula com o valor, ou NULL
cel *busca_valor(cel *arvore, int valor) {
	if (arvore == NULL) return NULL;
	if (arvore->dado == valor) return arvore;

	if (arvore->dado > valor) return busca_valor(arvore->esq, valor);
	return busca_valor(arvore->dir, valor);
}

int main(void) {
	cel *arvore = NULL;

	arvore = insere_arvore(NULL, 10);
	arvore = insere_arvore(arvore, 5);
	arvore = insere_arvore(arvore, 7);
	arvore = insere_arvore(arvore, 6);
	arvore = insere_arvore(arvore, 11);

	printf("\nimprime_inorder(arvore): ");
	imprime_inorder(arvore);
	printf("\n");

	printf("\nimprime_preorder(arvore): ");
	imprime_preorder(arvore);
	printf("\n");

	printf("\nimprime_posorder(arvore): ");
	imprime_posorder(arvore);
	printf("\n");

	printf("\ncalcula_altura(arvore): ");
	printf("%d", calcula_altura(arvore));
	printf("\n\n");

	if (busca_valor(arvore, 7) == NULL) {
		printf("7 nao esta na arvore!\n");
	}
	else {
		printf("7 esta na arvore!\n");
	}

	if (busca_valor(arvore, 12) == NULL) {
		printf("12 nao esta na arvore!\n");
	}
	else {
		printf("12 esta na arvore!\n");
	}
	printf("\n");

	return 0;
}
