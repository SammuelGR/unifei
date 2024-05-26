#define SIZE 6

#include <math.h>
#include <stdio.h>

typedef struct PolarCoordinate {
	float radius;
	float argument;
} PolarCoordinate;

typedef struct CartesianCoordinate {
	float x;
	float y;
} CartesianCoordinate;

int main() {
	const double PI = acos(-1.0);
	PolarCoordinate polarCoordinates[SIZE];
	CartesianCoordinate cartesianCoordinates[SIZE];
	int i;

	for (i = 0; i < SIZE; i++) {
		scanf("%f", &polarCoordinates[i].radius);
		scanf("%f", &polarCoordinates[i].argument);

		cartesianCoordinates[i].x = polarCoordinates[i].radius * cos((polarCoordinates[i].argument * PI) / 180.0);
		cartesianCoordinates[i].y = polarCoordinates[i].radius * sin((polarCoordinates[i].argument * PI) / 180.0);
	}

	for (i = 0; i < SIZE; i++) {
		printf("(%.2lf, %.2lf)\n", cartesianCoordinates[i].x, cartesianCoordinates[i].y);
	}

	return 0;
}
