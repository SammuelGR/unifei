/*
 * exercicio1.c
 *
 * Created on: 03 de nov de 2025
 *
 * Authors:
 *
 * Cria duas threas, onde cada uma incrementa 1000 de um contador compartilhado
 *
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 2

pthread_mutex_t meu_mutex = PTHREAD_MUTEX_INITIALIZER;

int contadorSimples = 0;
int contadorMutex = 0;

void *Contador(void *args) {
	int i;

	for (i = 0; i < 1000; i++) {
		contadorSimples++;
	}

	for (i = 0; i < 1000; i++) {
		pthread_mutex_lock(&meu_mutex);
		contadorMutex++;
		pthread_mutex_unlock(&meu_mutex);
	}

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
	printf("Contador com mutex = %d\n", contadorMutex);
	printf("Contador sem mutex = %d\n", contadorSimples);

	return 0;
}
