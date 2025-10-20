/*
 * exercicio12.c
 *
 * Created on: 20 de out de 2025
 *
 * Authors:
 * MAT - NOME
 *
 * Cria 10 processos via clone com escalonador em SCHED_FIFO e SCHED_OTHER e
 * atribui prioridades distintas a cada um.
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sched.h>
#include <unistd.h>

#define STACK_SIZE 4 * 1024
#define MAX 10

int run(void *arg) {
    struct sched_param sp;
    char sched_type[6];
    int n = *((int *)arg);

    if (n <= MAX) {
        strcpy(sched_type, "FIFO");
    } else {
        strcpy(sched_type, "OTHER");
    }

    sp.sched_priority = n;

    if (sched_setparam(0, &sp) == -1) {
        exit(3);
    }

    printf("Processo %d (%s): PID = %d encerrando...\n", n, sched_type, getpid());

    return 0;
}

int main(void) {
    struct sched_param sp;
    int i, ret, *pi;
    void *stack;

    sp.sched_priority = 3;

    ret = sched_setscheduler(0, SCHED_FIFO, &sp);
    if (ret == -1) {
        fprintf(stderr, "sched_setscheduler() falhou...\n");
        exit(1);
    }

    for (i = 1; i <= MAX; i++) {
        pi = malloc(sizeof(int *));
        *pi = i;
        stack = malloc(STACK_SIZE);

        ret = clone(&run, (char*)stack + STACK_SIZE, 0, (void *)pi);
    }

    ret = sched_setscheduler(0, SCHED_OTHER, &sp);
    if (ret == -1) {
        fprintf(stderr, "sched_setscheduler() falhou...\n");
        exit(1);
    }

    for (i = (MAX + 1); i <= (MAX * 2); i++) {
        pi = malloc(sizeof(int *));
        *pi = i;
        stack = malloc(STACK_SIZE);

        ret = clone(&run, (char*)stack + STACK_SIZE, 0, (void *)pi);
    }

    sleep(1);
    printf("Main: %d encerrando...\n", getpid() );

    return 0;
}