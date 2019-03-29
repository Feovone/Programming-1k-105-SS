#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <math.h>
=======
#include <math.h>
>>>>>>> deb2ecb4e1795b31562556ea1cf13b2bc7afb6b8
double f1(double);
double f2(double, double);
int main()
{
    int menu;
    int N=100;
    double x, leftX = 1, rightX = 5;

    printf("Press you choice:\n");
    printf("****************\n");
<<<<<<< HEAD
    printf("Press 1 to solve your problem:\n");
=======
    printf("Press 1 to solve your problem:\n");
>>>>>>> deb2ecb4e1795b31562556ea1cf13b2bc7afb6b8
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

    double a = 1/x, S = 0;

    for (int n = 0; n <= N; ++n) {
<<<<<<< HEAD
        double q = pow(x, 2)/(n+1);
=======
        double q = pow(x, 2)/(n+1);
>>>>>>> deb2ecb4e1795b31562556ea1cf13b2bc7afb6b8
        S += a;
        a *= q;

    }
    //Calc result
    double y = exp(pow(x,2))/x;
    printf("S=%.7f\n", S);
    printf("y=%.7f\n", y);
    double eps = fabs(y-S)/fabs(S)*100;
    printf("e=%.2f%%\n", eps);
    return 0;
<<<<<<< HEAD
    break;

        case 2:
second();
break;

    }
}

=======
    break;

        case 2:
second();
break;

    }
}

>>>>>>> deb2ecb4e1795b31562556ea1cf13b2bc7afb6b8
int second()
{
    double a = -3, b = 5, h = 0.1;

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

    double a1=4, b1 = 8, h1 = 0.1;
    double c1=4, d1 = 8, h2 = 0.1;
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
    if (x < -2.0) {
        return exp(-x)*x;
    } else {
        if (x >= 2 && x <= 4) {
            return exp(2-x)+exp(x);
        } else {
            return 4-x*exp(1-3*x);
        }
    }
}

double f2(double x, double y) {
    return pow(x*y,1.0/3);
<<<<<<< HEAD
}
=======
}
>>>>>>> deb2ecb4e1795b31562556ea1cf13b2bc7afb6b8
