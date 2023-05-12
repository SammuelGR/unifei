#include <stdio.h>
#include <math.h>

int main() {
    float angle = 0.0, radians = 0.0;

    scanf("%f", &angle);

    radians = angle * acos(-1) / 180;

    printf("%.1f %.1f %.1f\n", sin(radians), cos(radians), tan(radians));

    return 0;
}