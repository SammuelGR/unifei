/*
 * exercicio6.c
 *
 * Created on: 20 de out de 2025
 *
 * Authors:
 * MAT - NOME
 *
 * Cria um processo filho atraves de clone, e tenta alterar sua prioridade 
 * atraves do pai.
 */

#define _GNU_SOURCE
#include <errno.h>
#include <sched.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>

#define STACK_SIZE (64*1024)

static char CHILD_STACK[STACK_SIZE];

 static int filho(void *arg) {
    int prioridade;
    int *pfd = (int*)arg;
    char temp;

    if (close(pfd[1]) == -1)
        exit(2);

    errno = 0;
    prioridade = getpriority(PRIO_PROCESS, 0);

    if (prioridade == -1 && errno != 0)
        exit(1);

    printf("[FILHO] Prioridade antes: %d\n", prioridade);

    if (read(pfd[0], &temp, 1) == -1)
        exit(2);

    errno = 0;
    prioridade = getpriority(PRIO_PROCESS, 0);

    if (prioridade == -1 && errno != 0)
        exit(1);

    printf("[FILHO] Prioridade depois: %d\n", prioridade);

    return 0;
 }

int main(void) {
    pid_t child_pid;
    int pfd[2];

    if (pipe(pfd) == -1)
        exit(2);

    child_pid = clone(filho, CHILD_STACK + STACK_SIZE, 0, pfd);

    if (child_pid == -1)
        exit(3);

    if (close(pfd[0]) == -1)
        exit(2);

    printf("[PAI] Alterando prioridade do filho...\n");

    if (setpriority(PRIO_PROCESS, child_pid, 12) == -1)
        exit(1);

    if (write(pfd[1], "A", 1) == -1)
        exit(2);

    return 0;
}
