#include <stdio.h>

int main() {
    int N = 0, i = 0, sum = 0;

    do {
        scanf("%d", &N);

        if (N > 0) {
            for (i = 1; i <= N; i++) {
                if (N % i == 0) {
                    sum += i;
                }
            }
        }

    } while (N <= 0);

    printf("%d\n", sum);

    return 0;
}
