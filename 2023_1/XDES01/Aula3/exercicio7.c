#include <stdio.h>

int main() {
    float minorBaseValue = 0, majorBaseValue = 0, heightValue = 0;

    printf("Digite os valores das bases menor e maior:\n");
    scanf("%f %f", &minorBaseValue, &majorBaseValue);

    printf("Digite o valor da altura: ");
    scanf("%f", &heightValue);

    printf("Area do trapezio: %f\n", ((minorBaseValue + majorBaseValue) * heightValue) / 2);

    return 0;
}