#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
void clrscr()
{
    system("@cls||clear");
}
//task2
double equation (double x){
    return pow(x,3)-2*x-5;
}
double equation1 (double x){
    return 3*pow(x,2)-2;
}
char check (double a){
    if(a<0){
        return -1;
    }else if(a>0){
            return 1;
          } else {
                return 0;
            }
}
//task3
double func (double a){
return (exp(a)-1)/(exp(a)+1);
}



int menu(){
    char choice;

    printf("\n------------------------\n");
    printf("What do you want to do?\n");
    printf("------------------------\n");
    printf("[1]CALCULATION\n");
    printf("[2]LOCALIZATIon\n");
    printf("[3]INTEGRAL\n");
    printf("[C]CLEAR CON\n");
    printf("[Q]Exit\n");
    while((choice = getchar()) == '\n');
    printf("\n");
    return choice;
}

int main(int argc, char *argv[])
{
char ans;
while((ans = toupper(menu())) != 'Q') {
if (ans == 'C') {
     clrscr();
}
if (ans == '1') {
     task1();
}
if (ans == '2') {
     task2();
}
if (ans == '3') {
     task3();
}

  }
}

int task1()
{
    int m,n,q,temp;

    printf("Please enter matrix size [m][n] !\n");
    scanf("%d %d", &m, &n);
    int a[m][n];

    printf("Please enter matrix!\n");
    for(int i=0;i<m;++i){
        for(int j=0;j<n;++j){
            scanf("%d", &a[i][j]);
        }
    }
    printf("Your matrix\n");
    for(int i=0; i < m; i++){
     for(int j=0; j < n; j++){
        char c = j < n - 1 ? ' ' : '\n';
        printf("%d%c",a[i][j], c);
     }
    }
    printf("Sort relative to row!\n");
    scanf("%d", &q);
    q=q-1;
    for(int i=0; i < n-1; ++i){
        for (int j = i + 1; j < n; ++j) {
        if(a[q][i]>a[q][j]){
            temp=a[q][i];
            a[q][i]=a[q][j];
            a[q][j]=temp;
            for(int k=0; k < m; k++){
                if (k != q) {
                    temp=a[k][i];
                    a[k][i]=a[k][j];
                    a[k][j]=temp;
                }
            }
        }
        }


     }
    for(int i=0; i < m; i++){
        for(int j=0; j < n; j++){
            char c = j < n - 1 ? ' ' : '\n';
            printf("%d%c",a[i][j], c);
     }
    }
return 0;
}

task2(){
    int deg;
    printf("Enter degree\n");
    if(scanf("%d",&deg)!=1||deg>7||deg<2){
        printf("Incorrect deg,enter from interval [2-7]\n");
            return -1;
        }
    clrscr();
    double degm=pow(10,0-deg);
    printf("**************************\n%.7lf - degree\n",degm);
    double res = 2.09455148;
    printf("Result: %lf\n**************************\n",res);
    double x = degm, err,error;
    double ex, bisx, chordsx, chordtx;
    //BISECT
    double xb1 = degm, xb2 = 3-degm;
    do {
        ex = (xb2-xb1)/2;
        bisx = xb1 + ex;
        if(check(equation(xb1))!=check(equation(bisx))){
            xb2 = bisx;
            } else {
            xb1 = bisx;
                    }
        }
    while((xb2-xb1)>degm);
    error = fabs(res-bisx)/res*100;
    printf("Bisection:\nRoot %lf, Error = %f%%...\n///////////////////////////\n",bisx,error);
//Simple
    for(x; x < 3-degm ; x += degm){
        if(check(equation(x))*check(equation(x+degm)) < 0){
            printf("Simple iteration:\nRoot in interval [%f,%f]\n",x,x+degm);
            err = x+degm/2;
            error = fabs(res - err)/res*100;
            printf("Root %lf, Error = %f%%.\n///////////////////////////\n",err,error);
            break;
            }
        }
// chord sec
    double xs1 = degm, xs2 = 10-degm;
    do {
        ex=chordsx;
        chordsx = xs2-equation(xs2)*(xs1-xs2)/(equation(xs1)-equation(xs2));
        if(equation(xs2)*equation(chordsx)<0){
            xs1 = x;
            } else {
            xs2 = x;
            }
        }
    while (fabs(chordsx-ex)>degm);
    error = fabs(res-chordsx)/res*100;
    printf("Chord Secant:\nRoot %lf, Error = %f%%\n///////////////////////////\n",chordsx,error);
//chord ten
    double xt = degm;
    chordtx  = xt - equation(xt)/equation1(xt);
    while (fabs(chordtx-xt)>degm) {
                xt = chordtx;
                chordtx = chordtx - equation(chordtx)/equation1(chordtx);
            }
    error = fabs(res-chordtx)/res*100;
    printf("Chord tangent:\nRoot %lf, Error = %f%%;\n///////////////////////////\n\n",chordtx,error);
    }

task3(){
    double res = 0.627333, a=1, b = 2, e = 0.00001, error;
    double trap,left,right,center,parab;
    clrscr();
    printf("**************************\nResult: %lf\n**************************\n",res);
    //Trap
    for(double i = a; i < b; i+=e){
        trap += (e/2)*(func(i)+func(i+e));
        }
    error = 100*fabs(res-trap)/fabs(res);
    printf("Trap:\nResult: %lf, Error %lf%%\n///////////////////////////\n",trap,error);
    //left
    for(double i = a; i < b; i+=e){
        left += e*func(i);
        }
    error = 100*fabs(res-left)/fabs(res);
    printf("Rectangle left\nResult: %lf, Error = %lf%%\n///////////////////////////\n",left,error);
    //Center
    for(double i = a; i < b; i+=e){
        center += e*func(i+e/2);
        }
    error = 100*fabs(res-center)/fabs(res);
    printf("Rectangle center\nResult: %lf, Error = %lf%%\n///////////////////////////\n",center,error);
    //right
    for(double i = a; i < b; i+=e){
    right += e*func(i+e);
    }
    error = 100*fabs(res-right)/fabs(res);
    printf("Rectangle right\nResult: %lf, Error = %lf%%\n///////////////////////////\n",right,error);

    //parab
    for(double i = a; i < b; i+=e){

    }
    parab = 0.5/3*(func(1)+4*func(1.5)+func(2));
    error = 100*fabs(res-parab)/fabs(res);
    printf("Parabola\nResult: %lf, Error = %lf%%\n///////////////////////////\n",parab,error);
    }

