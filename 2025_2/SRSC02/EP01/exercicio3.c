/*
 * exercicio3.c
 *
 *  Created on: 8 de set de 2025
 *
 * Criação de três processos em cadeia, onde um processo é filho do outro
 *
 */

#include <unistd.h>
#include <stdio.h>

int main(void) {
    pid_t p1;

    p1 = fork();

    if (p1 == 0) {
        printf("ID Processo 1 - %d\n", getpid());
        printf("PID pai p1 %d\n", getppid());

        pid_t p2 = fork();

        if (p2 == 0) {
            printf("ID Processo 2 - %d\n", getpid());
            printf("PID pai p2 %d\n", getppid());

            pid_t p3 = fork();

            if (p3 == 0) {
                printf("ID Processo 3 - %d\n", getpid());
                printf("PID pai p3 %d\n", getppid());
            }
        }

    } else {
        printf("Apenas processo pai %d\n", getpid());
    }

    return 0;
}
