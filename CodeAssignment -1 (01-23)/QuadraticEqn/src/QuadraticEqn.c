#include <stdio.h>
#include <math.h>

int main(){
    double a,b,c;
    double root1, root2, d;
    printf("Enter the coefficients a, b and c:\n");
    scanf("%lf %lf %lf", &a, &b, &c);
    d = (b*b) - (4*a*c);
    if (d == 0){
        root1 = root2 = -(b/(2*a));
        printf("1st Root = 2nd Root = %.2lf\n", root1);
    }
    else if (d>0){
        root1 = ((-b + sqrt(d))/(2*a));
        root2 = ((-b - sqrt(d))/(2*a));
        printf("1st Root: %.2lf \n", root1);
        printf("2nd Root: %.2lf \n", root2);

    }
    else{
        double rp = -(b/(2*a));
        double imp = sqrt((-d)/(2*a));

        printf("1st Root: %.2lf + %.2lf\n", rp, imp);
        printf("2nd Root: %.2lf - %.2lf\n", rp, imp);
    }

    return 0;
}
