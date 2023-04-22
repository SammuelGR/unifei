#include <stdio.h>

int main() {
    float a = 0.0, b = 0.0, c = 0.0, sum = 0.0;

    printf("Digite tres valores:\n");
    scanf("%f %f %f", &a, &b, &c);

    sum = (a * a) + (b * b) + (c * c); 

    printf("A soma de seus quadrados eh: %f\n", sum);

    return 0;
}