#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t child_pid;

    printf("inicio do codigo\n");

    child_pid = fork();

    if (child_pid < 0)
    {
        fprintf(stderr, "falha na criacao do processo...\n");
        return 1;
    } else if (child_pid == 0)
    {
        printf("este eh o processo filho\n");
        printf("o PID do filho eh: %d\n", getpid());
        printf("o PID de seu pai eh: %d\n", getppid());
    } else
    {
        printf("este eh o processo pai\n");
        printf("o PID do pai eh: %d\n", getpid());
        printf("o PID do filho gerado eh: %d\n", child_pid);
    }

    printf("codigo comum a pai e filho\n");

    return 0;
}
