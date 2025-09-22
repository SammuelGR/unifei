/*
 * exercicio4.c
 *
 *  Created on: 15 de set de 2025
 *
 * Processo filho le uma string fornecida como argumento do terminal e escreve
 * no pipe. O processo pai tenta ler a string do pipe em blocos.
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define BUF_SIZE 10

int main(int argc, char *argv[]) {
    int pfd[2];              /* Descritor de pipes */
    char buf[BUF_SIZE];
    ssize_t numRead;

    if (argc != 2 || strcmp(argv[1], "--help") == 0) {
        printf("%s string\n", argv[0]);
        exit(1);
    }

    if (pipe(pfd) == -1)     /* Cria o pipe */
        exit(1);

    switch (fork()) {
        case -1:
            exit(2);

        case 0: /* Filho - escreve no pipe */
            if (close(pfd[0]) == -1) /* Terminal: leitura não usada */
                exit(6);

            if (write(pfd[1], argv[1], strlen(argv[1])) != strlen(argv[1]))
                exit(7);

            if (close(pfd[1]) == -1) /* Pai irá receber o EOF */
                exit(3);

            _exit(EXIT_SUCCESS);

        default: /* Pai - lê do pipe */
            if (close(pfd[1]) == -1) /* Terminal: escrita não usada */
                exit(3);

            for (;;) { /* Leia os dados do pipe, imprima */
                numRead = read(pfd[0], buf, BUF_SIZE);
                if (numRead == -1)
                    exit(4);
                if (numRead == 0) /* Fim de dados */
                    break;
                if (write(STDOUT_FILENO, buf, numRead) != numRead)
                    exit(5); /* Erro na impressão */
            }

            write(STDOUT_FILENO, "\n", 1);
            if (close(pfd[0]) == -1)
                exit(3);

            exit(EXIT_SUCCESS);
    }
}
