#include<stdio.h>
//use a sort of dfs to go through the blocks
int visited[1000][1000];
void DFS(int i,int j)
{
    
}

void island(int A[][],int M, int N)
{
    int B[M][N];
    int i,j,max=0;
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            n = DFS(i,j);
            if(max <n)
                max = n;
        }
    }
    printf("%d\n", max);
}

int main()
{
    int M,N,i,j;
    scanf("%d %d", &M,&N);
    int A[M][N];
    for(i=0;i<M;i++)
    {
        for(j=0;j<N;j++)
        {
            scanf("%d", &A[i][j]);
        }
    }
    island(A,M,N);
}
