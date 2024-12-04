#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>

//  Vamos considerar que o nosso alfabeto tem os caracteres da tabela ascii
//do 32 até o 126, portanto 95 caracteres diferentes 
#define TAMANHO_ALFABETO 95
//  O INICIO_ALFABETO serah usado para encontrar um deslocamento dos caracteres
//para que correspondam a um valor entre 0 e TAMANHO_ALFABETO - 1
//por exemplo o espa'co que tem valor 32 na tabela ascii sera considerado 0
#define INICIO_ALFABETO 32
//  Para simplificar, vamos considerar que a entrada tem no maximo 5000 caracteres
#define TAMANHO_MAX_ENTRADA 5000


typedef struct node{
  char ch;
  float chave;
  struct node * esq;
  struct node * dir;
} node;

node * criar_node(char ch, float chave, node * esq, node * dir){
    node * no = (node *) malloc(sizeof(node));
    no->ch = ch;
    no->chave = chave;
    no->esq = esq;
    no->dir = dir;
    return no;
}

//  Funcoes para imprimir a arvore em formato graphViz
//pode visualizar em uma plataforma online como https://dreampuf.github.io/GraphvizOnline
int print_tree_rec(node * r, int * node_num){
    if (r == NULL) return -1;
    int my_number = *node_num;
    printf("  %d[label=\"%c\"];\n", my_number, r->ch);
    (*node_num)++;
    int esq = print_tree_rec(r->esq, node_num);
    (*node_num)++;
    int dir = print_tree_rec(r->dir, node_num);
    if(esq != -1) printf("  %d -> %d;\n", my_number, esq);
    if(dir != -1) printf("  %d -> %d;\n", my_number, dir);
    return my_number;
}
void print_tree(node * r){
    if (r == NULL) return;
    printf("digraph G{\n  graph [ordering=\"out\"];\n");
    int num_node = 0;
    print_tree_rec(r, &num_node);
    printf("}\n");
    return;
}

