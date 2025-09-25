/*
 * exercicio13.c
 *
 * Created on: 22 de set de 2025
 *
 * Utiliza duas threads para trabalhar com 20 numeros aleatorios
 * Uma thread calcula a media dos valores, a outra thread calcula a mediana
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define N 20

int v[N];
double media_result = 0.0;
double mediana_result = 0.0;

int cmp_int(const void *a, const void *b) {
    return (*(const int *)a - *(const int *)b);
}

void *calc_media(void *arg) {
    long long soma = 0;
    int i;

    for (i = 0; i < N; i++) soma += v[i];

    media_result = (double)soma / N;

    return NULL;
}

void *calc_mediana(void *arg) {
    int copia[N];
    int i;

    /* copia para evitar alterar o vetor original (outra thread pode estar lendo) */
    for (i = 0; i < N; i++) copia[i] = v[i];

    qsort(copia, N, sizeof(int), cmp_int);

    if (N % 2 == 0) {
        mediana_result = (copia[N / 2 - 1] + copia[N / 2]) / 2.0;
    } else {
        mediana_result = copia[N / 2];
    }
    return NULL;
}

int main(void) {
    pthread_t t1, t2;
    int i;

    /* gera valores aleatórios */
    srand((unsigned)time(NULL));
    for (i = 0; i < N; i++) {
        v[i] = rand() % 100;  /* 0..99 */
    }

    /* cria threads */
    pthread_create(&t1, NULL, calc_media, NULL);
    pthread_create(&t2, NULL, calc_mediana, NULL);

    /* aguarda terminar */
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    /* imprime respostas */
    printf("Media: %.2f\n", media_result);
    printf("Mediana: %.2f\n", mediana_result);

    return 0;
}
