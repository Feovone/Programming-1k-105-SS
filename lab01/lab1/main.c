#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    int a=4.09,b=2.57,x=-6.31;
    int res=pow(a*pow(x,3)+3,1.0/7)/exp(b-abs(6*log(3*x)));
    printf("%d",&res);
    return 0;
}
