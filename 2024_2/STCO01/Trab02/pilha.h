//Definicao do tipo pilha
typedef struct tpilha * pilha;

//Cria uma pilha vazia
pilha cria_pilha();

//Recebe uma pilha e um inteiro
void empilhar(pilha P, int c);

//devolve o inteiro no topo da pilha
int desempilhar(pilha P);

//devolve 1 se a pilha estiver vazia, 0 caso contrario
int pilha_vazia(pilha P);

//funcao que libera toda memoria alocada na pilha, incluindo elementos que ainda
//possam ter ficado nela.
void libera_pilha(pilha P);

