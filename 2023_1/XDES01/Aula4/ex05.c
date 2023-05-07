#include <stdio.h>
#include <math.h>

int main() {
    int value = 0;
    float sum = 0.0;

    scanf("%d", &value);

    sum = cbrt(value) + pow(value, (1.0/4.0));

    printf("%.2f\n", sum);

    return 0;
}