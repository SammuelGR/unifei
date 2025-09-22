/*
 * exercicio12.c
 *
 *  Created on: 8 de set de 2025
 *
 * Criação de dois processos filhos, onde o pai aguarda sua finalização
 *
 */

#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

int main(void) {
    pid_t p1, p2 = 0;

    p1 = fork();

    if (p1 == 0) {
        printf("PID filho 1: %d\n", getpid());
        printf("PID do pai de p1 %d\n", getppid());

    } else {
        p2 = fork();

        if (p2 == 0 && p1 != 0) {
            printf("PID filho 2: %d\n", getpid());
            printf("PID do pai de p2 %d\n", getppid());

        } else if (p2 != 0 && p1 != 0) { // Executado apenas pelo processo pai
            printf("PID processo pai: %d\n", getpid());

            wait(NULL); // Aguarda finalização de ambos os filhos
        }
    }

    return 0;
}
