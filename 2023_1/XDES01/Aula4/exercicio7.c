#include <stdio.h>
#include <math.h>

int main() {
    float angle = 0.0, radians = 0.0;

    printf("Digite o valor de um angulo em graus: ");
    scanf("%f", &angle);

    radians = angle * M_PI / 180;

    printf("%.2f %.2f %.2f\n", sin(radians), cos(radians), tan(radians));

    return 0;
}