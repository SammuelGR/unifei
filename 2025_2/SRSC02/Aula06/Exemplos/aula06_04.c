#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    printf("pid do Pai: %d\n", getpid());
    system("./teste");
    printf("\nPrograma apos a funcao system\n");
    return 0;
}