//As duas funcoes abaixo recebem uma arvore e uma tabela onde sera escrito o codigo de 
//cada caractere presente na arvore
void percorre_arvore_rec(node * r, int * aux_codigo, int profundidade, int ** tabela) { 
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
void percorre_arvore(node * r, int ** tabela){
    int aux_codigo[TAMANHO_ALFABETO], profundidade = 0; 
    percorre_arvore_rec(r, aux_codigo, profundidade, tabela);
}

//essa funcao recebe uma tabela de codigo e um caractere c
//e escreve em str o codigo binario de 'c' descrito pela tabela
void write_code(char * str, char c, int ** tabela){
    int i = c - 32;
    int j = 0;
    while(tabela[i][j] != 2){
        char bit_string[2];
        sprintf(bit_string, "%d", tabela[i][j]);
        strcat(str, bit_string);
        j++;
    }
}



//************************* INICIO DO HEAP *******************************
// Normalmente isso deveria ser uma TAD em arquivos separados, mas para simplificar
//deixei aqui mesmo. Minha sugestao eh naum se preocupar demais com ela, mas entender
//o uso do criar_fila_prioridade, insere_na_fila e extrai_min_fila_prioridade
//Isso deve ser suficiente para usar a fila de prioridade
typedef struct heapElement{
  float chave;
  void * no;
} heapElement;

typedef struct{
    int tamanho;
    heapElement * heap;
} filaPrioridade;

filaPrioridade * criar_fila_prioridade(int tamanho_maximo){
    filaPrioridade * Q = (filaPrioridade *) malloc(sizeof(filaPrioridade));
    Q->heap = (heapElement *) calloc(tamanho_maximo + 1, sizeof(heapElement));
    Q->tamanho = 0;
    return Q;
}

void diminui_chave(int i, float chaveNova, heapElement *A){ 
  heapElement x;
  if(chaveNova > A[i].chave){ 
    printf("chaveNova maior que atual \n");
    return;
  }
  A[i].chave = chaveNova;
  while(i > 1 && A[i/2].chave > A[i].chave){ 
    x = A[i/2]; 
    A[i/2] = A[i]; 
    A[i] = x;
    i = i/2;
  }
}

void insere_na_fila (filaPrioridade * Q, void * no, float chave){
  Q->tamanho++;
  Q->heap[Q->tamanho].no = no; 
  Q->heap[Q->tamanho].chave = INT_MAX;
  diminui_chave(Q->tamanho, chave,  Q->heap);
}

void corrige_heap(int Esq, int Dir, heapElement *A){ 
  int i = Esq;
  int j; heapElement x;
  j = i * 2;
  x = A[i];
  while (j <= Dir){ 
    if (j < Dir)
      if (A[j].chave > A[j+1].chave) j++;
    if (x.chave <= A[j].chave) break;
    A[i] = A[j]; i = j; j = i*2;
  }
  A[i] = x;
}

void * extrai_min_fila_prioridade(filaPrioridade * Q){ 
  int * n =  &(Q->tamanho); 
  heapElement Min;
  if (*n < 1)
    printf("Erro: heap vazio \n" );
  else{ 
    Min = Q->heap[1]; 
    Q->heap[1] = Q->heap[*n]; 
    (*n)--;
    corrige_heap(1, *n, Q->heap);
  }
  return Min.no;
}
//**************************** FIM DO HEAP ********************************




int main(int argc, char * argv[]){

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
    while(c >= INICIO_ALFABETO && c <= INICIO_ALFABETO + TAMANHO_ALFABETO){
        count[c - INICIO_ALFABETO]++;
        entrada[tam_entrada] = c;
        tam_entrada++;
        scanf("%c", &c);
    }

    //impressao do contador para verificacao
    /*
    for (int i = 0; i < TAMANHO_ALFABETO; i++){
        if (count[i] > 0){
            printf("count[%c] = %d\n", (char) i+32, count[i]);
        }
    }
    */

    filaPrioridade * Q = criar_fila_prioridade(TAMANHO_ALFABETO);

    //insere na fila os nos folhas com os caracteres
    for (int i = 0; i < TAMANHO_ALFABETO; i++){
        if (count[i] > 0){
            node * no = criar_node((char) i + INICIO_ALFABETO, count[i], NULL, NULL);
            //insere na fila os caracteres com a respectiva quantidade
            insere_na_fila(Q, no, no->chave);
        }
    }



    //************************************************************************
    //************************************************************************
    // TODO: ESSA PARTE ABAIXO VOCE VAI PRECISAR REMOVER, E COLOCAR O CODIGO CERTO
    //************************************************************************
    //************************************************************************


    //se voce quiser pegar o node com a menor frequencia
    node * no_menos_frequente = (node*) extrai_min_fila_prioridade(Q);
    //se precisar, voce pode acessar o tamanho da arvore com Q->tamanho
    
    //vou criar uma arvore aleatoria aqui com os caracteres espaco, a, b, c, n 
    // minha arvore aleatoria eh assim, obviamente a otima eh diferente 
    /*
            raiz
          /      \  
         /        \
        /\        /\
       /  \      /  \
     ' '  'a'  'b'   \
                     /\
                    /  \
                  'c'  'n'
    */
    
    node * no_n   = criar_node('n', count['n' - INICIO_ALFABETO], NULL, NULL);
    node * no_c   = criar_node('c', count['c' - INICIO_ALFABETO], NULL, NULL);
    node * no_b   = criar_node('b', count['b' - INICIO_ALFABETO], NULL, NULL);
    node * no_a   = criar_node('a', count['a' - INICIO_ALFABETO], NULL, NULL);
    node * no_es  = criar_node(' ', count[' ' - INICIO_ALFABETO], NULL, NULL);
    node * no_cn  = criar_node(  0,     no_c->chave + no_n->chave, no_c,  no_n);
    node * no_bcn = criar_node(  0,    no_b->chave + no_cn->chave, no_b, no_cn);
    node * no_esa = criar_node(  0,    no_es->chave + no_a->chave, no_es, no_a);
    node * arvore = criar_node(  0, no_esa->chave + no_bcn->chave, no_esa, no_bcn);

    //************************************************************************ 
    //REMOVA ATE AQUI
    //**************************************************************************




    //imprimir a arvore para teste (comente no final)
    print_tree(arvore); printf("\n");

    //caracteres simples na tabela ascii tem valores entre 32 ateh 126
    //ou seja existem 95 caracteres validos e no pior caso essa eh a altura da ahrvore
    //  Se vc fosse fazer uma implementacao real, talvez aqui vc precisaria manipular bits
    //aqui, com objetivo didatico vamos fazer um arranjo de int mesmo.
    int ** tabela = (int**) calloc(TAMANHO_ALFABETO,  sizeof(int *));
    for(int i = 0; i < TAMANHO_ALFABETO; i++){
        tabela[i] = (int*) calloc(TAMANHO_ALFABETO, sizeof(int));
        tabela[i][0] = 2;
    }
    
    percorre_arvore(arvore, tabela);

    //impressao do codigo para verificacao, comente no final, (comente no final)
    for (int i = 0; i < TAMANHO_ALFABETO; ++i) {
        printf("%c: ", (char) i + 32);
        int j = 0;
        while(tabela[i][j] != 2){
            printf("%d", tabela[i][j]);
            j++;
        }
        printf("\n");
    }
    for (int i = 0; i < tam_entrada; ++i) {
        printf("%c", entrada[i]);
    }
    printf("\n");
   

    
    //Escrevendo a string em binario
    char str[TAMANHO_MAX_ENTRADA*TAMANHO_ALFABETO];
    for (int i = 0; i < tam_entrada; ++i) {
        write_code(str, entrada[i], tabela);
    }

    //impressao da string em binario para conferencia (comente no final)
    printf("\n%s\n", str);

    //imprimindo o tamanho da string no final eh soh isso que vc precisa
    printf("%ld\n", strlen(str));

    return 0;
}
