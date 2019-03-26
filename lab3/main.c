#include <stdio.h>
#include <stdlib.h>
#include <math.h>
char menu() {
    char choice;
    printf("\n\n***********************\n");
    printf("What do you want to do?\n");
    printf("________________________\n");
    printf("[1] Complete the first task \n");
    printf("[2] Complete the second task \n");
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
if (ans == '1') {
     function1();
}
if (ans == '2') {
     function2();
    }
}}
int function1()
{


   int q,sz,z=-1;
   int e=0;

   printf("Please enter size of massive\n");
   scanf("%d",&sz);
   int a[sz];
printf("Enter array numbers and -1 end\n");
   while(e!=-1){

   scanf("%d",&q);
   a[e]=q;
   e++;
   z++;
   if(q==-1){
    e=-1;
   }
      }
  if (z>sz || z<sz){
    printf("ERROR:INVALID SIZE OF MASSIVE");
}
//int sz=sizeof(a)/sizeof(a[0]);


  for(int i=1;i<sz;i++){
    int k=a[i];
    int j=i-1;

    while(j>=0 && a[j]>k){
     a[j+1]=a[j];
     j=j-1;
     for (int p=0;p<sz;p++){
   // printf("\n--%d",a[p]);
  }
    }
     a[j+1]=k;
   //printf("\n %d___%d\n",a[i],a[j]);
  }
  printf("SORT Massive ");
for (int p=0;p<sz;p++){
    printf("%d",a[p]);
  }
}
//*********************
//*********************
//*********************
//*********************
//*********************
int function2(){
    printf("Entered size ");
    int a=1;
    scanf("%d",&a);
    int b=a;
    int mat[a][b];
    for(int i=1;i<=a;i++){
        printf("\n");
    for(int j=1;j<=b;j++){
    if (i==j){
        mat[i][j]=1;
    }
    if (i!=j){
        mat[i][j]=0;
    }
    printf("%d",mat[i][j]);
}}
}
