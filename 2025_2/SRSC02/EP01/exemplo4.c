#include <unistd.h>
#include <stdio.h>
#include <stdlib.h> // system()

int main(int argc, char *argv[])
{
    char cmd[100];
    pid_t child_pid;

    printf("PID do pai: %d\n", getpid());

    child_pid = fork();

    if (child_pid == 0)
    {
        printf("PID do filho: %d\n", getpid());
    } else
    {
        sleep(3);
        sprintf(cmd, "ps | grep -i %s", &argv[0][2]); // vc entendeu esta linha?
        system(cmd);
    }

    return 0;
}
