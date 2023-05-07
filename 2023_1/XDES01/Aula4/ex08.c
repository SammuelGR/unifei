#include <stdio.h>
#include <math.h>

int main() {
    float radius = 0.0, height = 0.0, volume = 0.0;

    scanf("%f %f", &radius, &height);

    volume = acos(-1) * (radius * radius) * height;

    printf("%.2f\n", volume);

    return 0;
}