/*
 * exercicio2.c
 *
 *  Created on: 15 de set de 2025
 *
 * Utilizacao de pipe para que o processo filho envie uma mensagem para o
 * processo pai.
 *
 */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    int filedes[2];

    if (pipe(filedes) == -1) /* Cria o pipe */
        exit(1);

    switch (fork()) { /* Cria um processo filho */
        case -1:
            exit(2);

        case 0: /* Filho */
            if (close(filedes[0]) == -1) /* Fechar a terminação de leitura não usada */
                exit(3);

            /* Filho agora pode escrever dados no pipe */
            char texto[128];

            strcpy(texto, "Esta é a mensagem para o pai");
            write(filedes[1], texto, sizeof(texto));

            printf("Filho: mensagem enviada\n");

            break;

        default: /* Pai */
            if (close(filedes[1]) == -1) /* Fechar a terminação de escrita não usada */
                exit(3);

            /* Pai pode ler o pipe */
            char buffer[128];

            read(filedes[0], buffer, sizeof(buffer));
            printf("Pai: mensagem recebida: %s\n", buffer);

            break;
    }

    return 0;
}
