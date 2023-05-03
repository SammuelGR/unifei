#include <stdio.h>

int main() {
    float a = 0.0, b = 0.0;

    printf("Digite dois numeros:\n");
    scanf("%f %f", &a, &b);

    printf("O menor numero eh %f\n", a < b ? a : b);

    return 0;
}