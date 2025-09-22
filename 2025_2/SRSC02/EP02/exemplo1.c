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
            if (close(filedes[1]) == -1) /* Fechar a terminação de escrita não usada */
                exit(3);

            /* Filho agora pode ler dados do pipe */
            char buffer[128];
            read(filedes[0], buffer, sizeof(buffer));
            printf("Filho: mensagem recebida: %s\n", buffer);
            break;

        default: /* Pai */
            if (close(filedes[0]) == -1) /* Fechar a terminação de leitura não usada */
                exit(3);

            /* Pai pode escrever no pipe */
            char texto[128];
            strcpy(texto, "Esta é a mensagem para o filho");
            write(filedes[1], texto, sizeof(texto));
            printf("Pai: mensagem enviada\n");
            break;
    }

    return 0;
}
