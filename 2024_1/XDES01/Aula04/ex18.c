#define W_PER_SQUARED_METER 18

#include <stdio.h>

int main() {
	int x, y, area;

	scanf("%d %d", &x, &y);

	area = x * y;

	printf("%d %d\n", area, area * W_PER_SQUARED_METER);

	return 0;
}
