/*
 * exercicio1.c
 *
 * Created on: 29 de set de 2025
 *
 * Calcula pi atraves de paralelismo com OpenMP
 */

#include <stdio.h>
#include <omp.h>

#define NUM_THREADS 8

static long num_steps = 1000000;
double step;

int main(void) {
    int i;
    double pi, total_sum = 0.0;
    double partial_sum[NUM_THREADS];

    step = 1.0 / (double)num_steps;

    #pragma omp parallel num_threads(NUM_THREADS)
    {
        int tid = omp_get_thread_num();
        double current_sum = 0.0, x;

        long j;
        long step_size = (num_steps / NUM_THREADS); // Tamanho do intervalo de cada thread
        long start_interval = tid * step_size;
        long end_interval = (tid == NUM_THREADS - 1) ? num_steps : start_interval + step_size;

        for (j = start_interval; j < end_interval; j++) {
            x = (j + 0.5) * step; // Largura do retangulo
            current_sum = current_sum + 4.0 / (1.0 + x * x); // Sum += Area do retangulo
        }
        partial_sum[tid] = current_sum;
    }

    for (i = 0; i < NUM_THREADS; i++) {
        total_sum += partial_sum[i];
    }

    pi = step * total_sum;

    printf("Qtd threads: %d\n", NUM_THREADS);
    printf("%lf\n", pi);

    return 0;
}
