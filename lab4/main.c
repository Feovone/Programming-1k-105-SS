#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>



int main ()
{
    char array[100];
    for(int j=0;j<100;j++){
        char c;
        scanf("%c",&c);
        if(c=='!'){
            break;
        }
        array[j] = c;
        printf("%c",array[j]);
}

int len=strlen(array);
int a;
int s=0;
for(char i=0;len>i;++i)
{
        a=array[i];
        s+=a;
}
printf(" %d ",s);
}

