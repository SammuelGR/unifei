#include <stdio.h>
#include <math.h>

int main() {
    float userValue = 0;

    printf("Digite um numero real: ");
    scanf("%f", &userValue);

    printf("Quadrado de %f: %f\n", userValue, pow(userValue, 2));
    printf("Cubo de %f: %f\n", userValue, pow(userValue, 3));

    return 0;
}