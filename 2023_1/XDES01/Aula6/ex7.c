#include <stdio.h>

int main() {
    int N = 0, i = 0;

    do {
        scanf("%d", &N);

        if (N >= 0) {
            for (i = 1; i <= N; i++) {
                if (N % i == 0) printf("%d ", i);
            }
        }
    } while (N < 0);

    printf("\n");

    return 0;
}