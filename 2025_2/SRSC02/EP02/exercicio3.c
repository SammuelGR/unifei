/*
 * exercicio3.c
 *
 *  Created on: 15 de set de 2025
 *
 * Utilizacao de dois pipes para que o processo pai envie uma mensagem para o
 * filho, em seguida receba uma mensagem dele. O processo filho faz o oposto.
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 128

int main(void) {
    int filedes_1[2], filedes_2[2];

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
            printf("Filho: mensagem recebida: %s\n", buffer_filho);

            if (close(filedes_2[0]) == -1) /* Fechar a terminação de leitura não usada */
                exit(3);

            /* Filho agora pode escrever dados no pipe */
            char texto_filho[BUFFER_SIZE];

            strcpy(texto_filho, "Esta é a mensagem para o pai");
            write(filedes_2[1], texto_filho, sizeof(texto_filho));

            printf("Filho: mensagem enviada\n");

            break;

        default: /* Pai */
            if (close(filedes_1[0]) == -1) /* Fechar a terminação de leitura não usada */
                exit(3);

            /* Pai pode escrever no pipe */
            char texto_pai[BUFFER_SIZE];

            strcpy(texto_pai, "Esta é a mensagem para o filho");
            write(filedes_1[1], texto_pai, sizeof(texto_pai));

            printf("Pai: mensagem enviada\n");

            if (close(filedes_2[1]) == -1) /* Fechar a terminação de escrita não usada */
                exit(3);

            /* Pai pode ler o pipe */
            char buffer_pai[BUFFER_SIZE];

            read(filedes_2[0], buffer_pai, sizeof(buffer_pai));
            printf("Pai: mensagem recebida: %s\n", buffer_pai);

            break;
    }

    return 0;
}
