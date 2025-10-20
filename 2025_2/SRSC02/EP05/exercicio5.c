/*
 * exercicio5.c
 *
 * Created on: 20 de out de 2025
 *
 * Authors:
 * MAT - NOME
 *
 * Cria um processo filho atraves de fork, que tenta alterar a prioridade do
 * processo pai.
 */

 #include <errno.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <sys/resource.h>
 #include <sys/types.h>
 #include <unistd.h>

int main(int argc, char **argv) {
    int prioridade;
    pid_t child_pid;
    int pfd[2]; // pipe para sincronizar pai e filho

    if (pipe(pfd) == -1)
        exit(1);

    child_pid = fork(); 

    if (child_pid < 0) {
        exit(2);
    } else if (child_pid == 0) {
        if (close(pfd[0]) == -1)
            exit(3);


        printf("[FILHO]: Alterando prioridade do pai...\n");

        if (setpriority(PRIO_PROCESS, getppid(), 12) == -1)
            fprintf(stderr, "setpriority() falhou...\n");

        if (write(pfd[1], "A", 1) == -1) // liberar o pai
            exit(3);
    } else {
        char temp;
        if (close(pfd[1]) == -1)
            exit(3);

        errno = 0;
        prioridade = getpriority(PRIO_PROCESS, 0);

        if (prioridade == -1 && errno != 0)
            fprintf(stderr, "getpriority falhou...\n");
        
        printf("[PAI]: Prioridade antes: %d\n", prioridade);

        if (read(pfd[0], &temp, 1) == -1) // aguardar o filho
            exit(3);

        errno = 0;
        prioridade = getpriority(PRIO_PROCESS, 0);

        if (prioridade == -1 && errno != 0)
            fprintf(stderr, "getpriority falhou...\n");
        
        printf("[PAI]: Prioridade depois: %d\n", prioridade);
    }

    return 0;
}
