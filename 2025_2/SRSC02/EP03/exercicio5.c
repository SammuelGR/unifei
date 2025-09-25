/*
 * exercicio5.c
 *
 * Created on: 22 de set de 2025
 *
 * Uma thread invoca a funcao clone()
 *
 */
#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sched.h>

#define STACK_SIZE (64*1024)
#define CL_FLAGS (CLONE_VM | CLONE_SIGHAND | CLONE_FS | CLONE_FILES | CLONE_THREAD)

static char CHILD_STACK[STACK_SIZE];

static int filho(void *arg) {
    printf("clone: filho executando\n");
    return 0;
}

void *OLA(void *argumentos) {
    if (clone(filho, CHILD_STACK + STACK_SIZE, CL_FLAGS, NULL) == -1) {
        perror("clone");
    }
    sleep(1);
    return NULL;
}

int main(void) {
    pthread_t t;

    pthread_create(&t, NULL, OLA, NULL);
    pthread_join(t, NULL);

    return 0;
}
