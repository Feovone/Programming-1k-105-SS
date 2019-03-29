#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void clrscr()
{
    system("@cls||clear");
}
char menu() {
    char choice;
    printf("\n------------------------\n");
    printf("What do you want to do?\n");
    printf("------------------------\n");
    printf("[1] Tochka meshdy 2 krugov \n");
    printf("[2] Naimenshe chislo s 3 \n");
    printf("[3] Naibilshe cratne 2 chisel \n");
    printf("[C] Clear Console \n");
    printf("[Q] Quit\n");
    printf("***********************\n");
    printf("Your choice: ");
    while((choice = getchar()) == '\n');
    printf("\n");
    return choice;
}
int main(int argc, char *argv[]){
char ans;
    while((ans = toupper(menu())) != 'Q') {
if (ans == 'C') {
     clrscr();
}
if (ans == '1') {
     task1();
}
}

}

int task1(){
    int N=10;
 double a=-2,b=2,q,e,s,x;
scanf("%lf",&x);
printf("%f",x);
if(a>x||x>b){
    char* fmt = "Incorrect %.4f. Need from [%.4f, %.4f]\n";
    printf(fmt, x, a, b);
    return -2;
}
e=x;
s=e;
for (int n=1;n<=N;++n){
q=(4*x*x)/n;
e*=q;
s+=e;
}
s=x*x*x-s;
double y=x*x*x-cos(2*x);
printf("S=%.7lf\n", s);
printf("y=%.7lf\n", y);
double eps = fabs(y-s)/fabs(s)*100;
    printf("e=%.2f%%\n", eps);
    return 0;

}


