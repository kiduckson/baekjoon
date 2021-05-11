#include <stdio.h>
#include <math.h>

int main()
{
	double radius;
	scanf("%lf", &radius);
	printf("%.6f\n", radius * radius * M_PI);
	printf("%.6f\n", radius * radius * 2);
}
