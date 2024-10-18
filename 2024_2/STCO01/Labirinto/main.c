#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void resolve_labirinto(int n, char **labirinto) {
	char **visitado = (char **)malloc(sizeof(char *) * n);
	for (int i = 0; i < n; i++) {
		visitado[i] = (char *)malloc(sizeof(char) * n);
		for (int j = 0; j < n; j++) {
			visitado[i][j] = '0';
		}
	}

	pilha P = criar_pilha();

	empilhar(P, 0, 0);
	visitado[0][0] = 'E';

	while (!pilha_vazia(P)) {
		int x_atual;
		int y_atual;
		desempilhar(P, &x_atual, &y_atual);

		if (labirinto[x_atual][y_atual] == 'S') {
			printf("Cheguei na saida!\n");
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < n; x++) {
					printf("%c", visitado[x][y]);
				}
				printf("\n");
			}
			return;
		}

		//descobrindo novos caminhos
		//tentar ir pro sul
		if (y_atual + 1 < n && labirinto[x_atual][y_atual + 1] != 'X'
			&& visitado[x_atual][y_atual + 1] == '0') {
			empilhar(P, x_atual, y_atual + 1);
			visitado[x_atual][y_atual + 1] = 'N'; //vim do norte
		}
		//tentar ir pro norte
		if (y_atual - 1 >= 0 && labirinto[x_atual][y_atual - 1] != 'X'
			&& visitado[x_atual][y_atual - 1] == '0') {
			empilhar(P, x_atual, y_atual - 1);
			visitado[x_atual][y_atual - 1] = 's'; //vim do sul
		}
		//tentar ir para leste
		if (x_atual + 1 < n && labirinto[x_atual + 1][y_atual] != 'X'
			&& visitado[x_atual + 1][y_atual] == '0') {
			empilhar(P, x_atual + 1, y_atual);
			visitado[x_atual + 1][y_atual] = 'W'; //vim do (w)oeste
		}
		//tentar ir para oeste
		if (x_atual - 1 >= 0 && labirinto[x_atual - 1][y_atual] != 'X'
			&& visitado[x_atual - 1][y_atual] == '0') {
			empilhar(P, x_atual - 1, y_atual);
			visitado[x_atual - 1][y_atual] = 'L'; //vim do leste
		}
	}

	printf("Sem saida\n");

	liberar_pilha(P);
}

int main() {
	int n;

	scanf("%d\n", &n);

	char **labirinto;
	labirinto = (char **)malloc(sizeof(char *) * n);
	for (int i = 0; i < n; i++) {
		labirinto[i] = (char *)malloc(sizeof(char) * n);
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			scanf("%c", &(labirinto[x][y]));
		}
		scanf("\n");
	}

	for (int y = 0; y < n; y++) {
		for (int x = 0; x < n; x++) {
			printf("%c", labirinto[x][y]);
		}
		printf("\n");
	}

	resolve_labirinto(n, labirinto);

	return 0;
}
