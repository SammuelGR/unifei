/*
 * aula08_ex05.c
 *
 * Copyright 2023 Carlos Minoru Tamaki <minoru@minoru-nitroan51551>
 *
 */
#include <stdio.h>
#include <unistd.h> /* unix standard routines */
#include <pthread.h> /* pthread functions and data structures */

typedef struct { int a; float b; } ST;

void *funcao(void *argumentos) {
    ST *in = (ST *)argumentos;
    printf("recebi dois valores: %d %f ", in->a, in->b);

    return NULL;
}

int main(void) {
    int x = 5;
    float y = 2.5;
    ST v;
    v.a = x; v.b = y;

    pthread_t thread;

    // Passagem de múltiplos parâmetros usando uma estrutura
    pthread_create(&thread, NULL, funcao, (void *)&v);

    pthread_join(thread, NULL);

    return 0;
}