#include<stdio.h>
char A[10000];

void k_string(int n,int k)
{
    int j;
    if(n<1)
        printf("%s\n", A);
    else
    {
        for(j=0;j<k;j++)
        {
            A[n-1]=j+112;
            k_string(n-1,k);
        }
    }
}

int main()
{
    int n,k;
    scanf("%d %d", &n,&k);
    k_string(n,k);
}
