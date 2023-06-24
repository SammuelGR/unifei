#define SIZE 6

#include <math.h>
#include <stdio.h>

typedef struct polarCoordinate {
	float radius;
	float argument;
} polarCoordinate;

typedef struct cartesianCoordinate {
	float x;
	float y;
} cartesianCoordinate;

int main() {
	polarCoordinate polarCoordinates[SIZE];
	cartesianCoordinate cartesianCoordinates[SIZE];
	int i = 0;
	const double pi = 4.0 * atan(1.0);

	for (i = 0; i < SIZE; i++) {
		scanf("%f", &polarCoordinates[i].radius);
		scanf("%f", &polarCoordinates[i].argument);
	}

	for (i = 0; i < SIZE; i++) {
		cartesianCoordinates[i].x = polarCoordinates[i].radius * cos((polarCoordinates[i].argument * pi) / 180.0);
		cartesianCoordinates[i].y = polarCoordinates[i].radius * sin((polarCoordinates[i].argument * pi) / 180.0);
	}

	for (i = 0; i < SIZE; i++) {
		printf("(%.2f, %.2f)\n", cartesianCoordinates[i].x, cartesianCoordinates[i].y);
	}

	return 0;
}
