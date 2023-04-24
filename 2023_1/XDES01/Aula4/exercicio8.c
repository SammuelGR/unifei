#include <stdio.h>
#include <math.h>

int main() {
    float radius = 0.0, height = 0.0, volume = 0.0;

    printf("Digite os valores do raio e da altura do cilindro, respectivamente:\n");
    scanf("%f %f", &radius, &height);

    volume = M_PI * (radius * radius) * height;

    printf("O volume do cilindro eh %.2f\n", volume);

    return 0;
}