/*
 * exercicio6.c
 *
 *  Created on: 15 de set de 2025
 *
 * Processo pai le uma string da entrada padrao e envia o texto
 * atraves de pipe para o processo filho. O filho entao ira transformar o texto
 * em letras maiusculas e retornar para o pai em outro pipe.
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 128

int main(void) {
    int filedes_1[2], filedes_2[2];
    int i;

    if (pipe(filedes_1) == -1 || pipe(filedes_2) == -1) /* Cria os pipes */
        exit(1);

    switch (fork()) { /* Cria um processo filho */
        case -1:
            exit(2);

        case 0: /* Filho */
            if (close(filedes_1[1]) == -1) /* Fechar a terminação de escrita não usada */
                exit(3);

            /* Filho pode ler o pipe */
            char buffer_filho[BUFFER_SIZE];

            read(filedes_1[0], buffer_filho, sizeof(buffer_filho));

            if (close(filedes_2[0]) == -1) /* Fechar a terminação de leitura não usada */
                exit(3);

            /* Filho agora pode escrever dados no pipe */
            char texto_filho[BUFFER_SIZE];

            for (i = 0; i < strlen(buffer_filho) - 1; i++) {
                texto_filho[i] = toupper(buffer_filho[i]);
            }

            write(filedes_2[1], texto_filho, sizeof(texto_filho));

            break;

        default: /* Pai */
            if (close(filedes_1[0]) == -1) /* Fechar a terminação de leitura não usada */
                exit(3);

            /* Pai pode escrever no pipe */
            char texto_pai[BUFFER_SIZE];

            fgets(texto_pai, BUFFER_SIZE, stdin); // Pai le texto da entrada padrao

            write(filedes_1[1], texto_pai, sizeof(texto_pai));

            if (close(filedes_2[1]) == -1) /* Fechar a terminação de escrita não usada */
                exit(3);

            /* Pai pode ler o pipe */
            char buffer_pai[BUFFER_SIZE];

            read(filedes_2[0], buffer_pai, sizeof(buffer_pai));
            printf("%s\n", buffer_pai);

            break;
    }

    return 0;
}
