/*
 * aula08_ex03.c
 *
 * Copyright 2023 Carlos Minoru Tamaki <minoru@minoru-nitroan51551>
 *
 */
#include <stdio.h>
#include <unistd.h> /* unix standard routines */
#include <pthread.h> /* pthread functions and data structures */

void *funcao(void *argumentos) {
    int valor = *(int *)argumentos;

    printf("recebi um inteiro: %d \n", valor);

    pthread_exit(NULL);

    return (NULL);
}

int main(void) {
    pthread_t thread;
    int x = 5; // Passagem de um valor inteiro
    int flag;

    // chamada da thread
    flag = pthread_create(&thread, NULL, funcao, (void *)&x);
    if (flag) exit(-1);

    pthread_join(thread, NULL);

    return 0;
}
