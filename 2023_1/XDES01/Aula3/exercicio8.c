#include <stdio.h>
#include <math.h>

int main() {
    float radiusValue = 0;
    float circleArea = 0;

    printf("Digite valor do raio: ");
    scanf("%f", &radiusValue);

    circleArea = M_PI * (pow(radiusValue, 2));

    printf("Area do circulo: %f\n", circleArea);

    return 0;
}