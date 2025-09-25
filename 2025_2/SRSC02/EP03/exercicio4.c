/*
 * exercicio4.c
 *
 * Created on: 22 de set de 2025
 *
 * Uma thread invoca a funcao fork()
 *
 */

#include <stdio.h> /* standard I/O routines */
#include <unistd.h> /* unix standard routines */
#include <pthread.h> /* pthread functions and data structures */

 /* function to be executed by the new thread */
void *OLA(void *argumentos) {
    pid_t pid;

    pid = fork();

    if (pid == 0) {
        printf("Processo filho!\n");
    } else {
        printf("Processo pai!\n");
    }

    return NULL;
}

int main(void) {
    pthread_t thread;
    int flag;

    printf("A criar uma nova thread\n");

    flag = pthread_create(&thread, NULL, OLA, NULL);
    if (flag != 0) printf("Erro na criação duma nova thread\n");

    pthread_join(thread, NULL); // Aguarda finalização da thread

    return 0;
}
