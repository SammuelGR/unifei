/*
 * exercicio11.c
 *
 * Created on: 20 de out de 2025
 *
 * Authors:
 * MAT - NOME
 *
 * Cria 10 processos via clone com escalonador em SCHED_RR e atribui
 * prioridades distintas a cada um.
 */

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

#define STACK_SIZE 4 * 1024
#define MAX 10

int run(void *arg) {
    struct sched_param sp;
    int n = *((int *)arg);

    sp.sched_priority = n;

    if (sched_setparam(0, &sp) == -1) {
        exit(3);
    }

    printf("Processo %d: PID = %d encerrando...\n", n, getpid() );

    return 0;
}

int main(void) {
    struct sched_param sp;
    int i, ret, *pi;
    void *stack;

    sp.sched_priority = 3;

    ret = sched_setscheduler(0, SCHED_RR, &sp);
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

    sleep(1);
    printf("Main: %d encerrando...\n", getpid() );

    return 0;
}