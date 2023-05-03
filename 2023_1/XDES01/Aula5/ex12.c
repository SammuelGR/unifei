#include <stdio.h>

int main() {
    float a = 0.0, b = 0.0, c = 0.0;

    scanf("%f %f %f", &a, &b, &c);

    if (a == b && a == c) {
        printf("equilatero\n");
    } else if (a != b && a != c && b != c) {
        printf("escaleno\n");
    } else {
        printf("isosceles\n");
    }

    return 0;
}