#include <stdio.h>
#include <math.h>

int main() {
    float a = 0.0, b = 0.0, c = 0.0, delta = 0.0, x1 = 0.0, x2 = 0.0;

    printf("Digite os valores de a, b e c, respectivamente:\n");
    scanf("%f %f %f", &a, &b, &c);

    delta = (b * b) - 4 * a * c;

    if (delta < 0) {
        printf("sem raizes reais\n");
    } else if (delta == 0) {
        x1 = (-b + sqrt(delta)) / (2 * a);
        printf("%f\n", x1);
    } else {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);

        printf("%f %f\n", x1, x2);
    }

    return 0;
}