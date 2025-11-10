#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arq1, *arq2;
    char ch;

    arq1 = fopen("arq1.txt", "r");
    arq2 = fopen("arq2.txt", "w");

    if (arq1 == NULL || arq2 == NULL) {
        printf("Erro ao abrir arquivos.\n");
        exit(1);
    }

    while ((ch = fgetc(arq1)) != EOF) {
        fputc(ch, arq2);
    }

    fclose(arq1);
    fclose(arq2);

    printf("Cópia concluída com sucesso.\n");
    return 0;
}
