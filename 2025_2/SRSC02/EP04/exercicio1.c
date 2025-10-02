/*
 * exercicio1.c
 *
 * Created on: 29 de set de 2025
 *
 *
 * Aproxima pi pela soma de retangulos: integral 0..1 de 4/(1+x^2) dx
 * Divide a soma em 'n' partes entre 'T' threads
 */

#include <stdio.h>
#include <pthread.h>

#define QTD_THREADS 8
#define QTD_RETANGULOS 1000000000

 /* Variaveis globais para simplicidade */
double largura_retangulo;
double somas_parciais[QTD_THREADS];

void *calcula_soma(void *arg) {
    int tid = *(int *)arg;
    double soma_atual = 0.0;

    /* intervalo desta thread */
    long long bloco = QTD_RETANGULOS / QTD_THREADS;
    long long inicio = tid * bloco;
    long long fim = (tid == QTD_THREADS - 1) ? QTD_RETANGULOS : (inicio + bloco);

    for (long long i = inicio; i < fim; i++) {
        double x = (i + 0.5) * largura_retangulo;
        soma_atual += 4.0 / (1.0 + x * x);
    }

    somas_parciais[tid] = soma_atual;

    return NULL;
}

int main(void) {
    int i;

    double soma_total = 0.0;
    double pi = 0;

    // propaga para a variavel global usada pelas threads
    largura_retangulo = 1.0 / (double)QTD_RETANGULOS;

    pthread_t threads[QTD_THREADS];
    int ids[QTD_THREADS];

    for (i = 0; i < QTD_THREADS; i++) {
        ids[i] = i;

        pthread_create(&threads[i], NULL, calcula_soma, &ids[i]);
    }

    for (i = 0; i < QTD_THREADS; i++)
        pthread_join(threads[i], NULL);

    for (i = 0; i < QTD_THREADS; i++)
        soma_total += somas_parciais[i];

    pi = largura_retangulo * soma_total;
    printf("pi = %f\n", pi);

    printf("Qtd threads: %d\n", QTD_THREADS);
    return 0;
}
