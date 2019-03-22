#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
   int q,sz,z=-1;
   int e=0;

   printf("Please enter size of massive\n");
   scanf("%d",&sz);
   int a[sz];
printf("Enter array numbers\n");
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
for (int p=0;p<sz;p++){
    printf("%d",a[p]);
  }
       return 0;

}
