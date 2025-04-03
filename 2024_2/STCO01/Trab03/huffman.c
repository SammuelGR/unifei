#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

#define TAMANHO_ALFABETO 95
#define INICIO_ALFABETO 32
#define TAMANHO_MAX_ENTRADA 5000

typedef struct node {
	char ch;
	float chave;
	struct node *esq;
	struct node *dir;
} node;

node *criar_node(char ch, float chave, node *esq, node *dir) {
	node *no = (node *)malloc(sizeof(node));
	no->ch = ch;
	no->chave = chave;
	no->esq = esq;
	no->dir = dir;
	return no;
}

//  Funcoes para imprimir a arvore em formato graphViz
//pode visualizar em uma plataforma online como https://dreampuf.github.io/GraphvizOnline
int print_tree_rec(node *r, int *node_num) {
	if (r == NULL) return -1;
	int my_number = *node_num;
	printf("  %d[label=\"%c\"];\n", my_number, r->ch);
	(*node_num)++;
	int esq = print_tree_rec(r->esq, node_num);
	(*node_num)++;
	int dir = print_tree_rec(r->dir, node_num);
	if (esq != -1) printf("  %d -> %d;\n", my_number, esq);
	if (dir != -1) printf("  %d -> %d;\n", my_number, dir);
	return my_number;
}
void print_tree(node *r) {
	if (r == NULL) return;
	printf("digraph G{\n  graph [ordering=\"out\"];\n");
	int num_node = 0;
	print_tree_rec(r, &num_node);
	printf("}\n");
	return;
}

//As duas funcoes abaixo recebem uma arvore e uma tabela onde sera escrito o codigo de
//cada caractere presente na arvore
void percorre_arvore_rec(node *r, int *aux_codigo, int profundidade, int **tabela) {
	if (r->esq) {
		aux_codigo[profundidade] = 0;
		percorre_arvore_rec(r->esq, aux_codigo, profundidade + 1, tabela);
	}

	if (r->dir) {
		aux_codigo[profundidade] = 1;
		percorre_arvore_rec(r->dir, aux_codigo, profundidade + 1, tabela);
	}

	//se for uma folha
	if (r->esq == NULL && r->dir == NULL) {
		//escreve em codigo[c - 32] o codigo adequado
		for (int i = 0; i < profundidade; ++i) tabela[r->ch - 32][i] = aux_codigo[i];
		tabela[r->ch - 32][profundidade] = 2;
	}
}
void percorre_arvore(node *r, int **tabela) {
	int aux_codigo[TAMANHO_ALFABETO], profundidade = 0;
	percorre_arvore_rec(r, aux_codigo, profundidade, tabela);
}

//essa funcao recebe uma tabela de codigo e um caractere c
//e escreve em str o codigo binario de 'c' descrito pela tabela
void write_code(char *str, char c, int **tabela) {
	int i = c - 32;
	int j = 0;
	while (tabela[i][j] != 2) {
		char bit_string[2];
		sprintf(bit_string, "%d", tabela[i][j]);
		strcat(str, bit_string);
		j++;
	}
}

//************************* INICIO DO HEAP *******************************
typedef struct heapElement {
	float chave;
	void *no;
} heapElement;

typedef struct {
	int tamanho;
	heapElement *heap;
} filaPrioridade;

filaPrioridade *criar_fila_prioridade(int tamanho_maximo) {
	filaPrioridade *Q = (filaPrioridade *)malloc(sizeof(filaPrioridade));
	Q->heap = (heapElement *)calloc(tamanho_maximo + 1, sizeof(heapElement));
	Q->tamanho = 0;
	return Q;
}

void diminui_chave(int i, float chaveNova, heapElement *A) {
	heapElement x;
	if (chaveNova > A[i].chave) {
		printf("chaveNova maior que atual \n");
		return;
	}
	A[i].chave = chaveNova;
	while (i > 1 && A[i / 2].chave > A[i].chave) {
		x = A[i / 2];
		A[i / 2] = A[i];
		A[i] = x;
		i = i / 2;
	}
}

