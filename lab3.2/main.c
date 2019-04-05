#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
    int m = 3, n = m;
    int mat[m][n];
    for(int i=0; i < m; i++){
     for(int j=0; j < n; j++){
        scanf("%d", &mat[i][j]);
     }
    }

    for(int i=0; i < m; i++){
     for(int j=0; j < n; j++){
        char c = j < n - 1 ? ' ' : '\n';
        printf("%d%c",mat[i][j], c);
     }
    }
    int err=0;
    for(int k=0; k < m; k++){
     for(int l=0; l < n; l++){
    if(k==l){
        if(mat[k][l]!=1){

            err++;
        }
    }
    if (k!=l){
        if(mat[k][l]!=0){

            err++;
        }
    }}

    }
 if (err!=0){
        printf("MATRIX not Diagon");
    }

    if(err==0){
                printf("MATRIX  Diagon");


    }}
