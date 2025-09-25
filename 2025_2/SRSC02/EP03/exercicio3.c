/*
 * exercicio3.c
 *
 * Created on: 22 de set de 2025
 *
 * Criacao de uma thread, onde a main eh finalizada antes da thread
 *
 */
#include <stdio.h> /* standard I/O routines */
#include <unistd.h> /* unix standard routines */
#include <pthread.h> /* pthread functions and data structures */

void *OLA(void *argumentos) {
    printf("\nThread iniciada\n");

    sleep(5); // Aguarda a finalizacao da main()

    printf("\nThread finaliza execucao\n");
    return NULL;
}

int main(void) {
    pthread_t thread;
    int flag;

    printf("A criar uma nova thread\n");

    flag = pthread_create(&thread, NULL, OLA, NULL);
    if (flag != 0) printf("Erro na criação duma nova thread\n");

    printf("Programa principal encerrado\n");

    return 0;
}
