#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *texto;
    struct celula *esq;
    struct celula *dir;
} celula;

void imprimir_arvore(celula *raiz, int nivel) {
    if (!raiz) return;
    for (int i = 0; i < nivel; i++) {
        printf("  ");
    }
    printf("%s\n", raiz->texto);
    imprimir_arvore(raiz->esq, nivel + 1);
    imprimir_arvore(raiz->dir, nivel + 1);
}

celula *novo_no(const char *texto) {
    celula *n = malloc(sizeof(celula));
    n->texto = strdup(texto);
    n->esq = NULL;
    n->dir = NULL;
    return n;
}

int ler_linha(FILE *f, int *filhos, char *texto) {
    char linha[1024];
    if (!fgets(linha, sizeof(linha), f)) return 0;

    sscanf(linha, "%d;%[^\n]", filhos, texto);
    return 1;
}

celula *ler_arvore(FILE *f) {
    int filhos;
    char texto[1024];

    if (!ler_linha(f, &filhos, texto)) return NULL;

    celula *no = novo_no(texto);
    printf("Lendo nó: '%s' com %d filhos\n", texto, filhos);
    if (filhos >= 1) {
        no->esq = ler_arvore(f);
    }
    if (filhos == 2) {
        no->dir = ler_arvore(f);
    }
    return no;
}

void jogar(celula *no) {
    if (!no) return;

    if (!no->esq && !no->dir) {
        printf("\n%s\n", no->texto);
        return;
    }

    if (no->esq && !no->dir) {
        printf("\n%s\n", no->texto);
        jogar(no->esq);
        return;
    }

    printf("\n%s\n", no->texto);
    printf("1) %s\n", no->esq->texto);
    printf("2) %s\n", no->dir->texto);

    int esc = -1;
    while (esc < 1 || esc > 2) {
        printf("> ");
        scanf("%d", &esc);
    }

    if (esc == 1) {
        jogar(no->esq);
    } else {
        jogar(no->dir);
    }
}

void liberar(celula *raiz) {
    if (raiz == NULL) {
        return;
    }

    liberar(raiz->esq);
    liberar(raiz->dir);
    free(raiz->texto);
    free(raiz);
}

int main(void) {
    FILE *f = fopen("input.txt", "rb");

    if (!f) {
        perror("Erro ao abrir arquivo");
        return 1;
    }

    celula *raiz = ler_arvore(f);
    fclose(f);

    printf("\nBem-vindo à aventura!\n");
    jogar(raiz);

    liberar(raiz);
    printf("\nMemória liberada. Fim de jogo!\n");

    return 0;
}