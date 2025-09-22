/*
 * aula08_ex08.c
 *
 * Copyright 2023 Carlos Minoru Tamaki <minoru@minoru-nitroan51551>
 *
 */
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

#define NUM_THREADS 5

int saldo = 1000;

void *AtualizaSaldo(void *threadid) {
   int meu_saldo = saldo;
   int novo_saldo = meu_saldo + (long long)threadid * 100;
   printf("Novo saldo = %d\n", novo_saldo);
   saldo = novo_saldo;
   pthread_exit(NULL);

   return NULL;
}

int main(int argc, char *argv[]) {
   pthread_t threads[NUM_THREADS];
   int rc;
   long t;

   for (t = 0; t < NUM_THREADS; t++) {
      rc = pthread_create(&threads[t], NULL, AtualizaSaldo, (void *)(long long)(t + 1));
      if (rc) exit(-1);
   }

   for (t = 0; t < NUM_THREADS; t++)
      pthread_join(threads[t], NULL);

   printf("Saldo final = %d\n", saldo);
}
