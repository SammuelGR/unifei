typedef struct pilhaa *pilha;

pilha criar_pilha(void);

void empilhar(pilha P, char C);

char desempilhar(pilha P);

int pilha_vazia(pilha P);

void liberar_pilha(pilha P);
