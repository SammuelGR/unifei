/*
 * exercicio14.c
 *
 * Created on: 22 de set de 2025
 *
 * Declara um vetor de 20 inteiros aleatorios e cria duas threads
 * Uma thread computa a média dos elementos
 * Outra thread computa o desvio padrao dos elementos
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <pthread.h>

#define N 20

 /* Vetor e resultados globais para manter a simplicidade */
int v[N];
double media_result = 0.0;
double desvio_result = 0.0;

void *calc_media(void *arg) {
    long long soma = 0;
    int i;

    for (i = 0; i < N; i++) soma += v[i];

    media_result = (double)soma / N;

    return NULL;
}

void *calc_desvio(void *arg) {
    /* usa a media_result já calculada */
    double m = media_result;
    double acc = 0.0;
    int i;

    for (i = 0; i < N; i++) {
        double d = v[i] - m;
        acc += d * d;
    }
    desvio_result = sqrt(acc / N);  /* desvio padrão populacional */
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

    /* calcula média */
    pthread_create(&t1, NULL, calc_media, NULL);
    pthread_join(t1, NULL);

    /* calcula desvio padrão usando a média já disponível */
    pthread_create(&t2, NULL, calc_desvio, NULL);
    pthread_join(t2, NULL);

    /* imprime respostas */
    printf("Media: %.2f\n", media_result);
    printf("Desvio padrao: %.4f\n", desvio_result);

    return 0;
}
