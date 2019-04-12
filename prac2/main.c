#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef float (*uf)(float,float);
void clrscr()
{
    system("@cls||clear");
}

float sum(float a,float b){
return a+b;
}
float substract(float a,float b){
return a-b;
}
float divide(float a,float b){
return a/b;
}
float multiplie(float a,float b){
return a*b;
}

int main(int argc, char *argv[])
{
char ans;
while((ans = toupper(menu())) != 'Q') {
if (ans == 'C') {
     clrscr();
}
if (ans == '1') {
     cal();
}
if (ans == '2') {
     toup();
}

  }
}
  int menu(){
  char choice;
    printf("\n------------------------\n");
    printf("What do you want to do?\n");
    printf("------------------------\n");
    printf("[1]CALCULATION\n");
    printf("[C]CLEAR CON\n");
    printf("[2]1\n");
    while((choice = getchar()) == '\n');
    printf("\n");
    return choice;
  }

int cal(){
     uf array[256]={NULL};
  array['+']=sum;
  array['-']=substract;
  array['/']=divide;
  array['*']=multiplie;
  char c;
  float a,b;

  //scanf("%c",&c);
  if(scanf("%f%c%f",&a,&c,&b) == 3){

    printf("res: %f",array[c](a,b));
  }
}

toup(){

}



