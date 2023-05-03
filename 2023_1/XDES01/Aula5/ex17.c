#include <stdio.h>

int main() {
    float ballDiameter = 0.0, height = 0.0, width = 0.0, depth = 0.0;

    scanf("%f %f %f %f", &ballDiameter, &height, &width, &depth);

    if (ballDiameter <= height && ballDiameter <= width && ballDiameter <= depth) {
        printf("sim\n");
    } else {
        printf("nao\n");
    }

    return 0;
}