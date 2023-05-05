#include <stdio.h>

int main() {
    int A = 0, B = 0, sum = 0, product = 1, i = 0;

    scanf("%d %d", &A, &B);

    for (i = A; i <= B; i++) {
        if (i % 2 == 0) {
            sum += i;
        } else {
            product *= i;
        }
    }

    printf("%d %d\n", sum, product);

    return 0;
}