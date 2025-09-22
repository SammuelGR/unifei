/*
 * exercicio2.c
 *
 *  Created on: 8 de set de 2025
 *
 * Criação de dois processos irmãos, filhos do mesmo processo pai
 *
 */

#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t p1, p2 = 0;

    p1 = fork();

    if (p1 == 0) {
        printf("apenas p1 - %d\n", getpid());
        printf("pid pai p1 %d\n", getppid());

    } else {
        p2 = fork();

        if (p2 == 0 && p1 != 0) {
            printf("apenas p2 - %d\n", getpid());
            printf("pid pai p2 %d\n", getppid());

        } else if (p2 != 0 && p1 != 0) {
            printf("apenas processo pai %d\n", getpid());
        }
    }

    // printf("executa para todos\n");

    return 0;
}
