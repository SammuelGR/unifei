/*
 * exercicio2.c
 *
 * Created on: 03 de nov de 2025
 *
 * Authors:
 *
 * Cria tres threads que aguardam uma barreira para finalizar sua execucao.
 *
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 3

pthread_mutex_t meu_mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t barreira = PTHREAD_COND_INITIALIZER;

int contador = 0; // quantas threads estao prontas
int pronto = 0; // flag para avisar se pode prosseguir

void *Contador(void *args) {
    pthread_mutex_lock(&meu_mutex);
    contador++;

    if (contador == NUM_THREADS) {
        pronto = 1;
        pthread_cond_broadcast(&barreira); // todos threads prontos, libera barreira
    } else {
        while (!pronto) {
            pthread_cond_wait(&barreira, &meu_mutex); // aguarda outros threads ficarem prontos
        }
    }

    pthread_mutex_unlock(&meu_mutex);

    printf("Pronto!\n");

    pthread_exit(NULL);
    return NULL;
}

int main(void) {
    pthread_t threads[NUM_THREADS];
    int i;

    for (i = 0; i < NUM_THREADS; i++)
        pthread_create(&threads[i], NULL, Contador, NULL);

    for (i = 0; i < NUM_THREADS; i++)
        pthread_join(threads[i], NULL);

    printf("Threads finalizadas.\n");

    return 0;
}
