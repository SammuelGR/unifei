#include <sys/resource.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char **argv) {
    int which, prio, ret;
    id_t who;

    which = (argv[1][0] == 'p') ? PRIO_PROCESS : (argv[1][0] == 'g') ? PRIO_PGRP : PRIO_USER;

    sscanf(argv[2], "%ud", &who);
    sscanf(argv[3], "%d", &prio);

    errno = 0;
    ret = getpriority(which, who);

    if (ret == -1 && errno != 0) {
        fprintf(stderr, "getpriority() falhou...\n");

        return 1;
    } else printf("Prioridade antes: PID = %d Prio = %d\n", who, ret);

    ret = setpriority(which, who, prio);

    if (ret == -1)
    {
        fprintf(stderr, "setpriority() falhou...\n");
        return 1;
    }

    errno = 0;
    ret = getpriority(which, who);

    if (ret == -1 && errno != 0)
    {
        fprintf(stderr, "getpriority() falhou...\n");
        return 1;
    } else printf("Prioridade depois: PID = %d Prio = %d\n", who, ret);

    return 0;
}
