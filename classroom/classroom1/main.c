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
if (ans == '2') {
    task2();
    }
if (ans == '3') {
    task3();
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