void insere_na_fila(filaPrioridade *Q, void *no, float chave) {
	Q->tamanho++;
	Q->heap[Q->tamanho].no = no;
	Q->heap[Q->tamanho].chave = INT_MAX;
	diminui_chave(Q->tamanho, chave, Q->heap);
}

void corrige_heap(int Esq, int Dir, heapElement *A) {
	int i = Esq;
	int j; heapElement x;
	j = i * 2;
	x = A[i];
	while (j <= Dir) {
		if (j < Dir)
			if (A[j].chave > A[j + 1].chave) j++;
		if (x.chave <= A[j].chave) break;
		A[i] = A[j]; i = j; j = i * 2;
	}
	A[i] = x;
}

void *extrai_min_fila_prioridade(filaPrioridade *Q) {
	int *n = &(Q->tamanho);
	heapElement Min;
	if (*n < 1)
		printf("Erro: heap vazio \n");
	else {
		Min = Q->heap[1];
		Q->heap[1] = Q->heap[*n];
		(*n)--;
		corrige_heap(1, *n, Q->heap);
	}
	return Min.no;
}
//**************************** FIM DO HEAP ********************************

int main(int argc, char *argv[]) {

	//  Primeiramente vamos ler a entrada e contabilizar a quantidade de cada caractere
	//a entrada serah salva no array entrada para depois fazer a codificacao
	char c;
	int count[TAMANHO_ALFABETO];
	char entrada[TAMANHO_MAX_ENTRADA];
	int tam_entrada = 0;

	//zerar a quantidade
	for (int i = 0; i < TAMANHO_ALFABETO; i++) count[i] = 0;

	//lendo a entrada
	scanf("%c", &c);

	//enquanto forem os caracteres validos continua lendo.
	//quando for um fim de texto, quebra de linha ou fim de arquivo, o loop se encerra tb
	while (c >= INICIO_ALFABETO && c <= INICIO_ALFABETO + TAMANHO_ALFABETO) {
		count[c - INICIO_ALFABETO]++;
		entrada[tam_entrada] = c;
		tam_entrada++;
		scanf("%c", &c);
	}


	filaPrioridade *Q = criar_fila_prioridade(TAMANHO_ALFABETO);

	//insere na fila os nos folhas com os caracteres
	for (int i = 0; i < TAMANHO_ALFABETO; i++) {
		if (count[i] > 0) {
			node *no = criar_node((char)i + INICIO_ALFABETO, count[i], NULL, NULL);
			//insere na fila os caracteres com a respectiva quantidade
			insere_na_fila(Q, no, no->chave);
		}
	}

	/* ************ Alterações feitas: ************ */

	while (Q->tamanho > 1) {
		node *leftLeaf = extrai_min_fila_prioridade(Q);
		node *rightLeaf = extrai_min_fila_prioridade(Q);

		node *mergedLeaf = criar_node(0, leftLeaf->chave + rightLeaf->chave, leftLeaf, rightLeaf);
		insere_na_fila(Q, mergedLeaf, mergedLeaf->chave);
	}

	node *arvore = extrai_min_fila_prioridade(Q);

	/* ************ Fim das alterações ************ */

	int **tabela = (int **)calloc(TAMANHO_ALFABETO, sizeof(int *));
	for (int i = 0; i < TAMANHO_ALFABETO; i++) {
		tabela[i] = (int *)calloc(TAMANHO_ALFABETO, sizeof(int));
		tabela[i][0] = 2;
	}

	percorre_arvore(arvore, tabela);

	//Escrevendo a string em binario
	char str[TAMANHO_MAX_ENTRADA * TAMANHO_ALFABETO];
	for (int i = 0; i < tam_entrada; ++i) {
		write_code(str, entrada[i], tabela);
	}

	//imprimindo o tamanho da string no final eh soh isso que vc precisa
	printf("%lld\n", strlen(str));

	return 0;
}
