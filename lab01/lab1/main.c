#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    float a=4.09,b=2.57,x=6.31;
    float res=pow(a*pow(x,3)+3,1.0/7)/exp(b-abs(6*log(3*x)));
    printf("%f",res);
    return 0;

}
