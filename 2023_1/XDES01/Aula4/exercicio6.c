#include <stdio.h>
#include <math.h>

int main() {
    float a = 0.0, b = 0.0, c = 0.0, p = 0.0, area = 0.0;

    printf("Digite os valores de A, B e C:\n");
    scanf("%f %f %f", &a, &b, &c);

    p = (a + b + c) / 2.0;
    area = sqrt(p * (p - a) * (p - b) * (p - c));

    printf("Area = %.1f\n", area);

    return 0;
}