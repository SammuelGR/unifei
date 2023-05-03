#include <stdio.h>

int main() {
    char gender = '\0';
    float height = 0.0, result = 0.0;

    scanf("%f %c", &height, &gender);

    if (gender == 'm' || gender == 'M') {
        result = (72.7 * height) - 58;
    } else if (gender == 'f' || gender == 'F') {
        result = (62.1 * height) - 44.7;
    }

    printf("%f\n", result);

    return 0;
}