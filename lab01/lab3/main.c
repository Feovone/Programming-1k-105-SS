#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
   int res;
   int a[5]={8,2,3,4,5,7};
   int sz=sizeof(a)/sizeof(a[0]);
  for(int i=0;i<sz;i++){
    int k=a[i];
    int j=i+1;
    for(;j>=0 && a[j]>k;){
  a[j]=a[j-1];

  }}
  for (int p=0;p<=sz;p++){
    printf("%d",a[p]);
  }
       return 0;
}
