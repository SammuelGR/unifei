#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>

#define STACK_SIZE 4 * 1024
#define MAX 10

int run(void *arg) {
    int n = *((int *)arg);

    printf("Processo %d: PID = %d encerrando...\n", n, gettid() );

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

    sleep(1);
    printf("Main: %d encerrando...\n", gettid() );

    return 0;
}
