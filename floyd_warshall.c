#include <stdio.h>
#include <stdlib.h>

#define inf 999

void f_warshall(int **a,int n){
    int i,j,k;

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(i==j){
                    a[i][j]=0;
                }
                else if(a[i][j]>a[i][k]+a[k][j]){
                    a[i][j]=a[i][k]+a[k][j];
                }
                else{
                    a[i][j]=a[i][j];
                }
            }
        }
    }
}

int main(){
    int i,j,k,n;
printf("Enter the number of vertices: ");
scanf("%d",&n);

int **a=(int**)malloc(n * sizeof(int*));

for(i=0;i<n;i++){
    a[i]=(int*)malloc(n * sizeof(int));
}

printf("Enter the matrix: \n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
    scanf("%d",&a[i][j]);
    }
}

printf("The original matrix: \n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
    printf("%d\t",a[i][j]);
    }
    printf("/n");
}
    
f_warshall(a,n);

printf("All paired shortest path: \n");
for(i=0;i<n;i++){
    for(j=0;j<n;j++){
    printf("%d\t",a[i][j]);
    }
    printf("/n");
}

for(i=0;i<n;i++){
    free(a[i]);
}
free(a);

return 0;
}
