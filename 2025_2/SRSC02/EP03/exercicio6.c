/*
 * exercicio6.c
 *
 * Created on: 22 de set de 2025
 *
 * Uma thread invoca uma funcao exec
 *
 */
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *OLA(void *argumentos) {
    printf("Thread: chamando exec()\n");
    execlp("echo", "echo", "exec rodou (processo substituido)", NULL);
    perror("exec");
    return NULL;
}

int main(void) {
    pthread_t t;
    pthread_create(&t, NULL, OLA, NULL);
    pthread_join(t, NULL); /* Se exec() funcionar, esse join nao executa */
    return 0;
}
