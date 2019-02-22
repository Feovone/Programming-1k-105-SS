#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int menu;
    int N=8;
    double x, leftX = 1, rightX = 3;

    printf("Press you choice:\n");
    printf("****************\n");
    printf("Press 1 to solve your problem:\n");
    printf("****************\n");
    printf("Other EXIT\n");
    scanf("%d",&menu);

    switch (menu){
        case 1:
        printf("\nEnter x: ");
    if (scanf("%lf", &x )!= 1) {
        printf("Invalid input\n");
        return -1;
    }

    if (x < leftX || x > rightX) {
        char* fmt = "Incorrect %.4f. Need from [%.4f, %.4f]\n";
        printf(fmt, x, leftX, rightX);
        return -2;
    }

    double a = x, S = a;

    for (int n = 0; n <= N; ++n) {
        double q = x*log(5)/(n+1);
        a *= q;
        S += a;
    }
    //Calc result
    double y = x*pow(5,x);
    printf("S=%.7f\n", S);
    printf("y=%.7f\n", y);
    double eps = fabs(y-S)/fabs(S)*100;
    printf("e=%.2f%%\n", eps);
    return 0;
    break;
    }







}
