#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t child_pid = fork();

    if (child_pid == 0)
    {
        sleep(3);
        printf("PID do pai adotante: %d\n", getppid());
    } else
    {
        printf("PID do pai verdadeiro: %d\n", getpid());
    }

    return 0;
}
