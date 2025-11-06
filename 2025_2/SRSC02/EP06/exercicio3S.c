/*
 * exercicio3.c
 *
 * Created on: 03 de nov de 2025
 *
 * Authors:
 *
 * Simular atendimento bancário com duas filas (preferencial e normal) e dois
 * caixas usando threads, mutexes e semaforos.
 */

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define NUM_CAIXAS 2
#define NUM_CLIENTES 20

pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_caixa = PTHREAD_COND_INITIALIZER;

int clientes_pref = 0;
int clientes_normal = 0;
int atendidos = 0;

void *Caixa(void *arg) {
    long cx = (long)arg;

    while (1) {
        pthread_mutex_lock(&m);

        while (clientes_pref == 0 && clientes_normal == 0 && atendidos < NUM_CLIENTES)
            pthread_cond_wait(&cond_caixa, &m);

        if (atendidos >= NUM_CLIENTES && clientes_pref == 0 && clientes_normal == 0) {
            pthread_mutex_unlock(&m);
            break;
        }

        int pref;
        if (clientes_pref > 0) {
            clientes_pref--;
            pref = 1;
        } else {
            clientes_normal--;
            pref = 0;
        }

        atendidos++;
        pthread_mutex_unlock(&m);

        int tempo = (rand() % 3) + 1;
        printf("Caixa %ld atendeu cliente (%c) em %ds\n", cx, pref ? 'P' : 'N', tempo);
        sleep(tempo);
    }

    return NULL;
}

void *Cliente(void *arg) {
    int pref = (rand() % 100) >= 60;

    pthread_mutex_lock(&m);
    if (pref)
        clientes_pref++;
    else
        clientes_normal++;

    pthread_cond_signal(&cond_caixa);
    pthread_mutex_unlock(&m);

    return NULL;
}

int main(void) {
    pthread_t caixas[NUM_CAIXAS], clientes[NUM_CLIENTES];
    long i;

    srand(time(NULL));

    for (i = 1; i <= NUM_CAIXAS; i++)
        pthread_create(&caixas[i - 1], NULL, Caixa, (void *)i);

    for (i = 0; i < NUM_CLIENTES; i++)
        pthread_create(&clientes[i], NULL, Cliente, NULL);

    for (i = 0; i < NUM_CLIENTES; i++)
        pthread_join(clientes[i], NULL);

    pthread_mutex_lock(&m);
    pthread_cond_broadcast(&cond_caixa);
    pthread_mutex_unlock(&m);

    for (i = 0; i < NUM_CAIXAS; i++)
        pthread_join(caixas[i], NULL);

    printf("Atendimentos encerrados.\n");
    return 0;
}
