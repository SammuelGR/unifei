#include <stdio.h>

int main() {
    int a = 0, b = 0, c = 0, d = 0, lowerValue = 0;

    scanf("%d %d %d %d", &a, &b, &c, &d);

    if (a <= b && a <= c && a <= d) {
        lowerValue = a;
    } else if (b <= a && b <= c && b <= d) {
        lowerValue = b;
    } else if (c <= a && c <= b && c <= d) {
        lowerValue = c;
    } else if (d <= a && d <= b && d <= c) {
        lowerValue = d;
    }

    printf("%d\n", lowerValue);

    return 0;
}