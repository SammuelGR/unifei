/*
 * aula08_ex07.c
 *
 * Copyright 2023 Carlos Minoru Tamaki <minoru@minoru-nitroan51551>
 *
 */
#include <stdio.h>
#include <unistd.h> /* unix standard routines */
#include <pthread.h> /* pthread functions and data structures */

#define NUM_THREADS 5

void *funcao(void *args) {
   int x = *(int *)args;
   printf("Thread %d\n", x);
   return (NULL);
}

int main() {
   pthread_t threads[NUM_THREADS];
   int i, ids[NUM_THREADS];
   for (i = 0; i < NUM_THREADS; i++) ids[i] = i;

   for (i = 0;i < NUM_THREADS;i++)
      pthread_create(&threads[i], NULL, funcao, &ids[i]);

   for (i = 0;i < NUM_THREADS;i++) pthread_join(threads[i], NULL);

}
