#include <stdio.h>

int main() {
    int userValue = 0, counter = 0;
    float averageSum = 0.0;

    do {
        scanf("%d", &userValue);

        if (userValue >= 0) {
            averageSum += (float) userValue;
            counter++;
        }
    } while (userValue > 0);

    printf("%.1f\n", averageSum / (float) counter);

    return 0;
}