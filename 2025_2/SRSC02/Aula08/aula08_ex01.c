/*
 * aula08_ex01.c
 *
 * Copyright 2023 Carlos Minoru Tamaki <minoru@minoru-nitroan51551>
 *
 */
#include <stdio.h> /* standard I/O routines */
#include <unistd.h> /* unix standard routines */
#include <pthread.h> /* pthread functions and data structures */
 /* function to be executed by the new thread */
void *OLA(void *argumentos) {
    printf("\nOla\n");
    pthread_exit(NULL);

    return NULL;
}

int main() {
    pthread_t thread;
    int flag;

    printf("A criar uma nova thread\n");

    flag = pthread_create(&thread, NULL, OLA, NULL);
    if (flag != 0) printf("Erro na criação duma nova thread\n");

    sleep(2);

    return 0;
}
