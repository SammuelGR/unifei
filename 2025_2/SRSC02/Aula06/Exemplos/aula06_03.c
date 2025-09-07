#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *args[] = { "", "", "", NULL }; // argumentos para o programa
    printf("pid do Pai: %d\n", getpid());
    execv("./teste", args );
    printf("EU TENHO UM SEGREDO PRA CONTAR\n");
    return 0;
}
