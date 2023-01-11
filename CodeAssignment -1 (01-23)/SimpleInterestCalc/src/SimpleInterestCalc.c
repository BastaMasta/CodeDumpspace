#include <stdio.h>

int main(){

	double pAmt, intRate, yrs;
	printf("\nPlease enter the principal ammount:\n");
	scanf("%lf", &pAmt);
	printf("\nPlease enter interest rates(in percentage):\n");
	scanf("%lf", &intRate);
	printf("\nPlease enter the amount of time (in years):\n");
	scanf("%lf", &yrs);

	double intAmt = (intRate/100) * pAmt;

	printf("\nThe total amount (Principal+Accumulated ineterest) after %.2lf years is %.2lf\n", yrs, (yrs*intAmt + pAmt));

	return 0;

}
