#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef float (*uf)(float,float);


char DecToBin( int n )
 {
char i;
int j;
int res[10];
if ( n >= 2 )
{
DecToBin( n/2 );
i++;
res[i]=n%2;
}

while(j<3){
printf(" /%d",res[j]);
++j;}
return(res);
}



int main (int argc, char* argv[])
{
char array[]="A+2";
int len=strlen(array);
char a;
int s=0;
for(int i=0;len>i;++i)
{
a=DecToBin( array[i]);
printf(" _%d ",a);
s+=a;
}
printf("%d %d ",a,s);

}

