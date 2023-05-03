#include <stdio.h>

int main() {
    int userValue = 0;

    scanf("%d", &userValue);

    if (userValue % 3 == 0 && userValue % 5 != 0) {
        printf("divisivel por 3\n");
    } else if (userValue % 5 == 0 && userValue % 3 != 0) {
        printf("divisivel por 5\n");
    } else {
        printf("nao divisivel\n");
    }

    return 0;
}