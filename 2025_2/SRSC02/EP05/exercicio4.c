/*
 * exercicio4.c
 *
 * Created on: 20 de out de 2025
 *
 * Authors:
 * MAT - NOME
 *
 * Cria um processo filho atraves de fork, e tenta alterar sua prioridade 
 * atraves do pai.
 */

 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/resource.h>
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <unistd.h>

int main(int argc, char **argv) {
    int ret, prioridade;
    pid_t child_pid;
    int pfd[2]; // pipe para sincronizar pai e filho

    if (pipe(pfd) == -1)
        exit(1);

    child_pid = fork(); 

    if (child_pid < 0) {
        exit(2);
    } else if (child_pid == 0) {
        char temp;
        if (close(pfd[1]) == -1)
            exit(3);

        errno = 0;
        prioridade = getpriority(PRIO_PROCESS, 0);

        if (prioridade == -1 && errno != 0) {
            fprintf(stderr, "getpriority() falhou...\n");
        }

        printf("[FILHO]: PID %d\n", getpid());
        printf("[FILHO]: Prioridade antes: %d\n", prioridade);

        if (read(pfd[0], &temp, 1) == -1) // aguardar o pai
            exit(3);

        errno = 0;
        prioridade = getpriority(PRIO_PROCESS, 0);

        if (prioridade == -1 && errno != 0) {
            fprintf(stderr, "getpriority() falhou...\n");
        }

        printf("[FILHO]: Prioridade depois: %d\n", prioridade);
    } else {
        if (close(pfd[0]) == -1)
            exit(3);

        printf("[PAI]: Alterando prioridade do filho...\n");

        ret = setpriority(PRIO_PROCESS, child_pid, 12);

        if (ret == -1) {
            fprintf(stderr, "setpriority() falhou...\n");
            return 1;
        }

        if (write(pfd[1], "a", 1) == -1) // liberar o filho
            exit(3);

        wait(NULL);
    }

    return 0;
}
