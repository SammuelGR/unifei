#include <stdio.h>

int main() {
    float a = 0.0, b = 0.0, c = 0.0, d = 0.0, lowerValue = 0;

    printf("Digite quatro numeros:\n");
    scanf("%f %f %f %f", &a, &b, &c, &d);

    if (a <= b && a <= c && a <= d) {
        lowerValue = a;
    } else if (b <= a && b <= c && b <= d) {
        lowerValue = b;
    } else if (c <= a && c <= b && c <= d) {
        lowerValue = c;
    } else if (d <= a && d <= b && d <= c) {
        lowerValue = d;
    }

    printf("O menor numero eh: %f\n", lowerValue);

    return 0;
}