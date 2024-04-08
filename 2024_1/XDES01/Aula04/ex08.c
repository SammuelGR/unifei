#include <math.h>
#include <stdio.h>


int main() {
	double angleInDegrees, angleInRadians;
	const double PI = acos(-1);

	scanf("%lf", &angleInDegrees);
	angleInRadians = angleInDegrees * PI / 180.0;


	printf("%.2lf %.2lf %.2lf\n", sin(angleInRadians), cos(angleInRadians), tan(angleInRadians));


	return 0;
}
