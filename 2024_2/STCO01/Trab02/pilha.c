#include<stdlib.h>
#include<stdio.h>
#include "pilha.h"


typedef struct telemento{
  int dado;
  struct telemento* prox;
}elemento;

struct tpilha{
  elemento * inicio;
};

pilha cria_pilha(){
  pilha P = (pilha) malloc(sizeof(struct tpilha));
  P->inicio = NULL;
  return P;
}

void empilhar(pilha P, int c){
  if(P == NULL){
    fprintf(stderr, "ERRO: Na funcao empilhar. Pilha nao alocada!\n");
    exit(-1);
  }
  elemento * E = (elemento*) malloc(sizeof(elemento));
  E->dado = c;
  E->prox = P->inicio;
  P->inicio = E;
  return;
}

int desempilhar(pilha P){
  if(P == NULL || P->inicio == NULL){
    fprintf(stderr, "ERRO: Tentando desempilhar de uma pilha vazia!\n");
    exit(-1);
  }
  //cabeca guarda o inicio da pilha
  elemento * cabeca = P->inicio;
  int resultado = cabeca->dado;
  //o inicio da pilha passa agora a ser o segundo elemento (pode ser NULL)
  P->inicio = cabeca->prox;
  //libera o antigo inicio da fila e devolve o topo da pilha
  free(cabeca);
  return resultado;
}

int pilha_vazia(pilha P){
  if(P == NULL){
    fprintf(stderr, "ERRO: Na funcao pilha_vazia. Pilha nao alocada!\n");
    exit(-1);
  }
  if(P->inicio == NULL) return 1;
  return 0;
}

void libera_lista(elemento * e){
 if(e == NULL) return;
 libera_lista(e->prox);
 free(e);
}

void libera_pilha(pilha P){
  libera_lista(P->inicio);
  free(P);
}



