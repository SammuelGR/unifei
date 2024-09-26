typedef struct filaa *fila;

// Funcao para criar uma fila e retornar a fila criada.
fila criar_fila(void);

// Insere um inteiro numa fila passada por parametro.
void insere_fila(fila, int);

// Remove um item da fila e retorna o item removido.
int remover_fila(fila);

// Esvazia a fila e libera a memoria alocada.
void liberar_fila(fila);

// Indica se a fila esta vazia ou nao.
int fila_vazia(fila f);
