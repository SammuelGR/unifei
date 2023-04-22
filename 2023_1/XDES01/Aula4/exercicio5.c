#include <stdio.h>
#include <math.h>

int main() {
    int value = 0;
    float sum = 0.0;

    printf("Digite um numero inteiro: ");
    scanf("%d", &value);

    sum = cbrt(value) + pow(value, (1.0/4.0));

    printf("Resultado: %.2f\n", sum);

    return 0;
}