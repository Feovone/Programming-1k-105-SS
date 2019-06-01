#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double f1(double);
double f2(double, double);
int main()
{
    double a = -M_PI, b = M_PI, h = 0.1;

    printf("*************** Part 1 ***************\n");

    printf("x:\t");
    for (double x = a; x <= b; x += h) {
        char c = x + h < b ? '\t' : '\n';
        printf("%.3f%c", f1(x), c);
    }

    printf("y:\t");
    for (double x = a; x <= b; x += h) {
        char c = x + h < b ? '\t' : '\n';
        printf("%.3f%c", f1(x), c);
    }

    printf("**************************************\n");

    printf("*************** Part 2 ***************\n");

    double a1=-3, b1 =3, h1 = 0.25;
    double c1=1, d1 = 2, h2 = 0.15;
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
    if (x <= -M_PI_2) {
        return sin(2)*cos(x/2);
    }
        if (x > -M_PI_2 && x <= M_PI_2) {
            return fabs(x-M_PI_2);
        }
        if (x>M_PI_2){
            return (x-1)/(2+pow(x,1.0/2));
        }
}

double f2(double x, double y) {
    return (pow(x(y+1),1.0/2)/(x-y));
}



