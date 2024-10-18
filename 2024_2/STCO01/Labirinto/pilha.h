typedef struct pilhaa *pilha;

//comentario
pilha criar_pilha();

//comentario (push)
void empilhar(pilha P, int x, int y);

//comentario (pop)
void desempilhar(pilha P, int *x, int *y);

//comentario
int pilha_vazia(pilha P);

//comentario
void liberar_pilha(pilha P);
