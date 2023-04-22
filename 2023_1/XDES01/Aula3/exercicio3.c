#include <stdio.h>

int main() {
    float valueA = 0, valueB = 0, valueC = 0, sum = 0;

    printf("Digite 3 valores:\n");
    scanf("%f %f %f", &valueA, &valueB, &valueC);

    sum = valueA + valueB + valueC;

    printf("Soma dos valores: %f", sum);

    return 0;
}