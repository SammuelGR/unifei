#include <stdio.h>

typedef struct Ponto {
	int x, y;
} Ponto;

typedef struct Rectangle {
	Ponto v1;
	Ponto v2;
} Rectangle;

int isContained(int x, int y, Rectangle Rectangle);

int main() {
	Rectangle rectangle;
	Ponto ponto;

	scanf("%d %d", &ponto.x, &ponto.y);

	scanf("%d %d", &rectangle.v1.x, &rectangle.v1.y);
	scanf("%d %d", &rectangle.v2.x, &rectangle.v2.y);

	printf("%d\n", isContained(ponto.x, ponto.y, rectangle));

	return 0;
}

int isContained(int x, int y, Rectangle rectangle) {
	if ((x > rectangle.v1.x && x < rectangle.v2.x)
		&& (y > rectangle.v1.y && y < rectangle.v2.y))
		return 1;

	return 0;
}
