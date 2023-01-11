#include <stdio.h>

// A simple calculator in C

int main(){
    char opr;
    double a =7, b = 5;
    printf("Please input the operator:\n");
    scanf("%c", &opr);
    printf("\nInput first number:\n");
    scanf("%lf", &a);
    printf("\nInput second number:\n");
    scanf("%lf", &b);

    switch(opr){

    case '+':
        printf("\n %lf + %lf = %lf", a, b, a+b);
        break;

    case '-':
        printf("\n %lf - %lf = %lf", a, b, a-b);
        break;

    case '/':
        printf("\n %lf / %lf = %lf", a, b, a/b);
        break;

    case '*':
        printf("\n %lf x %lf = %lf", a, b, a*b);
        break;

	default:
    	printf("Invalid operator provided!");

    }

    return 0;
}
