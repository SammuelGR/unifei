#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>

#define BUF_SIZE 1000

char *currTime(const char *format) {
    static char buf[BUF_SIZE]; /* Nonreentrant */
    time_t t;
    size_t s;
    struct tm *tm;

    t = time(NULL);
    tm = localtime(&t);
    if (tm == NULL)
        return NULL;

    s = strftime(buf, BUF_SIZE, (format != NULL) ? format : "%c", tm);
    return (s == 0) ? NULL : buf;
}

int main(int argc, char *argv[]) {
    int pfd[2]; /* Sincronização de processos com pipe */
    int j, dummy;

    if (argc < 2 || strcmp(argv[1], "--help") == 0) {
        printf("%s sleep-time ...\n", argv[0]);
        exit(1);
    }

    setbuf(stdout, NULL); /* Torne a saída padrão (stdout) não bufferizada,
                           * já que encerramos o processo filho com _exit() */

    printf("%s Pai iniciado\n", currTime("%T"));

    if (pipe(pfd) == -1)
        exit(2);

    for (j = 1; j < argc; j++) {
        switch (fork()) {
            case -1:
                printf("fork %d", j);
                exit(3);

            case 0: /* Filho */
                if (close(pfd[0]) == -1) /* Terminal de leitura não é usado */
                    exit(4);

                /* O filho realiza algum trabalho e avisa ao pai que terminou */
                sleep(atoi(argv[j])); /* Simulação de processo */
                printf("%s Filho %d (PID=%ld) fechando pipe\n",
                    currTime("%T"), j, (long)getpid());

                if (close(pfd[1]) == -1)
                    exit(4);

                /* O filho agora continua para fazer outras coisas ... */
                exit(EXIT_SUCCESS);

            default: /* O pai entra em um loop para criar o próximo filho */
                break;
        }
    }

    /* O pai chega aqui; fecha a extremidade de escrita do pipe para que
     * possamos detectar o EOF */
    if (close(pfd[1]) == -1) /* Escrita não é usada */
        exit(4);

    /* O pai pode realizar outras tarefas e, em seguida, se sincroniza com os filhos */
    if (read(pfd[0], &dummy, 1) != 0)
        exit(5); /* O pai não recebeu EOF */

    printf("%s Pai pronto para prosseguir\n", currTime("%T"));

    /* O pai agora continua para fazer outras coisas ... */
    exit(EXIT_SUCCESS);
}
