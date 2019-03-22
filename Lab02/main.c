#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f1(double);
double f2(double, double);
int main()
{
    int menu;
    int N=8;
    double x, leftX = 1, rightX = 3;

    printf("Press you choice:\n");
    printf("****************\n");
    printf("Press 1 to solve your problem:\n");
    printf("Press 2 to solve your second problem:\n");
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

        case 2:
second();
break;

    }
}

int second()
{
    double a = 2, b = 5, h = 0.15;

    printf("*************** Part 1 ***************\n");

    printf("x:\t");
    for (double x = a; x <= b; x += h) {
        char c = x + h < b ? '\t' : '\n';
        printf("%.3f%c", x, c);
    }

    printf("y:\t");
    for (double x = a; x <= b; x += h) {
        char c = x + h < b ? '\t' : '\n';
        printf("%.3f%c", f1(x), c);
    }

    printf("**************************************\n");

    printf("*************** Part 2 ***************\n");

    double a1=1, b1 = 5, h1 = 0.1;
    double c1=0, d1 = 4, h2 = 0.2;
    printf("y\\x\t");
    for (double x = a1; x <= b1; x += h1) {
        char c = x + h1 < b1 ? '\t' : '\n';
        printf("%.3f%c", x, c);
    }

    for (double y = c1; y <= d1; y += h2) {
        printf("%.3f\t", y);
        for (double x = a1; x <= b1; x += h1) {
            char c = x + h1 < b1 ? '\t' : '\n';
            printf("%.3f%c", f2(x, y), c);
        }
    }

    printf("**************************************\n");
    return 0;
}

double f1(double x) {
    if (x <= 1.0) {
        return 3-fabs(x-pow(3-x,1.0/3));
    } else {
        if (x > 1 && x <= 4) {
            return pow(x, 1.0/3);
        } else {
            return pow(2-x,1.0/3);
        }
    }
}

double f2(double x, double y) {
    return (x-2*y)/pow(3*x+y,1.0/2);
}
