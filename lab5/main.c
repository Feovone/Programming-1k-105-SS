#include <stdio.h>
#include <stdlib.h>

int main()
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
