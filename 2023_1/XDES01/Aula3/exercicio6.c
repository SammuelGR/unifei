#include <stdio.h>

int main() {
    float baseValue = 0, heightValue = 0;

    printf("Digite os valores da base e da altura:\n");
    scanf("%f %f", &baseValue, &heightValue);

    printf("Area do triangulo: %f\n", (baseValue*heightValue)/2);

    return 0;
}