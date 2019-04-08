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
    printf("[5] Domino \n");
    printf("[6] Triangle Vid \n");
    printf("[7] Triangle Rasto \n");
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
if (ans == '2') {
    task2();
    }
if (ans == '3') {
    task3();
    }
if (ans == '5') {
    task5();
    }
if (ans == '6') {
    task6();
    }
if (ans == '7') {
    task7();
    }
}}
//*******************************************
int task1()
{
    printf("Enter x and y ");
    float x,y;
    scanf("%f %f",&x,&y);

    //В случаи движение кругов
    int i=0;
    int j=0;
    int k=-1;
    int l=0;
  const int a[i][j];
  const int b[k][l];
  float r1=pow(pow(x-i,2)+pow(y-j,2),1.0/2);
  float r2=pow(pow(x-k,2)+pow(y-l,2),1.0/2);

    printf("Radius 1=%.5f\n",r1);
    printf("Radius 2=%.5f\n",r2);
    if (r1>=1||r2>=1){
        printf("point beyond the intersection area\n\n");
    }
    else {
       printf("point in the intersection area\n\n");
    }

}
//*******************************************
//*******************************************
task2(){
    printf("Enter x,y,z ");
    float x,y,z;
    scanf("%f %f %f",&x,&y,&z);
    float max,min;
    if(x<y){
    if(y<z){
        max=z;
        min=x;
    }
    if(y>z){
        max=y;
    if(x>z){
            min=x;
        }
    if(x>z){
        min=z;
        }
    }
    }
    if (x>y){
        if(x<z){
            max=z;
            min=y;
        }
        if (x>z){
        max=x;
        if(y>z){
            min=z;
        }
        if(y<z){
        min=y;
        }
        }
    }
    printf("min=%f max=%f",min,max);
}
//*******************************************
//*******************************************
//*******************************************
task3(){
printf("Enter x and y \n");
    float x,y;
    scanf("%f %f",&x,&y);
    //printf("%f %f\n",x,y);
    if(x>y){
           for(float i=y;i>0;i--){
            float r0=x/i;
            int r1=r0;
            //printf("float%f__%d\n",r0,r1);
            if(r1==r0){
                float r2=y/i;
                int r3=r2;
                if(r3==r2){
                    printf("\nDILNIK %f\n",i);
                    i=1;
                }
            }
           }

    }
    }
//*******************************************
//*******************************************
//*******************************************
//*******************************************
//*******************************************
task5(){
    int i,j,k,l;
    printf("Enter nominal 1 kosti ");
    scanf("%d%d",&i,&j);
    printf("Enter nominal 2 kosti ");
    scanf("%d%d",&k,&l);
    if(i>6||j>6||k>6||l>6){
        printf("ERROR NUmber\n");
        return -1;
    }
    printf("%d_%d %d_%d\n",i,j,k,l);
    if((i==k||i==l)||(j==k||j==l)){
        if(i==j||k==l){
            printf("Mi moshem poloshit tolko vertikalno");
            return -2;
        }
        printf("Moshemo poloshit gorisontalno");
        return 0;
    }
    printf("Ne moshem :(");
}
//*******************************************
//*******************************************
//*******************************************
//*******************************************
//*******************************************
//*******************************************
task6(){
    double a,b,c;
    printf("Enter 3 storoni:\n");
    scanf("%lf %lf %lf",&a , &b, &c);

    if(a==b && b==c){
        printf("TRIANGLE RIVNOSTORONIQ\n");
        return 0;
    }
    if(a==b || b==c){
        printf("TRIANGLE RIVNOBEDRENIQ\n");
        return 0;
    }
    if((a * a + b * b == c * c) || (a * a + c * c == b * b) || (c * c + b * b == a * a)){
        printf("TRIANGLE PRIAMOQ\n");
        return 0;
    }
    printf("Eto prosto TRIANGLE\n");
}

task7(){
    struct dat{
    double x;
    double y;
    double d1;
    double d2;
    double d3;
    };
    struct dat a;
    printf("Enter x,y A point:\n");
    scanf("%lf %lf",&a.x , &a.y);
    struct dat b;
    printf("Enter x,y B point:\n");
    scanf("%lf %lf",&b.x , &b.y);
    struct dat c;
    printf("Enter x,y C point:\n");
    scanf("%lf %lf",&c.x , &c.y);
    struct dat x;
    printf("Enter x,y X point:\n");
    scanf("%lf %lf",&x.x , &x.y);
    a.d1=pow(pow(b.x-a.x,2.0)+pow(b.y-a.y,2.0),1.0/2);
    a.d2=pow(pow(c.x-a.x,2.0)+pow(c.y-a.y,2.0),1.0/2);
    a.d3=pow(pow(x.x-a.x,2.0)+pow(x.y-a.y,2.0),1.0/2);
    if(a.d3>a.d1||a.d3>a.d1){
        printf("Toshka za Treygolnikom");
        return 0;
    }
    b.d1=pow(pow(a.x-b.x,2.0)+pow(a.y-b.y,2.0),1.0/2);
    b.d2=pow(pow(c.x-b.x,2.0)+pow(c.y-b.y,2.0),1.0/2);
    b.d3=pow(pow(x.x-b.x,2.0)+pow(x.y-b.y,2.0),1.0/2);
    if(b.d3>b.d1||b.d3>b.d1){
        printf("Toshka za Treygolnikom");
        return 0;
    }
    c.d1=pow(pow(a.x-c.x,2.0)+pow(a.y-c.y,2.0),1.0/2);
    c.d2=pow(pow(b.x-c.x,2.0)+pow(b.y-c.y,2.0),1.0/2);
    c.d3=pow(pow(x.x-c.x,2.0)+pow(x.y-c.y,2.0),1.0/2);
    if(c.d3>c.d1||c.d3>c.d1){
        printf("Toshka za Treygolnikom");
        return 0;
    }
    printf("Toshka v Treygolnike");
    }
