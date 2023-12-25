#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void main(){
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d", &n);

    //Visited array
    int V[n];
    for(int i=0; i<n; i++){
        V[i]=0;
    }

    int A[n][n],u,v;
    int min= INT_MAX;
    int cost=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            printf("A[%d][%d]:", i, j);
            scanf("%d",&A[i][j]);
            if(A[i][j]==0)
            A[i][j]=INT_MAX;
            if(A[i][j]<min){
                min=A[i][j];
                u=i;
                v=j;
            }
        }
    }
    int e=1;
    V[v]=1;
    V[u]=1;
    cost+=min;
    printf("{%d, %d} = %d \n", u, v, min);
    while(e<n-1){
        min=INT_MAX;
        for(int i=0; i<n; i++){
            if(V[i]<min){
                if(V[i]==1){
                    for(int j=0; j<n; j++){
                        if(A[i][j]<min){
                            if(V[j]!=1)
                            min=A[i][j];
                            u=i;
                            v=j;
                        }
                    }
                }
            }
        }

        V[v]=1;
        
        printf("{%d, %d} = %d\n", u, v, min);
        cost+=min;
        e++;
    }
    printf("Minimum Cost : %d\n", cost);
}