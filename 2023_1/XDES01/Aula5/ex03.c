#include <stdio.h>
#include <math.h>

int main() {
    int userNumber = 0;

    scanf("%d", &userNumber);

    if (userNumber > 0) {
        printf("%f\n", sqrt(userNumber));
    } else {
        printf("%d\n", (userNumber * userNumber));
    }
}