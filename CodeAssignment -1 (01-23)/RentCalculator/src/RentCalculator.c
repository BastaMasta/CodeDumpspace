#include <stdio.h>

int main(){

	double rent, months;
	printf("\nEnter the monthly rent:\n");
	scanf("%lf", &rent);
	printf("\nEnter the number of months:\n");
	scanf("%lf", &months);
	printf("\nThe total rent for %.1lf months at the rate of %.1lf per month is %.1lf\n", months, rent, rent*months);

	// OR

	double total_rent = 0;
	for(int i = 1; i <= months; i++){
		total_rent += rent;
	}

	printf("\nThe total rent for %.1lf months at the rate of %.1lf per month is %.1lf(\'for\' iterative loop)\n", months, rent, total_rent);

	return 0;
}
