#include <stdio.h>

int main(){

	int shape;
	double height, base, length, breadth, side, radius;
	const double pi = 3.14159;

	printf("\nPlease choose the shape and enetr the option you want to calculate the are a for (1, 2, 3 ...\n");
	printf("1.Circle\n2.Square\n3.Rectangle\n4.Triangle\n");
	scanf("%d", &shape);
	switch (shape){

	case 1:
		printf("\nPlease enter the radius of the circle\n");
		scanf("%lf", &radius);
		printf("\nThe area of the circle with radius %.2lf is: %.2lf sq. units\n", radius, (radius*radius)*pi);
		break;

	case 2:
		printf("\nPlease enter the side of the square\n");
		scanf("%lf", &side);
		printf("\nThe area of the square with side %.2lf is: %.2lf sq. units\n", side, (side*side));
		break;

	case 3:
		printf("\nPlease enter the length and the breadth of the rectangle:\n");
		scanf("%lf %lf", &length, &breadth);
		printf("\nThe area of the rectancle with length %.2lf and breadth %.2lf is: %.2lf sq. units\n", length, breadth, (length*breadth));
		break;

	case 4:
		printf("\nPlease enter the base and the height of the triangle:\n");
		scanf("%lf %lf", &base, &height);
		printf("\nThe area of the triangle with base %.2lf and height %.2lf is: %.2lf sq. units\n", base, height, 0.5*(base*height));
		break;

	default:
		printf("\nPlease enter a valid option!\n");

	}


}
