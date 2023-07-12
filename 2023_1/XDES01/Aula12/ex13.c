#include <stdio.h>

typedef struct Ponto {
	int x, y;
} Ponto;

int isInsideRectangle(Ponto p, Ponto v1, Ponto v2);

int main() {
	Ponto p = { 0 };
	Ponto v1 = { 0 }, v2 = { 0 };

	scanf("%d %d", &p.x, &p.y);
	scanf("%d %d", &v1.x, &v1.y);
	scanf("%d %d", &v2.x, &v2.y);

	printf("%d\n", isInsideRectangle(p, v1, v2));

	return 0;
}

int isInsideRectangle(Ponto p, Ponto v1, Ponto v2) {
	return p.x > v1.x && p.y < v2.y;
}
