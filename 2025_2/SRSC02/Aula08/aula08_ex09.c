/*
 * aula08_ex09.c
 *
 * Copyright 2023 Carlos Minoru Tamaki <minoru@minoru-nitroan51551>
 *
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

pthread_mutex_t meu_mutex = PTHREAD_MUTEX_INITIALIZER;

int saldo = 1000;

void *AtualizaSaldo(void *threadid) {
   pthread_mutex_lock(&meu_mutex);
   saldo = saldo + (long long)threadid * 100;
   printf("Novo saldo = %d\n", saldo);
   pthread_mutex_unlock(&meu_mutex);
   pthread_exit(NULL);

   return NULL;
}

int main(int argc, char *argv[]) {
   pthread_t threads[NUM_THREADS];
   long t;

   for (t = 0; t < NUM_THREADS; t++)
      pthread_create(&threads[t], NULL, AtualizaSaldo, (void *)(long long)(t + 1));

   for (t = 0; t < NUM_THREADS; t++)
      pthread_join(threads[t], NULL);

   printf("Saldo final = %d\n", saldo);
}
